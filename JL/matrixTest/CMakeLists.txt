#
#   matrixTest CMakeLists.txt
#

add_executable(matrixTest 
                main.cpp 
                MatrixTest.cpp 
                LinearTransformationTest.cpp)
target_link_libraries(matrixTest PUBLIC utils)
