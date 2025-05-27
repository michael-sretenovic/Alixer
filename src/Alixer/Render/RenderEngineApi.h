#pragma once

#include "Core.h"
#include "RenderEngine.h"
#include "glm/glm.hpp"

namespace Alixer
{
	class ALIXER_API RenderEngineApi
	{
	public:
		explicit RenderEngineApi(RenderEngine renderEngineApi);

		RenderEngineApi(RenderEngineApi& engine) = default;

		RenderEngineApi(RenderEngineApi&& engine) = default;

		virtual ~RenderEngineApi() = default;

		RenderEngineApi& operator=(const RenderEngineApi& window) = default;

		RenderEngineApi& operator=(RenderEngineApi&& window) noexcept = default;

		virtual void Render() = 0;

		RenderEngine GetRenderEngineApi() const;

		virtual void Initialize() = 0;

		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;

		virtual void SetClearColor(float r, float g, float b, float a);

		virtual void SetClearColor(glm::vec4& color) = 0;

		virtual void Clear() = 0;

	private:
		RenderEngine _renderEngineApi;
	};
}
