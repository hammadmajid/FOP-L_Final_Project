cmake_minimum_required(VERSION 3.28)

project(cipher VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_executable(cipher main.cpp)
