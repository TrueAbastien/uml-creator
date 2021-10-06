cmake_minimum_required(VERSION 3.2)

# Sources
file(GLOB Sources "include/model/*.h" "sources/*.cpp")

# Create Library
add_library(model STATIC ${Sources})
target_include_directories(model PUBLIC "include")

# Dependencies
target_link_libraries(model PUBLIC core)
