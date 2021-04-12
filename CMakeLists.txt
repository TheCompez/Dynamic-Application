cmake_minimum_required(VERSION 3.14)

project(Dynamic-Application LANGUAGES CXX)

option(BUILD_APPLICATION "Enable building application" ON)
option(BUILD_INTERFACE "Enable building interface" ON)
option(BUILD_PLUGINS "Enable building plugins" ON)

if(BUILD_APPLICATION)
    add_subdirectory(Application)
endif()
if(BUILD_INTERFACE)
    add_subdirectory(Interface)
endif()
if(BUILD_PLUGINS)
    add_subdirectory(Plugins/PluginOne)
    add_subdirectory(Plugins/PluginTwo)
endif()
