#include "pch.h"

#include "Logger.h"
#include "MouseButton.h"

namespace Alixer
{
#define MOUSE_BUTTON_TO_CASE(type) case MouseButton::type: return #type;

	std::string GetMouseButtonName(const MouseButton button)
	{
		switch (button)
		{
			MOUSE_BUTTON_TO_CASE(None)
			MOUSE_BUTTON_TO_CASE(Button0)
			MOUSE_BUTTON_TO_CASE(Button1)
			MOUSE_BUTTON_TO_CASE(Button2)
			MOUSE_BUTTON_TO_CASE(Button3)
			MOUSE_BUTTON_TO_CASE(Button4)
			MOUSE_BUTTON_TO_CASE(Button5)
			MOUSE_BUTTON_TO_CASE(Button6)
			MOUSE_BUTTON_TO_CASE(Button7)
		};

		AL_CORE_WARN("Unknown Mouse Button: {0}", std::to_string(static_cast<uint8_t>(button)));
		return "Unknown Mouse Button";
	}
}
