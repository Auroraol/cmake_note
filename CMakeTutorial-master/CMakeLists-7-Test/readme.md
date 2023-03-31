refer:
- [CMakeList模板(二)：编译多个工程](https://blog.csdn.net/lianshaohua/article/details/107783811)
- [CMake——CMakeLists.txt 的详解](https://blog.csdn.net/zhangzhikang_zzk/article/details/125681694#t5)

使用cmake构建一个工程，每个子模块都有自己的cmakelists，该工程创建了两个静态库和一个动态库，另外生成一个调用这些库的可执行文件。

涉及到使用ADD_SUBDIRECTORY实现多个cmakelists的调用。

# **目录结构**


```
CMakeLists-7-Test
├─ CMakeLists.txt
├─ readme.md
├─ run.sh
└─ source
   ├─ add
   │  ├─ add.cpp
   │  ├─ add.h
   │  ├─ add3.cpp
   │  ├─ add3.h
   │  └─ CMakeLists.txt
   ├─ main
   │  ├─ CMakeLists.txt
   │  └─ main.cpp
   ├─ mul
   │  ├─ CMakeLists.txt
   │  ├─ mul.cpp
   │  └─ mul.h
   └─ sub
      ├─ CMakeLists.txt
      ├─ sub.cpp
      └─ sub.h

```

# **根目录cmake**

```makefile
cmake_minimum_required(VERSION 3.5)  # cmake版本最低要求
project(test7)  # 设置工程名称

set(CMAKE_CXX_STANDARD 11)  # 指定 C++ 版本
set(CMAKE_BUILD_TYPE Release)  # 调试使用Debug，可以查看中间变量；发布使用Release，运行速度快

message("${PROJECT_SOURCE_DIR}=" ${PROJECT_SOURCE_DIR})

# 这里设置好路径后，进入子模块的cmake时不用再次设置
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)  # 设置可执行文件的输出目录
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)	   # 设置库文件的输出目录

ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/source/add)     # 会调用该目录中的CMakeLists.txt进行编译生成静态库
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/source/sub)     # 会调用该目录中的CMakeLists.txt进行编译生成静态库
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/source/mul)     # 会调用该目录中的CMakeLists.txt进行编译生成动态库
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/source/main)    # 会调用该目录中的CMakeLists.txt进行编译生成可执行文件

```

**add目录cmake**

```makefile
# 编译成静态库, libadd.a
# 方法一：逐个添加cpp源文件，适用于文件数量少的情况
# add_library(add ${CMAKE_CURRENT_SOURCE_DIR}/add.cpp ${CMAKE_CURRENT_SOURCE_DIR}/add3.cpp)

# 方法二：搜索有的cpp源文件，并将列表存储在一个变量中，适用于文件多的情况
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
add_library(add ${SRC_LIST})

# 方法三：递归遍历目录，获取所有的CPP文件，适用于多级目录的情况
# file(GLOB_RECURSE cpp_files  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)  # GLOB是不递归
# add_library(add ${cpp_files})
```

# **mul目录cmake**

```makefile
# 编译成动态库libmul.so
add_library(mul SHARED ${CMAKE_CURRENT_SOURCE_DIR}/mul.cpp)
```

# **sub目录cmake**

```makefile
# 编译成静态库, libsub.a
add_library(sub ${CMAKE_CURRENT_SOURCE_DIR}/sub.cpp)
```

# **mian目录cmake**

```makefile
# 添加头文件路径，会检索目录中的所有头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../add
                    ${CMAKE_CURRENT_SOURCE_DIR}/../sub
                    ${CMAKE_CURRENT_SOURCE_DIR}/../mul
                    ${CMAKE_CURRENT_SOURCE_DIR}/../main)

# 把源码编译成一个可执行文件
add_executable(main ./main.cpp)

# 添加链接库，动态和静态都行
target_link_libraries(main add sub mul)
```

