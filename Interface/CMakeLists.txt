cmake_minimum_required(VERSION 3.14)

project(PluginInterface LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PREFIX_HPPHEADER *.hpp)
set(PREFIX_SOURCE *.cpp)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)


file(GLOB SOURCESFILE
    ${PREFIX_HPPHEADER}
    ${PREFIX_SOURCE}
)

option(ENABLE_STATIC "Enable building static for ${PROJECT_NAME}" FALSE)

if(ENABLE_STATIC)
    add_library(${PROJECT_NAME} STATIC ${SOURCESFILE})
    else()
    add_library(${PROJECT_NAME} SHARED ${SOURCESFILE})
endif()

#json
find_package(nlohmann_json REQUIRED)
include_directories(third-party/json/)

target_compile_definitions(${PROJECT_NAME} PRIVATE PLUGININTERFACE_LIBRARY)

install(TARGETS ${PROJECT_NAME} DESTINATION build/lib)
