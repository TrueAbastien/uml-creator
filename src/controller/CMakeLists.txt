cmake_minimum_required(VERSION 3.2)

# Sources
file(GLOB Sources "include/controller/*.h" "sources/*.cpp")

# Create Library
add_library(controller STATIC ${Sources})
set_target_properties(controller PROPERTIES FOLDER "project")
target_include_directories(controller PUBLIC "include")

# Dependencies
target_link_libraries(controller PUBLIC model view)
