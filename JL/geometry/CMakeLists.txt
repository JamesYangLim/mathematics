#
#   geometry CMakeLists.txt
#

set(CPP src/temp.cpp)
set(HEADERS Point.h Random.h)
set(INL detail/Point.inl)

add_library(geometry ${CPP} ${HEADERS} ${INL})