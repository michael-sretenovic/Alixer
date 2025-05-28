#pragma once

#include "Core.h"
#include "Layer.h"

namespace Alixer
{
	class ALIXER_API LayerList final
	{
	public:
		LayerList();

		LayerList(const LayerList& layerList);

		LayerList(LayerList&& layerList) noexcept;

		~LayerList();

		LayerList& operator=(const LayerList& layerList) = delete;

		LayerList& operator=(LayerList&& layerList) noexcept = delete;

		bool Add(const Shared<Layer>& layer);

		bool AddRange(const std::vector<Shared<Layer>>& layers);

		void Clear();

		size_t IndexOf(const Uuid& id, size_t startIndex) const;

		size_t IndexOf(const char* name, size_t startIndex) const;

		size_t IndexOf(const Shared<Layer>& layer, size_t startIndex) const;

		bool Insert(size_t index, const Shared<Layer>& layer);

		size_t LastIndexOf(const Uuid& id, size_t startIndex);

		size_t LastIndexOf(const char* name, size_t startIndex);

		size_t LastIndexOf(const Shared<Layer>& layer, size_t startIndex);

		bool TryGet(const Uuid& id, Shared<Layer>& layer) const;

		bool TryGet(const char* name, Shared<Layer>& layer) const;

		bool TryRemove(const Uuid& id, Shared<Layer>& layer);

		bool TryRemove(const char* name, Shared<Layer>& layer);

		bool TryRemove(Shared<Layer>& layer);

		bool TryRemoveAt(size_t index, Shared<Layer>& layer);

		std::vector<Shared<Layer>>::iterator Begin();

		std::vector<Shared<Layer>>::iterator End();

		std::vector<Shared<Layer>>::reverse_iterator RBegin();

		std::vector<Shared<Layer>>::reverse_iterator REnd();

		std::vector<Shared<Layer>>::const_iterator Begin() const;

		std::vector<Shared<Layer>>::const_iterator End() const;

		std::vector<Shared<Layer>>::const_reverse_iterator RBegin() const;

		std::vector<Shared<Layer>>::const_reverse_iterator REnd() const;

	private:
		static constexpr size_t INITIAL_LAYER_COUNT = 16;

		void Copy(const LayerList& layerList);

		void Remove(const std::vector<Shared<Layer>>::iterator& it);

		std::vector<Shared<Layer>> _layers;
	};
}
