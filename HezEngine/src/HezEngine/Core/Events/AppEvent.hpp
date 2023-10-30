#pragma once

#include "hezpch.hpp"
#include "HezEngine/Core/Events/Event.hpp"

namespace HezEngine
{
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int pWidth, unsigned int pHeight)
			: m_Width(pWidth), m_Height(pHeight)
		{
		}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

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

	class WindowMinimizeEvent : public Event
	{
	public:
		WindowMinimizeEvent(bool pMinimized)
			: m_Minimized(pMinimized)
		{
		}

		inline bool IsMinimized() const { return m_Minimized; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowMinimizeEvent: " << m_Minimized;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowMinimize)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		bool m_Minimized = false;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowCloseEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowClose)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
