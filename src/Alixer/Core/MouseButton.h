#pragma once

#include <string>

namespace Alixer
{
	enum class MouseButton : uint8_t
	{
		None = 0,

		// From glfw3.h + 1
		Button0 = 1,
		Button1 = 2,
		Button2 = 3,
		Button3 = 4,
		Button4 = 5,
		Button5 = 6,
		Button6 = 7,
		Button7 = 8,

		ButtonLast   = Button7,
		ButtonLeft   = Button0,
		ButtonRight  = Button1,
		ButtonMiddle = Button2
	};

	std::string GetMouseButtonName(MouseButton button);
}
