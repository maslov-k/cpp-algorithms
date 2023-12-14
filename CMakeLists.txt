cmake_minimum_required(VERSION 3.5)

project(algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gcd gcd.cpp log_duration.h)

add_executable(covering_set covering_set.cpp log_duration.h)

add_executable(knapsack knapsack.cpp log_duration.h)

add_executable(max_components max_components.cpp log_duration.h)

add_executable(huffman_encode huffman_encode.cpp log_duration.h)

add_executable(huffman_decode huffman_decode.cpp log_duration.h)

add_executable(priority_queue priority_queue.cpp log_duration.h)

add_executable(binary_search binary_search.cpp log_duration.h)

add_executable(merge_sort merge_sort.cpp log_duration.h)

add_executable(number_of_inversions number_of_inversions.cpp log_duration.h)

add_executable(points_and_segments points_and_segments.cpp log_duration.h)

add_executable(quick_sort quick_sort.cpp log_duration.h)

install(TARGETS gcd quick_sort
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
