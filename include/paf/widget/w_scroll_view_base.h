/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_SCROLL_VIEW_BASE_H
#define _VDSUITE_USER_PAF_WIDGET_W_SCROLL_VIEW_BASE_H

#include <paf/widget/core/widget.h>
#include <paf/widget/factory.h>
#include <paf/timer/timer.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryScrollViewBase;

namespace paf {

	namespace ui {

		class ScrollBar;
		class ScrollViewScrollBarController;
		class ScrollViewTimer;

		class ScrollViewSnapPoint
		{
		public:

			ScrollViewSnapPoint(math::v2 const& pos) : m_pos(pos)
			{

			}

		protected:

			math::v2 m_pos;
		};

		class ScrollViewBaseStyleParam : public WidgetStyleParam
		{
		public:
			static const char *ParamName();
			ScrollViewBaseStyleParam();
			virtual const char *GetParamName() const;
			virtual ~ScrollViewBaseStyleParam();
			virtual int32_t Create(int32_t mode);
			virtual int32_t SetEach(Widget *widget);
			virtual int32_t GetEach(Widget *widget);

		private:
			unsigned char unk_0x60[0x108];

			__declspec (dllimport) static const char m_param_name[];
		};

		class ScrollViewBase : public Widget
		{
		public:

			enum
			{
				OBJ_BG = 0,
				OBJ_SCROLL_VIEW_BASE_END = 1
			};

			enum
			{
				CB_SCROLL_VIEW_BASE_BEGIN = 0x10000000,
				CB_SCROLL_VIEW_BASE_FOCUS_CHANGED = 0x10000001,
				CB_SCROLL_VIEW_BASE_SNAPPED = 0x10000002,
				CB_SCROLL_VIEW_BASE_PREFER_SNAPPED = 0x10000003,
				CB_SCROLL_VIEW_BASE_SNAP_POINT_DETECTED = 0x10000004,
				CB_SCROLL_VIEW_BASE_END = 0x10000005
			};

			enum MoveDir
			{
				MoveDir_None = 0,
				MoveDir_X = 1,
				MoveDir_Y = 2,
				MoveDir_XY = 3
			};

			class Snap : public ScrollViewSnapPoint
			{
			public:

				Snap(ScrollViewSnapPoint const& snap_point);

			protected:

				int32_t m_id;
			};

			static void CBScrollBarChanged(int32_t type, Handler *h, Event *e, void *userdata);

			static const char *TypeName();

			ScrollViewBase(Widget *_parent, CreateParam *_param);

			virtual ~ScrollViewBase();

			virtual void SetVerticalScrollBar(ScrollBar *scroll_bar);
			virtual void SetHorizontalScrollBar(ScrollBar *scroll_bar);
			virtual void SetScrollBarController(ScrollViewScrollBarController *controller);
			virtual int32_t AddSnapPoint(ScrollViewSnapPoint const& snap_point);
			virtual void DelSnapPoint(int32_t snap_id);
			virtual void UpdateSnapPoint(int32_t snap_id, ScrollViewSnapPoint const& snap_point);
			virtual void SetSnapPower(float snap_power);
			virtual void DoSnap(int32_t snap_id, Timer *timer);
			virtual void SetPreferredSnapPoint(int32_t snap_id, float time, int32_t func);
			virtual int32_t unkFun_194();
			virtual void OnViewLayoutUpdated(bool is_dirty);
			virtual void OnPartsLayoutUpdated(bool is_dirty);
			virtual void TrackBegin(Event *e);
			virtual void TrackEnd(Event *e);
			virtual bool TrackPress(Event *e);
			virtual int32_t unkFun_1AC();
			virtual bool TrackRelease(Event *e);
			virtual bool TrackGrab(Event *e);
			virtual bool TrackMove(Event *e);
			virtual bool TrackDrag(Event *e);
			virtual int32_t unkFun_1C0();
			virtual int32_t unkFun_1C4();
			virtual int32_t unkFun_1C8();
			virtual int32_t unkFun_1CC();
			virtual int32_t unkFun_1D0();
			virtual int32_t unkFun_1D4();
			virtual int32_t unkFun_1D8();
			virtual int32_t unkFun_1DC();
			virtual int32_t unkFun_1E0();
			virtual int32_t unkFun_1E4();
			virtual int32_t unkFun_1E8();
			virtual int32_t unkFun_1EC();
			virtual int32_t unkFun_1F0();
			virtual int32_t unkFun_1F4();
			virtual bool MochiBegin(Event *e);
			virtual bool MochiMove(Event *e);
			virtual int32_t unkFun_200();
			virtual int32_t unkFun_204();
			virtual int32_t unkFun_208();
			virtual int32_t unkFun_20C();
			virtual int32_t unkFun_210();
			virtual int32_t unkFun_214();
			virtual int32_t unkFun_218();
			virtual int32_t unkFun_21C();
			virtual int32_t unkFun_220();
			virtual void SetViewBox(math::v4 const& view_box);
			virtual int32_t unkFun_228();
			virtual int32_t unkFun_22C();
			virtual void UpdateScrollRange();
			virtual int32_t unkFun_234();
			virtual void UpdateScrollLayout();
			virtual void UpdateMovableDirection();
			virtual int32_t unkFun_240();
			virtual void OnChildRegistered();
			virtual void OnChildRemoved();
			virtual void OnDestroyTimer(ScrollViewTimer *timer);
			virtual void OnScrollBarChanged(Handler *h);
			virtual int32_t unkFun_254();
			virtual int32_t unkFun_258();
			virtual int32_t unkFun_25C();
			virtual int32_t unkFun_260();
			virtual int32_t unkFun_264();
			virtual int32_t unkFun_268();

			ScrollViewSnapPoint GetSnapPoint(int32_t snap_id);

			int32_t FindSnapID(ScrollViewSnapPoint const& snap_point);

			float GetSnapPower();

			math::v2 GetViewFocus();

			math::v2 GetViewFocusTarget();

			void BlockUpdateViewPort();

			void UnblockUpdateViewPort();

		protected: //0x400

			void ResetScrollBar(ScrollBar*& scroll_bar, ScrollBar *next_bar);

			list<Snap>::iterator FindSnapPoint(int32_t snap_id);

			void SendEvent(int32_t type, int32_t v0, int32_t v1, int32_t v2, int32_t v3);

			void SetDefaultScrollBar();

			void SendFocusChangeEvent();

			char m_unk_27C[0x144];
			float m_snap_power;
			char m_unk_3C4[0x3C];

			__declspec(dllimport) static const char m_widget_type[];
		};

		class ScrollViewParent : public Widget
		{
		public:

			static const char *TypeName();

			ScrollViewParent(Widget *_parent, CreateParam *_param);

			virtual ~ScrollViewParent();

		protected: //0x2A8

			char m_unk_27C[0x2C];

			__declspec(dllimport) static const char m_widget_type[];
		};

		class ScrollViewTimer : public Timer
		{
		public:

			enum TimerType
			{
				TIMER_TYPE_MOVE = 0,
				TIMER_TYPE_MOTION = 1,
				TIMER_TYPE_SNAP_AUTO = 2
			};

			ScrollViewTimer(ScrollViewBase *widget, TimerType type, float total, int32_t func, int32_t repeat, int32_t rep_count, float *param, int32_t userdata);

			virtual ~ScrollViewTimer();

		protected:

			int32_t m_unk_28;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_SCROLL_VIEW_BASE_H */