cmake_minimum_required(VERSION 3.2)

# Setup Project
set(This UMLCreator)
project(${This} C CXX)

# C++ Configuration
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 3rd Parties
# TODO

# Sources
add_subdirectory(src)