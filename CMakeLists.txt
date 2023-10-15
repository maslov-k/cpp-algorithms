cmake_minimum_required(VERSION 3.5)

project(algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(algorithms main.cpp)

install(TARGETS algorithms
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
