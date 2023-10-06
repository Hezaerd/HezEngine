#pragma once

#include "HezEngine/Core/Base.hpp"

#include "HezEngine/Core/Window.hpp"
#include "HezEngine/Events/AppEvent.hpp"
#include "HezEngine/Core/LayerStack.hpp"

#include "HezEngine/Core/Timestep.hpp"

namespace HezEngine
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& pEvent);

		void PushLayer(Layer* pLayer);
		void PushOverlay(Layer* pLayer);

		static Application& Get() { return *s_Instance; }
		Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& pEvent);
		bool OnWindowResize(WindowResizeEvent& pEvent);

		void CalculateMouseOffset();

	private:
		Scope<Window> m_Window;
		LayerStack m_LayerStack;

		bool m_Running = true;
		bool m_Minimized = false;
		float m_LastFrameTime;

		//TODO: Remove or make it in a new class
		//mouse input
		float m_LastX, m_LastY, m_MouseX, m_MouseY, m_OffsetX, m_OffsetY;
		bool m_FirstMouse = true;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}