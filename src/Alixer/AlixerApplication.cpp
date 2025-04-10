#include "pch.h"

#include "AlixerApplication.h"

namespace Alixer
{
	AlixerApplication::AlixerApplication(const RenderEngine renderEngine)
		: _renderEngine(renderEngine)
	{
		
	}

	std::shared_ptr<AlixerWindow> AlixerApplication::CreateWindow(const WindowConfig& config)
	{
		// Create a new AlixerWindow instance
		std::shared_ptr<AlixerWindow> window = std::make_shared<AlixerWindow>(config);
		return window;
	}

	void AlixerApplication::Run()
	{
		// Main application loop
	}
}
