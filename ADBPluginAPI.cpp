// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(OS_WIN)
#include <winsock2.h>
#elif defined(OS_POSIX)
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#endif

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"

#include "ADBPluginAPI.h"

#if defined(OS_WIN)
typedef SOCKET Socket;
#else
typedef int Socket;
#endif

void CloseSocket(Socket socket)
{
#if defined(OS_WIN)
    closesocket(socket);
#else
    close(socket);
#endif
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
    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(5037);
    client.sin_addr.s_addr = inet_addr("127.0.0.1");
    Socket sock = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(sock, (struct sockaddr*)&client, sizeof(client)) != 0) {
        CloseSocket(sock);
        return "Error: could not connect to ADB";
    }

    std::string devices = "000Chost:devices";
    if (send(sock, devices.c_str(), devices.length(), 0) == -1) {
        CloseSocket(sock);
        return "Error: could not send command";
    }

    std::string response;
    char buffer[10240];
    int result;
    do {
        result = recv(sock, &buffer[0], 10240, 0);
        if (result > 0)
            response += std::string(&buffer[0], result);
        else if (result < 0)
            response = "Error: could not read response";
    } while (result != 0);
    CloseSocket(sock);
    return response;
}

std::string ADBPluginAPI::adb(const std::string& command)
{
    std::string plugin_path = getPlugin()->getFilesystemPath();
#if defined(OS_WIN)
    plugin_path = plugin_path.substr(0, plugin_path.rfind("\\"));
    std::string adb_path = plugin_path + "\\win\\adb.exe";

    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(sa);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;

    HANDLE pipe_read, pipe_write;
    int result = CreatePipe(&pipe_read, &pipe_write, &sa, 0);
    if (!result)
        return "Error: could not create pipe";

    SetHandleInformation(pipe_read, HANDLE_FLAG_INHERIT, 0);

    STARTUPINFOA startup;
    ZeroMemory(&startup, sizeof(startup));
    startup.cb = sizeof(startup);
    startup.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
    startup.hStdOutput = pipe_write;
    startup.hStdError = GetStdHandle(STD_ERROR_HANDLE);
    startup.dwFlags = STARTF_USESTDHANDLES;

    PROCESS_INFORMATION pinfo;
    ZeroMemory(&pinfo, sizeof(pinfo));
    std::string adb_command = "adb " + command;
    result = CreateProcessA(
        adb_path.c_str(),  /* program path  */
        const_cast<char*>(adb_command.c_str()),  /* command */
        NULL,              /* process handle is not inheritable */
        NULL,              /* thread handle is not inheritable */
        TRUE,              /* yes, inherit some handles */
        DETACHED_PROCESS,  /* the new process doesn't have a console */
        NULL,              /* use parent's environment block */
        NULL,              /* use parent's starting directory */
        &startup,          /* startup info, i.e. std handles */
        &pinfo);

    CloseHandle(pipe_write);

    if (!result)
        return "Error: could not create process";

    CloseHandle(pinfo.hProcess);
    CloseHandle(pinfo.hThread);

    // Read response.
    char  temp[1000];
    DWORD  count;
    result = ReadFile(pipe_read, temp, 1000, &count, NULL);
    CloseHandle(pipe_read);
    if (!result)
        return "Error: could not read response";
    return std::string(temp, count);
#else
    for (int i = 0; i < 4; ++i)
        plugin_path = plugin_path.substr(0, plugin_path.rfind("/"));

    std::string adb_command = "/bin/sh '" + plugin_path + "/mac/adb_command.sh' " + command;

    FILE * pPipe;
    char buffer[2048];
    if (!(pPipe = popen(adb_command.c_str(), "r")))
         return "Error: failed starting server";

    std::string response = "";
    while(fgets(buffer, sizeof(buffer), pPipe) != NULL)
        response += buffer;
    pclose(pPipe);
    return response;
#endif
}

ADBPluginPtr ADBPluginAPI::getPlugin()
{
    ADBPluginPtr plugin(m_plugin.lock());
    if (!plugin)
        throw FB::script_error("The plugin is invalid");
    return plugin;
}
