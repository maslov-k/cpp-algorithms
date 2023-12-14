cmake_minimum_required(VERSION 3.5)

project(algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gcd methods/gcd.cpp log_duration.h)
target_include_directories(gcd PRIVATE .)

add_executable(covering_set methods/covering_set.cpp log_duration.h)
target_include_directories(covering_set PRIVATE .)

add_executable(knapsack methods/knapsack.cpp log_duration.h)
target_include_directories(knapsack PRIVATE .)

add_executable(max_components methods/max_components.cpp log_duration.h)
target_include_directories(max_components PRIVATE .)

add_executable(huffman_encode methods/huffman_encode.cpp log_duration.h)
target_include_directories(huffman_encode PRIVATE .)

add_executable(huffman_decode methods/huffman_decode.cpp log_duration.h)
target_include_directories(huffman_decode PRIVATE .)

add_executable(priority_queue methods/priority_queue.cpp log_duration.h)
target_include_directories(priority_queue PRIVATE .)

add_executable(binary_search methods/binary_search.cpp log_duration.h)
target_include_directories(binary_search PRIVATE .)

add_executable(merge_sort methods/merge_sort.cpp log_duration.h)
target_include_directories(merge_sort PRIVATE .)

add_executable(number_of_inversions methods/number_of_inversions.cpp log_duration.h)
target_include_directories(number_of_inversions PRIVATE .)

add_executable(quick_sort methods/quick_sort.cpp log_duration.h)
target_include_directories(quick_sort PRIVATE .)

add_executable(points_and_segments methods/points_and_segments.cpp log_duration.h)
target_include_directories(points_and_segments PRIVATE .)

install(TARGETS
    gcd
    covering_set
    knapsack
    max_components
    huffman_encode
    huffman_decode
    priority_queue
    binary_search
    merge_sort
    number_of_inversions
    quick_sort
    points_and_segments
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
