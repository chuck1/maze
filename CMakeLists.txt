cmake_minimum_required (VERSION 2.6)

INCLUDE($ENV{HOME}/.config.cmake)

PROJECT(maze)

FIND_PACKAGE(CMakeHelper)

cmh_static_library()

SET(libs ${PROJECT_NAME})

ADD_SUBDIRECTORY(test)

