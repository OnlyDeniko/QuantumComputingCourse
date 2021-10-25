cmake_minimum_required( VERSION 3.15 )
project("Quantum Computing Course")

message( STATUS "Quantum Computing Course" )

include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Configure.cmake" )

add_subdirectory(modules)