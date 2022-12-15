#include "pch.h"

#include "GameApp.h"
#include "PixelUtil.h"
#include "PixelWindow.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "Picture.h"
#include "Renderer.h"
#include "Event.h"
#include "Key.h"
#include "Unit.h"

namespace Ekko
{
	GameApp::GameApp()
	{
		PixelWindow::Init();
		PixelWindow::GetWindow()->Create(1000, 800, "TestWindow");

		Renderer::Init();
	}

	void GameApp::ForceUpdate()
	{

	}

	void GameApp::Run()
	{
		PIXEL_LOG("Pixel Running...");

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		//Picture pic{ "Assets/Textures/smile.png" };
		///Picture pic2{ "Assets/Textures/test.png" };

		while (true)
		{
			Renderer::Clear();

			ForceUpdate();

			//Ekko::Renderer::Draw(pic, 200, 200, 1);
			//Ekko::Renderer::Draw(pic2, 100, 100, 1);

			std::this_thread::sleep_until(mNextFrameTime);

			PixelWindow::GetWindow()->SwapBuffers();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}

	}
}