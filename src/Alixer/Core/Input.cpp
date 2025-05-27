#include "pch.h"

#include "Input.h"

namespace Alixer
{
	float Input::GetMouseX() const { return GetMousePosition().x; }

	float Input::GetMouseY() const { return GetMousePosition().y; }
}
