#pragma once

#include "Core.h"
#include "KeyCode.h"
#include "MouseButton.h"
#include "glm/glm.hpp"

namespace Alixer
{
	class ALIXER_API Input
	{
	public:
		Input() = default;

		virtual ~Input() = default;

		virtual bool IsKeyPressed(KeyCode key) const = 0;

		virtual bool IsMouseButtonPressed(MouseButton button) const = 0;

		virtual glm::vec2 GetMousePosition() const = 0;

		float GetMouseX() const;

		float GetMouseY() const;
	};
}
