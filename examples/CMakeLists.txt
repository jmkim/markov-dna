cmake_minimum_required(VERSION 3.1)
project(markov_dna_examples)

set(CMAKE_CXX_STANDARD 14)

add_executable(training_data training_data.cpp)

target_link_libraries(training_data LINK_PUBLIC markov)
