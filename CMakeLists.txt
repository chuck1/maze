cmake_minimum_required (VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

FIND_PACKAGE(CMakeHelper)

PROJECT(maze)
INCLUDE(../../config.cmake)
INCLUDE(cmh_build_config)

INCLUDE_DIRECTORIES(../glm)

INCLUDE(cmh_library)

ADD_SUBDIRECTORY(test)

