#pragma once

#include "MinecraftGL/Core/Base.hpp"
#include "MinecraftGL/Events/Event.hpp"

#include "GLFW/glfw3.h"
#include <glad/glad.h>

namespace MinecraftGL
{
	struct WindowData
	{
		using EventCallbackFn = std::function<void(Event&)>;

		std::string Title;
		uint32_t Width;
		uint32_t Height;

		bool VSync = true;

		EventCallbackFn EventCallback;

		WindowData(const std::string& pTitle = "MinecraftGL", uint32_t pWidth = 1600, uint32_t pHeight = 900)
			: Title(pTitle), Width(pWidth), Height(pHeight)
		{
		}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		Window(const WindowData& pData);
		~Window();

		void OnUpdate();

		unsigned int GetWidth() const { return m_Data.Width; }
		unsigned int GetHeight() const { return m_Data.Height; }

		void SetEventCallback(const EventCallbackFn& pCallback) { m_Data.EventCallback = pCallback; }
		void ProcessMousePos(float& pXpos, float& pYpos);

		void SetVSync(bool pEnabled);
		bool IsVSync() const;

		void* GetNativeWindow() const { return m_Window; }

		static Scope<Window> Create(const WindowData& pData = WindowData());

		float GetAspectRatio() const;

	private:
		void Init(const WindowData& pData);
		void Shutdown();

	public:
		GLFWwindow* m_Window;
		WindowData m_Data;
	};

	class Time
	{
	public:
		static float GetTime();
	};
}