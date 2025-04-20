cmake_minimum_required(VERSION 3.16)
project(Sandbox VERSION 0.1.0)

# Define source files
set(SOURCES
    src/SandboxApp.cpp
)

# Create the Sandbox executable
add_executable(Sandbox ${SOURCES})

# Link the Sandbox with Vox
target_link_libraries(Sandbox PRIVATE Vox)

# Include directories - only needs access to the public Vox.h
target_include_directories(Sandbox PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Add post-build command to copy the Vox DLL next to the Sandbox executable
if(WIN32)
    add_custom_command(TARGET Sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Vox> $<TARGET_FILE_DIR:Sandbox>
    )
endif()
