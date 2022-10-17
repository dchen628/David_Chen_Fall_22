#include "pch.h"
#include "PixelWindow.h"

namespace Ekko
{
	void PixelWindow::Init()
	{
		if (mInstance == nullptr)
		{
			mInstance = new PixelWindow;

			//mInstance->mImplementation
		}
	}

	PixelWindow* PixelWindow::GetWindow()
	{
		return mInstance;
	}
	void PixelWindow::Create(int width, int height, const std::string& windowName)
	{
		mImplementation->Create(width, height, windowName);
	}

	void PixelWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

}