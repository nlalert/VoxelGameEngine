cmake_minimum_required(VERSION 3.16)
project(VoxeraEngine VERSION 0.1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find OpenGL
find_package(OpenGL REQUIRED)

# GLFW options
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

# Add subdirectories for dependencies
add_subdirectory(vendor/GLFW)
add_subdirectory(vendor/imgui) # Add ImGui subdirectory

# Add GLAD source file
set(GLAD_SOURCE
    vendor/GLAD/src/glad.c
)

# Define source files
# Engine source files
set(SOURCES
    src/Voxera/Application.cpp
    src/Voxera/Log.cpp
    src/Voxera/Layer.cpp
    src/Voxera/LayerStack.cpp
    src/vxrpch.cpp  # Add precompiled header cpp file
    src/Platform/Windows/WindowsWindow.cpp  # Add Windows implementation
    src/Platform/Windows/WindowsInput.cpp
    src/Platform/OpenGL/ImGuiOpenGLRenderer.cpp  # Add ImGui OpenGL renderer
    src/Platform/OpenGL/ImGuiGLFWRenderer.cpp  # Add ImGui GLFW renderer
    src/Voxera/ImGui/ImGuiLayer.cpp  # Add ImGui layer
    ${GLAD_SOURCE}  # Add GLAD source
)

# Internal headers
set(INTERNAL_HEADERS
    src/Voxera/Application.h
    src/Voxera/Core.h
    src/Voxera/EntryPoint.h
    src/Voxera/Input.h
    src/Voxera/Log.h
    src/Voxera/Layer.h
    src/Voxera/LayerStack.h
    src/Voxera/Window.h  # Add Window interface
    src/Platform/Windows/WindowsWindow.h  # Add Windows implementation
    src/Platform/Windows//WindowsInput.h
    src/Platform/OpenGL/ImGuiOpenGLRenderer.h  # Add ImGui OpenGL renderer
    src/Platform/OpenGL/ImGuiGLFWRenderer.h  # Add ImGui GLFW renderer
    src/Voxera/ImGui/ImGuiLayer.h  # Add ImGui layer
    src/Voxera/Events/Event.h
    src/Voxera/Events/ApplicationEvent.h
    src/Voxera/Events/KeyEvent.h
    src/Voxera/Events/MouseEvent.h
    src/vxrpch.h    # Add precompiled header file
)

# Public API header
set(PUBLIC_HEADERS
    src/Voxera.h
)

# Create the Voxera library
add_library(Voxera SHARED ${SOURCES} ${INTERNAL_HEADERS} ${PUBLIC_HEADERS})

# Add spdlog include directory
set(SPDLOG_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include")

# Verify that the directory exists
if(NOT EXISTS ${SPDLOG_INCLUDE_DIR})
    message(FATAL_ERROR "spdlog include directory not found: ${SPDLOG_INCLUDE_DIR}")
endif()

# Update include directories for Voxera
target_include_directories(Voxera
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Voxera
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Platform
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${SPDLOG_INCLUDE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW/include
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLAD/include
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui
        ${OPENGL_INCLUDE_DIR}
)

# Link with GLFW, ImGui, and OpenGL
target_link_libraries(Voxera 
    PRIVATE 
        glfw
        ImGui
        ${OPENGL_LIBRARIES}
)

# Set specific properties for GLAD source file to not use precompiled header
set_source_files_properties(${GLAD_SOURCE} PROPERTIES SKIP_PRECOMPILE_HEADERS ON)

# Define export macro for DLL
target_compile_definitions(Voxera 
    PRIVATE 
        VXR_BUILD_DLL
        VXR_PLATFORM_WINDOWS
        VXR_DEBUG
        GLFW_INCLUDE_NONE
)

# Enable precompiled headers
target_precompile_headers(Voxera
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/vxrpch.h
)
