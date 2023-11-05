#include "hezpch.hpp"
#include "HezEngine/Core/Application.hpp"
#include "HezEngine/Core/Debug/Debug.hpp"

#include "HezEngine/Core/Input.hpp"

#include <filesystem>

extern bool g_ApplicationRunning;

namespace HezEngine
{
#define BIND_EVENT_FN(fn) std::bind(&Application::##fn, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSpecification& pSpecification)
		: m_Specification(pSpecification)
	{
		HEZ_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		if (!pSpecification.WorkingDirectory.empty())
			std::filesystem::current_path(pSpecification.WorkingDirectory);

		WindowSpecification windowSpec;
		windowSpec.Title = pSpecification.Name;
		windowSpec.Width = pSpecification.WindowWidth;
		windowSpec.Height = pSpecification.WindowHeight;
		windowSpec.Fullscreen = pSpecification.Fullscreen;
		windowSpec.VSync = pSpecification.VSync;
		m_Window = Window::Create(windowSpec);
		m_Window->Init();
		m_Window->SetEventCallback([this](Event& e) {OnEvent(e); });

		/*if (pSpecification.StartMaximized)
			m_Window->Maximize();*/
			//else
		m_Window->CenterWindow();
		m_Window->SetResizable(pSpecification.Resizable);
	}

	Application::~Application()
	{
		for (Layer* layer : m_LayerStack)
		{
			layer->OnDetach();
			delete layer;
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
		OnInit();

		while (m_Running)
		{
			float time = GetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized)
			{
				{
					for (Layer* layer : m_LayerStack)
						layer->OnUpdate(timestep);
				}
			}
		}

		OnShutdown();
	}

	void Application::Close()
	{
		m_Running = false;
	}

	void Application::OnShutdown()
	{
		g_ApplicationRunning = false;
	}

	void Application::ProcessEvents()
	{
		Input::TransitionPressedKeys();
		Input::TransitionPressedButtons();

		m_Window->ProcessEvents();
	}

	void Application::OnEvent(Event& pEvent)
	{
		HEZ_CORE_INFO_TAG("Events", pEvent.ToString());

		EventDispatcher eventHandler(pEvent);
		eventHandler.Dispatch<WindowResizeEvent>([this](WindowResizeEvent& e) {return OnWindowResize(e); });
		eventHandler.Dispatch<WindowMinimizeEvent>([this](WindowMinimizeEvent& e) {return OnWindowMinimize(e); });
		eventHandler.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& e) {return OnWindowClose(e); });

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(pEvent);
			if (pEvent.Handled)
				break;
		}

		if (pEvent.Handled)
			return;

		for (auto& eventCallback : m_EventCallbacks)
		{
			eventCallback(pEvent);

			if (pEvent.Handled)
				break;
		}
	}

	bool Application::OnWindowResize(WindowResizeEvent& pEvent)
	{
		if (pEvent.GetWidth() == 0 || pEvent.GetHeight() == 0)
		{
			return false;
		}

		return false;
	}

	bool Application::OnWindowMinimize(WindowMinimizeEvent& pEvent)
	{
		m_Minimized = pEvent.IsMinimized();
		return false;
	}

	bool Application::OnWindowClose(WindowCloseEvent& /*pEvent*/)
	{
		HEZ_CORE_INFO("Window closed.");

		m_Running = false;
		return true;
	}

	float Application::GetTime()
	{
		return (float)glfwGetTime();
	}
}
