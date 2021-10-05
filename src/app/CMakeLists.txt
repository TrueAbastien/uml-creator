cmake_minimum_required(VERSION 3.2)

# Sources
file(GLOB Sources "include/*.h" "sources/*.cpp")

# Create Binaries
add_executable(${This} ${Sources})
target_include_directories(${This} PUBLIC "include")

# Dependencies
target_link_libraries(${This} PUBLIC controller)
