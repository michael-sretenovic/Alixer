#include "TestRenderEngine.h"

namespace AlixerTests
{
	TestRenderEngine::TestRenderEngine() : RenderEngineApi(RenderEngine::None), _totalRenders(0) { }

	void TestRenderEngine::Render() { ++_totalRenders; }

	uint32_t TestRenderEngine::GetTotalRenderCount() const { return _totalRenders; }

	void TestRenderEngine::Initialize() { }

	void TestRenderEngine::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) { }

	void TestRenderEngine::SetClearColor(glm::vec4& color) { }

	void TestRenderEngine::Clear() { }

	CreateRenderEngineFunction TestRenderEngine::CreateRenderEngine = [](const RenderEngine& type)
		-> Shared<RenderEngineApi>
		{
			return CreateShared<TestRenderEngine>();
		};
}
