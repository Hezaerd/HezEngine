#include "mglpch.hpp"
#include "MinecraftGL/Core/Application.hpp"
#include "MinecraftGL/Core/Log.hpp"

#include "MGLMaths/MGLMaths.hpp"
#include "MinecraftGL/Renderer/Shader.hpp"

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
        MGL_CORE_INFO("Application destroyed.");
    }

    void Application::OnEvent(Event& pEvent)
    {
        EventDispatcher eventHandler(pEvent);
        eventHandler.Dispatch<WindowCloseEvent>(MGL_BIND_EVENT_FN(Application::OnWindowClose));
        eventHandler.Dispatch<WindowResizeEvent>(MGL_BIND_EVENT_FN(Application::OnWindowResize));

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
    }

    void Application::PushOverlay(Layer* pLayer)
    {
        m_LayerStack.PushOverlay(pLayer);
    }

    void Application::Run()
    {
        //current dir = MinecraftGL-Game
        Shader shader("basicShader", "shaders/vertex.vert", "shaders/fragment.frag");

        while (m_Running)
        {
            if (!m_Minimized)
            {
                for (Layer* layer : m_LayerStack)
                    layer->OnUpdate();

                glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
            }

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& /*pEvent*/)
    {
        MGL_CORE_INFO("Window closed.");

        m_Running = false;
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent& /*pEvent*/)
    {
        return true;
    }
}