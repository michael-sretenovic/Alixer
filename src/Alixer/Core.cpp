#include "pch.h"

#include "Core.h"

namespace Alixer
{
	uint32_t FromMs(const MsDuration duration)
	{
		return static_cast<uint32_t>(std::chrono::duration_cast<std::chrono::milliseconds>(duration).count());
	}

	void SleepMs(const uint32_t ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }
}
