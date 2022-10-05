#include "pch.h"

#include "GameApp.h"
#include "PixelUtil.h"


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