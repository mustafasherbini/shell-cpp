cmake_minimum_required(VERSION 3.13)

project(shell-starter-cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(shell ${SOURCE_FILES}
        src/Commands/PwdCommand.cpp
        src/Commands/PwdCommand.h
        src/Commands/PWDCommand.cpp
        src/Commands/PWDCommand.h
        src/Commands/CdCommand.cpp
        src/Commands/CdCommand.h)

target_include_directories(shell PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)