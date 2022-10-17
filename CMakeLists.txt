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

add_subdirectory(GameEngine)
add_subdirectory(Pixel)
add_subdirectory(glfw)

set(VS_STARTUP_PROJECT GameEngine)