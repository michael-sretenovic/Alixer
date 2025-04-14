#include "pch.h"

#include "TestAlixerWindow.h"

namespace AlixerTests
{
	using namespace Alixer;
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(AlixerWindowTests)
	{
	public:
		TEST_METHOD(Success_TickReturns)
		{
			const WindowConfig config("Alixer Test Window", 800, 600);

			const std::shared_ptr<AlixerWindow> window = std::make_shared<TestAlixerWindow>(config);
			Assert::IsNotNull(window.get(), L"Window creation failed");

			window->Tick(0);
		}

		TEST_METHOD(Success_GetProperties)
		{
			constexpr uint8_t expectedMaxFps = 60;
			const WindowConfig config("Alixer Test Window", 800, 600);

			const std::shared_ptr<AlixerWindow> window = std::make_shared<TestAlixerWindow>(config);
			Assert::IsNotNull(window.get(), L"Window creation failed");

			const uint32_t width = window->GetWidth();
			const uint32_t height = window->GetHeight();
			const uint8_t maxFps = window->GetMaxFps();
			const char* title = window->GetTitle();

			Assert::AreEqual(800u, width, L"Width mismatch");
			Assert::AreEqual(600u, height, L"Height mismatch");
			Assert::AreEqual(expectedMaxFps, maxFps, L"Max FPS mismatch");
			Assert::AreEqual("Alixer Test Window", title, L"Title mismatch");
		}
	};
}
