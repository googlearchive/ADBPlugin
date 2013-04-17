// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "FactoryBase.h"
#include "ADBPlugin.h"
#include <boost/make_shared.hpp>

class PluginFactory : public FB::FactoryBase
{
public:
    FB::PluginCorePtr createPlugin(const std::string& mimetype)
    {
        return boost::make_shared<ADBPlugin>();
    }
    
    void globalPluginInitialize()
    {
        ADBPlugin::StaticInitialize();
    }
    
    void globalPluginDeinitialize()
    {
        ADBPlugin::StaticDeinitialize();
    }
};

FB::FactoryBasePtr getFactoryInstance()
{
    static boost::shared_ptr<PluginFactory> factory = boost::make_shared<PluginFactory>();
    return factory;
}

