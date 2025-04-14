#include "pch.h"

#include "TestAlixerWindow.h"
#include "TestRenderEngine.h"

namespace AlixerTests
{
	using namespace Alixer;
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(AlixerApplicationTests)
	{
	public:
		
		TEST_METHOD(Success_CreateWindow)
		{
			AlixerApplication app(TestRenderEngine::CreateRenderEngine, TestAlixerWindow::CreateWindow);

			const WindowConfig config("Alixer Test Window", 800, 600);

			const Shared<AlixerWindow> window = app.CreateWindow(config);
			Assert::IsNotNull(window.get(), L"Window creation failed");
		}

		TEST_METHOD(Success_TickReturns)
		{
			constexpr uint32_t totalTicksExpected = 1;

			AlixerApplication app(TestRenderEngine::CreateRenderEngine, TestAlixerWindow::CreateWindow);
			const WindowConfig config("Alixer Test Window", 800, 600);
			const Shared<AlixerWindow> window = app.CreateWindow(config);
			const Shared<TestAlixerWindow> testWindow = std::dynamic_pointer_cast<TestAlixerWindow>(window);

			Assert::IsNotNull(window.get(), L"Window creation failed");

			app.Tick();

			Assert::AreEqual(totalTicksExpected, testWindow->GetTotalTicks(), L"Total ticks is incorrect");
		}

		TEST_METHOD(Success_CanStartAndStop)
		{
			AlixerApplication app(TestRenderEngine::CreateRenderEngine, TestAlixerWindow::CreateWindow);

			const WindowConfig config("Alixer Test Window", 800, 600);
			const Shared<AlixerWindow> window = app.CreateWindow(config);
			const Shared<TestAlixerWindow> testWindow = std::dynamic_pointer_cast<TestAlixerWindow>(window);

			Assert::IsFalse(app.IsRunning(), L"App should not be running");

			app.Run();
			SleepMs(10); // Give some time for the app to run

			Assert::IsTrue(app.IsRunning(), L"App should be running");
			Assert::IsTrue(testWindow->GetTotalRenderCount() == 0, L"Window should not have been rendered");

			SleepMs(25); // Give some time for the app to run

			Assert::IsTrue(testWindow->GetTotalRenderCount() > 0, L"Window should have been rendered");

			app.Stop();

			Assert::IsFalse(app.IsRunning(), L"App should not be running");
			Assert::IsTrue(testWindow->GetTotalTicks() > 0, L"Window should have been ticked");
		}
	};
}
