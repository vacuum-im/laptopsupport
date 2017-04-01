cmake_minimum_required(VERSION 3.2)

project(laptopsupport-plugin)
set(PLUGIN_NAME "laptopsupport")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES laptopsupport.cpp systemwatch.cpp)
set(HEADERS laptopsupport.h systemwatch.h)
set(MOC_HEADERS laptopsupport.h systemwatch.h)

include_directories("${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}")

include("${CMAKE_SOURCE_DIR}/cmake/config.cmake")
include("${CMAKE_SOURCE_DIR}/translations/languages.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/plugin.cmake")

find_package(Qt5Xml REQUIRED)
find_package(Qt5Widgets REQUIRED)
qt5_use_modules(${PLUGIN_NAME} Xml Widgets)

if (UNIX)
    find_package(Qt5DBus REQUIRED)
    qt5_use_modules(${PLUGIN_NAME} DBus)
endif (UNIX)
