cmake_minimum_required(VERSION 3.2)

# Sources
file(GLOB Sources "include/view/*.h" "sources/*.cpp")

# Create Library
add_library(view STATIC ${Sources})
target_include_directories(view PUBLIC "include")

# Dependencies
# TODO?
