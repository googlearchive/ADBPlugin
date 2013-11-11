# ADB Plugin 

ADB Plugin is a Chrome Extension that runs ADB daemon and enables remote debugging for mobile. With it, you do not need to download the Android SDK or run ADB yourself from the command line. This extension is experimental. It runs on Win, Mac and Linux (ia32/x86_64). For full installation directions, click through to [developers.google.com](https://developers.google.com/chrome-developer-tools/docs/remote-debugging).

## How to install and run

Special Notes:

* **Linux**: If you encounter "error while loading shared libraries" during installation, install the `ia32-libs` package.
* **Windows**, make sure you have [ADB USB communication drivers](http://developer.android.com/tools/extras/oem-usb.html) installed. ([Google Nexus USB driver here](https://dl.google.com/android/repository/usb_driver_r07-windows.zip))
* **Windows 8**: Unfortunately you cannot install from the Chrome Web Store. Right click and download [this CRX file](https://github.com/GoogleChrome/ADBPlugin/blob/master/out/npADBPlugin-crx.crx?raw=true) then open `about:extensions` in Chrome and drag the CRX onto that page to install. This extension will not automatically stay up to date.
 
Normal install:

- [Install from the Chrome Web Store](https://chrome.google.com/webstore/detail/adb/dpngiggdglpdnjdoaefidgiigpemgage)
- Click little Android icon next to address bar.


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
