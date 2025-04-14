#pragma once

namespace Alixer
{
	enum class RenderEngineType : uint8_t
	{
		None,
		OpenGl,
		Vulkan
	};

	ALIXER_API class RenderEngine
	{
	public:
		virtual ~RenderEngine() = default;

		virtual void Render() = 0;
	};
}
