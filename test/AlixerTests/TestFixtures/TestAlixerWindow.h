#pragma once

#include <cstdint>

#include "AlixerApplication.h"
#include "Render/AlixerWindow.h"

namespace AlixerTests
{
	using namespace Alixer;

	class TestAlixerWindow final : public AlixerWindow
	{
	public:
		explicit TestAlixerWindow(const WindowConfig& config);

		void Tick(uint32_t deltaMs) override;

		void Render() override;

		uint32_t GetTotalTicks() const;

		uint32_t GetTotalRenderCount() const;

		std::any GetNativeWindow() override;

		void SetVSync(bool enabled) override;

		bool IsVSync() const override;

		static CreateWindowFunction CreateWindow;

	private:
		uint32_t _totalTicks;

		uint32_t _totalRenders;

		bool _isVSyncEnabled = false;
	};
}
