cmake_minimum_required(VERSION 2.6)
project(GAMEENGINE)

include_directories(
	src
)

add_library(GameEngine
	src/GameEngine/Core.cpp
	src/GameEngine/Core.h
	src/GameEngine/Component.cpp
	src/GameEngine/Component.h
	src/GameEngine/Entity.cpp
	src/GameEngine/Entity.h
	src/GameEngine/Exception.cpp
	src/GameEngine/Exception.h
	src/GameEngine/Shader.cpp
	src/GameEngine/Shader.h
	src/GameEngine/FragmentShader.cpp
	src/GameEngine/FragmentShader.h
	src/GameEngine/VertexShader.cpp
	src/GameEngine/VertexShader.h
	src/GameEngine/Transform.cpp
	src/GameEngine/Transform.h
	src/GameEngine/Camera.cpp
	src/GameEngine/Camera.h
	src/GameEngine/Screen.cpp
	src/GameEngine/Screen.h
	src/GameEngine/GameEngine.h
)

if(MSVC)
target_link_libraries(gameengine glew32 SDL2 opengl32)
else()
target_link_libraries(GameEngine GLEW SDL2 GL)
endif()

add_executable(sandbox
	src/sandbox/Main.cpp
	src/sandbox/TestScene.cpp
	src/sandbox/TestScene.h
)


target_link_libraries(sandbox gameengine)