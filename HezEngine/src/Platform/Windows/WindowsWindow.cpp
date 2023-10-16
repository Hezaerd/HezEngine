#include "hezpch.hpp"
#include "Platform/Windows/WindowsWindow.hpp"

#include "HezEngine/Core/Input.hpp"

#include "HezEngine/Events/AppEvent.hpp"
#include "HezEngine/Events/KeyEvent.hpp"
#include "HezEngine/Events/MouseEvent.hpp"

namespace HezEngine
{
	static uint8_t s_GLFWWindowCount = 0;

	static void GLFWErrorCallback(int pError, const char* pDescription)
	{
		HEZ_CORE_ERROR("GLFW Error ({0}): {1}", pError, pDescription);
	}

	WindowsWindow::WindowsWindow(const WindowProps& pProps)
	{
		Init(pProps);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		HEZ_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (s_GLFWWindowCount == 0)
		{
			int success = glfwInit();
			HEZ_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		++s_GLFWWindowCount;

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW callbacks

		// Window resize
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* pWindow, int pWidth, int pHeight)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);
				data.Width = pWidth;
				data.Height = pHeight;

				WindowResizeEvent event(pWidth, pHeight);
				data.EventCallback(event);
			});

		// Window close
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* pWindow)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);
				WindowCloseEvent event;
				data.EventCallback(event);
			});

		// Key press
		glfwSetKeyCallback(m_Window, [](GLFWwindow* pWindow, int pKey, int /*pScancode*/, int pAction, int /*pMods*/)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

				switch (pAction)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(pKey, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(pKey);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(pKey, 1);
					data.EventCallback(event);
					break;
				}
				}
			});

		// Char input
		glfwSetCharCallback(m_Window, [](GLFWwindow* pWindow, unsigned int pKey)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

				KeyTypedEvent event(pKey);
				data.EventCallback(event);
			});

		// Mouse button press
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* pWindow, int pButton, int pAction, int /*pMods*/)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

				switch (pAction)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(pButton);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(pButton);
					data.EventCallback(event);
					break;
				}
				}
			});

		// Mouse scroll
		glfwSetScrollCallback(m_Window, [](GLFWwindow* pWindow, double pXOffset, double pYOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

				MouseScrolledEvent event((float)pXOffset, (float)pYOffset);
				data.EventCallback(event);
			});

		// Mouse move
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* pWindow, double pXPos, double pYPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

				MouseMovedEvent event((float)pXPos, (float)pYPos);
				data.EventCallback(event);
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
		--s_GLFWWindowCount;

		if (s_GLFWWindowCount == 0)
			glfwTerminate();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
	}

	void WindowsWindow::SetVSync(bool pEnabled)
	{
		//if (pEnabled)
		//	glfwSwapInterval(1);
		//else
		//	glfwSwapInterval(0);

		m_Data.VSync = pEnabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}
