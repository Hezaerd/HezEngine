#include "hezpch.hpp"
#include "HezEngine/Core/Window.hpp"

namespace HezEngine
{
	static void GLFWErrorCallback(int error, const char* description)
	{
		HEZ_CORE_ERROR_TAG("GLFW", "GLFW Error ({0}): {1}", error, description);
	}

	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowSpecification& pSpecification)
	{
		return new Window(pSpecification);
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
	}
}
