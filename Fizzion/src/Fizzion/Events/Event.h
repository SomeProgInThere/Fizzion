#pragma once

#include "Fizzion/Core.h"

#include <string>
#include <functional>

namespace Fizzion
{
	/* Currently the events are executed as interrupt */

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventGroup
	{
		None = 0,
		EventGroupApplication = BIT(0),
		EventGroupInput = BIT(1),
		EventGroupKeyboard = BIT(2),
		EventGroupMouse = BIT(3),
		EventGroupMouseButton = BIT(4),
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								  virtual EventType GetEventType() const override { return GetStaticType(); }\
								  virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_GROUP(group) virtual int GetGroupFlags() const override { return group; }

	class FIZZION_API Event
	{
		friend class EventDispatcher;
	public:

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetGroupFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInGroup(EventGroup group)
		{
			return GetGroupFlags() & group;
		}

	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFunc = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event) : m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFunc<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

    private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) { return os << e.ToString(); }
}
