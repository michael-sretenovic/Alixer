#include "pch.h"

#include "NullArgumentException.h"

namespace Alixer
{
	NullArgumentException::NullArgumentException(const char* message)
		: Exception(message) { }
}
