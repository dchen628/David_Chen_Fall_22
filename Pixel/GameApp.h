#pragma once

#include "pch.h"
#include "PixelUtil.h"

constexpr int FRAMES_PER_SECOND = 60;

namespace Ekko
{
	class PIXEL_API GameApp
	{
	public:
		GameApp();
		virtual void ForceUpdate();
		void Run();

	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / FRAMES_PER_SECOND };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}
