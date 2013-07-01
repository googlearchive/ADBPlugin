# The ADB Plugin Chrome extension for remote debugging

ADB Plugin is a Chrome Extension that runs ADB daemon and enables remote debugging for mobile. With it, you do not need to download the Android SDK or run ADB yourself from the command line. This extension is experimental. It runs on Win, Mac and Linux (ia32/x86_64). For full installation directions, click through to [developers.google.com](https://developers.google.com/chrome-developer-tools/docs/remote-debugging).

## How to install and run
- [Install from the Chrome Web Store](https://chrome.google.com/webstore/detail/adb/dpngiggdglpdnjdoaefidgiigpemgage)
- Click little Android icon next to address bar.
- For **Windows**, make sure you have ADB communication [drivers](https://dl.google.com/android/repository/usb_driver_r07-windows.zip) installed.

You need both USB debugging for your phone enabled as well as remote debugging turned on inside of Chrome for Android. Follow through for [details on how to enable these settings](https://developers.google.com/chrome-developer-tools/docs/remote-debugging)..

## Screenshots

![](http://i.imgur.com/q4qn1le.png)

![](http://i.imgur.com/q90tutk.png)


## Building this extension (Mac)
- Get FireBreath at [firebreath.org/display/documentation/Download](http://www.firebreath.org/display/documentation/Download)
- Place ADBPlugin under `firebreath/projects/ADBPlugin`
- Run the following to build and create a zip (for CWS):
```sh
./prepmac.sh && xcodebuild ARCHS=i386 ONLY_ACTIVE_ARCH=NO -configuration Release -project build/FireBreath.xcodeproj && find ./build/projects/ADBPlugin/gen/npADBPlugin-crx -path '*/.*' -prune -o -type f -print | zip ./ADBPlugin-CWS.zip -@
```
- The build will be available at `build/projects/ADBPlugin/gen/npADBPlugin-crx.crx`. The zip will be in the current path.
