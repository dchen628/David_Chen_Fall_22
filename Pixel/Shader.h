#pragma once

#include "PixelUtil.h"
#include "ShaderImplementation.h"
#include "pch.h"

namespace Ekko
{
	class PIXEL_API Shader
	{
	public:
		Shader(const std::string& vertexFile, const std::string&& fragmentShader);
		Shader(std::string& vertexFile, std::string&& fragmentShader);
		
		void Activate();

		void ProvideFloatValues(const std::string& valueName, const std::vector<float>& vals);
		void ProvideFloatValues(std::string&& valueName, std::vector<float>&& vals);
	private:
		ShaderImplementation* mImplementation{ nullptr };
	};
}