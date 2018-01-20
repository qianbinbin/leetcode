cmake_minimum_required(VERSION 3.7)

aux_source_directory(. DIR_LIB_SRCS)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(lc ${DIR_LIB_SRCS})
