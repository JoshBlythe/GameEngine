cmake_minimum_required(VERSION 2.6)
project(GAMEENGINE)

include_directories(
	${PROJECT_SOURCE_DIR}/src
)

add_definitions(-DGLM_FORCE_CTOR_INIT)

add_library(rend
  	src/rend/Exception.cpp
  	src/rend/Exception.h
  	src/rend/Context.cpp	
	src/rend/Context.h
	src/rend/TextureAdapter.h
  	src/rend/Texture.cpp
  	src/rend/Texture.h
  	src/rend/RenderTexture.cpp
  	src/rend/RenderTexture.h
  	src/rend/Shader.cpp
  	src/rend/Shader.h
  	src/rend/Buffer.cpp
  	src/rend/Buffer.h
	src/rend/Mesh.cpp
	src/rend/Mesh.h
	src/rend/rend.h
	src/rend/mathutil.h
	src/rend/Util.cpp
	src/rend/Util.h
)

if(WIN32)
target_link_libraries(rend glew32 SDL2 opengl32 openal32)
else()
target_link_libraries(rend GLEW SDL2 GL openal)
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
	src/GameEngine/Mesh.cpp
	src/GameEngine/Mesh.h
	src/GameEngine/Texture.cpp
	src/GameEngine/Texture.h
	src/GameEngine/Shader.cpp
	src/GameEngine/Shader.h
	src/GameEngine/Resource.cpp
	src/GameEngine/Resource.h
	src/GameEngine/Resources.h
	src/GameEngine/Material.cpp
	src/GameEngine/Material.h
	src/GameEngine/MaterialAttribute.h
	src/GameEngine/Enviroment.cpp
	src/GameEngine/Enviroment.h
	src/GameEngine/Sound.cpp	
	src/GameEngine/Sound.h
	src/GameEngine/SoundSource.cpp	
	src/GameEngine/SoundSource.h
	src/GameEngine/MeshRender.cpp
	src/GameEngine/MeshRender.h
	src/GameEngine/CollisionDetection.cpp
	src/GameEngine/CollisionDetection.h
	src/GameEngine/ModelCollider.cpp
	src/GameEngine/ModelCollider.h
	src/GameEngine/UserInput.cpp
	src/GameEngine/UserInput.h
	src/GameEngine/Keyboard.cpp
	src/GameEngine/Keyboard.h
	src/GameEngine/Ray.cpp	
	src/GameEngine/Ray.h
	src/GameEngine/tribox.cpp
	src/GameEngine/tribox.h
	src/GameEngine/GameEngine.h
	src/GameEngine/RendInc.h
)

target_link_libraries(GameEngine rend)


add_executable(sandbox
	src/sandbox/Main.cpp
	src/sandbox/Player.cpp
	src/sandbox/Player.h

)


target_link_libraries(sandbox GameEngine)