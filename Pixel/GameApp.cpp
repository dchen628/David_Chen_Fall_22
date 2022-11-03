#include "pch.h"

#include "GameApp.h"
#include "PixelUtil.h"
#include "PixelWindow.h"

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

		while (true)
		{
			PixelWindow::GetWindow()->SwapBuffers();

			ForceUpdate();
		}

	}
}