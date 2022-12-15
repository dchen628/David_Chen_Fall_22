set(SOURCE_FILES
		Event.cpp
		OpenGLthings/OpenGLPicture.cpp
		OpenGLthings/OpenGLShader.cpp
		OpenGLthings/OpenGLRenderer.cpp
		Picture.cpp
		Shader.cpp
		Renderer.cpp
		Unit.cpp
		GameApp.cpp
		PixelWindow.cpp
		GLFWthings/GLFWimplementation.cpp
	)
set(HEADER_FILES
		Event.h
		Key.h
		OpenGLthings/OpenGLPicture.h
		OpenGLthings/OpenGLShader.h
		OpenGLthings/OpenGLRenderer.h
		Picture.h
		Shader.h
		Renderer.h
		PictureImplementation.h
		ShaderImplementation.h
		RendererImplementation.h
		Unit.h
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
include_directories(../stbi)

target_link_libraries(Pixel glfw glad stbi)