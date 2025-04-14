#include "pch.h"

#include "WindowConfig.h"

namespace Alixer
{
	WindowConfig::WindowConfig(const char* title, const uint32_t width,
		const uint32_t height, const uint8_t maxFps)
		: _title(title), _width(width), _height(height), _maxFps(maxFps) { }

	uint32_t WindowConfig::GetWidth() const { return _width; }

	uint32_t WindowConfig::GetHeight() const { return _height; }

	uint8_t WindowConfig::GetMaxFps() const { return _maxFps; }

	char* WindowConfig::GetTitle() const { return const_cast<char*>(_title); }
}
