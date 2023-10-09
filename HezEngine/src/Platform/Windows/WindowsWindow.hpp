#pragma once

#include "HezEngine/Core/Window.hpp"

#include <GLFW/glfw3.h>

namespace HezEngine
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& pProps);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline uint32_t GetWidth() const override { return m_Data.Width; }
		inline uint32_t GetHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& pCallback) override { m_Data.EventCallback = pCallback; }
		void SetVSync(bool pEnabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const override { return m_Window; }

	private:
		virtual void Init(const WindowProps& pProps);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			uint32_t Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}