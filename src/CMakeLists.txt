cmake_minimum_required(VERSION 3.2)

# Find Sources
file(GLOB Sources "sources/*.cpp" "include/*.h")

# Create Binaries
add_executable(${This} ${Sources})
target_include_directories(${This} PUBLIC "include")
