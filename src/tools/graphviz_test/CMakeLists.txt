cmake_minimum_required(VERSION 3.2)

# Sources
file(GLOB Sources "include/*.h" "sources/*.cpp")

# Create Binaries
add_executable(graphviz_test ${Sources})
set_target_properties(graphviz_test PROPERTIES FOLDER "tools")

# Dependencies
target_link_libraries(graphviz_test PUBLIC cgraph gvc)
