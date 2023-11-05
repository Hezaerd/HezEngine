#include "hezpch.hpp"
#include "HezEngine/Core/Window.hpp"

#include "HezEngine/Core/Events/AppEvent.hpp"
#include "HezEngine/Core/Events/KeyEvent.hpp"
#include "HezEngine/Core/Events/MouseEvent.hpp"
#include "HezEngine/Core/Input.hpp"

#include "HezEngine/Renderer/Renderer.hpp"

namespace HezEngine
{
	static void GLFWErrorCallback(int error, const char* description)
	{
		HEZ_CORE_ERROR_TAG("GLFW", "GLFW Error ({0}): {1}", error, description);
	}

	static bool s_GLFWInitialized = false;

	Scope<Window> Window::Create(const WindowSpecification& pSpecification)
	{
		return CreateScope<Window>(pSpecification);
	}

	Window::Window(const WindowSpecification& pSpecification)
		: m_Specification(pSpecification)
	{
	}

	Window::~Window()
	{
		Shutdown();
	}

	void Window::Init()
	{
		m_Data.Title = m_Specification.Title;
		m_Data.Width = m_Specification.Width;
		m_Data.Height = m_Specification.Height;

		HEZ_CORE_INFO_TAG("GLFW", "Creating window {0} ({1}, {2})", m_Specification.Title, m_Specification.Width, m_Specification.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			HEZ_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialized = true;
		}

		if (Renderer::GetAPI() == RendererAPI::API::Vulkan)
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		if (m_Specification.Fullscreen)
		{
			GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

			glfwWindowHint(GLFW_DECORATED, false);
			glfwWindowHint(GLFW_RED_BITS, mode->redBits);
			glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
			glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
			glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

			m_Window = glfwCreateWindow(mode->width, mode->height, m_Data.Title.c_str(), primaryMonitor, nullptr);
		}
		else
		{
			m_Window = glfwCreateWindow((int)m_Specification.Width, (int)m_Specification.Height, m_Data.Title.c_str(), nullptr, nullptr);
		}

		bool isRawMouseMotionSupported = glfwRawMouseMotionSupported();
		if (isRawMouseMotionSupported)
			glfwSetInputMode(m_Window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
		else
			HEZ_CORE_WARN_TAG("Platform", "Raw mouse motion is not supported.");

		///////////////////////
		// GLFW Callbacks	//
		//////////////////////

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* pWindow, int pWidth, int pHeight)
		{
			HEZ_CORE_TRACE_TAG("GLFW Events", "Window resized to {0}x{1}", pWidth, pHeight);

			//auto& data = *((WindowData*)glfwGetWindowUserPointer(pWindow));
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(pWindow);

			WindowResizeEvent event((uint32_t)pWidth, (uint32_t)pHeight);
			data.EventCallback(event);
			data.Width = pWidth;
			data.Height = pHeight;
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* pWindow)
		{
			HEZ_CORE_TRACE_TAG("GLFW Events", "Window closed");

			auto& data = *((WindowData*)glfwGetWindowUserPointer(pWindow));

			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* pWindow, int pKey, int pScancode, int pAction, int pMods)
		{
			HEZ_CORE_TRACE_TAG("GLFW Events", "Key {0} ({1}) {2}", pKey, pScancode, pAction);

			auto& data = *((WindowData*)glfwGetWindowUserPointer(pWindow));

			switch (pAction)
			{
				case GLFW_PRESS:
				{
					Input::UpdateKeyState((KeyCode)pKey, KeyState::Pressed);
					KeyPressedEvent event((KeyCode)pKey, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					Input::UpdateKeyState((KeyCode)pKey, KeyState::Released);
					KeyReleasedEvent event((KeyCode)pKey);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					Input::UpdateKeyState((KeyCode)pKey, KeyState::Held);
					KeyPressedEvent event((KeyCode)pKey, 1);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* pWindow, uint32_t pCodepoint)
		{
			auto& data = *((WindowData*)glfwGetWindowUserPointer(pWindow));

			KeyTypedEvent event((KeyCode)pCodepoint);
			data.EventCallback(event);
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* pWindow, int pButton, int pAction, int pMods)
		{
			HEZ_CORE_TRACE_TAG("GLFW Events", "Mouse button {0} {1}", pButton, pAction);

			auto& data = *((WindowData*)glfwGetWindowUserPointer(pWindow));

			switch (pAction)
			{
				case GLFW_PRESS:
				{
					Input::UpdateButtonState((MouseButton)pButton, KeyState::Pressed);
					MouseButtonPressedEvent event((MouseButton)pButton);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					Input::UpdateButtonState((MouseButton)pButton, KeyState::Released);
					MouseButtonReleasedEvent event((MouseButton)pButton);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* pWindow, double pXOffset, double pYOffset)
		{
			auto& data = *((WindowData*)glfwGetWindowUserPointer(pWindow));

			MouseScrolledEvent event((float)pXOffset, (float)pYOffset);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* pWindow, double pX, double pY)
		{
			auto& data = *((WindowData*)glfwGetWindowUserPointer(pWindow));
			MouseMovedEvent event((float)pX, (float)pY);
			data.EventCallback(event);
		});

		// Update window size to actual size
		{
			int width, height;
			glfwGetWindowSize(m_Window, &width, &height);
			m_Data.Width = width;
			m_Data.Height = height;
		}
	}

	void Window::Shutdown()
	{
		glfwTerminate();
		s_GLFWInitialized = false;
	}

	std::pair<float, float> Window::GetWindowPos() const
	{
		int x, y;
		glfwGetWindowPos(m_Window, &x, &y);
		return { (float)x, (float)y };
	}

	void Window::SetWindowPos(int pX, int pY) const
	{
		HEZ_CORE_ASSERT(m_Window, "Window is null!");

		glfwSetWindowPos(m_Window, pX, pY);
	}

	void Window::ProcessEvents()
	{
		glfwPollEvents();
	}

	void Window::SwapBuffers()
	{
		// TODO: Replace this with the SwapChain swapBuffers function
		// once Vulkan renderer is implemented
		glfwSwapBuffers(m_Window);
	}

	void Window::SetVSync(bool pEnabled)
	{
		m_Specification.VSync = pEnabled;

		// TODO: Replace this and queue an event to set the VSync in the renderer using the swapchain
		// once Vulkan renderer is implemented

		if (pEnabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	bool Window::IsVSync() const
	{
		return m_Specification.VSync;
	}

	void Window::SetResizable(bool pResizable) const
	{
		HEZ_CORE_ASSERT(m_Window, "Window is null!");

		glfwSetWindowAttrib(m_Window, GLFW_RESIZABLE, pResizable ? GLFW_TRUE : GLFW_FALSE);
	}

	void Window::Maximize() const
	{
		HEZ_CORE_ASSERT(m_Window, "Window is null!");

		glfwMaximizeWindow(m_Window);
	}

	void Window::Minimize() const
	{
		HEZ_CORE_ASSERT(m_Window, "Window is null!");

		glfwIconifyWindow(m_Window);
	}

	void Window::CenterWindow() const
	{
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

		int x = (mode->width / 2) - (m_Data.Width / 2);
		int y = (mode->height / 2) - (m_Data.Height / 2);

		SetWindowPos(x, y);
	}

	void Window::SetTitle(const std::string& pTitle) const
	{
		glfwSetWindowTitle(m_Window, pTitle.c_str());
	}
}
