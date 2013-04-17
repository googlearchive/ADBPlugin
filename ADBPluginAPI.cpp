// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"

#include "ADBPluginAPI.h"

FB::variant ADBPluginAPI::shell(const std::string& command)
{
    FILE * pPipe;
    fd_set readfd;
    char buffer[2048];

    if (!(pPipe = popen(command.c_str(), "r")))
         return "failed starting server";

    std::string response = "";
    while(fgets(buffer, sizeof(buffer), pPipe) != NULL)
        response += buffer;
    pclose(pPipe);
    return response;
}

FB::variant ADBPluginAPI::adb(const std::string& command)
{
    std::string plugin_path = getPlugin()->getFilesystemPath();
    for (int i = 0; i < 4; ++i)
        plugin_path = plugin_path.substr(0, plugin_path.rfind("/"));

    return shell("/bin/sh '" + plugin_path + "/adb_command.sh' " + command);
}

ADBPluginPtr ADBPluginAPI::getPlugin()
{
    ADBPluginPtr plugin(m_plugin.lock());
    if (!plugin)
        throw FB::script_error("The plugin is invalid");
    return plugin;
}
