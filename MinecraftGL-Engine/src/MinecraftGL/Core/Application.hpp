#pragma once

#include "MinecraftGL/Core/Base.hpp"

#include "MinecraftGL/Core/Window.hpp"
#include "MinecraftGL/Events/AppEvent.hpp"
#include "MinecraftGL/Core/LayerStack.hpp"

namespace MinecraftGL
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

    private:
        bool OnWindowClose(WindowCloseEvent& pEvent);
        bool OnWindowResize(WindowResizeEvent& pEvent);

    private:
        Scope<Window> m_Window;
        LayerStack m_LayerStack;

        bool m_Running = true;
        bool m_Minimized = false;

        static Application* s_Instance;
    };

    Application* CreateApplication();
}