# 简介CMake使用，文件：CMakeTutorialPB.md
# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (algorithms)
add_compile_options(-fpermissive)

#获取指定路径所有源文件
aux_source_directory(. DIR_SRCS)
# 指定生成目标，以工程目录为名
STRING( REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} )
set(TARGET ${CURRENT_FOLDER})
add_executable(${TARGET} ${DIR_SRCS})

# 输出库位置，尝试放在统一位置
# add_library(exn SHARED )
# add_library(exn STATIC )
