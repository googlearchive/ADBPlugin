// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

chrome.browserAction.setBadgeBackgroundColor({color: '#070'});

chrome.browserAction.setIcon({
  path: {
    19: 'off_19.png',
    38: 'off_38.png'
  }
});

function devices() {
  chrome.tabs.create({url:'chrome://inspect'});
}
