cmake_minimum_required(VERSION 2.6)
project(GAMEENGINE)

include_directories(
	src
)

add_library(gameengine
	src/gameengine/core.cpp
	src/gameengine/core.h
	src/gameengine/object.cpp
	src/gameengine/object.h
)

add_executable(sandbox
	src/sandbox/main.cpp
)


target_link_libraries(sandbox gameengine)