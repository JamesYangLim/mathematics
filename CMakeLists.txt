#
#   mathematics project CMakeLists.txt
#

cmake_minimum_required(VERSION 3.5)
project(mathematics VERSION 0.1 LANGUAGES CXX)
enable_testing()

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(JL)
add_subdirectory(Libraries)

