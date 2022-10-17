#include "pch.h"

#include "GameApp.h"
#include "PixelUtil.h"

#include "GLFW/glfw3.h"


namespace Ekko
{
	void GameApp::ForceUpdate()
	{

	}

	void GameApp::Run()
	{
		PIXEL_LOG("Pixel Running...");



		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLFWwindow* win{ glfwCreateWindow(600, 400, "Onedow", NULL, NULL) };
		glfwMakeContextCurrent(win);

		while (true)
		{
			glfwSwapBuffers(win);
			glfwPollEvents();

			ForceUpdate();
		}

		glfwTerminate();
	}
}