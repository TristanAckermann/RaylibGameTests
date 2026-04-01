cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)


FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG master
)


FetchContent_MakeAvailable(raylib)

add_executable(untitled
        main.cpp
        player.cpp
        player.h
)


target_link_libraries(untitled PRIVATE raylib)