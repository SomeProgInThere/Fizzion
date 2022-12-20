#pragma once

#include "Event.h"

namespace Fizzion
{
	class FIZZION_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << "x" << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_GROUP(EventGroupApplication)
	
	private:
		unsigned int m_Width, m_Height;
	};

	class FIZZION_API WindowCloseEvent : public Event
	{
		WindowCloseEvent() {}
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_GROUP(EventGroupApplication)
	};

	// Maybe useless from here ?
	class FIZZION_API AppTickEvent : public Event
	{
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_GROUP(EventGroupApplication)
	};

	class FIZZION_API AppUpdateEvent : public Event
	{
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_GROUP(EventGroupApplication)
	};

	class FIZZION_API AppRenderEvent : public Event
	{
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_GROUP(EventGroupApplication)
	};
}
