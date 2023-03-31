cmake_minimum_required (VERSION 3.5)

project(subprojects)

# Add sub directories
# 向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制存放的位置
add_subdirectory(sublibrary1)
add_subdirectory(sublibrary2)
add_subdirectory(subbinary)
