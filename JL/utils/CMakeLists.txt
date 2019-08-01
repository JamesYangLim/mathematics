#
#   utils CMakeLists.txt
#

set(CPP src/Utils.cpp)

set(HEADERS Utils.h)

add_library(utils ${CPP} ${HEADERS})

target_include_directories(utils PUBLIC ${PROJECT_SOURCE_DIR})
