#include "mglpch.hpp"

#include "MinecraftGL/Core/Window.hpp"
#include "MinecraftGL/Events/AppEvent.hpp"

namespace MinecraftGL
{
	static void GLFWErrorCallback(int pError, const char* pDescription)
	{
		MGL_CORE_ERROR("GLFW Error ({0}): {1}", pError, pDescription);
	}

	Window::Window(const WindowData& pData)
	{
		Init(pData);
	}

	Window::~Window()
	{
		Shutdown();
	}

	void Window::Init(const WindowData& pData)
	{
		m_Data.Title = pData.Title;
		m_Data.Width = pData.Width;
		m_Data.Height = pData.Height;

		MGL_CORE_INFO("Creating window {0} ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);

		int success = glfwInit();
		MGL_CORE_ASSERT(success, "Failed to initialize GLFW!");
		glfwSetErrorCallback(GLFWErrorCallback);

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* pWindow, int pWidth, int pHeight)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);
				data.Width = pWidth;
				data.Height = pHeight;

				WindowResizeEvent event(pWidth, pHeight);
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* pWindow)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);
				WindowCloseEvent event;
				data.EventCallback(event);
			});
	}

	void Window::Shutdown()
	{
		glfwDestroyWindow(m_Window);

		glfwTerminate();
	}

	void Window::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Window::SetVSync(bool pEnabled)
	{
		if (pEnabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = pEnabled;
	}

	bool Window::IsVSync() const
	{
		return m_Data.VSync;
	}
}