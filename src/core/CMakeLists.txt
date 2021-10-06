cmake_minimum_required(VERSION 3.2)

# Sources
file(GLOB Sources "include/core/*.h" "sources/*.cpp")

# Create Library
add_library(core STATIC ${Sources})
set_target_properties(core PROPERTIES FOLDER "project")
target_include_directories(core PUBLIC "include")

# Dependencies
# TODO?
