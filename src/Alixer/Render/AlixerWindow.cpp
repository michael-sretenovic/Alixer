#include "pch.h"

#include "AlixerWindow.h"

namespace Alixer
{
	AlixerWindow::AlixerWindow(const WindowConfig& config)
		: _config(config) { }

	AlixerWindow& AlixerWindow::operator=(const AlixerWindow& window)
	{
		if (this == &window)
		{
			return *this;
		}
		_config = window._config;
		return *this;
	}

	AlixerWindow& AlixerWindow::operator=(AlixerWindow&& window) noexcept
	{
		if (this == &window)
		{
			return *this;
		}
		_config = window._config;
		return *this;
	}

	uint32_t AlixerWindow::GetWidth() const { return _config.GetWidth(); }

	uint32_t AlixerWindow::GetHeight() const { return _config.GetHeight(); }

	uint8_t AlixerWindow::GetMaxFps() const { return _config.GetMaxFps(); }

	char* AlixerWindow::GetTitle() const { return _config.GetTitle(); }
}
