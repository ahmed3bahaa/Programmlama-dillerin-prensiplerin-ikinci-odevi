cmake_minimum_required(VERSION 3.12)

project(BicimselDillerProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(nfa_to_dfa cpp/nfa_to_dfa.cpp)
add_executable(dfa_minimization cpp/dfa_minimization.cpp)
add_executable(kleene_regex cpp/kleene_regex.cpp)
