#pragma once

#include "AlixerConfiguration.h"

namespace Alixer
{
	class ALIXER_API OpenGlConfiguration final : public AlixerConfiguration
	{
	public:
		explicit OpenGlConfiguration(uint8_t maxFps = 60);

		OpenGlConfiguration(const OpenGlConfiguration& config) = default;

		OpenGlConfiguration(OpenGlConfiguration&& config) = default;

		~OpenGlConfiguration() = default;

		OpenGlConfiguration& operator=(const OpenGlConfiguration& config) = default;

		OpenGlConfiguration& operator=(OpenGlConfiguration&& config) noexcept = default;

		static Shared<RenderEngineApi> CreateRenderEngine(RenderEngine type);

		static Shared<AlixerWindow> CreateWindow(const WindowConfig& config);
	};
}
