#/**********************************************************\
#
# Auto-Generated Plugin Configuration file
# for ADB
#
#\**********************************************************/

set(PLUGIN_NAME "ADBPlugin")
set(PLUGIN_PREFIX "ADB")
set(COMPANY_NAME "Chromium")

# ActiveX constants:
set(FBTYPELIB_NAME ADBPluginLib)
set(FBTYPELIB_DESC "ADBPlugin 1.0 Type Library")
set(IFBControl_DESC "ADBPlugin Control Interface")
set(FBControl_DESC "ADBPlugin Control Class")
set(IFBComJavascriptObject_DESC "ADBPlugin IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "ADBPlugin ComJavascriptObject Class")
set(IFBComEventSource_DESC "ADBPlugin IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID e709c186-d261-586d-9eff-0d87c54da863)
set(IFBControl_GUID 802a5427-54a1-50ba-880d-9de7b401d3c0)
set(FBControl_GUID 45dd2b59-0500-590f-88f7-81f76af9ff39)
set(IFBComJavascriptObject_GUID ac4cd386-f1d6-5156-9d0e-6466c33cac53)
set(FBComJavascriptObject_GUID 67fdb95e-8614-54c8-96b8-45ce9493a96c)
set(IFBComEventSource_GUID 61e8409d-5068-5435-873e-7ee0a1470494)
if ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID aeba086f-7248-5c8a-a4cf-aa862ce5152b)
else ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID fbead137-e30f-5f43-bdad-d5bc0cb6c735)
endif ( FB_PLATFORM_ARCH_32 )

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "Chromium.ADBPlugin")
set(MOZILLA_PLUGINID "chromium.org/ADBPlugin")

# strings
set(FBSTRING_CompanyName "Chromium")
set(FBSTRING_PluginDescription "ADB Daemon Plugin")
set(FBSTRING_PLUGIN_VERSION "0.9.1")
set(FBSTRING_LegalCopyright "Copyright 2013 Chromium Authors")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}")
set(FBSTRING_ProductName "ADB")
set(FBSTRING_FileExtents "")
if ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "ADB")  # No 32bit postfix to maintain backward compatability.
else ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "npADBPlugin")
endif ( FB_PLATFORM_ARCH_32 )
set(FBSTRING_MIMEType "application/x-adbplugin")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 0)
set(FBMAC_USE_COCOA 0)
set(FBMAC_USE_COREGRAPHICS 0)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
