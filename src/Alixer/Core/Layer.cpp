#include "pch.h"

#include "Layer.h"

namespace Alixer
{
	Layer::Layer(const char* name) : _name(name), _uuid(Uuid::Generate()) { }

	Layer::Layer(const Layer& layer) = default;

	Layer::Layer(Layer&& layer) noexcept = default;

	Layer::~Layer() = default;

	Layer& Layer::operator=(const Layer& layer) = default;

	Layer& Layer::operator=(Layer&& layer) noexcept = default;

	bool Layer::operator==(const Layer& layer) const
	{
		if (_uuid != layer.GetId())
		{
			return false;
		}

		if (_name == layer.GetName())
		{
			return true;
		}

		return strcmp(_name, layer.GetName()) == 0;
	}

	bool Layer::operator!=(const Layer& layer) const { return !(*this == layer); }

	const char* Layer::GetName() const { return _name; }

	const Uuid& Layer::GetId() const { return _uuid; }

	bool Layer::IsEmpty() const { return *this == Empty(); }

	void Layer::OnAttach() { /* To be overridden by client. */ }

	void Layer::OnDetach() { /* To be overridden by client. */ }

	void Layer::OnUpdate(MsDuration duration) { /* To be overridden by client. */ }

	void Layer::OnEvent(Event& event) { /* To be overridden by client. */ }

	const char* Layer::_emptyName = const_cast<char*>("<<EMPTY>>");

	const Layer& Layer::Empty()
	{
		static const Layer EMPTY_LAYER(_emptyName, Uuid::Empty());
		return EMPTY_LAYER;
	}

	Shared<Layer> Layer::SharedEmpty()
	{
		static const Shared<Layer> EMPTY_LAYER = CreateShared<Layer>(Empty());
		return EMPTY_LAYER;
	}

	Layer::Layer(const char* name, const Uuid& id) : _name(name), _uuid(id) { }
}
