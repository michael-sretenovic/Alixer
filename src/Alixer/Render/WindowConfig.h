#pragma once

#include "Core.h"

namespace Alixer
{
	class ALIXER_API WindowConfig
	{
	public:
		explicit WindowConfig(const char* title, uint32_t width, uint32_t height, uint8_t maxFps = 60);

		uint32_t GetWidth() const;

		uint32_t GetHeight() const;

		uint8_t GetMaxFps() const;

		char* GetTitle() const;

	private:
		const char* _title;
		uint32_t _width;
		uint32_t _height;
		uint8_t _maxFps;
	};
}
