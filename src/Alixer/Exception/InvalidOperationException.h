#pragma once

#include "Exception.h"

namespace Alixer
{
	class InvalidOperationException final : public Exception
	{
	public:
		explicit InvalidOperationException(const char* message);
	};
}
