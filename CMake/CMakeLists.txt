cmake_minimum_required (VERSION 3.0)
project (Tutorial)

# optionally use our own math functions
option (USE_MYMATH "Use tutorial provided math implementation" OFF) # no mysqrt.c defined

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
if(USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")  # So MathFunctions/mysqrt.h file can be found by function prototype
    add_subdirectory(MathFunctions)     # so library will get built
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(USE_MYMATH)
    
# add the executable to the project
add_executable(Tutorial tutorial.c)
target_link_libraries(Tutorial MathFunctions)

# C compiler's math library
# must link libraries to project AFTER add_executable
#find_library(M_LIB m)          # now using mysqrt
#target_link_libraries(Tutorial ${M_LIB})
