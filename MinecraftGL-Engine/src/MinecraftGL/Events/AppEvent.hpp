#pragma once

#include "mglpch.hpp"
#include "MinecraftGL/Events/Event.hpp"

namespace MinecraftGL
{
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int pWidth, unsigned int pHeight)
			: m_Width(pWidth), m_Height(pHeight) {}

		unsigned int GetWidth() const { return m_Width; }
		unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}