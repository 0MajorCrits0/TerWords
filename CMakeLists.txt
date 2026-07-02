cmake_minimum_required(VERSION 3.28)

project(TerWords LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED) 

add_executable( TerWords src/main.cpp
		src/KeyboardHandler.cpp
		src/Window.cpp
		src/WindowHandlerProxy.cpp
		src/World.cpp)

add_library(RenderSystem STATIC src/renderSystem/Program.cpp
				src/renderSystem/Aggregation.cpp
				src/renderSystem/WorldRenderer.cpp)

target_link_libraries(RenderSystem PUBLIC glad::glad glfw)
target_link_libraries(TerWords PRIVATE RenderSystem)
target_include_directories(RenderSystem PUBLIC include)
target_compile_definitions(RenderSystem PUBLIC SHADER_PATH="${CMAKE_SOURCE_DIR}/shaders/")