#
#   matrixTest CMakeLists.txt
#

add_executable(tinyplyTest tests.cpp)

target_link_libraries(tinyplyTest PUBLIC tinyply)

add_test(NAME tinyplyTest COMMAND tinyplyTest)