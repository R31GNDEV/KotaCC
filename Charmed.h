#include <UIKit/UIKit.h>

/*

Header(s) *meow*

*/

@class NSArray, CCUIModuleInstanceManager, CCUIModuleSettingsManager, CCUIControlCenterPositionProvider, CCUILayoutOptions, NSDictionary, NSHashTable, NSObject, NSString, CCUIModuleCollectionView;

@interface FCCCControlCenterModule : UIView 
@end

@interface CCUIContentModuleContentContainerView : UIView {



	bool _expanded;
	bool _moduleProvidesOwnPlatter;
	bool _clipsContentInCompactMode;
}
@property (assign,nonatomic) bool moduleProvidesOwnPlatter;                  //@synthesize moduleProvidesOwnPlatter=_moduleProvidesOwnPlatter - In the implementation block
@property (assign,nonatomic) bool clipsContentInCompactMode;                 //@synthesize clipsContentInCompactMode=_clipsContentInCompactMode - In the implementation block
-(id)init;
-(id)initWithFrame:(CGRect)arg1 ;
-(void)addSubview:(id)arg1 ;
-(void)layoutSubviews;
-(void)_setContinuousCornerRadius:(double)arg1 ;
-(void)_transitionToExpandedMode:(bool)arg1 force:(bool)arg2 ;
-(void)_configureModuleMaterialViewIfNecessary;
-(bool)_isContentClippingRequiredForSubview:(id)arg1 ;
-(void)transitionToExpandedMode:(bool)arg1 ;
-(void)setModuleProvidesOwnPlatter:(bool)arg1 ;
-(bool)moduleProvidesOwnPlatter;
-(id)materialViewGroupName;
-(bool)clipsContentInCompactMode;
-(void)setClipsContentInCompactMode:(bool)arg1 ;
@end

@interface MTMaterialView : UIView
@property (nonatomic, strong, readwrite) UIColor *backgroundColor;
@end

@interface SBControlCenterWindow : UIView
@end

@interface MTMaterialShadowView : UIView
{
    MTMaterialView *_materialView;
}
@property(nonatomic, readonly) MTMaterialView *materialView;
@property(nonatomic, assign, readwrite, getter=isOpaque) BOOL opaque;
@end

@protocol CCUIContentModuleContainerViewControllerDelegate, CCUIContentModule, CCUIContentModuleContentViewController;
@class NSString, NSArray, UIViewController, UIView, CCUIContentModuleBackgroundView, CCUIContentModuleContentContainerView, UITapGestureRecognizer, UIPreviewInteraction;

@interface CCUIContentModuleContainerViewController : UIView {

	BOOL _expanded;
	BOOL _contentModuleProvidesOwnPlatter;
	NSString* _moduleIdentifier;
	NSArray* _topLevelBlockingGestureRecognizers;
	UIViewController* _backgroundViewController;
	UIView* _highlightWrapperView;
	CCUIContentModuleBackgroundView* _backgroundView;
	CCUIContentModuleContentContainerView* _contentContainerView;
	UIView* _contentView;
	UIView* _maskView;
	UITapGestureRecognizer* _tapRecognizer;
	UIPreviewInteraction* _previewInteraction;
	UIEdgeInsets _expandedContentEdgeInsets;
}
@property (nonatomic,copy) NSString * moduleIdentifier;                                                          //@synthesize contentModule=_contentModule - In the implementation block
@property (nonatomic,retain) UIViewController * backgroundViewController;                                                  //@synthesize backgroundViewController=_backgroundViewController - In the implementation block
@property (assign,nonatomic) BOOL contentModuleProvidesOwnPlatter;                                                         //@synthesize contentModuleProvidesOwnPlatter=_contentModuleProvidesOwnPlatter - In the implementation block
@property (nonatomic,retain) UIView * highlightWrapperView;                                                                //@synthesize highlightWrapperView=_highlightWrapperView - In the implementation block
@property (nonatomic,retain) CCUIContentModuleBackgroundView * backgroundView;                                             //@synthesize backgroundView=_backgroundView - In the implementation block
@property (nonatomic,retain) CCUIContentModuleContentContainerView * contentContainerView;                                 //@synthesize contentContainerView=_contentContainerView - In the implementation block
@property (nonatomic,retain) UIView * contentView;                                                                         //@synthesize contentView=_contentView - In the implementation block
@property (nonatomic,retain) UIView * maskView;                                                                            //@synthesize maskView=_maskView - In the implementation block
@property (nonatomic,retain) UITapGestureRecognizer * tapRecognizer;                                                       //@synthesize tapRecognizer=_tapRecognizer - In the implementation block
@property (nonatomic,retain) UIPreviewInteraction * previewInteraction;                                                    //@synthesize previewInteraction=_previewInteraction - In the implementation block
@property (assign,getter=isExpanded,nonatomic) BOOL expanded;                                                              //@synthesize expanded=_expanded - In the implementation block
@property (assign,nonatomic) UIEdgeInsets expandedContentEdgeInsets;                                                       //@synthesize expandedContentEdgeInsets=_expandedContentEdgeInsets - In the implementation block
@property (nonatomic,readonly) CCUIContentModuleContentContainerView * moduleContentView; 
@property (nonatomic,readonly) NSArray * topLevelBlockingGestureRecognizers;                                               //@synthesize topLevelBlockingGestureRecognizers=_topLevelBlockingGestureRecognizers - In the implementation block
@property (readonly) unsigned long long hash; 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (copy,readonly) NSString * debugDescription; 
@property (nonatomic,readonly) NSArray * childViewControllersForAppearancePropagation; 
-(id)init;
-(void)setContentView:(UIView *)arg1 ;
-(UIView *)contentView;
-(id)initWithCoder:(id)arg1 ;
-(void)loadView;
-(id)initWithNibName:(id)arg1 bundle:(id)arg2 ;
-(void)setMaskView:(UIView *)arg1 ;
-(UIView *)maskView;
-(void)viewWillLayoutSubviews;
-(void)setBackgroundView:(CCUIContentModuleBackgroundView *)arg1 ;
-(CCUIContentModuleBackgroundView *)backgroundView;
-(BOOL)shouldAutomaticallyForwardAppearanceMethods;
-(BOOL)isExpanded;
-(void)previewInteraction:(id)arg1 didUpdatePreviewTransition:(double)arg2 ended:(BOOL)arg3 ;
-(void)previewInteractionDidCancel:(id)arg1 ;
-(BOOL)previewInteractionShouldBegin:(id)arg1 ;
-(id)_previewInteractionHighlighterForPreviewTransition:(id)arg1 ;
-(id)_previewInteraction:(id)arg1 viewControllerPresentationForPresentingViewController:(id)arg2 ;
-(BOOL)_previewInteractionShouldFinishTransitionToPreview:(id)arg1 ;
-(BOOL)_previewInteractionShouldAutomaticallyTransitionToPreviewAfterDelay:(id)arg1 ;
-(void)setExpanded:(BOOL)arg1 ;
-(UIPreviewInteraction *)previewInteraction;
-(void)setPreviewInteraction:(UIPreviewInteraction *)arg1 ;
-(NSString *)moduleIdentifier;
-(void)expandModule;
-(void)dismissExpandedModuleAnimated:(BOOL)arg1 ;
-(void)willResignActive;
-(void)willBecomeActive;
-(void)_handleTapGestureRecognizer:(id)arg1 ;
-(void)setContentContainerView:(CCUIContentModuleContentContainerView *)arg1 ;
-(UITapGestureRecognizer *)tapRecognizer;
-(void)setTapRecognizer:(UITapGestureRecognizer *)arg1 ;
-(CCUIContentModuleContentContainerView *)contentContainerView;
-(void)dismissPresentedContentAnimated:(BOOL)arg1 ;
-(NSArray *)topLevelBlockingGestureRecognizers;
-(BOOL)_shouldApplyBackgroundEffects;
-(id)initWithModuleIdentifier:(id)arg1 contentModule:(id)arg2 ;
-(void)setExpandedContentEdgeInsets:(UIEdgeInsets)arg1 ;
-(void)_closeExpandedModule;
-(void)_dismissModulePresentedContentAnimated:(BOOL)arg1 completion:(/*^block*/id)arg2 ;
-(void)_configureForContentModuleGroupRenderingIfNecessary;
-(void)_findTopLevelGestureRecognizersForView:(id)arg1 installOnView:(id)arg2 ;
-(void)_addTopLevelGestureRecognizersFromViewAndSubviews:(id)arg1 toGestureRecognizers:(id)arg2 blockingGestureRecognizers:(id)arg3 ;
-(CGRect)_backgroundFrameForExpandedState;
-(CGRect)_contentFrameForExpandedState;
-(BOOL)_isForceTouchAvailable;
-(CGRect)_contentBoundsForExpandedState;
-(CGRect)_presentationFrameForExpandedState;
-(CGRect)_contentFrameForRestState;
-(void)_configureMaskViewIfNecessary;
-(CCUIContentModuleContentContainerView *)moduleContentView;
-(void)_setDidExpandModulePreference;
-(CGRect)_backgroundFrameForRestState;
-(CGRect)_contentBoundsForTransitionProgress:(double)arg1 ;
-(void)setModuleIdentifier:(NSString *)arg1 ;
-(UIEdgeInsets)expandedContentEdgeInsets;
-(id<CCUIContentModule>)contentModule;
-(void)setContentModule:(id<CCUIContentModule>)arg1 ;
-(void)setBackgroundViewController:(UIViewController *)arg1 ;
-(BOOL)contentModuleProvidesOwnPlatter;
-(void)setContentModuleProvidesOwnPlatter:(BOOL)arg1 ;
-(UIView *)highlightWrapperView;
-(void)setHighlightWrapperView:(UIView *)arg1 ;
-(UIViewController *)backgroundViewController;
@end


@interface CCUIModuleCollectionView : UIView {


	CCUIModuleInstanceManager* _moduleManager;
	CCUIModuleSettingsManager* _settingsManager;
	CCUIControlCenterPositionProvider* _portraitPositionProvider;
	CCUIControlCenterPositionProvider* _landscapePositionProvider;
	CCUILayoutOptions* _layoutOptions;
	NSDictionary* _moduleViewControllerByIdentifier;
	NSDictionary* _moduleContainerViewByIdentifier;
	NSHashTable* _homeGestureDismissalAllowedModules;
	NSHashTable* _currentModules;
	NSHashTable* _expandedModules;
	NSString* _topmostModuleIdentifier;
	NSArray* _portraitDoubleMarginIndices;
	NSArray* _landscapeDoubleMarginIndices;
	BOOL _pendingModulePopulation;
	BOOL _pendingModulePositionProviderRefresh;
	BOOL _homeGestureDismissalAllowed;
}
@property (nonatomic,readonly) unsigned long long expandedModuleCount; 
@property (getter=isHomeGestureDismissalAllowed,nonatomic,readonly) BOOL homeGestureDismissalAllowed;              //@synthesize homeGestureDismissalAllowed=_homeGestureDismissalAllowed - In the implementation block
@property (nonatomic,retain) CCUIModuleCollectionView * moduleCollectionView; 
@property (readonly) unsigned long long hash; 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (nonatomic, strong, readwrite) UIColor *shadowColor;
@property (copy,readonly) NSString * debugDescription; 
@property (nonatomic,readonly) NSArray * childViewControllersForAppearancePropagation; 
-(void)dismissExpandedModuleAnimated:(BOOL)arg1 completion:(/*^block*/id)arg2 ;
-(long long)_interfaceOrientation;
-(void)moduleInstancesLayoutChangedForModuleInstanceManager:(id)arg1 ;
-(void)expandModuleWithIdentifier:(id)arg1 ;
-(id)_sizesForModuleIdentifiers:(id)arg1 moduleInstanceByIdentifier:(id)arg2 interfaceOrientation:(long long)arg3 ;
-(void)moduleInstancesChangedForModuleInstanceManager:(id)arg1 ;
-(void)displayWillTurnOff;
-(void)dismissPresentedContentAnimated:(BOOL)arg1 completion:(/*^block*/id)arg2 ;
-(BOOL)isHomeGestureDismissalAllowed;
-(void)contentModuleContainerViewController:(id)arg1 willCloseExpandedModule:(id)arg2 ;
-(void)contentModuleContainerViewController:(id)arg1 didBeginInteractionWithModule:(id)arg2 ;
-(id)queryAllTopLevelBlockingGestureRecognizers;
-(CCUIModuleCollectionView *)moduleCollectionView;
-(void)contentModuleContainerViewController:(id)arg1 willPresentViewController:(id)arg2 ;
-(void)loadView;
-(BOOL)contentModuleContainerViewController:(id)arg1 canBeginInteractionWithModule:(id)arg2 ;
-(void)viewWillAppear:(BOOL)arg1 ;
-(void)_updateHomeGestureDismissalAllowed;
-(id)_positionProviderForInterfaceOrientation:(long long)arg1 ;
-(void)willResignActive;
-(id)_moduleInstances;
-(NSArray *)childViewControllersForAppearancePropagation;
-(void)viewDidLoad;
-(id)_doubleMarginIndicesForModuleIdentifiers:(id)arg1 moduleInstanceByIdentifier:(id)arg2 interfaceOrientation:(long long)arg3 ;
-(id)verticalDoubleMarginIndicesForLayoutView:(id)arg1 ;
-(void)_beginAppearanceTransition:(BOOL)arg1 affectedModule:(id)arg2 ;
-(void)contentModuleContainerViewController:(id)arg1 willOpenExpandedModule:(id)arg2 ;
-(void)contentModuleContainerViewController:(id)arg1 didFinishInteractionWithModule:(id)arg2 ;
-(void)_removeAndTearDownModuleViewControllerFromHierarchy:(id)arg1 ;
-(void)didUpdateHomeGestureDismissalAllowed:(BOOL)arg1 forModuleWithIdentifier:(id)arg2 ;
-(CGSize)preferredContentSize;
-(void)contentModuleContainerViewController:(id)arg1 willDismissViewController:(id)arg2 ;
-(id)_setupAndAddModuleViewControllerToHierarchy:(id)arg1 ;
-(void)_refreshPositionProvidersIfNecessary;
-(void)contentModuleContainerViewControllerDismissPresentedContent:(id)arg1 ;
-(unsigned long long)expandedModuleCount;
-(id)topmostModuleView;
-(void)viewWillDisappear:(BOOL)arg1 ;
-(void)setModuleCollectionView:(CCUIModuleCollectionView *)arg1 ;
-(void)willBecomeActive;
-(id)_currentLayoutOptions;
-(void)_refreshPositionProviders;
-(void)_updateModuleControllers;
-(void)_updatePositionProviders;
-(void)orderedEnabledModuleIdentifiersChangedForSettingsManager:(id)arg1 ;
-(void)_updateEnabledModuleIdentifiers;
-(id)initWithModuleInstanceManager:(id)arg1 ;
-(void)_populateModuleViewControllers;
-(void)viewDidDisappear:(BOOL)arg1 ;
-(BOOL)ccui_shouldPropagateAppearanceCalls;
-(BOOL)_canShowWhileLocked;
-(void)contentModuleContainerViewController:(id)arg1 didCloseExpandedModule:(id)arg2 ;
-(BOOL)isModuleExpandedForIdentifier:(id)arg1 ;
-(BOOL)shouldAutomaticallyForwardAppearanceMethods;
-(id)_activePositionProvider;
-(void)viewDidAppear:(BOOL)arg1 ;
-(CGSize)sizeForChildContentContainer:(id)arg1 withParentContainerSize:(CGSize)arg2 ;
-(id)horizontalDoubleMarginIndicesForLayoutView:(id)arg1 ;
-(CGRect)compactModeFrameForContentModuleContainerViewController:(id)arg1 ;
-(void)_populateModulesIfNecessary;
-(id)relevantSnapHeightsForOrientation:(long long)arg1 ;
-(BOOL)isAtMaxHeight;
-(void)contentModuleContainerViewController:(id)arg1 didOpenExpandedModule:(id)arg2 ;
@end

@interface CCUIContentModuleBackgroundView : UIView
@end
