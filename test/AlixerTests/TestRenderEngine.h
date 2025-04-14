#pragma once

#include "AlixerApplication.h"
#include "Render/RenderEngine.h"

namespace AlixerTests
{
	using namespace Alixer;

	class TestRenderEngine final : public RenderEngine
	{
	public:
		explicit TestRenderEngine();

		void Render() override;

		uint32_t GetTotalRenderCount() const;

		static CreateRenderEngineFunction CreateRenderEngine;

	private:
		uint32_t _totalRenders;
	};
}
