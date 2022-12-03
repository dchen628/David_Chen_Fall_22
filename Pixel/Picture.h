#pragma once

#include "pch.h"
#include "PixelUtil.h"
#include "PictureImplementation.h"

namespace Ekko
{
	class PIXEL_API Picture
	{
	public:
		Picture(const std::string& sourceFile);
		Picture(const std::string&& sourceFile);

		int GetHeight() const;
		int GetWidth() const;

		void Activate();

	private:
		PictureImplementation* mImplementation{ nullptr };

	};
}