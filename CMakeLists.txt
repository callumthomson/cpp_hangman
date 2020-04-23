cmake_minimum_required(VERSION 3.15)
project(cpp_hangman)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_hangman main.cpp include/Hangman.cpp include/Hangman.h include/Renderer.cpp include/Renderer.h)