cmake_minimum_required(VERSION 3.2)

# Sources
file(GLOB Sources "include/core/*.h" "sources/*.cpp")

# Create Library
add_library(core STATIC ${Sources})
target_include_directories(core PUBLIC "include")

# Dependencies
# TODO?
