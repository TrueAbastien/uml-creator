cmake_minimum_required(VERSION 3.2)

# Setup Project
set(This UMLCreator)
project(${This} C CXX)

# Global Properties
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_INSTALL_PREFIX "" CACHE INTERNAL "" FORCE)
set(CMAKE_CONFIGURATION_TYPES Release Debug CACHE INTERNAL "" FORCE)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "default")
set(CMAKE_DEBUG_POSTFIX d)

# C++ Configuration
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 3rd Parties
# TODO

# Sources
add_subdirectory(src)