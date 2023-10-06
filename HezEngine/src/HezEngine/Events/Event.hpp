#pragma once

#include "HezEngine/Core/Base.hpp"
#include <functional>

namespace HezEngine
{
	enum class EventType
	{
		None = 0,
		// Window events
		WindowClose, WindowResize,
		// Keyboard events
		KeyPressed, KeyReleased, KeyTyped,
		// Mouse events
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	// Base class for all events
	class Event
	{
	public:
		virtual ~Event() = default;

		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory pCategory)
		{
			return GetCategoryFlags() & pCategory;
		}
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& pEvent)
			: m_Event(pEvent)
		{
		}

		template<typename T, typename F>
		bool Dispatch(const F& pFunc)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = pFunc(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& pOs, const Event& pEvent)
	{
		return pOs << pEvent.ToString();
	}
}