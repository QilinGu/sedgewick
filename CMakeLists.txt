cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

project("Algoriths and Data Structures 4th by Robert Sedgewick")

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to DEBUG")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# -- tools
find_program(SED_TOOL NAMES sed)
if (NOT SED_TOOL)
    message(FATAL_ERROR "Unable to find sed - used in unit-tests")
endif(NOT SED_TOOL)


# -- external libs
add_subdirectory(ext)

include_directories(
    ext/gmock/include
    ext/gmock/gtest/include
)


# -- flags, etc
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -O0")


# -- includes
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_BINARY_DIR}")

enable_testing()

# -- builds
