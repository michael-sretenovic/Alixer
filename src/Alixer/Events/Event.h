#pragma once

#include "Core.h"
#include "EventType.h"

namespace Alixer
{
	class ALIXER_API Event
	{
	public:
		explicit Event(EventType eventType);

		Event(const Event&) = default;

		Event(Event&&) = default;

		virtual ~Event() = default;

		Event& operator=(const Event&) = default;

		Event& operator=(Event&&) = default;

		EventType GetCategory() const;

		EventType GetEvents() const;

		bool HasEventType(EventType type) const;

	private:
		EventType _eventType;
	};
}
