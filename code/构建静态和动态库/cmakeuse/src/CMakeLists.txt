INCLUDE_DIRECTORIES(/usr/include/hello)

ADD_EXECUTABLE(hello main.cpp)

TARGET_LINK_LIBRARIES(hello libhello.so)


