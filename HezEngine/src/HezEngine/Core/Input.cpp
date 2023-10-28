#include "hezpch.hpp"
#include "HezEngine/Core/Input.hpp"

#include "HezEngine/Core/Window.hpp"
#include "HezEngine/Core/Application.hpp"

#include <GLFW/glfw3.h>

namespace HezEngine
{
	bool Input::IsKeyPressed(KeyCode pKey)
	{
		return s_KeyData.find(pKey) != s_KeyData.end() && s_KeyData[pKey].State == KeyState::Pressed;
	}

	bool Input::IsKeyHeld(KeyCode pKey)
	{
		return s_KeyData.find(pKey) != s_KeyData.end() && s_KeyData[pKey].State == KeyState::Held;
	}

	bool Input::IsKeyDown(KeyCode pKey)
	{
		auto& window = static_cast<Window&>(Application::Get().GetWindow());
		auto state = glfwGetKey(static_cast<GLFWwindow*>(window.GetNativeWindow()), static_cast<int32_t>(pKey));

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsKeyReleased(KeyCode pKey)
	{
		return s_KeyData.find(pKey) != s_KeyData.end() && s_KeyData[pKey].State == KeyState::Released;
	}

	bool Input::IsMouseButtonPressed(MouseButton pButton)
	{
		return s_MouseData.find(pButton) != s_MouseData.end() && s_MouseData[pButton].State == KeyState::Pressed;
	}

	bool Input::IsMouseButtonHeld(MouseButton pButton)
	{
		return s_MouseData.find(pButton) != s_MouseData.end() && s_MouseData[pButton].State == KeyState::Held;
	}

	bool Input::IsMouseButtonDown(MouseButton pButton)
	{
		auto& window = static_cast<Window&>(Application::Get().GetWindow());
		auto state = glfwGetMouseButton(static_cast<GLFWwindow*>(window.GetNativeWindow()), static_cast<int32_t>(pButton));

		return state == GLFW_PRESS;
	}

	bool Input::IsMouseButtonReleased(MouseButton pButton)
	{
		return s_MouseData.find(pButton) != s_MouseData.end() && s_MouseData[pButton].State == KeyState::Released;
	}

	float Input::GetMouseX()
	{
		auto [x, y] = GetMousePosition();
		return (float)x;
	}

	float Input::GetMouseY()
	{
		auto [x, y] = GetMousePosition();
		return (float)y;
	}

	std::pair<float, float> Input::GetMousePosition()
	{
		auto& window = static_cast<Window&>(Application::Get().GetWindow());

		double x, y;
		glfwGetCursorPos(static_cast<GLFWwindow*>(window.GetNativeWindow()), &x, &y);
		return { (float)x, (float)y };
	}

	void Input::SetCursorMode(CursorMode pMode)
	{
		auto& window = static_cast<Window&>(Application::Get().GetWindow());
		glfwSetInputMode(static_cast<GLFWwindow*>(window.GetNativeWindow()), GLFW_CURSOR, GLFW_CURSOR_NORMAL + (int)pMode);
	}

	CursorMode Input::GetCursorMode()
	{
		auto& window = static_cast<Window&>(Application::Get().GetWindow());
		return (CursorMode)(glfwGetInputMode(static_cast<GLFWwindow*>(window.GetNativeWindow()), GLFW_CURSOR) - GLFW_CURSOR_NORMAL);
	}

	void Input::TransitionPressedKeys()
	{
		for (const auto& [key, keyData] : s_KeyData)
		{
			if (keyData.State == KeyState::Pressed)
				UpdateKeyState(key, KeyState::Held);
		}
	}

	void Input::TransitionPressedButtons()
	{
		for (const auto& [button, buttonData] : s_MouseData)
		{
			if (buttonData.State == KeyState::Pressed)
				UpdateButtonState(button, KeyState::Held);
		}
	}

	void Input::UpdateKeyState(KeyCode pKey, KeyState pState)
	{
		auto& keyData = s_KeyData[pKey];
		keyData.Key = pKey;
		keyData.OldState = keyData.State;
		keyData.State = pState;
	}

	void Input::UpdateButtonState(MouseButton pButton, KeyState pState)
	{
		auto& mouseData = s_MouseData[pButton];
		mouseData.Button = pButton;
		mouseData.OldState = mouseData.State;
		mouseData.State = pState;
	}

	void Input::ClearReleasedKeys()
	{
		for (const auto& [key, keyData] : s_KeyData)
		{
			if (keyData.State == KeyState::Released)
				UpdateKeyState(key, KeyState::None);
		}

		for (const auto& [button, buttonData] : s_MouseData)
		{
			if (buttonData.State == KeyState::Released)
				UpdateButtonState(button, KeyState::None);
		}
	}
}
