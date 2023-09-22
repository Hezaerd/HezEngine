#include "mglpch.hpp"

#include "MinecraftGL/Core/Window.hpp"

#include "MinecraftGL/Events/Events.hpp"

namespace MinecraftGL
{
	float Time::GetTime()
	{
		return static_cast<float>(glfwGetTime());
	}

	static void GLFWErrorCallback(int pError, const char* pDescription)
	{
		MGL_CORE_ERROR("GLFW Error ({0}): {1}", pError, pDescription);
	}

	Scope<Window> Window::Create(const WindowData& pData)
	{
		return CreateScope<Window>(pData);
	}

	float Window::GetAspectRatio() const
	{
		return (float)m_Data.Width / (float)m_Data.Height;
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
		int success;

		m_Data.Title = pData.Title;
		m_Data.Width = pData.Width;
		m_Data.Height = pData.Height;

		MGL_CORE_INFO("Creating window {0} ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);

		success = glfwInit();
		MGL_CORE_ASSERT(success, "Failed to initialize GLFW!");
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
		glfwSetErrorCallback(GLFWErrorCallback);

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_Window);
		success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MGL_CORE_ASSERT(success, "Failed to initialize Glad!");
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

		glfwSetKeyCallback(m_Window, [](GLFWwindow* pWindow, int key, int /*scancode*/, int action, int /*mods*/)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event((KeyCode)key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event((KeyCode)key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event((KeyCode)key, 1);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* pWindow, int button, int action, int /*mods*/)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event((MouseCode)button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event((MouseCode)button);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* pWindow, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* pWindow, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

				MouseMovedEvent event((float)xPos, (float)yPos);
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

	void Window::ProcessMousePos(float& pXpos, float& pYpos)
	{
		double xpos, ypos;
		glfwGetCursorPos(m_Window, &xpos, &ypos);
		pXpos = (float)xpos;
		pYpos = (float)ypos;
	}

	//void Window::ProcessKeyboardInput()
	//{
	//}

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