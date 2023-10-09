#include "hezpch.hpp"
#include "Platform/Windows/WindowsWindow.hpp"

#include <GLFW/glfw3.h>

namespace HezEngine
{
	float Time::GetTime()
	{
		return (float)glfwGetTime();
	}
}