#pragma once

#include <any>

#include "Core.h"
#include "WindowConfig.h"

namespace Alixer
{
	class ALIXER_API AlixerWindow
	{
	public:
		explicit AlixerWindow(const WindowConfig& config);

		AlixerWindow(AlixerWindow& window) = default;

		AlixerWindow(AlixerWindow&& window) = default;

		virtual ~AlixerWindow() = default;

		AlixerWindow& operator=(const AlixerWindow& window);

		AlixerWindow& operator=(AlixerWindow&& window) noexcept;

		uint32_t GetWidth() const;

		uint32_t GetHeight() const;

		uint8_t GetMaxFps() const;

		char* GetTitle() const;

		virtual std::any GetNativeWindow() = 0;

		virtual void SetVSync(bool enabled) = 0;

		virtual bool IsVSync() const = 0;

		virtual void Tick(uint32_t deltaMs) = 0;

		virtual void Render() = 0;

	private:
		WindowConfig _config;
	};
}
