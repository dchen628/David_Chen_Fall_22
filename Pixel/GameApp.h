#pragma once
#include "PixelUtil.h"

namespace Ekko
{
	class PIXEL_API GameApp
	{
	public:

		virtual void ForceUpdate();
		void Run();
	};
}
