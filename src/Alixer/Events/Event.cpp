#include "pch.h"

#include "Event.h"

namespace Alixer
{
	constexpr uint16_t CATEGORY_BITS = 0b1111;

	constexpr uint16_t EVENT_BITS = 0b1111111111110000;

	Event::Event(const EventType eventType) : _eventType(eventType) { }

	EventType Event::GetCategory() const
	{
		const uint16_t value = static_cast<uint16_t>(_eventType) & CATEGORY_BITS;

		uint8_t total = 0;
		for (uint8_t i = 0; i < 4; ++i)
		{
			if ((value >> i) & 1)
			{
				++total;
			}
		}

		// If multiple bits are set, then make it an Application level event.
		return (total >= 2) ? EventType::Application : static_cast<EventType>(value);
	}

	EventType Event::GetEvents() const
	{
		const uint16_t value = static_cast<uint16_t>(_eventType) & EVENT_BITS;
		return static_cast<EventType>(value);
	}

	bool Event::HasEventType(EventType type) const
	{
		const uint16_t upperValue = static_cast<uint16_t>(_eventType) & EVENT_BITS;
		const uint16_t upperType = static_cast<uint16_t>(type) & EVENT_BITS;

		return (upperValue & upperType) == upperType;
	}
}
