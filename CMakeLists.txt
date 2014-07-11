cmake_minimum_required (VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)


PROJECT(maze)
SET(maze_STATIC TRUE)

INCLUDE_DIRECTORIES(../glm)

FIND_PACKAGE(CMakeHelper)

cmh_library()

SET(libs ${PROJECT_NAME})

ADD_SUBDIRECTORY(test)

