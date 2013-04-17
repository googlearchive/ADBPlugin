// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef H_ADBPluginPLUGIN
#define H_ADBPluginPLUGIN

#include "PluginWindow.h"
#include "PluginEvents/MouseEvents.h"
#include "PluginEvents/AttachedEvent.h"

#include "PluginCore.h"


FB_FORWARD_PTR(ADBPlugin)
class ADBPlugin : public FB::PluginCore
{
public:
    static void StaticInitialize();
    static void StaticDeinitialize();

public:
    ADBPlugin();
    virtual ~ADBPlugin();

public:
    void onPluginReady();
    void shutdown();
    virtual FB::JSAPIPtr createJSAPI();
    virtual bool isWindowless() { return false; }

    std::string getFilesystemPath();

    BEGIN_PLUGIN_EVENT_MAP()
    END_PLUGIN_EVENT_MAP()

    /** BEGIN EVENTDEF -- DON'T CHANGE THIS LINE **/
    /** END EVENTDEF -- DON'T CHANGE THIS LINE **/
};


#endif

