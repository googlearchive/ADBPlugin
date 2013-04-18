# ADB Plugin

ADB Plugin is a Chrome Extension that runs ADB daemon and enables remote debugging for mobile.

# How to run (Mac)
Visit https://github.com/repenaxa/ADBPlugin/raw/master/out/npADBPlugin-crx.crx and download extension.
Go to chrome://extensions and drop that file there.
Click little Android icon next to address bar.

# How to build
Get FireBreath at http://www.firebreath.org/display/documentation/Download
Place ADBPlugin under firebreath/projects/ADBPlugin
Run ./prepmac.sh && xcodebuild ARCHS=i386 ONLY_ACTIVE_ARCH=NO -project build/FireBreath.xcodeproj
The build will be available at build/projects/ADBPlugin/gen/npADBPlugin-crx.crx.
There is a pre-built version available at https://github.com/repenaxa/ADBPlugin/raw/master/out/npADBPlugin-crx.crx for convenience. 
