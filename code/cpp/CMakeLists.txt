cmake_minimum_required(VERSION 3.0)

project(CPP)

aux_source_directory(src/. SRC) 
add_subdirectory(src/ff)

add_executable(demo main.cpp ${SRC})