#include "pch.h"

#include "Exception.h"

namespace Alixer
{
	Exception::Exception(const char* message) : std::exception(message) {}

	const char* Exception::GetMessage() const { return what(); }
}
