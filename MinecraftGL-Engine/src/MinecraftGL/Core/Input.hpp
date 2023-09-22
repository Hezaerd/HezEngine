#pragma once

#include "MinecraftGL/Core/KeyCodes.hpp"
#include "MinecraftGL/Core/MouseCode.hpp"

#include <MGLMaths/Vec/Vec2.hpp>

namespace MinecraftGL
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