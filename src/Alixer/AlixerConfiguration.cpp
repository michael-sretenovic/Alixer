#include "pch.h"

#include "AlixerConfiguration.h"
#include "Exception/NullArgumentException.h"

namespace Alixer
{
	AlixerConfiguration::AlixerConfiguration(const CreateRenderEngineFunction& createRenderEngine,
		const CreateWindowFunction& createWindow, const uint8_t maxFps)
		: _createRenderEngineFunction(createRenderEngine),
		  _createWindowFunction(createWindow),
		  _maxFps(maxFps)
	{
		if (_createRenderEngineFunction == nullptr)
		{
			throw NullArgumentException("CreateRenderEngine function is null.");
		}

		if (_createWindowFunction == nullptr)
		{
			throw NullArgumentException("CreateWindow function is null.");
		}
	}

	CreateRenderEngineFunction AlixerConfiguration::GetCreateRenderEngineFunction() const
	{
		return _createRenderEngineFunction;
	}

	CreateWindowFunction AlixerConfiguration::GetCreateWindowFunction() const {
		return _createWindowFunction;
	}

	uint8_t AlixerConfiguration::GetMaxFps() const { return _maxFps; }
}
