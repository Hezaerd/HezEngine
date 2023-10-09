#pragma once

#include "HezEngine/Core/Base.hpp"
#include "HezEngine/Events/Event.hpp"

#include "GLFW/glfw3.h"
#include <glad/glad.h>

namespace HezEngine
{
	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& pTitle = "HezEngine", uint32_t pWidth = 1600, uint32_t pHeight = 900)
			: Title(pTitle), Width(pWidth), Height(pHeight)
		{
		}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& pCallback) = 0;
		virtual void SetVSync(bool pEnabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Scope<Window> Create(const WindowProps& pProps = WindowProps());
	};

	class Time
	{
	public:
		static float GetTime();
	};
}