cmake_minimum_required(VERSION 3.0)

project(SOLIDERFIRE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR}/include)

aux_source_directory(src/ SRC)
add_executable(my_cmake_exe ${SRC})