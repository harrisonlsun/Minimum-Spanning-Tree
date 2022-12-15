# CMakeList.txt : CMake project for Algorithms, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Algorithms")

# Add source to this project's executable.
add_executable (Algorithms "Algorithms.cpp"  "prim_list.h" "prim_matrix.h" "djikstra.h" "bellman-ford.h" "header.h" "heap.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Algorithms PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
