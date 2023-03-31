# 目录结构


```
CMakeLists-2-Test
├─ CMakeLists.txt
└─ test02.cpp

```

# 根目录cmake

```makefile
# 1,设置工程名称，叫“Demo2”，在Linux下可以随便设置
project( Demo2 )

# 2,设置 CMake 最低版本号，我电脑装的是3.5
cmake_minimum_required( VERSION 3.5 )

# 3,设定编译参数
set(CMAKE_CXX_STANDARD    11)  # 指定 C++ 11版本

# 设置编译选项
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

# 4,设置默认构建类型
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release") # 调试使用Debug，可以查看中间变量；发布使用Release，运行速度快
endif()
 


# 4，把源码编译成一个可执行文件，文件名为test02（可以随便取名），会保存在当前目录下
add_executable( test02 test02.cpp )

```

