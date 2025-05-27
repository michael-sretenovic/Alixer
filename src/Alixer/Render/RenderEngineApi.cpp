#include "pch.h"

#include "RenderEngineApi.h"

namespace Alixer
{
	RenderEngineApi::RenderEngineApi(const RenderEngine renderEngineApi) : _renderEngineApi(renderEngineApi) { }

	RenderEngine RenderEngineApi::GetRenderEngineApi() const { return _renderEngineApi; }

	void RenderEngineApi::SetClearColor(const float r, const float g, const float b, const float a)
	{
		glm::vec4 color = glm::vec4(r, g, b, a);
		SetClearColor(color);
	}

}
