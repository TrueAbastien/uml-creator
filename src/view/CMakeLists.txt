cmake_minimum_required(VERSION 3.2)

# Sources
file(GLOB Sources "include/view/*.h" "sources/*.cpp")

# Create Library
add_library(view STATIC ${Sources})
set_target_properties(view PROPERTIES FOLDER "project")
target_include_directories(view PUBLIC "include")

# Dependencies
target_link_libraries(view PUBLIC core)
