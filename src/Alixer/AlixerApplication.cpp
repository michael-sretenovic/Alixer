#include "pch.h"

#include "AlixerApplication.h"
#include "Exception/InvalidOperationException.h"

namespace Alixer
{
	AlixerApplication::AlixerApplication(const CreateRenderEngineFunction& createRenderEngine,
		const CreateWindowFunction& createWindow, const uint8_t maxFps)
		: _createRenderEngine(createRenderEngine), _createWindow(createWindow),
		  _targetFrameDuration(1000 / (maxFps > 0 ? maxFps : 60))
	{
		_lastTickTime = HighResClock::now();
		_lastRenderTime = HighResClock::now();
	}

	std::shared_ptr<AlixerWindow> AlixerApplication::CreateWindow(const WindowConfig& config)
	{
		if (_createWindow == nullptr)
		{
			throw InvalidOperationException("CreateWindow function is not set.");
		}

		Shared<AlixerWindow> window = _createWindow(config);
		_windows.push_back(window);
		return window;
	}

	void AlixerApplication::Run()
	{
		_isRunning = true;

		_thread = std::jthread{
			[this](const std::stop_token& stopToken)
			{
				while (!stopToken.stop_requested() && _isRunning)
				{
					Tick();
				}
				_isRunning = false;
			}
		};
	}

	bool AlixerApplication::IsRunning() const { return _isRunning; }

	void AlixerApplication::Tick()
	{
		const TimePoint currentTime = HighResClock::now();
		const uint32_t deltaMs = FromMs(currentTime - _lastTickTime);
		_lastTickTime = currentTime;

		bool canRender = false;
		if (const uint32_t deltaRenderMs = FromMs(currentTime - _lastRenderTime);
			deltaRenderMs > _targetFrameDuration)
		{
			_lastRenderTime = currentTime;
			canRender = true;
		}

		Tick(deltaMs, canRender);
	}

	void AlixerApplication::Tick(const uint32_t deltaMs, const bool canRender) const
	{
		for (const std::shared_ptr<AlixerWindow>& window : _windows)
		{
			if (window)
			{
				window->Tick(deltaMs);
				if (canRender)
				{
					window->Render();
				}
			}
		}
	}

	void AlixerApplication::Stop()
	{
		_thread.request_stop();
		while (_isRunning)
		{
			SleepMs(100);
		}
	}
}
