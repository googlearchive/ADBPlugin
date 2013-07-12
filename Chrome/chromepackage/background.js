// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

var plugin = document.getElementById('adb-plugin');

chrome.browserAction.setBadgeBackgroundColor({color: '#070'});

function update(oneTime) {
  var devicesMessage = plugin.devices();
  var serverIsRunning = devicesMessage.substr(0, 4) === "OKAY";
  if (serverIsRunning) {
    var devices = devicesMessage.substr(8).split("\n");
    chrome.browserAction.setIcon({
      path: {
        19: 'on_19.png',
        38: 'on_38.png'
      }
    });

    var deviceCount = devices.length - 1;
    if (deviceCount) {
      chrome.browserAction.setBadgeText({text: String(deviceCount)});
    } else {
      chrome.browserAction.setBadgeText({text: ''});
    }
  } else {
    chrome.browserAction.setIcon({
      path: {
        19: 'off_19.png',
        38: 'off_38.png'
      }
    });
    chrome.browserAction.setBadgeText({text: ''});
  }
  if (!oneTime)
    setTimeout(update, 3000);
}

update();

function start() {
  setTimeout(function() { plugin.startServer(); });
}

function stop() {
  setTimeout(function() { plugin.killServer(); });
}

function isServerRunning() {
  return plugin.devices().substr(0, 4) === "OKAY";
}

function devices() {
  chrome.tabs.create({url:'chrome://inspect'});
}

function help(url) {
  chrome.tabs.create({url: "https://developers.google.com/chrome-developer-tools/docs/remote-debugging"});
}
