cmake_minimum_required(VERSION 3.0)

project(MUTIL)

#设置hello world 给环境变量TARGET
set(TARGET helloworld)

#添加头文件
include_directories(
    ${PROJECT_SOURCE_DIR}/hello
    ${PROJECT_SOURCE_DIR}/world
)

#添加包含CMakeLists.txt和源文件的子目录
add_subdirectory(hello)
add_subdirectory(world)

aux_source_directory(. DIRSRCS)

#生成可执行文件
add_executable(${TARGET} ${DIRSRCS})

#helloworld 链接静态库hello和world
target_link_libraries(${TARGET}  hello world)