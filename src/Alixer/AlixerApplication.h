#pragma once

#include <chrono>
#include <functional>
#include <memory>
#include <thread>
#include <vector>

#include "AlixerConfiguration.h"
#include "Core.h"
#include "Render/AlixerWindow.h"

namespace Alixer
{
	class ALIXER_API AlixerApplication
	{
	public:
		explicit AlixerApplication(const CreateRenderEngineFunction& createRenderEngine,
			const CreateWindowFunction& createWindow, uint8_t maxFps = 60);

		Shared<AlixerWindow> CreateWindow(const WindowConfig& config);

		void Run();

		bool IsRunning() const;

		void Tick();

		void Tick(uint32_t deltaMs, bool canRender = false) const;

		void Stop();

	private:
		CreateRenderEngineFunction _createRenderEngine;

		CreateWindowFunction _createWindow;

		std::vector<Shared<AlixerWindow>> _windows;

		std::atomic<bool> _isRunning = false;

		uint16_t _targetFrameDuration;

		std::jthread _thread;

		std::stop_token _stopToken;

		TimePoint _lastTickTime;

		TimePoint _lastRenderTime;
	};
}
