#/**********************************************************\
#
# Auto-Generated Plugin Configuration file
# for ADB
#
#\**********************************************************/

set(PLUGIN_NAME "ADBPlugin")
set(PLUGIN_PREFIX "ADB")
set(COMPANY_NAME "Chromium")

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
    set(FBSTRING_PluginName "ADB_${FB_PLATFORM_ARCH_NAME}")
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
