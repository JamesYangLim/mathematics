#
#   utils CMakeLists.txt
#

add_library(utils src/Utils.cpp)
target_include_directories(utils PUBLIC ${PROJECT_SOURCE_DIR})
