cmake_minimum_required(VERSION 3.14)

project(PluginOne LANGUAGES CXX)

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

include_directories(${PROJECT_SOURCE_DIR}/../../Interface/)

option(ENABLE_STATIC "Enable building static for ${PROJECT_NAME}" FALSE)

if(ENABLE_STATIC)
    add_library(${PROJECT_NAME} STATIC ${SOURCESFILE})
    else()
    add_library(${PROJECT_NAME} SHARED ${SOURCESFILE})
endif()

target_link_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/../../Interface/build)
target_link_libraries(${PROJECT_NAME} PRIVATE PluginInterface)

install(TARGETS ${PROJECT_NAME} DESTINATION build/lib)

