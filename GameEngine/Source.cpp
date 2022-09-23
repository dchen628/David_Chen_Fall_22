/*
	Include Pixel.h
	Inherit a class from GameApp. Override method OnUpdate in it.
	Feed the name of your class to LINK_START macro.
*/

#include "Pixel.h"

class PixelGame : public Ekko::GameApp
{
public:
	void ForceUpdate() override
	{

	}
};

LINK_START(PixelGame)