#
#   utils CMakeLists.txt
#

set(CPP src/tinyply.cpp)

set(HEADERS tinyply.h)

add_library(tinyply ${CPP} ${HEADERS})