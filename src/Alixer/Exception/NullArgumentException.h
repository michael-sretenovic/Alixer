#pragma once

#include "Exception.h"

namespace Alixer
{
	class NullArgumentException final : public Exception
	{
	public:
		explicit NullArgumentException(const char* message);
	};
}
