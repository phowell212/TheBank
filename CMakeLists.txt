cmake_minimum_required(VERSION 3.21)
project(TheBank)

set(CMAKE_CXX_STANDARD 23)

add_executable(TheBank main.cpp Account.cpp Account.h)
