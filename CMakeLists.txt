#/**********************************************************\ 
# 
# Auto-generated CMakeLists.txt for the ADB project
#
#\**********************************************************/

# Written to work with cmake 2.6
cmake_minimum_required (VERSION 2.6)
set (CMAKE_BACKWARDS_COMPATIBILITY 2.6)

Project(${PLUGIN_NAME})

file (GLOB GENERAL RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    [^.]*.cpp
    [^.]*.h
    [^.]*.cmake
    )

include_directories(${PLUGIN_INCLUDE_DIRS})

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


function (chrome_package PROJNAME CRX_OUTDIR DLLFILE KEYFILE CRX_PROJDEP)
        file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen/${FBSTRING_PluginFileName}-crx)
        add_custom_command(
            TARGET ${PROJNAME}${FB_CRX_SUFFIX}
            POST_BUILD
            COMMAND ${CMD_CP} -r ${CMAKE_CURRENT_SOURCE_DIR}/Chrome/chromepackage/* ${CMAKE_CURRENT_BINARY_DIR}/gen/${FBSTRING_PluginFileName}-crx
            COMMAND ${CMD_CP} -r ${CMAKE_CURRENT_BINARY_DIR}/Debug/ADB_x86_64.plugin ${CMAKE_CURRENT_BINARY_DIR}/gen/${FBSTRING_PluginFileName}-crx
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
   "${FB_BIN_DIR}/${PLUGIN_NAME}/${CMAKE_CFG_INTDIR}/${FBSTRING_PluginFileName}.dll"
   "${CMAKE_CURRENT_SOURCE_DIR}/sign/dummy_key.pem"
   ${PROJECT_NAME})
