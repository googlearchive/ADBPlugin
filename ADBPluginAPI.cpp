// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"

#include "ADBPluginAPI.h"

FB::variant ADBPluginAPI::isServerRunning()
{
    std::string result = shell("echo '000Chost:devices' | telnet 127.0.0.1 5037 2>/dev/null");
    return result.find("Connected to localhost") != std::string::npos;
}

FB::variant ADBPluginAPI::startServer()
{
    return adb("start-server");
}

FB::variant ADBPluginAPI::killServer()
{
    return adb("kill-server");
}

FB::variant ADBPluginAPI::devices()
{
    return adb("devices");
}

FB::variant ADBPluginAPI::forward(const std::string& port)
{
    return adb("forward tcp:" + port + " localabstract:chrome_devtools_remote");
}

std::string ADBPluginAPI::shell(const std::string& command)
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

std::string ADBPluginAPI::adb(const std::string& command)
{
    std::string plugin_path = getPlugin()->getFilesystemPath();
    return shell("/bin/sh '" + dirname(plugin_path) + "/adb_command.sh' " + command);
}

std::string ADBPluginAPI::dirname(const std::string& path)
{
    std::string directory;
    const size_t last_slash_idx = path.rfind('/');
    if (std::string::npos != last_slash_idx)
    {
        directory = path.substr(0, last_slash_idx);
    }
    return directory;
}

ADBPluginPtr ADBPluginAPI::getPlugin()
{
    ADBPluginPtr plugin(m_plugin.lock());
    if (!plugin)
        throw FB::script_error("The plugin is invalid");
    return plugin;
}
