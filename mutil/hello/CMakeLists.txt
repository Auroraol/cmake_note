#把指定目录下所有源代码文件入变量DIR_HELLO “.”是指当前目录
aux_source_directory(. DIR_HELLO)

#从${DIR_HELLO}文件中生成hello库, STATIC是生成静态库
add_library(hello STATIC ${DIR_HELLO})