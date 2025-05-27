#pragma once

#include <cstdint>

namespace Alixer
{
	enum class EventType : uint16_t
	{
		Application   = 0b0000000000000000, //     0
		Window        = 0b0000000000000001, //     1
		Input         = 0b0000000000000010, //     2
		Keyboard      = 0b0000000000000100, //     4
		Mouse         = 0b0000000000001000, //     8

		Render        = 0b0000000000010000, //    16
		Tick          = 0b0000000000100000, //    32
		Close         = 0b0000000001000000, //    64
		GainFocus     = 0b0000000010000000, //   128
		LostFocus     = 0b0000000100000000, //   256
		Move          = 0b0000001000000000, //   512
		Resize        = 0b0000010000000000, //  1024
		ButtonPress   = 0b0000100000000000, //  2048
		ButtonRelease = 0b0001000000000000, //  4096
		Clicked       = 0b0010000000000000, //  8192
		Scroll        = 0b0100000000000000, // 16384


		ApplicationRender = Application | Render,
		ApplicationTick   = Application | Tick,
		ApplicationClose  = Application | Close,

		WindowRender    = Window | Render,
		WindowTick      = Window | Tick,
		WindowClose     = Window | Close,
		WindowGainFocus = Window | GainFocus,
		WindowLostFocus = Window | LostFocus,
		WindowMove      = Window | Move,
		WindowResize    = Window | Resize,

		InputKeyboardButtonPress   = Input | Keyboard | ButtonPress,
		InputKeyboardButtonRelease = Input | Keyboard | ButtonRelease,
		InputKeyboardClicked       = Input | Keyboard | Clicked,

		InputMouseButtonPress   = Input | Mouse | ButtonPress,
		InputMouseButtonRelease = Input | Mouse | ButtonRelease,
		InputMouseClicked       = Input | Mouse | Clicked,
		InputMouseScroll        = Input | Mouse | Scroll,
	};
}
