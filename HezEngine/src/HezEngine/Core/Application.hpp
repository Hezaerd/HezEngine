#pragma once

#include "HezEngine/Core/Base.hpp"

#include "HezEngine/Core/Window.hpp"
#include "HezEngine/Core/Events/AppEvent.hpp"
#include "HezEngine/Core/LayerStack.hpp"

#include "HezEngine/Core/Timestep.hpp"

#include "HezEngine/ImGui/ImGuiLayer.hpp"

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

		float GetTime();

	private:
		bool OnWindowClose(WindowCloseEvent& pEvent);
		bool OnWindowResize(WindowResizeEvent& pEvent);

	private:
		Window* m_Window;
		LayerStack m_LayerStack;

		//ImGuiLayer* m_ImGuiLayer;

		bool m_Running = true;
		bool m_Minimized = false;
		float m_LastFrameTime;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
