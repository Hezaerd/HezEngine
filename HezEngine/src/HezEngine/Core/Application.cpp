#include "hezpch.hpp"
#include "HezEngine/Core/Application.hpp"
#include "HezEngine/Core/Log.hpp"

#include <HezMaths/HezMaths.hpp>

namespace HezEngine
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		HEZ_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = Window::Create();
		m_Window->SetEventCallback(HEZ_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& pEvent)
	{
		EventDispatcher eventHandler(pEvent);
		eventHandler.Dispatch<WindowCloseEvent>(HEZ_BIND_EVENT_FN(Application::OnWindowClose));
		eventHandler.Dispatch<WindowResizeEvent>(HEZ_BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(pEvent);
			if (pEvent.Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* pLayer)
	{
		m_LayerStack.PushLayer(pLayer);
		pLayer->OnAttach();
	}

	void Application::PushOverlay(Layer* pLayer)
	{
		m_LayerStack.PushOverlay(pLayer);
		pLayer->OnAttach();
	}

	void Application::Run()
	{
		while (m_Running)
		{
			float time = Time::GetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			CalculateMouseOffset();

			if (!m_Minimized)
			{
				for (Layer* layer : m_LayerStack)
					layer->OnUpdate(timestep);

				m_Window->OnUpdate();
			}
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& /*pEvent*/)
	{
		HEZ_CORE_INFO("Window closed.");

		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& pEvent)
	{
		if (pEvent.GetWidth() == 0 || pEvent.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		return false;
	}

	void Application::CalculateMouseOffset()
	{
		m_Window->ProcessMousePos(m_MouseX, m_MouseY);

		if (m_FirstMouse)
		{
			m_LastX = m_MouseX;
			m_LastY = m_MouseY;
			m_FirstMouse = false;
		}

		m_OffsetX = m_MouseX - m_LastX;
		m_OffsetY = m_LastY - m_MouseY;

		m_LastX = m_MouseX;
		m_LastY = m_MouseY;
	}
}