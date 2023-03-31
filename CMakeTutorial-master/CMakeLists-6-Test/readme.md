[Cmake命令之add_subdirectory介绍](https://www.jianshu.com/p/07acea4e86a3)

只有一个动态库subadd，另外生成一个引用该库的可执行文件main。

涉及到使用ADD_SUBDIRECTORY实现多个cmakelists的调用。

# 目录结构


```
CMakeLists-6-Test
├─ CMakeLists.txt
├─ main.cpp
├─ readme.md
├─ run.sh
└─ sub
   ├─ add.cpp
   ├─ add.h
   └─ CMakeLists.txt

```

# 根目录cmake

```makefile
# 父目录下的CMakeLists.txt
cmake_minimum_required(VERSION 3.5)  # cmake版本最低要求
project(main)  # 设置工程名称

# sub子模块
include_directories(sub)  # 添加头文件查找路径
add_subdirectory(sub)  # 会编译子模块生成静态库，默认保存位置：build/sub/libsubadd.a

add_executable(main main.cpp)
target_link_libraries(main subadd)  # 会链接静态库subadd

```

# sub目录cmake

```makefile
add_library(subadd add.cpp)  # 生成动态库libsubadd.a，subadd这个名字可以自定义
```

