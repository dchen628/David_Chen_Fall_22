#pragma once

#include "pch.h"
#include "PixelUtil.h"
#include "WindowImplementation.h"

namespace Ekko
{
	class PIXEL_API PixelWindow
	{
	public:
		static void Init();
		PixelWindow* GetWindow();

		void Create(int width, int height, const std::string& windowName);
		void SwapBuffers();


	private:
		PixelWindow();

		inline static PixelWindow* mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };
	};
}