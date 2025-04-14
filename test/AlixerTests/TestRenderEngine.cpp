#include "TestRenderEngine.h"

namespace AlixerTests
{
	TestRenderEngine::TestRenderEngine() : _totalRenders(0) { }

	void TestRenderEngine::Render() { ++_totalRenders; }

	uint32_t TestRenderEngine::GetTotalRenderCount() const { return _totalRenders; }

	CreateRenderEngineFunction TestRenderEngine::CreateRenderEngine = [](const RenderEngineType& type)
		-> Shared<RenderEngine>
		{
			return CreateShared<TestRenderEngine>();
		};
}
