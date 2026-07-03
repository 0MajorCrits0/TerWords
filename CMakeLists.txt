cmake_minimum_required(VERSION 3.28)

project(TerWords LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED) 

add_executable( TerWords src/main.cpp
		src/MathObjects.cpp 
		src/PlayerController.cpp
		src/WorldFrameData.cpp)

add_library(RenderSystem STATIC src/RenderSystem/Program.cpp
				src/RenderSystem/SceneGroup.cpp
				src/RenderSystem/WorldRenderer.cpp
				src/RenderSystem/RenderManager.cpp)

add_library(WorldSystem  STATIC 
				src/WorldSystem/WorldGenerator.cpp
				src/WorldSystem/WorldChunkLoader.cpp
				src/WorldSystem/World.cpp
				src/WorldSystem/WorldManager.cpp)

add_library(EnvSystem    STATIC src/EnvSystem/Keyboard.cpp
				src/EnvSystem/Window.cpp
				src/EnvSystem/EnvironmentManager.cpp
				src/EnvSystem/Time.cpp)


target_link_libraries(RenderSystem PUBLIC glad::glad glfw)
target_link_libraries(EnvSystem PUBLIC glad::glad glfw)
target_link_libraries(WorldSystem PUBLIC glad::glad glfw)
target_link_libraries(TerWords PRIVATE RenderSystem)
target_link_libraries(TerWords PRIVATE WorldSystem)
target_link_libraries(TerWords PRIVATE EnvSystem)

target_link_libraries(RenderSystem PRIVATE WorldSystem)
target_link_libraries(WorldSystem PRIVATE EnvSystem)

target_include_directories(RenderSystem PUBLIC include)
target_include_directories(WorldSystem PUBLIC include)
target_include_directories(EnvSystem PUBLIC include)
target_include_directories(TerWords PRIVATE include)	
target_compile_definitions(RenderSystem PUBLIC SHADER_PATH="${CMAKE_SOURCE_DIR}/shaders/")