cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

project("Algoriths and Data Structures 4th by Robert Sedgewick")

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to DEBUG")
    set(CMAKE_BUILD_TYPE "Debug")
endif()


# -- external libs
add_subdirectory(ext)

include_directories(
    ext/gmock/include
    ext/gmock/gtest/include
)


# -- flags, etc
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -O0")

option(STUDY "STUDY" OFF)   # build source form study folders


# -- includes
include_directories(
    "${PROJECT_SOURCE_DIR}/src"
)


# -- enable unit-testing
enable_testing()


# -- builds
add_subdirectory(src)
