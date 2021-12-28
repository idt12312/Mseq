cmake_minimum_required(VERSION 3.11)

set(SRCS Mseq.cpp)

add_library(mseq STATIC ${SRCS})
target_include_directories(mseq PUBLIC ./)
