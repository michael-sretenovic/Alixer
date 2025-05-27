#pragma once

#include "Core.h"
#include "Uuid.h"
#include "Events/Event.h"

namespace Alixer
{
	class ALIXER_API Layer
	{
	public:
		explicit Layer(const char* name);

		Layer(const Layer& layer);

		Layer(Layer&& layer) noexcept;

		virtual ~Layer();

		Layer& operator=(const Layer& layer);

		Layer& operator=(Layer&& layer) noexcept;

		bool operator==(const Layer& layer) const;

		bool operator!=(const Layer& layer) const;

		const char* GetName() const;

		const Uuid& GetId() const;

		bool IsEmpty() const;

		virtual void OnAttach();

		virtual void OnDetach();

		virtual void OnUpdate(MsDuration duration);

		virtual void OnEvent(Event& event);

		static const Layer& Empty();

		static Shared<Layer> SharedEmpty();

	private:
		static const char* _emptyName;

		Layer(const char* name, const Uuid& id);

		const char* _name;

		Uuid _uuid;
	};
}
