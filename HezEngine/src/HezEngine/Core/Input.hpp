#pragma once

#include "HezEngine/Core/KeyCodes.hpp"
#include "HezEngine/Core/MouseCode.hpp"

#include <glm/glm.hpp>

namespace HezEngine
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);
		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
