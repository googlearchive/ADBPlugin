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
        registerMethod("startServer", make_method(this, &ADBPluginAPI::startServer));
        registerMethod("killServer", make_method(this, &ADBPluginAPI::killServer));
        registerMethod("devices", make_method(this, &ADBPluginAPI::devices));
        registerMethod("openUrl", make_method(this, &ADBPluginAPI::openUrl));
    }

    virtual ~ADBPluginAPI() {};

    ADBPluginPtr getPlugin();

    FB::variant startServer();
    FB::variant killServer();
    FB::variant devices();
    FB::variant openUrl(const std::string& url);

private:
    std::string adb(const std::string& command);

    ADBPluginWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;

    std::string m_testString;
};

#endif // H_ADBPluginAPI

