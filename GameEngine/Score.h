#pragma once

#include "Pixel.h"

namespace Ekko
{
	class Score
	{
	public:
		Score();
		int addScore();
		int getScore();
		void drawScore();
	private:
		Ekko::Picture zero{ "Assets/Textures/0.png" };
		Ekko::Picture one{ "Assets/Textures/1.png" };
		Ekko::Picture two{ "Assets/Textures/2.png" };
		Ekko::Picture three{ "Assets/Textures/3.png" };
		Ekko::Picture four{ "Assets/Textures/4.png" };
		Ekko::Picture five{ "Assets/Textures/5.png" };
		Ekko::Picture six{ "Assets/Textures/6.png" };
		Ekko::Picture seven{ "Assets/Textures/7.png" };
		Ekko::Picture eight{ "Assets/Textures/8.png" };
		Ekko::Picture nine{ "Assets/Textures/9.png" };
		int score{ 0 };
		int xCoord{ 80 };
		int increment{ 0 };
	};
}