// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

function devices() {
  chrome.tabs.create({url:'chrome://inspect'});
}

function help(url) {
  chrome.tabs.create({url: "https://developers.google.com/chrome-developer-tools/docs/remote-debugging"});
}

function ticket(url) {
  chrome.tabs.create({url: "https://github.com/GoogleChrome/ADBPlugin"});
}
