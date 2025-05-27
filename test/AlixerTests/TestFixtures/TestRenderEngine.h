#pragma once

#include "AlixerApplication.h"
#include "Render/RenderEngineApi.h"

namespace AlixerTests
{
	using namespace Alixer;

	class TestRenderEngine final : public RenderEngineApi
	{
	public:
		explicit TestRenderEngine();

		void Render() override;

		uint32_t GetTotalRenderCount() const;

		void Initialize() override;

		void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

		void SetClearColor(glm::vec4& color) override;

		void Clear() override;

		static CreateRenderEngineFunction CreateRenderEngine;

	private:
		uint32_t _totalRenders;
	};
}
