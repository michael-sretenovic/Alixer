#include "TestLayer.h"

namespace AlixerTests
{
	TestLayer::TestLayer(const char* name) : Layer(name),
		_onAttachCalledCount(0), _onDetachCalledCount(0), _onUpdateCalledCount(0), _onEventCalledCount() { }

	TestLayer::TestLayer(const Layer& layer) : Layer(layer),
		_onAttachCalledCount(0), _onDetachCalledCount(0), _onUpdateCalledCount(0), _onEventCalledCount() { }

	TestLayer::TestLayer(Layer&& layer) : Layer(std::move(layer)),
		_onAttachCalledCount(0), _onDetachCalledCount(0), _onUpdateCalledCount(0), _onEventCalledCount() { }

	void TestLayer::OnAttach() { ++_onAttachCalledCount; }

	void TestLayer::OnDetach() { ++_onDetachCalledCount; }

	void TestLayer::OnUpdate(MsDuration duration) { ++_onUpdateCalledCount; }

	void TestLayer::OnEvent(Event& event) { ++_onEventCalledCount; }

	uint8_t TestLayer::GetOnAttachCalledCount() const { return _onAttachCalledCount; }

	uint8_t TestLayer::GetOnDetachCalledCount() const { return _onDetachCalledCount; }

	uint8_t TestLayer::GetOnUpdateCalledCount() const { return _onUpdateCalledCount; }

	uint8_t TestLayer::GetOnEventCalledCount() const { return _onEventCalledCount; }
}
