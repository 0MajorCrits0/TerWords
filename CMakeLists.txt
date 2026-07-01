cmake_minimum_required(VERSION 3.28)

project(TerWords LANGUAGES CXX)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED) 

add_executable(TerWords src/main.cpp)

target_link_libraries(TerWords PRIVATE glad::glad glfw)
