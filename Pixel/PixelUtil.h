#pragma once

#define LINK_START(PixelGame) \
	int main()\
	{ \
		PixelGame __pixel__game;\
		__pixel__game.Run();\
		return 0;\
	}


#ifdef PIXEL_WINDOWS
	#ifdef PIXEL_LIB
		#define PIXEL_API __declspec(dllexport)
	#else
		#define PIXEL_API __declspec(dllimport)
	#endif
#else
	#define PIXEL_API
#endif


#ifdef PIXEL_DEBUG
	#define PIXEL_LOG(x) std::cout<<x<<std::endl; 
#else
	#define PIXEL_LOG(x)
#endif