#pragma once

#include "RenderEngineApi.h"

namespace Alixer
{
	class NoneRenderEngine final : public RenderEngineApi
	{
	public:
		NoneRenderEngine();

		NoneRenderEngine(const NoneRenderEngine& engine) = delete;

		NoneRenderEngine(NoneRenderEngine&& engine) = default;

		~NoneRenderEngine() override = default;

		NoneRenderEngine& operator=(const NoneRenderEngine& window) = default;

		NoneRenderEngine& operator=(NoneRenderEngine&& window) noexcept = default;

		void Render() override;

		void Initialize() override;

		void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

		void SetClearColor(glm::vec4& color) override;

		void Clear() override;
	};
}
