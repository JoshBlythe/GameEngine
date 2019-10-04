cmake_minimum_required(VERSION 2.6)
project(GAMEENGINE)

add_library(gameengine
	src/gameengine/core.cpp
)

add_executable(sandbox
	src/sandbox/main.cpp
)


target_link_libraries(sandbox gameengine)