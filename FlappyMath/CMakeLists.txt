cmake_minimum_required(VERSION 3.10)

project(FlappyMath)

set(CMAKE_CXX_STANDARD 11)

# Specify the source files
set(SOURCES
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
    src/Pipe.cpp
    src/Operation.cpp
    src/ScoreManager.cpp
    src/AudioManager.cpp
    src/ResourceManager.cpp
)

# Include directories
include_directories(src)

# Create the executable
add_executable(FlappyMath ${SOURCES})

# Link libraries if needed (e.g., raylib)
# find_package(raylib REQUIRED)
# target_link_libraries(FlappyMath raylib)