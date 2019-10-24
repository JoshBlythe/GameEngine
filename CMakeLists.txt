cmake_minimum_required(VERSION 2.6)
project(GAMEENGINE)

include_directories(
	src
)

add_library(gameengine
	src/gameengine/core.cpp
	src/gameengine/core.h
	src/gameengine/component.cpp
	src/gameengine/component.h
	src/gameengine/entity.cpp
	src/gameengine/entity.h
	src/gameengine/exception.cpp
	src/gameengine/exception.h
)

add_executable(sandbox
	src/sandbox/main.cpp
	src/sandbox/testscene.cpp
	src/sandbox/testscene.h
)


target_link_libraries(sandbox gameengine)