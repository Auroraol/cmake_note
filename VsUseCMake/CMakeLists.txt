cmake_minimum_required (VERSION 3.8)

#指定项目名
project ("VsUseCMake")

#配置头文件包含目录
include_directories("C:/Tools/SDL2-2.24.0/include" "C:/Tools/SDL2_image-2.6.2/include")

#配置连接库文件包含目录(对应着最后一行)
link_directories("C:/Tools/SDL2-2.24.0/lib/x64" "C:/Tools/SDL2_image-2.6.2/lib/x64")

#指定可执行文件的输出目录为 ./bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  "${CMAKE_CURRENT_LIST_DIR}/bin")

#根据指定的文件生成可执行程序 可执行程序名为CMake_SDL
add_executable (CMake_SDL  "main.cpp" "Game.cpp" "Game.h")

#给可执行程序指定需要链接的库  //手动的添加
target_link_libraries(CMake_SDL SDL2 SDL2main SDL2_image)


 cmr      cmake_minimum_required  最小版本要求
 pr       project                 工程名称
 set(集合名 文件)                   源文件名中含有空格，就必须要加双引号
 incd     include_directories     配置头文件包含目录
 lind     link_directories        配置连接库文件包含目录
