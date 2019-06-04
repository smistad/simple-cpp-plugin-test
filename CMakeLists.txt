cmake_minimum_required(VERSION 3.0)
project(simple-cpp-plugin-test)

set(CMAKE_CXX_STANDARD 14)

# Common library
include_directories(${PROJECT_BINARY_DIR})
add_library(common SHARED Plugin.hpp Plugin.cpp)
include(GenerateExportHeader)
generate_export_header(common EXPORT_FILE_NAME Export.hpp)

# Plugin A
add_library(pluginA SHARED PluginA.hpp PluginA.cpp)
target_link_libraries(pluginA common)
set_target_properties(pluginA PROPERTIES INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR};${PROJECT_BINARY_DIR}")
generate_export_header(pluginA EXPORT_FILE_NAME PluginAExport.hpp)

# Plugin B
add_library(pluginB SHARED PluginB.hpp PluginB.cpp)
target_link_libraries(pluginB common)
set_target_properties(pluginB PROPERTIES INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR};${PROJECT_BINARY_DIR}")
generate_export_header(pluginB EXPORT_FILE_NAME PluginBExport.hpp)

# Executable to load the plugins
add_executable(run main.cpp PluginManager.hpp PluginManager.cpp)
if(NOT WIN32)
    set(LIBRARIES dl)
endif()
target_link_libraries(run common ${LIBRARIES})
add_dependencies(run pluginA pluginB)
