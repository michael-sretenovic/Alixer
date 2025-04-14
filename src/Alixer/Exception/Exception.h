#pragma once

#include <exception>

namespace Alixer
{
	class Exception : public std::exception
	{
	public:
		explicit Exception(const char* message);

		const char* GetMessage() const;
	};
}
