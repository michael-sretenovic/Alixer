#include "pch.h"

#include <ranges>

#include "LayerList.h"
#include "Logger.h"

namespace Alixer
{
	LayerList::LayerList()
	{
		_layers.reserve(INITIAL_LAYER_COUNT);
	}

	LayerList::LayerList(const LayerList& layerList) { Copy(layerList); }

	LayerList::LayerList(LayerList&& layerList) noexcept { Copy(layerList); }

	LayerList::~LayerList() = default;

	bool LayerList::Add(const Shared<Layer>& layer)
	{
		Shared<Layer> existingLayer;
		if (TryGet(layer->GetId(), existingLayer))
		{
			AL_CORE_INFO("LayerList::Add: Layer with ID {0} already exists.", layer->GetId());
			return false;
		}

		if (TryGet(layer->GetName(), existingLayer))
		{
			AL_CORE_INFO("LayerList::Add: Layer with ID {0} already exists.", layer->GetId());
			return false;
		}

		_layers.emplace_back(layer);
		layer->OnAttach();

		return true;
	}

	bool LayerList::AddRange(const std::vector<Shared<Layer>>& layers)
	{
		size_t layerAddErrorCount = 0;
		for (const Shared<Layer>& layer : layers)
		{
			if (!Add(layer))
			{
				++layerAddErrorCount;
			}
		}
		return layerAddErrorCount > 0;
	}

	void LayerList::Clear()
	{
		for (const Shared<Layer>& layer : _layers)
		{
			layer->OnDetach();
		}

		_layers.clear();
	}

	size_t LayerList::IndexOf(const Uuid& id, const size_t startIndex = 0) const
	{
		if (startIndex >= _layers.size())
		{
			AL_CORE_TRACE("IndexOf::IndexOf: Start index out of range: {0}.", std::to_string(startIndex));
			return std::string::npos;
		}

		for (size_t i = startIndex; i < _layers.size(); ++i)
		{
			if (_layers[i]->GetId() == id)
			{
				return i;
			}
		}

		AL_CORE_TRACE("LayerList::IndexOf: Layer with ID '{0}' not found.", id);
		return std::string::npos;
	}

	size_t LayerList::IndexOf(const char* name, const size_t startIndex = 0) const
	{
		if (startIndex >= _layers.size())
		{
			AL_CORE_TRACE("IndexOf::IndexOf: Start index out of range: {0}.", std::to_string(startIndex));
			return std::string::npos;
		}

		for (size_t i = startIndex; i < _layers.size(); ++i)
		{
			if (strcmp(_layers[i]->GetName(), name) == 0)
			{
				return i;
			}
		}

		AL_CORE_TRACE("LayerList::IndexOf: Layer with name '{0}' not found.", name);
		return std::string::npos;
	}

	size_t LayerList::IndexOf(const Shared<Layer>& layer, const size_t startIndex = 0) const
	{
		if (startIndex >= _layers.size())
		{
			AL_CORE_TRACE("IndexOf::IndexOf: Start index out of range: {0}.", std::to_string(startIndex));
			return std::string::npos;
		}

		for (size_t i = startIndex; i < _layers.size(); ++i)
		{
			if (_layers[i] == layer)
			{
				return i;
			}
		}

		AL_CORE_TRACE("LayerList::IndexOf: Layer with ID '{0}' not found.", layer->GetId());
		return std::string::npos;
	}

	bool LayerList::Insert(const size_t index, const Shared<Layer>& layer)
	{
		if (index >= _layers.size())
		{
			AL_CORE_INFO("LayerList::Insert: Index out of range: {0}.", std::to_string(index));
			return false;
		}

		_layers.insert(_layers.begin() + static_cast<int64_t>(index), layer);
		return true;
	}

	size_t LayerList::LastIndexOf(const Uuid& id, size_t startIndex = std::string::npos)
	{
		if (startIndex >= _layers.size())
		{
			startIndex = _layers.size() - 1;
		}

		for (const std::shared_ptr<Layer>& layer : std::ranges::reverse_view(_layers))
		{
			if (layer->GetId() == id)
			{
				return startIndex;
			}
			--startIndex;
		}

		AL_CORE_TRACE("LayerList::LastIndexOf: Layer with ID '{0}' not found.", id);
		return std::string::npos;
	}

	size_t LayerList::LastIndexOf(const char* name, size_t startIndex = std::string::npos)
	{
		if (startIndex >= _layers.size())
		{
			startIndex = _layers.size() - 1;
		}

		for (const std::shared_ptr<Layer>& layer : std::ranges::reverse_view(_layers))
		{
			if (strcmp(layer->GetName(), name) == 0)
			{
				return startIndex;
			}
			--startIndex;
		}

		AL_CORE_TRACE("LayerList::LastIndexOf: Layer with name '{0}' not found.", name);
		return std::string::npos;
	}

	size_t LayerList::LastIndexOf(const Shared<Layer>& layer, size_t startIndex = std::string::npos)
	{
		if (startIndex >= _layers.size())
		{
			startIndex = _layers.size() - 1;
		}

		for (const std::shared_ptr<Layer>& searchLayer : std::ranges::reverse_view(_layers))
		{
			if (layer == searchLayer)
			{
				return startIndex;
			}
			--startIndex;
		}

		AL_CORE_TRACE("LayerList::LastIndexOf: Layer with ID '{0}' not found.", layer->GetId());
		return std::string::npos;
	}

	bool LayerList::TryGet(const Uuid& id, Shared<Layer>& layer) const
	{
		for (const Shared<Layer>& it : _layers)
		{
			if (it->GetId() == id)
			{
				layer = it;
				return true;
			}
		}

		AL_CORE_TRACE("LayerList::TryGet: Layer with ID '{0}' not found.", id);
		layer = Layer::SharedEmpty();
		return false;
	}

	bool LayerList::TryGet(const char* name, Shared<Layer>& layer) const
	{
		for (const Shared<Layer>& it : _layers)
		{
			if (strcmp(it->GetName(), name) == 0)
			{
				layer = it;
				return true;
			}
		}

		AL_CORE_TRACE("LayerList::TryGet: Layer with name '{0}' not found.", name);
		layer = Layer::SharedEmpty();
		return false;
	}

	bool LayerList::TryRemove(const Uuid& id, Shared<Layer>& layer)
	{
		int64_t index = 0;
		for (const Shared<Layer>& it : _layers)
		{
			if (it->GetId() == id)
			{
				layer = it;
				it->OnDetach();
				_layers.erase(_layers.begin() + index);
				return true;
			}
			++index;
		}

		AL_CORE_TRACE("LayerList::TryRemove: Layer with ID '{0}' not found.", id);
		layer = Layer::SharedEmpty();
		return false;
	}

	bool LayerList::TryRemove(const char* name, Shared<Layer>& layer)
	{
		int64_t index = 0;
		for (const Shared<Layer>& it : _layers)
		{
			if (strcmp(it->GetName(), name) == 0)
			{
				layer = it;
				it->OnDetach();
				_layers.erase(_layers.begin() + index);
				return true;
			}
			++index;
		}

		AL_CORE_TRACE("LayerList::TryRemove: Layer with name '{0}' not found.", name);
		layer = Layer::SharedEmpty();
		return false;
	}

	bool LayerList::TryRemove(Shared<Layer>& layer) { return TryRemove(layer->GetId(), layer); }

	bool LayerList::TryRemoveAt(const size_t index, Shared<Layer>& layer)
	{
		if (index >= _layers.size())
		{
			AL_CORE_INFO("LayerList::TryRemoveAt: Index out of range: {0}.", std::to_string(index));
			layer = Layer::SharedEmpty();
			return false;
		}

		layer = _layers[index];
		Remove(_layers.begin() + static_cast<int64_t>(index));

		return true;
	}

	std::vector<Shared<Layer>>::iterator LayerList::Begin() { return _layers.begin(); }

	std::vector<Shared<Layer>>::iterator LayerList::End() { return _layers.end(); }

	std::vector<Shared<Layer>>::reverse_iterator LayerList::RBegin() { return _layers.rbegin(); }

	std::vector<Shared<Layer>>::reverse_iterator LayerList::REnd() { return _layers.rend(); }

	std::vector<Shared<Layer>>::const_iterator LayerList::Begin() const { return _layers.begin(); }

	std::vector<Shared<Layer>>::const_iterator LayerList::End() const { return _layers.end(); }

	std::vector<Shared<Layer>>::const_reverse_iterator LayerList::RBegin() const { return _layers.rbegin(); }

	std::vector<Shared<Layer>>::const_reverse_iterator LayerList::REnd() const { return _layers.rend(); }

	void LayerList::Copy(const LayerList& layerList)
	{
		_layers.reserve(layerList._layers.size());
		for (const Shared<Layer>& layer : layerList._layers)
		{
			_layers.push_back(layer);
		}
	}

	void LayerList::Remove(const std::vector<Shared<Layer>>::iterator& it)
	{
		it->get()->OnDetach();
		_layers.erase(it);
	}
}
