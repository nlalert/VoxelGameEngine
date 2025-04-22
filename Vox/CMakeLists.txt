cmake_minimum_required(VERSION 3.16)
project(VoxEngine VERSION 0.1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Define source files
# Engine source files
set(SOURCES
    src/Vox/Application.cpp
    src/Vox/Log.cpp
    src/voxpch.cpp  # Add precompiled header cpp file
)

# Internal headers
set(INTERNAL_HEADERS
    src/Vox/Application.h
    src/Vox/Core.h
    src/Vox/EntryPoint.h
    src/Vox/Log.h
    src/voxpch.h    # Add precompiled header file
)

# Public API header
set(PUBLIC_HEADERS
    src/Vox.h
)

# Create the Vox library
add_library(Vox SHARED ${SOURCES} ${INTERNAL_HEADERS} ${PUBLIC_HEADERS})

# Add spdlog include directory
set(SPDLOG_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include")

# Verify that the directory exists
if(NOT EXISTS ${SPDLOG_INCLUDE_DIR})
    message(FATAL_ERROR "spdlog include directory not found: ${SPDLOG_INCLUDE_DIR}")
endif()

# Update include directories for Vox
target_include_directories(Vox
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Vox
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${SPDLOG_INCLUDE_DIR}
)

# Enable precompiled headers
target_precompile_headers(Vox
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/voxpch.h
)

# Define export macro for DLL
target_compile_definitions(Vox 
    PRIVATE 
        VOX_BUILD_DLL
        VOX_PLATFORM_WINDOWS  # Define platform for precompiled header
)
