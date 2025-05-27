#include "pch.h"

#include "OpenGlConfiguration.h"

namespace Alixer
{
	OpenGlConfiguration::OpenGlConfiguration(const uint8_t maxFps)
		: AlixerConfiguration(CreateRenderEngineFunction(&CreateRenderEngine),
			CreateWindowFunction(&CreateWindow), maxFps)
	{
		// OpenGL specific initialization can be done here
		// Create an OpenGL specific CreateRenderEngineFunction and CreateWindowFunction

	}

	Shared<RenderEngineApi> OpenGlConfiguration::CreateRenderEngine(RenderEngine type)
	{
		return nullptr; // Placeholder for OpenGL render engine creation
	}

	Shared<AlixerWindow> OpenGlConfiguration::CreateWindow(const WindowConfig& config)
	{
		return nullptr;
	}
}
