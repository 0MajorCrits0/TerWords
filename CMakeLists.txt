cmake_minimum_required(VERSION 3.28)

project(TerWords LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED) 

add_executable(TerWords src/main.cpp
			src/MathObjects.cpp
			src/InputMessage.cpp)

add_library(RenderSystem STATIC src/RenderSystem/RenderProgram.cpp
				src/RenderSystem/RenderGroup.cpp
				src/RenderSystem/RenderWorld.cpp
				src/RenderSystem/RenderManager.cpp)

add_library(WorldSystem  STATIC 
				src/WorldSystem/WorldGenerator.cpp
				src/WorldSystem/WorldChunkSelector.cpp
				src/WorldSystem/WorldManager.cpp
				src/WorldSystem/WorldDatabase.cpp)

add_library(EnvSystem    STATIC src/EnvSystem/EnvKeyboard.cpp
				src/EnvSystem/EnvWindow.cpp
				src/EnvSystem/EnvManager.cpp
				src/EnvSystem/EnvTime.cpp)

add_library(PlayerSystem STATIC src/PlayerSystem/PlayerController.cpp)

add_library(PhysicsSystem STATIC src/PhysicsSystem/PhysicsPlayer.cpp)

target_link_libraries(RenderSystem PUBLIC glad::glad glfw)
target_link_libraries(EnvSystem PUBLIC glad::glad glfw)
target_link_libraries(WorldSystem PUBLIC glad::glad glfw)
target_link_libraries(PlayerSystem PUBLIC glad::glad glfw)

target_link_libraries(TerWords PRIVATE RenderSystem)
target_link_libraries(TerWords PRIVATE WorldSystem)
target_link_libraries(TerWords PRIVATE EnvSystem)
target_link_libraries(TerWords PRIVATE PlayerSystem)
target_link_libraries(TerWords PRIVATE PhysicsSystem)

target_link_libraries(RenderSystem PRIVATE WorldSystem)
target_link_libraries(WorldSystem PRIVATE EnvSystem)

target_include_directories(PlayerSystem PUBLIC include)
target_include_directories(RenderSystem PUBLIC include)
target_include_directories(WorldSystem PUBLIC include)
target_include_directories(EnvSystem PUBLIC include)
target_include_directories(TerWords PRIVATE include)
target_include_directories(PhysicsSystem PRIVATE include)	
target_compile_definitions(RenderSystem PUBLIC SHADER_PATH="${CMAKE_SOURCE_DIR}/shaders/")