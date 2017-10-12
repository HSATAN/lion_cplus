cmake_minimum_required(VERSION 3.8)
project(Pratice)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp thread.cpp tree.cpp tree.h common.cpp common.h)
add_executable(Pratice ${SOURCE_FILES})