set(SOURCE_FILES
		GameApp.cpp
		PixelWindow.cpp
		GLFWthings/GLFWimplementation.cpp
	)
set(HEADER_FILES
		Pixel.h
		GameApp.h
		PixelUtil.h
		PixelWindow.h
		WindowImplementation.h
		GLFWthings/GLFWimplementation.h
	)

add_library(Pixel SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DPIXEL_LIB)

target_precompile_headers(Pixel PRIVATE pch.h)

include_directories(../glfw/include/)
include_directories(../glad/include/)
include_directories(../Pixel)

target_link_libraries(Pixel glfw glad)