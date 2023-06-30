TARGET := iphone:clang:14.5:12.0
THEOS_PACKAGE_SCHEME = rootless

include $(THEOS)/makefiles/common.mk

BUNDLE_NAME = kotaprefs2

kotaprefs2_FILES = $(wildcard *.m)
kotaprefs2_FRAMEWORKS = UIKit
kotaprefs2_PRIVATE_FRAMEWORKS = Preferences
kotaprefs2_INSTALL_PATH = /Library/PreferenceBundles
kotaprefs2_CFLAGS = -fobjc-arc
kotaprefs2_LIBRARIES = colorpicker
# kotaprefs2_EXTRA_FRAMEWORKS = Alderis

include $(THEOS_MAKE_PATH)/bundle.mk
