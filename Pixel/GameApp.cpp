#include "pch.h"

#include "GameApp.h"
#include "PixelUtil.h"
#include "PixelWindow.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "Picture.h"
#include "Renderer.h"

namespace Ekko
{
	void GameApp::ForceUpdate()
	{

	}

	void GameApp::Run()
	{
		PIXEL_LOG("Pixel Running...");

		PixelWindow::Init();
		PixelWindow::GetWindow()->Create(600, 400, "Onedow");

		Picture pic{ "Assets/Textures/test.png" };

		while (true)
		{
			glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			Renderer::Draw(pic, 100, 100, 1);

			PixelWindow::GetWindow()->SwapBuffers();

			ForceUpdate();
		}

	}
}