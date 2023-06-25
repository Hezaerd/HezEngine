#pragma once

#include "MinecraftGL/Core/Base.hpp"

#include "MinecraftGL/Core/Window.hpp"
#include "MinecraftGL/Events/AppEvent.hpp"

namespace MinecraftGL
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& pEvent);

	private:
		bool OnWindowClose(WindowCloseEvent& pEvent);
		bool OnWindowResize(WindowResizeEvent& pEvent);

	private:
		Scope<Window> m_Window;
		bool m_Running = true;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}