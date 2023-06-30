/*
KotaCC
*/

#include "kotacc.h"

UIColor* colorFromHexString(NSString* hexString) {
    NSString *daString = [hexString stringByReplacingOccurrencesOfString:@" " withString:@""];
    if (![daString containsString:@"#"]) {
        daString = [@"#" stringByAppendingString:daString];
    }
    unsigned rgbValue = 0;
    NSScanner *scanner = [NSScanner scannerWithString:daString];
    [scanner setScanLocation:1]; // bypass '#' character
    [scanner scanHexInt:&rgbValue];

    NSRange range = [hexString rangeOfString:@":" options:NSBackwardsSearch];
    NSString* alphaString;
    if (range.location != NSNotFound) {
        alphaString = [hexString substringFromIndex:(range.location + 1)];
    } else {
        alphaString = @"1.0"; //no opacity specified - just return 1 :/
    }

    return [UIColor colorWithRed:((rgbValue & 0xFF0000) >> 16)/255.0 green:((rgbValue & 0xFF00) >> 8)/255.0 blue:(rgbValue & 0xFF)/255.0 alpha:[alphaString floatValue]];
}

NSUserDefaults *_preferences;
BOOL _enabled;
BOOL moduleProvidesOwnPlatter;
/*
My Hooks
*/

%hook SBControlCenterWindow

-(UIColor *)setFill {
    NSString *ccBackgroundColorString = [_preferences objectForKey:@"CCbackgroundColor"];
    if (ccBackgroundColorString) {
      self.backgroundColor = colorFromHexString(ccBackgroundColorString);
    }
    return %orig;
}

%end

%hook CCUIContentModuleContentContainerView

-(NSArray *)subviews {
 id subviews = %orig;
 NSString *realBussyString = [_preferences objectForKey:@"backgroundColor"];
 for (MTMaterialView * origSubview in subviews) {
  if ([origSubview isMemberOfClass:%c(MTMaterialView)]) {
   if (realBussyString) {
    origSubview.backgroundColor = colorFromHexString(realBussyString);
   }
  }
 }
 return subviews;
}

-(CALayer *)layer {
  CALayer *origLayer = %orig;
  NSString *glowColorString2 = [_preferences objectForKey:@"shadowColor"];
  NSLog(@"[*]Kota CC Glow: %@",glowColorString2);
  if (glowColorString2) {
    origLayer.shadowColor = colorFromHexString(glowColorString2).CGColor;
  }
  origLayer.shadowOpacity = 1;
  origLayer.shadowOffset = CGSizeMake(3.0f,3.0f);
  return origLayer;
}

-(void)setModuleProvidesOwnPlatter:(bool)arg1 {
  %orig(YES);
}

%end

%hook CCUIModuleCollectionView

-(CALayer *)layer {
  CALayer *origLayer = %orig;
  NSString *glowColorString = [_preferences objectForKey:@"shadowColor"];
  NSLog(@"[*]Kota CC Glow: %@",glowColorString);
  if (glowColorString) {
    origLayer.shadowColor = colorFromHexString(glowColorString).CGColor;
  }
  origLayer.shadowOpacity = 1;
  origLayer.shadowOffset = CGSizeMake(-3.0f,-3.0f);
  return origLayer;
}

%end

/*
Init prefs
*/

%ctor {
	_preferences = [[NSUserDefaults alloc] initWithSuiteName:@"gay.kota.kotacc"];
	[_preferences registerDefaults:@{
		@"enabled" : @YES,
	}];
	_enabled = [_preferences boolForKey:@"enabled"];
	if(_enabled) {
		NSLog(@"[KotaCC] Enabled");
		%init();
	} else {
		NSLog(@"[KotaCC] Disabled, bye!");
	}
}