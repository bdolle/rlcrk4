cmake_minimum_required(VERSION 3.9)
project(RUNGErlc)

set(CMAKE_CXX_STANDARD 11)

add_executable(RUNGErlc main.cpp coords.cpp coords.h diffeq.cpp diffeq.h)