// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "ADBPlugin.h"

#ifndef H_ADBPluginAPI
#define H_ADBPluginAPI

class ADBPluginAPI : public FB::JSAPIAuto
{
public:
    ADBPluginAPI(const ADBPluginPtr& plugin, const FB::BrowserHostPtr& host) :
        m_plugin(plugin), m_host(host)
    {
        registerMethod("isRunning", make_method(this, &ADBPluginAPI::isRunning));
        registerMethod("adb", make_method(this, &ADBPluginAPI::adb));
    }

    virtual ~ADBPluginAPI() {};

    ADBPluginPtr getPlugin();

    FB::variant isRunning();
    FB::variant adb(const std::string& command);

private:
    FB::variant shell(const std::string& command);

    ADBPluginWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;

    std::string m_testString;
};

#endif // H_ADBPluginAPI

