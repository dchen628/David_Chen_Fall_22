#include "pch.h"
#include "PixelWindow.h"
#include "GLFWthings/GLFWimplementation.h"

namespace Ekko
{
	void PixelWindow::Init()
	{
		if (mInstance == nullptr)
		{
			mInstance = new PixelWindow;

#ifdef PIXEL_WINDOWS
			mInstance->mImplementation = new GLFWimplementation;
#elif defined PIXEL_MAC
			mInstance->mImplementation = new GLFWimplementation;
#else
			mInstance->mImplementation = new GLFWimplementation;
#endif
		}
	}

	PixelWindow* PixelWindow::GetWindow()
	{
		return mInstance;
	}
	void PixelWindow::Create(int width, int height, const std::string& windowName)
	{
		mImplementation->Create(width, height, windowName);

		mWidth = width;
		mHeight = height;
	}

	void PixelWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

	int PixelWindow::GetWidth() const
	{
		return mWidth;
	}

	int PixelWindow::GetHeight() const
	{
		return mHeight;
	}

}