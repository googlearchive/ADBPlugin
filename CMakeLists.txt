#/**********************************************************\ 
# 
# Auto-generated CMakeLists.txt for the ADB project
#
#\**********************************************************/

# Written to work with cmake 2.6
cmake_minimum_required (VERSION 2.6)
set (CMAKE_BACKWARDS_COMPATIBILITY 2.6)
set (CMAKE_BUILD_TYPE "Release")
set (CMAKE_CONFIGURATION_TYPES "Release")
set (CMAKE_OSX_ARCHITECTURES "i386")

Project(${PLUGIN_NAME})

file (GLOB GENERAL RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    [^.]*.cpp
    [^.]*.h
    [^.]*.cmake
    )

include_directories(${PLUGIN_INCLUDE_DIRS})

if (WIN32)
    add_definitions("-DOS_WIN")
else (WIN32)
    add_definitions("-DOS_POSIX")
endif (WIN32)

if (APPLE)
    add_definitions("-DOS_MACOSX")
endif (APPLE)

# Generated files are stored in ${GENERATED} by the project configuration
SET_SOURCE_FILES_PROPERTIES(
    ${GENERATED}
    PROPERTIES
        GENERATED 1
    )

SOURCE_GROUP(Generated FILES
    ${GENERATED}
    )

SET( SOURCES
    ${GENERAL}
    ${GENERATED}
    )

# This will include Win/projectDef.cmake, X11/projectDef.cmake, Mac/projectDef 
# depending on the platform
include_platform()


function (chrome_package PROJNAME CRX_OUTDIR KEYFILE CRX_PROJDEP)
        file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen/${FBSTRING_PluginFileName}-crx)
        add_custom_command(
            TARGET ${PROJNAME}${FB_CRX_SUFFIX}
            POST_BUILD
            COMMAND ${CMD_CP} -r ${CMAKE_CURRENT_SOURCE_DIR}/Chrome/chromepackage/* ${CMAKE_CURRENT_BINARY_DIR}/gen/${FBSTRING_PluginFileName}-crx
            COMMAND ${CMD_CP} -r ${CMAKE_CURRENT_BINARY_DIR}/Release/npADBPlugin.plugin ${CMAKE_CURRENT_BINARY_DIR}/gen/${FBSTRING_PluginFileName}-crx
        )
        configure_template(${CMAKE_CURRENT_SOURCE_DIR}/Chrome/chromepackage/manifest.json ${CMAKE_CURRENT_BINARY_DIR}/gen/${FBSTRING_PluginFileName}-crx/manifest.json)

        add_custom_command(
            TARGET ${PROJNAME}${FB_CRX_SUFFIX}
            POST_BUILD
            COMMAND "/Applications/Google Chrome.app/Contents/MacOS/Google Chrome" --pack-extension="${CMAKE_CURRENT_BINARY_DIR}/gen/${FBSTRING_PluginFileName}-crx" --pack-extension-key="${KEYFILE}" --no-message-box
         )

        ADD_DEPENDENCIES(${PROJNAME}${FB_CRX_SUFFIX} ${CRX_PROJDEP})
endfunction(chrome_package)

chrome_package(${PLUGIN_NAME}
   ${FB_BIN_DIR}/${PLUGIN_NAME}/${CMAKE_CFG_INTDIR}/
   "${CMAKE_CURRENT_SOURCE_DIR}/sign/dummy_key.pem"
   ${PROJECT_NAME})
