#pragma once

#include "AlixerConfiguration.h"

namespace AlixerTests
{
	using namespace Alixer;

	class TestConfiguration final : public AlixerConfiguration
	{
	public:
		explicit TestConfiguration(uint8_t maxFps = 60);

		TestConfiguration(const TestConfiguration& config) = default;

		TestConfiguration(TestConfiguration&& config) = default;

		~TestConfiguration() = default;

		TestConfiguration& operator=(const TestConfiguration& config) = default;

		TestConfiguration& operator=(TestConfiguration&& config) noexcept = default;

		static Shared<RenderEngineApi> CreateRenderEngine(RenderEngine type);

		static Shared<AlixerWindow> CreateWindow(const WindowConfig& config);
	};
}
