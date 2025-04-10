#pragma once

#include "Core.h"
#include "WindowConfig.h"

namespace Alixer
{
	class ALIXER_API AlixerWindow
	{
	public:
		explicit AlixerWindow(const WindowConfig config);

	private:
		WindowConfig _config;
	};
}
