# ADB Plugin

ADB Plugin is a Chrome Extension that runs ADB daemon and enables remote debugging for mobile.

# How to build
Get FireBreath at http://www.firebreath.org/display/documentation/Download
Place ADBPlugin under firebreath/projects/ADBPlugin
Run ./prepmac.sh && xcodebuild ARCHS=i386 OLNY_ACTIVE_ARCH=NO -project build/FireBreath.xcodeproj 
