#pragma once

#include "HezEngine/Core/KeyCodes.hpp"
#include "HezEngine/Core/MouseCode.hpp"

#include <HezMaths/Vec/Vec2.hpp>

namespace HezEngine
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);
		static bool IsMouseButtonPressed(MouseCode button);
		static MGLMaths::Vec2f GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}