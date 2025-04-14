#include "pch.h"

#include "InvalidOperationException.h"

namespace Alixer
{
	InvalidOperationException::InvalidOperationException(const char* message)
		: Exception(message) { }
}
