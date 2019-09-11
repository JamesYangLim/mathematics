#
#   geometryTest CMakeLists.txt
#

add_executable(geometryTest
                main.cpp
                PointTest.cpp)

target_link_libraries(geometryTest PUBLIC geometry utils)

add_test(NAME geometryTest COMMAND geometryTest)