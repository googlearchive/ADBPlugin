// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

var plugin = document.getElementById("adb-plugin");

var running = false;

chrome.browserAction.onClicked.addListener(function() {
  chrome.browserAction.disable();
  if (plugin.isServerRunning())
    plugin.killServer();
  else
    plugin.startServer();
  chrome.browserAction.enable();
  update(true);
});

function update(oneTime) {
  running = plugin.isServerRunning();
  if (running) {
    chrome.browserAction.setIcon({
      path: {
        19: "on_19.png",
        38: "on_38.png"
      }
    });
    var devices = plugin.devices().split("\n");
    devices = devices.slice(1); // Trim the header
    var count = 0;
    for (var i = 0; i < devices.length; ++i) {
      if (devices[i] !== "")
        count++;
    }
    chrome.browserAction.setBadgeText({text: String(count)});
    chrome.browserAction.setTitle({title: "Stop ADB"});
  } else {
    chrome.browserAction.setIcon({
      path: {
        19: "off_19.png",
        38: "off_38.png"
      }
    });
    chrome.browserAction.setBadgeText({text: ""});
    chrome.browserAction.setTitle({title: "Start ADB"});
  }
  if (!oneTime)
    setTimeout(update, 1000);
}

update();
