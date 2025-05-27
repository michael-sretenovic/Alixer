#include "pch.h"

#include "NoneRenderEngine.h"

namespace Alixer
{
	NoneRenderEngine::NoneRenderEngine() : RenderEngineApi(RenderEngine::None) { };

	void NoneRenderEngine::Render() { }

	void NoneRenderEngine::Initialize() { }

	void NoneRenderEngine::SetViewport(const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height) { }

	void NoneRenderEngine::SetClearColor(glm::vec4& color) { }

	void NoneRenderEngine::Clear() { }
}
