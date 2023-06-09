#pragma once

// #include "GameEngine/Core.h"
#include "src/GameEngine/Core.h"

#include <string>
#include <functional>

namespace GameEngine {

	enum class EventType 
	{
		None = 0, 
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender, 
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0, 
		EventCategoryApplication = Bit(0),
		EventCategoryInput = Bit(1),
		EventCategoryKeyboard = Bit(2),
		EventCategoryMouse = Bit(3),
		EventCategoryMouseButton = Bit(4),
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; } \
															 virtual EventType GetEventType() const override { return GetStaticType(); }\
															 virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class HAZEL_API Event 
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T> 
		using EventFn = std::function<bool>(T&) > ;
	public:
		EventDispatcher(Event& event): m_Event(event){}
		template<typename T>
		bool Dispatch(EventFn<T> fn)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = fn(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) 
	{
		return os << e.ToString();
	}

}
