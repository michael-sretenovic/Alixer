#include "pch.h"

#include <random>

#include "Uuid.h"

namespace Alixer
{
	Uuid::Uuid() : _uuid(s_distribution(s_generator)) { }

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

	Uuid Uuid::Generate() { return Uuid(s_distribution(s_generator)); }

	const Uuid& Uuid::Empty()
	{
		static const Uuid empty(0);
		return empty;
	}

	std::random_device Uuid::s_randomDevice;

	std::mt19937_64 Uuid::s_generator(s_randomDevice());

	std::uniform_int_distribution<uint64_t> Uuid::s_distribution(0, UINT64_MAX);
}
