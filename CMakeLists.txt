cmake_minimum_required(VERSION 3.0)
project(simple-cpp-plugin-test)

set(CMAKE_CXX_STANDARD 14)

add_library(common SHARED Plugin.hpp Plugin.cpp)

add_library(pluginA SHARED PluginA.hpp PluginA.cpp)
target_link_libraries(pluginA common)
set_target_properties(pluginA PROPERTIES INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR})

add_library(pluginB SHARED PluginB.hpp PluginB.cpp)
target_link_libraries(pluginB common)
set_target_properties(pluginB PROPERTIES INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR})

add_executable(test main.cpp PluginManager.hpp PluginManager.cpp)
if(WIN32)
    set(LIBRARIES )
else()
    set(LIBRARIES dl)
endif()
target_link_libraries(test common ${LIBRARIES})
add_dependencies(test pluginA pluginB)
