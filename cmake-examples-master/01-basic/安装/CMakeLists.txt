cmake_minimum_required(VERSION 3.5)

project(cmake_examples_install)

############################################################
# Create a library
############################################################

#Generate the shared library from the library sources
add_library(cmake_examples_inst SHARED
    src/Hello.cpp
)

target_include_directories(cmake_examples_inst
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(cmake_examples_inst_bin
    src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( cmake_examples_inst_bin
    PRIVATE 
        cmake_examples_inst
)

############################################################
# Install  安装
############################################################

# Binaries
# 安装可执行文件
# install (可执行文件 自定义文件名 DESTINATION 安装到的绝对路径)

install (TARGETS cmake_examples_inst_bin
    DESTINATION bin)

# Library
# 安装库文件
# 注意:可能不能在windows上工作
# Note: may not work on windows
# install (可执行文件 自定义库文件名
#     LIBRARY DESTINATION 安装到的绝对路径)
install (TARGETS cmake_examples_inst LIBRARY DESTINATION lib)


# Header files
#安装头文件
# install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
#     DESTINATION 绝对路径)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
    DESTINATION include)

# Config
install (FILES cmake-examples.conf
    DESTINATION etc)

    