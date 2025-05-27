#pragma once

#include "Core/Layer.h"

namespace AlixerTests
{
	using namespace Alixer;

	class TestLayer final : public Layer
	{
	public:
		explicit TestLayer(const char* name);

		explicit TestLayer(const Layer& layer);

		explicit TestLayer(Layer&& layer);

		void OnAttach() override;

		void OnDetach() override;

		void OnUpdate(MsDuration duration) override;

		void OnEvent(Event& event) override;

		uint8_t GetOnAttachCalledCount() const;

		uint8_t GetOnDetachCalledCount() const;

		uint8_t GetOnUpdateCalledCount() const;

		uint8_t GetOnEventCalledCount() const;

	private:
		uint8_t _onAttachCalledCount;

		uint8_t _onDetachCalledCount;

		uint8_t _onUpdateCalledCount;

		uint8_t _onEventCalledCount;
	};
}
