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

        static inline Application& Get() { return *s_Instance; }
        inline Window& GetWindow() { return *m_Window; }

    private:
        bool OnWindowClose(WindowCloseEvent& pEvent);
        bool OnWindowResize(WindowResizeEvent& pEvent);

        void CalculateDeltaTime();
        void CalculateMouseOffset();

    private:
        Scope<Window> m_Window;
        LayerStack m_LayerStack;

        bool m_Running = true;
        bool m_Minimized = false;

        //TODO: Remove or make it in a new class
        //mouse input
        float mLastX, mLastY, mMouseX, mMouseY, mOffsetX, mOffsetY;
        bool mFirstMouse = true;
        //Delta time
        std::chrono::steady_clock::time_point mLastTime;
        std::chrono::steady_clock::time_point mCurrentTime;
        float mDeltaTime;

        static Application* s_Instance;
    };

    Application* CreateApplication();
}