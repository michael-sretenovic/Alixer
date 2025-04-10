#pragma once

#ifdef AL_PLATFORM_WINDOWS
	#define MOUSE_CURSOR_FORMAT "{:.0f}"
	#ifdef AL_BUILD_DLL
		#define ALIXER_API __declspec(dllexport)
	#else
		#define ALIXER_API __declspec(dllimport)
	#endif
#elif AL_PLATFORM_LINUX
	#define MOUSE_CURSOR_FORMAT "{:.0f}"
	#error Alixer does not currently support Linux.
#elif AL_PLATFORM_MAC
	#define MOUSE_CURSOR_FORMAT "{:.2f}"
	#error Alixer does not currently support MacOS.
#else
	#error Unknown platform not supported!
#endif
