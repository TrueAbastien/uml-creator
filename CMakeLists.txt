cmake_minimum_required(VERSION 3.2)

# Setup Project
set(This UMLCreator)
project(${This} C CXX)

# Global Properties
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_INSTALL_PREFIX "" CACHE INTERNAL "" FORCE)
set(CMAKE_CONFIGURATION_TYPES Release Debug CACHE INTERNAL "" FORCE)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "default")
#set(CMAKE_DEBUG_POSTFIX d)

# C++ Configuration
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

##########################################################################
# # Additional files used by cmake
# set (CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# # Find GraphViz
# if (NOT GRAPHVIZ_ROOT)
#   set(GRAPHVIZ_ROOT ${CMAKE_SOURCE_DIR}/3rdparty/Graphviz)
# endif()
# set(ENV{GRAPHVIZ_ROOT} ${GRAPHVIZ_ROOT})
# if (VERBOSE)
#   find_package(Graphviz REQUIRED)
# else ()
#   find_package(Graphviz QUIET REQUIRED)
# endif ()
# if (NOT ${GRAPHVIZ_VERSION} VERSION_GREATER "2.29")
#   message(FATAL_ERROR "GraphViz version >= 2.30 is required.")
# endif()
##########################################################################

# 3rd Parties
set(3RD_PARTY_DIR ${PROJECT_SOURCE_DIR}/3rdparty)
# -- Directories
set(GRAPHVIZ_ROOT_DIR ${3RD_PARTY_DIR}/Graphviz)    # Graphviz
# -- Headers
include_directories(
    ${GRAPHVIZ_ROOT_DIR}/include    # Graphviz
)
# -- Libraries
link_directories(
    ${GRAPHVIZ_ROOT_DIR}/lib    # Graphviz
)

# Sources
add_subdirectory(src)