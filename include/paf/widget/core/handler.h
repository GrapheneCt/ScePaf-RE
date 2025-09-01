/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_CORE_HANDLER_H
#define _VDSUITE_USER_PAF_WIDGET_CORE_HANDLER_H

#include <stdint.h>
#include <paf/std/stdcxx.h>
#include <paf/widget/types.h>
#include <paf/widget/core/event.h>
#include <paf/timer/timerlistener.h>

namespace paf {
	namespace ui {

		class EventCBListener : public EventListener
		{
		public:

			EventCBListener(HandlerCB func, void *data)
			{
				m_func = func;
				m_data = data;
			}

			virtual ~EventCBListener()
			{

			}

			virtual int32_t Do(int32_t type, Handler *self, Event *e)
			{
				SceInt32 ret;

				if (!m_killed)
				{
					if (m_func != NULL)
					{
						m_func(type, self, e, m_data);
					}
					ret = SCE_OK;
				}
				else
				{
					ret = 0x80AF4101;
				}
				return ret;
			}

			virtual HandlerCB GetFunc()
			{
				return m_func;
			}

		protected:

			void *m_data;
			HandlerCB m_func;
		};

		class TimeoutListener : public TimerListener
		{
		public:

			virtual ~TimeoutListener()
			{

			}

			virtual void OnFinish(void *data1, void *data2)
			{
				if (data1 != NULL)
				{
					Event ev(EV_TIMER, (Handler *)data2, Event::ROUTE_FORWARD, 0, 0, 0, 0, 0);
					ev.SetValue(m_id, 0);
					EventQueue *evq = (EventQueue *)data1;
					evq->PushBack(ev);
				}
				return;
			}

		protected:

			int32_t m_id;
		};

		class Handler
		{
		public:

			enum
			{
				CB_INPUT = 0x10000,
				CB_KEYCODE_PRESS = 0x10001,
				CB_KEYCODE_RELEASE = 0x10002,
				CB_KEYCODE_REPEAT = 0x10003,
				CB_POINT_PRESS = 0x10004,
				CB_POINT_RELEASE = 0x10005,
				CB_POINT_MOVE = 0x10006,
				CB_POINT_OVER = 0x10007,
				CB_POINT_OUT = 0x10008,
				CB_POINT_WHEEL = 0x10009,
				CB_POINT_ABORT = 0x1000A,
				CB_TOUCH_PRESS = 0x1000B,
				CB_TOUCH_RELEASE = 0x1000C,
				CB_TOUCH_MOVE = 0x1000D,
				CB_TOUCH_OVER = 0x1000E,
				CB_TOUCH_OUT = 0x1000F,
				CB_TOUCH_ABORT = 0x10010,
				CB_ANALOG_XYZ = 0x10011,
				CB_ANALOG_XYZ_NEUTRAL = 0x10012,
				CB_ENTRY_FORWARD = 0x1000,
			};

			enum
			{
				CB_GESTURE = 0x20000,
				CB_GESTURE_LONG_PRESS = 0x20001,
				CB_GESTURE_LONG_PRESS_REPEAT = 0x20002,
				CB_GESTURE_LONG_PRESS_REPEAT_END = 0x20003,
				CB_GESTURE_TAP = 0x20004,
				CB_GESTURE_MULTI_TAP = 0x20005,
				CB_GESTURE_FLICK = 0x20006,
				CB_GESTURE_DRAG_BEGIN = 0x20007,
				CB_GESTURE_DRAG_MOVE = 0x20008,
				CB_GESTURE_DRAG_END = 0x20009,
				CB_GESTURE_DRAG_REFRESH = 0x2000a,
				CB_GESTURE_DRAG_ABORT = 0x2000b,
				CB_GESTURE_DRAG_LEAK = 0x2000c,
				CB_GESTURE_PINCH_BEGIN = 0x2000d,
				CB_GESTURE_PINCH_MOVE = 0x2000e,
				CB_GESTURE_PINCH_END = 0x2000f,
				CB_GESTURE_PINCH_REFRESH = 0x20010,
				CB_GESTURE_PINCH_ABORT = 0x20011,
				CB_GESTURE_PINCH_LEAK = 0x20012,
				CB_MODAL_PRESS_OUTSIDE = 0x20013,
				CB_MODAL_RELEASE_OUTSIDE = 0x20014,
				CB_GESTURE_SINGLE_USER = 0x20100,
				CB_GESTURE_MULTI_USER = 0x20200,
			};

			enum
			{
				CB_FOCUS = 0x40000,
				CB_FOCUS_IN = 0x40001,
				CB_FOCUS_OUT = 0x40002,
				CB_FOCUS_UP = 0x40003,
				CB_FOCUS_DOWN = 0x40004,
				CB_FOCUS_LEFT = 0x40005,
				CB_FOCUS_RIGHT = 0x40006,
				CB_FOCUS_TABBACK = 0x40007,
				CB_FOCUS_TABFRONT = 0x40008,
				CB_FOCUS_SWITCH = 0x40009,
			};

			enum
			{
				CB_STATE = 0x100000,
				CB_STATE_INIT = 0x100001,
				CB_STATE_TERM = 0x100002,
				CB_STATE_PREPARE = 0x100003,
				CB_STATE_READY = 0x100004,
				CB_STATE_READY_CACHEIMAGE = 0x100005,
				CB_COMMAND = 0x100006,
			};

			enum
			{
				CB_TIMEOUT = 0x1000000,
				CB_TIMEOUT_END = 0x100FFFF,
				CB_INTERVAL = 0x2000000,
				CB_INTERVAL_END = 0x200FFFF,
			};

			Handler(uint32_t enable);

			virtual ~Handler();

			virtual int32_t HandlerProc(Event *e);
			virtual int32_t HandlePointFwEvent(Event *e);
			virtual int32_t HandleTouchFwEvent(Event *e);
			virtual int32_t HandleKeycodeEvent(Event *e);
			virtual int32_t HandleAnalogEvent(Event *e);
			virtual int32_t unkFun_1C();
			virtual int32_t unkFun_20();
			virtual int32_t HandlePointEvent(Event *e);
			virtual int32_t HandleTouchEvent(Event *e);
			virtual int32_t HandleGestureEvent(Event *e);
			virtual int32_t HandleFocusEvent(Event *e);
			virtual int32_t HandleFocusSwitchEvent(Event *e);
			virtual int32_t unkFun_38();
			virtual int32_t HandleStateEvent(Event *e);
			virtual int32_t HandleCommandEvent(Event *e);
			virtual int32_t HandleSystemEvent(Event *e);
			virtual int32_t HandleTimerEvent(Event *e);
			virtual void EnableFocusEvent(bool on_off);
			virtual int32_t EnableTouchRearEvent(bool on_off);
			virtual int32_t unkFun_54();
			virtual int32_t unkFun_58();
			virtual int32_t unkFun_5C();
			virtual int32_t DoEvent(int32_t type, Event *e);

			int32_t AddEventListener(int32_t type, EventListener *listener, bool del_prev = false);

			int32_t DeleteEventListener(int32_t type, EventListener *listener);

			int32_t DeleteEventCallback(int32_t type, HandlerCB func, void *data);

			void UpdateTimer();

			int32_t AddEventCallback(int32_t type, HandlerCB func, void *data = NULL)
			{
				EventCBListener *listener = new EventCBListener(func, data);
				return AddEventListener(type, listener, false);
			}

			int32_t SetEventCallback(int32_t type, HandlerCB func, void *data = NULL)
			{
				EventCBListener *listener = new EventCBListener(func, data);
				return AddEventListener(type, listener, true);
			}

			void DisableEvent(int32_t disable)
			{
				if (((m_event_enable & EV_FOCUS) != 0) && ((disable & EV_FOCUS) == 0))
				{
					EnableFocusEvent(false);
				}
				m_event_enable = m_event_enable & ~disable;
			}

			void EnableEvent(int32_t enable)
			{
				if (((m_event_enable & EV_FOCUS) == 0) && ((enable & EV_FOCUS) != 0)) {
					EnableFocusEvent(true);
				}
				m_event_enable = m_event_enable | enable;
			}

			int32_t SetEventQueue(EventQueue *eq)
			{
				m_event_queue = eq;
				return 0;
			}

			bool IsEnableEvent(uint32_t event_type) const
			{
				return ((m_event_enable & event_type) != 0);
			}

			int32_t SetTimeoutEvent(int32_t id, float timeout, HandlerCB func, void *data = NULL)
			{
				return SetTimerListener(CB_TIMEOUT | (id & 0xFFFF), timeout, new EventCBListener(func, data));
			}

			int32_t SetIntervalEvent(int32_t id, float interval, HandlerCB func, void *data = NULL)
			{
				return SetTimerListener(CB_INTERVAL | (id & 0xFFFF), interval, new EventCBListener(func, data));
			}

			int32_t KillIntervalEvent(int32_t id)
			{
				return KillTimer(CB_INTERVAL | (id & 0xFFFF));
			}

		protected:

			int32_t HandlePointEvent_core(Event *e, bool is_forward);

			int32_t HandleTouchEvent_core(Event *e, bool is_forward);

			int32_t SetTimerListener(int32_t id, float timeout, EventListener *listener);

			int32_t KillTimer(int32_t id);

			int32_t delete_timer_listener(map<int32_t, EventListenerList*> i, bool map_erase);

			EventQueue *m_event_queue;
			uint32_t m_event_enable;
			map<int32_t, EventListenerList*> m_map_e_listener;
			map<int32_t, TimeoutListener*> m_map_t_listener;
			int32_t m_unk_24;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_CORE_HANDLER_H */
