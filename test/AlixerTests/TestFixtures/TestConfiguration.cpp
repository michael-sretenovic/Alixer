#include "TestConfiguration.h"
#include "TestRenderEngine.h"

namespace AlixerTests
{
	TestConfiguration::TestConfiguration(const uint8_t maxFps)
		: AlixerConfiguration(&CreateRenderEngine, &CreateWindow, maxFps)
	{
		// Test specific initialization can be done here
		// Create a Test specific CreateRenderEngineFunction and CreateWindowFunction
	}

	Shared<RenderEngineApi> TestConfiguration::CreateRenderEngine(RenderEngine type)
	{
		return nullptr; // Placeholder for Test render engine creation
	}

	Shared<AlixerWindow> TestConfiguration::CreateWindow(const WindowConfig& config)
	{
		return nullptr;
	}
}
