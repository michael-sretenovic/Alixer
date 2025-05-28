#include "pch.h"

#include <random>

#include "Uuid.h"

namespace Alixer
{
	Uuid::Uuid() : _uuid(GenerateNumber()) { }

	Uuid::Uuid(const uint64_t uuid) : _uuid(uuid) {}

	Uuid::Uuid(const Uuid& uuid) = default;

	Uuid::Uuid(Uuid&& uuid) noexcept = default;

	Uuid::~Uuid() = default;

	Uuid& Uuid::operator=(const Uuid& uuid) noexcept = default;

	Uuid& Uuid::operator=(Uuid&& uuid) noexcept = default;

	bool Uuid::operator==(const Uuid& uuid) const noexcept { return _uuid == uuid._uuid; }

	bool Uuid::operator!=(const Uuid& uuid) const noexcept { return _uuid != uuid._uuid; }

	Uuid::operator uint64_t() const noexcept { return _uuid; }

	size_t Uuid::Hash() const noexcept { return std::hash<uint64_t>()(_uuid); }

	Uuid Uuid::Generate() { return Uuid(GenerateNumber()); }

	const Uuid& Uuid::Empty()
	{
		static const Uuid empty(0);
		return empty;
	}

	uint64_t Uuid::GenerateNumber()
	{
		static std::random_device randomDevice;
		static std::mt19937_64 generator(randomDevice());
		static std::uniform_int_distribution<uint64_t> distribution(0, UINT64_MAX);

		return distribution(generator);
	}
}
