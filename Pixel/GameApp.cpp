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

		while (true)
		{
			Renderer::Clear();

			ForceUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			PixelWindow::GetWindow()->SwapBuffers();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}

	}
}