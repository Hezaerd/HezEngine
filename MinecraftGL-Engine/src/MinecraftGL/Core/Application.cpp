#include "mglpch.hpp"
#include "MinecraftGL/Core/Application.hpp"
#include "MinecraftGL/Core/Log.hpp"

#include "MGLMaths/MGLMaths.hpp"
#include "MinecraftGL/Renderer/Shader.hpp"
#include "MinecraftGL/Scene/Model.hpp"
#include "MinecraftGL/Scene/Camera.hpp"
#include "MinecraftGL/Renderer/Renderer.hpp"

namespace MinecraftGL
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		MGL_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = Window::Create();
		RendererOpenGL::Init();
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
	}

	void Application::Run()
	{
		//current dir = MinecraftGL-Game
		Shader shader("basicShader", "shaders/vertex.vert", "shaders/fragment.frag");
		Model model("assets/models/Cube.obj", MGLMaths::Vec3f(0, 0, -3), MGLMaths::Vec3f(0), MGLMaths::Vec3f(1));
		Camera cam(MGLMaths::Vec3f(0.0f, 0.0f, 3.0f), MGLMaths::Vec3f::Up);

		while (m_Running)
		{
			CalculateDeltaTime();
			CalculateMouseOffset();

			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glClear(GL_DEPTH_BUFFER_BIT);

			if (!m_Minimized)
			{
				//TODO: Change to Draw Func and pass it the object to draw ??? (maybe)
				//TODO: Check using renderdoc if the model is drawn correctly
				cam.ProcessMouseInput(mDeltaTime, mOffsetX, mOffsetY);
				{
					shader.Bind();
					//send MVP
					MGLMaths::Mat4f MVP = model.getModelMatrix() * cam.GetViewMatrix() * cam.GetProjectionMatrix();

					shader.SetMat4("MVP", MVP);
					//send model
					shader.SetMat4("model", model.getModelMatrix());
					//send normal matrix
					MGLMaths::Mat4f normalMatrix = model.getModelMatrix();

					model.Draw();
					shader.Unbind();
				}

				m_Window->OnUpdate();
			}
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

	void Application::CalculateDeltaTime()
	{
		mCurrentTime = std::chrono::steady_clock::now();
		mDeltaTime = std::chrono::duration<float>(mCurrentTime - mLastTime).count();
		mLastTime = mCurrentTime;
	}

	void Application::CalculateMouseOffset()
	{
		m_Window->ProcessMousePos(mMouseX, mMouseY);

		if (mFirstMouse)
		{
			mLastX = mMouseX;
			mLastY = mMouseY;
			mFirstMouse = false;
		}

		mOffsetX = mMouseX - mLastX;
		mOffsetY = mLastY - mMouseY;

		mLastX = mMouseX;
		mLastY = mMouseY;
	}
}