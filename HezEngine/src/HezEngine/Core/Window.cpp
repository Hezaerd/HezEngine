#include "hezpch.hpp"
#include "HezEngine/Core/Window.hpp"

#ifdef HEZ_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.hpp"
#endif

namespace HezEngine
{
	Scope<Window> Window::Create(const WindowProps& pProps)
	{
#ifdef HEZ_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(pProps);
#else
		HEZ_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}