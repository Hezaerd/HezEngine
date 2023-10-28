#pragma once

#include "HezEngine/Core/KeyCodes.hpp"

#include <map>

namespace HezEngine
{
	struct KeyData
	{
		KeyCode Key;
		KeyState State = KeyState::None;
		KeyState OldState = KeyState::None;
	};

	struct ButtonData
	{
		MouseButton Button;
		KeyState State = KeyState::None;
		KeyState OldState = KeyState::None;
	};

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode pKey);
		static bool IsKeyHeld(KeyCode pKey);
		static bool IsKeyDown(KeyCode pKey);
		static bool IsKeyReleased(KeyCode pKey);

		static bool IsMouseButtonPressed(MouseButton pButton);
		static bool IsMouseButtonHeld(MouseButton pButton);
		static bool IsMouseButtonDown(MouseButton pButton);
		static bool IsMouseButtonReleased(MouseButton pButton);
		static float GetMouseX();
		static float GetMouseY();
		static std::pair<float, float> GetMousePosition();

		static void SetCursorMode(CursorMode pMode);
		static CursorMode GetCursorMode();

		///////////////////////////
		// Internal Use ONLY	 //
		///////////////////////////

		static void TransitionPressedKeys();
		static void TransitionPressedButtons();
		static void UpdateKeyState(KeyCode pKey, KeyState pState);
		static void UpdateButtonState(MouseButton pButton, KeyState pState);
		static void ClearReleasedKeys();

	private:
		static inline std::map<KeyCode, KeyData> s_KeyData;
		static inline std::map<MouseButton, ButtonData> s_MouseData;
	};
}
