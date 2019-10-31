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
	src/gameengine/shader.cpp
	src/gameengine/shader.h
	src/gameengine/transform.cpp
	src/gameengine/transform.h
	src/gameengine/camera.cpp
	src/gameengine/camera.h
)

target_link_libraries(gameengine glew32 SDL2 opengl32)

add_executable(sandbox
	src/sandbox/main.cpp
	src/sandbox/testscene.cpp
	src/sandbox/testscene.h
)


target_link_libraries(sandbox gameengine)