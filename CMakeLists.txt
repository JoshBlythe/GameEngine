cmake_minimum_required(VERSION 2.6)
project(GAMEENGINE)

include_directories(
	${PROJECT_SOURCE_DIR}/src
)

#add_definitions(-DSTD_SR1_DEBUG)

add_library(rend
  	src/rend/Exception.cpp
  	src/rend/Exception.h
  	src/rend/Context.cpp	
	src/rend/Context.h
  	src/rend/Texture.cpp
  	src/rend/Texture.h
  	src/rend/RenderTexture.cpp
  	src/rend/RenderTexture.h
  	src/rend/Shader.cpp
  	src/rend/Shader.h
  	src/rend/Buffer.cpp
  	src/rend/Buffer.h
	src/rend/rend.h
	src/rend/mathutil.h
)

if(MSVC)
target_link_libraries(rend glew32 SDL2 opengl32)
else()
target_link_libraries(rend GLEW SDL2 GL)
endif()


add_library(GameEngine
	src/GameEngine/Core.cpp
	src/GameEngine/Core.h
	src/GameEngine/Component.cpp
	src/GameEngine/Component.h
	src/GameEngine/Entity.cpp
	src/GameEngine/Entity.h
	src/GameEngine/Exception.cpp
	src/GameEngine/Exception.h
	src/GameEngine/Transform.cpp
	src/GameEngine/Transform.h
	src/GameEngine/Camera.cpp
	src/GameEngine/Camera.h
	src/GameEngine/Screen.cpp
	src/GameEngine/Screen.h
	src/GameEngine/GameEngine.h
	src/GameEngine/RendInc.h
)

target_link_libraries(GameEngine rend)



add_executable(sandbox
	src/sandbox/Main.cpp
	src/sandbox/TestScene.cpp
	src/sandbox/TestScene.h
)


target_link_libraries(sandbox GameEngine)