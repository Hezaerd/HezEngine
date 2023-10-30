#pragma once

#include "HezEngine/Core/Events/Event.hpp"

#include <sstream>

namespace HezEngine
{
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int pWidth, unsigned int pHeight)
		{
			m_PrevWidth = m_Width;
			m_PrevHeight = m_Height;

			m_Width = pWidth;
			m_Height = pHeight;
		}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		inline unsigned int GetPreviousWidth() const { return m_PrevWidth; }
		inline unsigned int GetPreviousHeight() const { return m_PrevHeight; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			ss << " (Previous: " << m_PrevWidth << ", " << m_PrevHeight << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width, m_Height;
		unsigned int m_PrevWidth, m_PrevHeight = 0;
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
