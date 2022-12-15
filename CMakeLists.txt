cmake_minimum_required(VERSION 3.24)

project(ultimate_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DPIXEL_WINDOWS)
elseif(APPLE)
	add_definitions(-DPIXEL_MAC)
else()
	add_definitions(-DPIXEL_LINUX)
endif()

add_definitions(-DPIXEL_DEBUG)
add_definitions(-DPIXEL_OPENGL)

add_subdirectory(GameEngine)
add_subdirectory(Pixel)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)

set(VS_STARTUP_PROJECT GameEngine)

file(COPY GameEngine/Assets DESTINATION ${PROJECT_BINARY_DIR}/GameEngine)
file(COPY GameEngine/Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY GameEngine/Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)