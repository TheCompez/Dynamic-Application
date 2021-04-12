cmake_minimum_required(VERSION 3.5)

project(Application LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PREFIX_HPPHEADER *.hpp)
set(PREFIX_SOURCE *.cpp)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

file(GLOB SOURCESFILE
    ${PREFIX_HPPHEADER}
    ${PREFIX_SOURCE}
)


include_directories(${PROJECT_SOURCE_DIR}/../Interface/)

add_executable(${PROJECT_NAME} ${SOURCESFILE})


target_link_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/../Interface/)
target_link_libraries(${PROJECT_NAME} PRIVATE PluginInterface)

install(TARGETS ${PROJECT_NAME} DESTINATION build/bin)
