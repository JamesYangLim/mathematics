#
#   matrix CMakeLists.txt
#

set(CPP src/temp.cpp)

set(HEADERS 
        Matrix.h 
        LinearTransformation.h 
        RandomMatrix.h)

set(INL detail/Matrix.inl)

add_library(matrix ${CPP} ${HEADERS} ${INL})
