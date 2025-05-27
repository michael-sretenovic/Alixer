#pragma once

#include <string>

namespace Alixer
{
	enum class KeyModifier : uint8_t
	{
		None     = 0x00,
		Shift    = 0x01,
		Control  = 0x02,
		Alt      = 0x04,
		Super    = 0x08,
		CapsLock = 0x10,
		NumLock  = 0x20
	};

	std::string GetKeyModifierName(KeyModifier modifier);
}
