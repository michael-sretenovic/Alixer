#include "pch.h"

#include "WindowConfig.h"

namespace Alixer
{
	WindowConfig::WindowConfig(const char* title, const uint32_t width, const uint32_t height)
		: _title(title), _width(width), _height(height) { }
}
