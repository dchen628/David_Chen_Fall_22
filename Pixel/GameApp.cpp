#include "GameApp.h"
#include "PixelUtil.h"
#include <iostream>

namespace Ekko
{
	void GameApp::ForceUpdate()
	{

	}

	void GameApp::Run()
	{
		PIXEL_LOG("Pixel Running...");

		while (true)
		{
			

			ForceUpdate();
		}
	}
}