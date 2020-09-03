cmake_minimum_required(VERSION 3.16)
project(PercolationMCS)
add_executable(PercolationMCS MonteCarloSim.cpp Percolation.cpp PercolationStats.cpp Union_Find_WQU.cpp)
