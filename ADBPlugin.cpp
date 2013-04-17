// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ADBPluginAPI.h"

#include "ADBPlugin.h"

void ADBPlugin::StaticInitialize()
{
}

void ADBPlugin::StaticDeinitialize()
{
}

ADBPlugin::ADBPlugin()
{
}

ADBPlugin::~ADBPlugin()
{
    // This is optional, but if you reset m_api (the shared_ptr to your JSAPI
    // root object) and tell the host to free the retained JSAPI objects then
    // unless you are holding another shared_ptr reference to your JSAPI object
    // they will be released here.
    releaseRootJSAPI();
    m_host->freeRetainedObjects();
}

void ADBPlugin::onPluginReady()
{
}

void ADBPlugin::shutdown()
{
}

FB::JSAPIPtr ADBPlugin::createJSAPI()
{
    // m_host is the BrowserHost
    return boost::make_shared<ADBPluginAPI>(FB::ptr_cast<ADBPlugin>(shared_from_this()), m_host);
}

std::string ADBPlugin::getFilesystemPath()
{
    return m_filesystemPath;
}
