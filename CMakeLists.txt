cmake_minimum_required(VERSION 3.26)

project(pngsmasher)
include(FetchContent)

FetchContent_Declare(SFML
	GIT_REPOSITORY https://github.com/SFML/SFML
	GIT_TAG d7fb1bf0f643e1cb66b93d9fab50e54941a6e90c)
FetchContent_MakeAvailable(SFML)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
	add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Wold-style-cast)
elseif(MSVC)
	add_compile_options(/W4 /permissive- /wd4251 /wd4201)
endif()

add_subdirectory(pngsmasher)