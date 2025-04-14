#pragma once

#include <chrono>
#include <memory>
#include <thread>

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

namespace Alixer
{
	template<typename T> using Unique = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Unique<T> CreateUnique(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T> using Shared = std::shared_ptr<T>;

	template<typename T, typename ... Args >
	constexpr Shared<T> CreateShared(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	using HighResClock = std::chrono::high_resolution_clock;

	using MsDuration = std::common_type_t<std::chrono::duration<long long, std::ratio<1, 1000000000>>,
		std::chrono::duration<long long, std::ratio<1, 1000000000>>>;

	using TimePoint = std::chrono::high_resolution_clock::time_point;

	ALIXER_API uint32_t FromMs(MsDuration duration);

	ALIXER_API void SleepMs(uint32_t ms);
}
