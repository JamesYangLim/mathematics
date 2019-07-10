#include(GenerateExportHeader)

add_library(geometry src/temp.cpp)
target_include_directories(geometry PUBLIC ${PROJECT_SOURCE_DIR})
#generate_export_header(geom)
