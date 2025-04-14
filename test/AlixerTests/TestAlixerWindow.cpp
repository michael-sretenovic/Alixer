#include "TestAlixerWindow.h"
#include "Render/AlixerWindow.h"

namespace AlixerTests
{
	TestAlixerWindow::TestAlixerWindow(const WindowConfig& config)
		: AlixerWindow(config), _totalTicks(0), _totalRenders(0) { }

	void TestAlixerWindow::Tick(uint32_t deltaMs) { ++_totalTicks; }

	void TestAlixerWindow::Render() { ++_totalRenders; }

	uint32_t TestAlixerWindow::GetTotalTicks() const { return _totalTicks; }

	uint32_t TestAlixerWindow::GetTotalRenderCount() const { return _totalRenders; }

	CreateWindowFunction TestAlixerWindow::CreateWindow = [](const WindowConfig& config)
		-> Shared<AlixerWindow>
		{
			return CreateShared<TestAlixerWindow>(config);
		};
}
