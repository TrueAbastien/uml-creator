cmake_minimum_required(VERSION 3.2)

# Sources
file(GLOB Sources "include/model/*.h" "sources/*.cpp")

# Create Library
add_library(model STATIC ${Sources})
set_target_properties(model PROPERTIES FOLDER "project")
target_include_directories(model PUBLIC "include")

# Dependencies
target_link_libraries(model PUBLIC core)
