cmake_minimum_required(VERSION 3.5)

project(algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Methods
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

add_executable(longest_div_subseq methods/longest_div_subseq.cpp log_duration.h)
target_include_directories(longest_div_subseq PRIVATE .)

add_executable(longest_non_incr_subseq methods/longest_non_incr_subseq.cpp log_duration.h)
target_include_directories(longest_non_incr_subseq PRIVATE .)

add_executable(levenshtein_distance methods/levenshtein_distance.cpp log_duration.h)
target_include_directories(levenshtein_distance PRIVATE .)

add_executable(knapsack_without_reps methods/knapsack_without_reps.cpp log_duration.h)
target_include_directories(knapsack_without_reps PRIVATE .)

add_executable(stairs methods/stairs.cpp log_duration.h)
target_include_directories(stairs PRIVATE .)

add_executable(calculator methods/calculator.cpp log_duration.h)
target_include_directories(calculator PRIVATE .)

# Data structures
add_executable(check_brackets "data structures/check_brackets.cpp" log_duration.h)
target_include_directories(check_brackets PRIVATE .)

add_executable(tree_height "data structures/tree_height.cpp" log_duration.h)
target_include_directories(tree_height PRIVATE .)

add_executable(net_buffer "data structures/net_buffer.cpp" log_duration.h)
target_include_directories(net_buffer PRIVATE .)

add_executable(stack_with_max "data structures/stack_with_max.cpp" log_duration.h)
target_include_directories(stack_with_max PRIVATE .)

add_executable(sliding_window "data structures/sliding_window.cpp" log_duration.h)
target_include_directories(sliding_window PRIVATE .)

add_executable(build_heap "data structures/build_heap.cpp" log_duration.h)
target_include_directories(build_heap PRIVATE .)

add_executable(parallel_processing "data structures/parallel_processing.cpp" log_duration.h)
target_include_directories(parallel_processing PRIVATE .)

install(TARGETS
    # Methods
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
    longest_div_subseq
    longest_non_incr_subseq
    levenshtein_distance
    knapsack_without_reps
    stairs
    calculator
    # Data structures
    check_brackets
    tree_height
    net_buffer
    stack_with_max
    sliding_window
    build_heap
    parallel_processing
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
