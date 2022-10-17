set(SOURCE_FILES
		GameApp.cpp
	)
set(HEADER_FILES
		Pixel.h
		GameApp.h
		PixelUtil.h
	)

add_library(Pixel SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DPIXEL_LIB)

target_precompile_headers(Pixel PRIVATE pch.h)

include_directories(../glfw/include/)

target_link_libraries(Pixel glfw)