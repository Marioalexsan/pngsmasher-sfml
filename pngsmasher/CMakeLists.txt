cmake_minimum_required(VERSION 3.26)

include(GenerateExportHeader)

add_library(pngsmasher)

target_compile_features(pngsmasher PUBLIC cxx_std_23)
target_include_directories(pngsmasher PUBLIC "include")
target_include_directories(pngsmasher PRIVATE "external/include")
target_link_libraries(pngsmasher PRIVATE SFML::Graphics SFML::System)

if(NOT BUILD_SHARED_LIBS)
    target_compile_definitions(pngsmasher PUBLIC COFFEE2D_STATIC_DEFINE)
endif()

generate_export_header(pngsmasher EXPORT_FILE_NAME include/Coffee2D/Export.hpp)

set(SRC "src/pngsmasher")
target_sources(pngsmasher PUBLIC
  "${SRC}/Corruption.cpp"
)