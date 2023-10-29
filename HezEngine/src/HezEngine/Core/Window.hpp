#pragma once

#include "HezEngine/Core/Base.hpp"
#include "HezEngine/Core/Events/Event.hpp"

// Note(Hezaerd):	This ensures that the first inclusion of GLFW defines
//					Vulkan exclusive procs before include guards trip.
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

namespace HezEngine
{
	struct WindowSpecification
	{
		std::string Title = "HezEngine";
		uint32_t Width = 1600;
		uint32_t Height = 900;

		bool VSync = true;
		bool Fullscreen = false;
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		Window(const WindowSpecification& pSpecification);
		~Window();

		void Init();
		void ProcessEvents();
		void SwapBuffers();

		inline uint32_t GetWidth() { return m_Data.Width; }
		inline uint32_t GetHeight() { return m_Data.Height; }

		inline std::pair<uint32_t, uint32_t> GetSize() const { return { m_Data.Width, m_Data.Height }; }
		std::pair<float, float> GetWindowPos() const;
		void SetWindowPos(int pX, int pY) const;

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& pCallback) { m_Data.EventCallback = pCallback; }
		void SetVSync(bool pEnabled);
		bool IsVSync() const;
		void SetResizable(bool pResizable) const;

		void Maximize() const;
		void Minimize() const;
		void CenterWindow() const;

		inline const std::string& GetTitle() const { return m_Data.Title; }
		void SetTitle(const std::string& pTitle) const;

		inline void* GetNativeWindow() const { return m_Window; }

	public:
		static Window* Create(const WindowSpecification& pSpecification = WindowSpecification());

	private:
		void Shutdown();

	private:
		struct WindowData
		{
			std::string Title;
			uint32_t Width, Height;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
		WindowSpecification m_Specification;

	private:
		GLFWwindow* m_Window;
		float m_LastFrameTime = 0.0f;
	};
}
