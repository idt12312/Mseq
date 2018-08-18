cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -Wall -Wextra")

include_directories(../)
add_executable(example example.cpp ../Mseq.cpp)
