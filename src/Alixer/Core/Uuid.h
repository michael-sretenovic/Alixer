#pragma once

#include <random>
#include <string>

#include "Core.h"
#include "spdlog/fmt/bundled/base.h"

namespace Alixer
{
	class ALIXER_API Uuid
	{
	public:
		Uuid();

		explicit Uuid(uint64_t uuid);

		Uuid(const Uuid& uuid);

		Uuid(Uuid&& uuid) noexcept;

		~Uuid();

		Uuid& operator=(const Uuid& uuid) noexcept;

		Uuid& operator=(Uuid&& uuid) noexcept;

		bool operator==(const Uuid& uuid) const noexcept;

		bool operator!=(const Uuid& uuid) const noexcept;

		// ReSharper disable once CppNonExplicitConversionOperator
		operator uint64_t() const noexcept;

		size_t Hash() const noexcept;

		static Uuid Generate();

		static const Uuid& Empty();

	private:
		static uint64_t GenerateNumber();

		friend struct std::hash<Uuid>;

		uint64_t _uuid;
	};
}

template <>
struct std::hash<Alixer::Uuid> {
	size_t operator()(const Alixer::Uuid& uuid) const noexcept {
		return uuid;
	}
};

template<>
struct fmt::formatter<Alixer::Uuid> : fmt::formatter<uint64_t> {
	// ReSharper disable once CppInconsistentNaming
	auto format(const Alixer::Uuid& uuid, format_context& ctx) const-> format_context::iterator
	{
		return fmt::formatter<uint64_t>::format(uuid, ctx);  // NOLINT(clang-diagnostic-undefined-func-template)
	}
};
