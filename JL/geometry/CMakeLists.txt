#
#   geometry CMakeLists.txt
#

set(CPP src/temp.cpp)
set(HEADERS Point.h Random.h InfiniteRegularGrid.h Ply.h)
set(INL detail/Point.inl detail/InfiniteRegularGrid.inl)

add_library(geometry ${CPP} ${HEADERS} ${INL})

target_link_libraries(geometry tinyply)
