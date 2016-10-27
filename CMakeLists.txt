cmake_minimum_required(VERSION 3.5)
project(aeda_casino)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(untitled ${SOURCE_FILES})