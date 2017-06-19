cmake_minimum_required(VERSION 3.1)
project(markov_dna)

set(CMAKE_CXX_STANDARD 14)
find_package(Eigen3 REQUIRED)

add_library(markov markov.cpp markov.hpp)

target_include_directories(markov PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
