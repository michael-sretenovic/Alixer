#pragma once

#include "Core.h"

namespace Alixer
{
	class ALIXER_API WindowConfig
	{
	public:
		explicit WindowConfig(const char* title, uint32_t width, uint32_t height);

	private:
		const char* _title;
		uint32_t _width;
		uint32_t _height;
	};
}
