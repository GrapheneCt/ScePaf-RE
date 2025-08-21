/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_CORE_EVENT_H
#define _VDSUITE_USER_PAF_WIDGET_CORE_EVENT_H

#include <stdint.h>
#include <paf/std/stdcxx.h>

namespace paf {
	namespace ui {

		class Handler;
		class Event;

		typedef void(*HandlerCB)(int32_t type, Handler *self, Event *e, void *userdata);

		class Event
		{
		public:

			enum
			{
				ROUTE_FORWARD = 0x10000,
				ROUTE_BACK = 0x20000,
				ROUTE_TERM = 0x40000,
				MODE_DISPATCH = 0x100000,
				MODE_BROADCAST = 0x200000,
				MODE_DIRECT = 0x400000,
				MODE_DO = 0x800000,
				STATE_CONSUME = 0x1000000,
				STATE_IGNORE = 0x2000000,
				DETAIL_GRABBED = 0x10000000,
				DETAIL_SUPPLY = 0x20000000,
				DETAIL_HOOKED = 0x80000000,
			};

			Event();

			Event(uint32_t _type, Handler *_target, uint32_t _route, uint32_t _detail, int32_t d0 = 0, int32_t d1 = 0, int32_t d2 = 0, int32_t d3 = 0);

			Event(uint32_t _type, uint32_t _mode, uint32_t _route, uint32_t _detail, int32_t d0 = 0, int32_t d1 = 0, int32_t d2 = 0, int32_t d3 = 0);

			virtual ~Event()
			{

			}

			void Forward()
			{
				type = type & 0xfff0ffff | ROUTE_FORWARD;
			}

			void Back()
			{
				type = type & 0xfff0ffff | ROUTE_BACK;
			}

			void Consume()
			{
				type = type & 0xf0ffffff | STATE_CONSUME;
			}

			void Direct()
			{
				type = type & 0xff0fffff | MODE_DIRECT;
			}

			void Do(uint32_t _type, Handler *w)
			{
				type = type & 0xff0fffff | MODE_DO;
				dotype = _type;
				target = w;
			}

			uint32_t GetDoType()
			{
				return dotype;
			}

			uint32_t GetMode() const
			{
				return type & 0xffff0000;
			}

			Handler *GetTarget()
			{
				return target;
			}

			void Grabbed()
			{
				type = type & 0xfffffff | 0x10000000;
			}

			void SetDetail(uint32_t _detail)
			{
				detail = _detail;
			}

			void SetRoute(int32_t route)
			{
				type = type & 0xfff0ffff | route;
			}

			void SetTarget(Handler *w)
			{
				if (w != NULL)
				{
					Direct();
					target = w;
				}
			}

			void SetType(uint32_t _type)
			{
				type = type & 0xffff0000 | _type & 0xffff;
			}

			int32_t SetValue4(int32_t val, int32_t num)
			{
				if ((num < 0) || (3 < num))
				{
					return -1;
				}
				data[num] = val;
				return 0;
			}

			int32_t SetValue(int32_t val, int32_t num)
			{
				return  SetValue4(val, num);
			}

			void Term()
			{
				type = type & 0xfff0ffff | 0x40000;
			}

			Event& operator=(Event const& rhs)
			{
				type = rhs.type;
				detail = rhs.detail;
				dotype = rhs.dotype;
				target = rhs.target;
				for (int i = 0; i < 4; i++)
				{
					data[i] = rhs.data[i];
				}
				return *this;
			}

			uint32_t GetType() const
			{
				return type & 0xffff;
			}

			int32_t GetValue(int32_t num) const
			{
				return GetValue4(num);
			}

			int32_t GetValue4(int32_t num) const
			{
				if ((num < 0) || (3 < num))
				{
					return -1;
				}
				return data[num];
			}

			uint32_t GetDetail() const
			{
				return detail;
			}

			bool IsForward() const
			{
				return ((type & ROUTE_FORWARD) != 0);
			}

			bool IsBack() const
			{
				return ((type & ROUTE_BACK) != 0);
			}

			bool IsTerm() const
			{
				return ((type & ROUTE_TERM) != 0);
			}

			bool IsDispatch() const
			{
				return ((type & MODE_DISPATCH) != 0);
			}

			bool IsBroadcast() const
			{
				return ((this->type & MODE_BROADCAST) != 0);
			}

			bool IsDirect() const
			{
				return ((type & MODE_DIRECT) != 0);
			}

			bool IsDo() const
			{
				return ((type & MODE_DO) != 0);
			}

			bool IsConsume() const
			{
				return ((type & STATE_CONSUME) != 0);
			}

			bool IsIgnore() const
			{
				return ((type & STATE_IGNORE) != 0);
			}

			bool Comp(Event const& e, uint32_t mode, uint32_t mask) const;

		private:

			uint32_t type;
			uint32_t detail;
			uint32_t dotype;
			int32_t data[4];
			Handler *target;
		};

		class EventListener
		{
		public:

			EventListener() : m_killed(false), m_autodelete(true)
			{

			}

			virtual ~EventListener()
			{

			}

			virtual int32_t Do(int32_t type, Handler *self, Event *e) = 0;

			virtual HandlerCB GetFunc()
			{
				return NULL;
			}

			void SetAutoDelete(bool value)
			{
				m_autodelete = value;
			}

			bool IsAutoDelete()
			{
				return m_autodelete;
			}

			void Kill()
			{
				m_killed = true;
			}

			bool UpdateKill()
			{
				if (!m_killed)
				{
					return false;
				}
				delete this;
				return true;
			}

		protected:

			bool m_killed : 1;
			bool m_autodelete : 1;
		};

		class EventListenerList
		{
		public:

			EventListenerList() : m_killed(false), m_on_exec(0)
			{

			}

			virtual ~EventListenerList()
			{
				m_on_exec = 0;
				DelAll();
				for (list<EventListener*>::iterator it = m_list.begin(); it != m_list.end(); ++it)
				{
					delete *it;
				}
			}

			bool UpdateKill();

			int32_t DelAll();

			int32_t Do(int32_t type, Handler *self, Event *e);

			EventListener *Find(EventListener *listener);

			int32_t Add(EventListener *listener);

			int32_t AddFront(EventListener *listener);

			int32_t Del(EventListener *listener);

			EventListener *Find(HandlerCB func);

			bool IsOnExec()
			{
				return (m_on_exec != 0);
			}

			uint32_t Size()
			{
				return m_list.size();
			}

		protected:

			list<EventListener*> m_list;
			bool m_killed;
			int32_t m_on_exec;
		};

		class EventQueue
		{
		public:

			EventQueue(int32_t size);

			virtual ~EventQueue()
			{

			}

			int32_t Add(Event const& e, int32_t num);

			int32_t Get(Event& e, int32_t num);

			int32_t PushBack(Event const& e);

			int32_t PushFront(Event const& e);

			int32_t PopFront(Event& e);

			int32_t Remove(int32_t num);

			int32_t Cancel(Event const& e, uint32_t mode);

			int32_t Clear();

		protected:

			vector<Event> m_queue;
			thread::RMutex m_mutex;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_CORE_EVENT_H */
