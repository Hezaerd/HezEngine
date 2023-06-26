#include "mglpch.hpp"
#include "MinecraftGL/Core/Application.hpp"
#include "MinecraftGL/Core/Log.hpp"

namespace MinecraftGL
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		MGL_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = Window::Create();
		m_Window->SetEventCallback(MGL_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& pEvent)
	{
		EventDispatcher eventHandler(pEvent);
		eventHandler.Dispatch<WindowCloseEvent>(MGL_BIND_EVENT_FN(Application::OnWindowClose));
		eventHandler.Dispatch<WindowResizeEvent>(MGL_BIND_EVENT_FN(Application::OnWindowResize));

		//MGL_CORE_TRACE(pEvent.ToString());
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& pEvent)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& pEvent)
	{
		return true;
	}
}