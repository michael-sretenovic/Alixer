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
		friend struct std::hash<Uuid>;

		uint64_t _uuid;

		static std::random_device s_randomDevice;

		static std::mt19937_64 s_generator;

		static std::uniform_int_distribution<uint64_t> s_distribution;
	};
}

template <>
struct std::hash<Alixer::Uuid> {
	size_t operator()(const Alixer::Uuid& uuid) const noexcept {
		return uuid.Hash();
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
