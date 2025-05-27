#pragma once

#include <functional>

#include "Core.h"
#include "Render/AlixerWindow.h"
#include "Render/RenderEngineApi.h"
#include "Render/WindowConfig.h"

namespace Alixer
{
	typedef std::function<Shared<RenderEngineApi>(RenderEngine)> CreateRenderEngineFunction;

	typedef std::function<Shared<AlixerWindow>(const WindowConfig&)> CreateWindowFunction;

	class ALIXER_API AlixerConfiguration
	{
	public:
		explicit AlixerConfiguration(const CreateRenderEngineFunction& createRenderEngine,
			const CreateWindowFunction& createWindow, uint8_t maxFps);

		CreateWindowFunction GetCreateWindowFunction() const;

		CreateRenderEngineFunction GetCreateRenderEngineFunction() const;

		uint8_t GetMaxFps() const;

	protected:
		CreateRenderEngineFunction _createRenderEngineFunction;

		CreateWindowFunction _createWindowFunction;

		uint8_t _maxFps;
	};
}
