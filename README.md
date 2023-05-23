# Lightshot Privacy Tools
Patches and workarounds to make Lightshot less spyware-like.
## Removing Screenshot Analytics
Prevent lightshot from recording excessive meta information about your screenshots.
### macOS
Lightshot sends what appears to be screen coordinate data to a Google Analytics endpoint every time you take a screenshot. The program in this repo will patch your Lightshot install so that it no longer contacts the GA domain.
```bash
sudo ./lightshot-remove-analytics-mac
```
Please note that since this app is from the Mac App Store, making changes like we just did will require us to remove existing codesignatures to launch the app again. I've included an open source program called "unsign" in this repository, which will allow us to do the following:
```bash
sudo ./unsign /Applications/Lightshot\ Screenshot.app/Contents/MacOS/Lightshot\ Screenshot /Applications/Lightshot\ Screenshot.app/Contents/MacOS/Lightshot\ Screenshot
```
Alternatively, if you're on or above macOS 10.15.x and also have the Xcode CLI tools installed (`xcode-select --install`), you can use:
```bash
codesign --remove-signature /Applications/Lightshot\ Screenshot.app/
```
### Windows
Lightshot on Windows does not record analytics to the same extent as it does on macOS.

## Custom upload server
// todo
