#pragma once

#include "HezEngine/Core/Base.hpp"

#include "HezEngine/Core/Window.hpp"
#include "HezEngine/Core/Events/AppEvent.hpp"
#include "HezEngine/Core/LayerStack.hpp"

#include "HezEngine/Core/Timestep.hpp"

#include "HezEngine/ImGui/ImGuiLayer.hpp"

namespace HezEngine
{
	struct ApplicationSpecification
	{
		std::string Name = "HezEngine";
		uint32_t WindowWidth = 1600;
		uint32_t WindowHeight = 900;

		bool Fullscreen = false;
		bool VSync = true;

		bool StartMaximized = true;
		bool Resizable = true;

		std::string WorkingDirectory;
	};

	class Application
	{
		using EventCallbackFn = std::function<void(Event&)>;
	public:
		Application(const ApplicationSpecification& pSpecification);
		virtual ~Application();

		void Run();
		void Close();

		void OnInit() {};
		void OnShutdown();
		void OnUpdate(Timestep pTs) {};

		void OnEvent(Event& pEvent);

		void PushLayer(Layer* pLayer);
		void PushOverlay(Layer* pLayer);
		void PopLayer(Layer* pLayer) {};
		void PopOverlay(Layer* pLayer) {};

		static inline Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

		float GetTime();
		Timestep GetTimestep() const { return m_LastFrameTime; }

	private:
		void ProcessEvents();

		bool OnWindowClose(WindowCloseEvent& pEvent);
		bool OnWindowMinimize(WindowMinimizeEvent& pEvent);
		bool OnWindowResize(WindowResizeEvent& pEvent);

	private:
		ApplicationSpecification m_Specification;
		Scope<Window> m_Window;

		LayerStack m_LayerStack;

		bool m_Running = true;
		bool m_Minimized = false;

		Timestep m_FrameTime;
		Timestep m_TimeStep;
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;

	protected:
		inline static bool s_IsRuntime = false;
	};

	// To be defined in CLIENT
	Application* CreateApplication(int argc, char** argv);
}
