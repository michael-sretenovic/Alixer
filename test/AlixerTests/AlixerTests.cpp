#include "pch.h"

#include "Alixer.h"

using namespace Alixer;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlixerTests
{
	TEST_CLASS(AlixerTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			AlixerApplication app(RenderEngine::OpenGl);

			const WindowConfig config("Alixer Test Window", 800, 600);

			const std::shared_ptr<AlixerWindow> window = app.CreateWindow(config);
			Assert::IsNotNull(window.get(), L"Window creation failed");
		}
	};
}
