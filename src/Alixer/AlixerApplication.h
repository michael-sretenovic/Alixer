#pragma once

#include <memory>

#include "Core.h"
#include "Render/AlixerWindow.h"
#include "Render/RenderEngine.h"

namespace Alixer
{
	class ALIXER_API AlixerApplication
	{
	public:
		explicit AlixerApplication(RenderEngine renderEngine);

		std::shared_ptr<AlixerWindow> CreateWindow(const WindowConfig& config);

		void Run();

	private:
		RenderEngine _renderEngine;
	};
}
