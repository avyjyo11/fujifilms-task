# CMake configuration
cmake_minimum_required(VERSION 3.10)
project(InventoryManagement)

# Set C++ version
set(CMAKE_CXX_STANDARD 17)

# Include header files
include_directories(include)

# Define source files
set(SOURCES 
    src/product.cpp 
    src/organization.cpp 
)

# Add executable target
add_executable(inventory-management main.cpp ${SOURCES})