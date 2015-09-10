cmake_minimum_required (VERSION 3.0)
project (Tutorial)

# The version number
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 1)

# configure a header file to pass some of the CMake settings to the source code
configure_file(
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# add the binary tree to the search path for include file
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable to the project
add_executable(Tutorial tutorial.c)
