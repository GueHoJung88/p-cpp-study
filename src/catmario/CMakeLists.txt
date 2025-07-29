cmake_minimum_required(VERSION 3.16)
project(MarioGame2 LANGUAGES C CXX)

# Enable C++17
set(CMAKE_CXX_STANDARD )
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build directory for generated files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ------------------------------------------------------------------------------
# Dependencies
# ------------------------------------------------------------------------------

# GLAD (OpenGL function loader)
add_library(glad STATIC
    glad/src/glad.c
)
target_include_directories(glad PUBLIC
    ${CMAKE_SOURCE_DIR}/glad/include
)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find SDL2 (requires SDL2Config.cmake from your system)
find_package(SDL2 REQUIRED)

# ------------------------------------------------------------------------------
# Project sources
# ------------------------------------------------------------------------------

# Collect all .cpp source files under src/
file(GLOB_RECURSE GAME_SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# Collect all .hpp/.h headers (for IDE navigation)
file(GLOB_RECURSE GAME_HEADERS
    "${CMAKE_SOURCE_DIR}/src/*.hpp"
    "${CMAKE_SOURCE_DIR}/src/*.h"
)

# Create the executable
add_executable(MarioGame2
    ${GAME_SOURCES}
    ${GAME_HEADERS}
)

# Include directories for project modules
target_include_directories(MarioGame2 PUBLIC
    ${CMAKE_SOURCE_DIR}/glad/include
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/core
    ${CMAKE_SOURCE_DIR}/src/renderer
    ${CMAKE_SOURCE_DIR}/src/ecs
    ${CMAKE_SOURCE_DIR}/src/ecs/components
    ${CMAKE_SOURCE_DIR}/src/ecs/systems
    ${CMAKE_SOURCE_DIR}/src/game
)

# ------------------------------------------------------------------------------
# Linking
# ------------------------------------------------------------------------------

target_link_libraries(MarioGame2 PRIVATE
    glad
    OpenGL::GL
    SDL2::SDL2
    SDL2::SDL2main
)

# On Linux, link with pthread if SDL2 main requires it
if(UNIX AND NOT APPLE)
    find_package(Threads REQUIRED)
    target_link_libraries(MarioGame2 PRIVATE Threads::Threads)
endif()

# ------------------------------------------------------------------------------
# Platform-specific settings
# ------------------------------------------------------------------------------

# On Windows, ensure SDL2.dll is found
if(WIN32)
    add_custom_command(TARGET MarioGame2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SDL2::SDL2>
            $<TARGET_FILE_DIR:MarioGame2>
    )
endif()
