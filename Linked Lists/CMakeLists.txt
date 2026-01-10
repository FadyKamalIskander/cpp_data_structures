cmake_minimum_required(VERSION 4.0)
project(Linked_Lists)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic-errors -Wconversion -Wshadow -Wsign-conversion -Wold-style-cast -Wnon-virtual-dtor -Woverloaded-virtual  -Wconversion -Wnull-dereference -Wunused-parameter -D_GLIBCXX_DEBUG")

add_executable(Linked_Lists main.cpp)
