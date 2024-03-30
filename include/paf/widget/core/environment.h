/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_CORE_ENVIRONMENT_H
#define _VDSUITE_USER_PAF_WIDGET_CORE_ENVIRONMENT_H

#include <stdint.h>
#include <stddef.h>
#include <paf/std/list>
#include <paf/std/memory>
#include <paf/math/math.h>
#include <paf/graphics/surface/surface.h>
#include <paf/graphics/graphics.h>
#include <paf/widget/core/event.h>

namespace paf {
	namespace ui {

		class Widget;
		class HitInfo;

		class Screen
		{
		public:

			static int32_t PushTarget(Screen *tgt);

			static int32_t PopTarget(Screen *tgt);

			static void SetRootScreen(Screen *scr);

			static Screen *GetRootScreen()
			{
				return s_root_screen;
			}

			Screen();

			Screen(intrusive_ptr<graph::Surface> surf);

			virtual ~Screen();

			void SetSurface(intrusive_ptr<graph::Surface> surf);

			int32_t OnTarget();

			int32_t OnClear();

			int32_t OnFinish();

			int32_t Swap();

			int32_t Term();

			void AutoDelete(bool _autodelete)
			{
				is_auto_delete = _autodelete;
			}

			bool IsAutoDelete()
			{
				return is_auto_delete;
			}

			void SetCleared(bool _cleared)
			{
				is_cleared = _cleared;
			}

			void SetDisplayHandle(gutil::WinHandle whandle)
			{
				m_whandle = whandle;
			}

			void SetScissor(int32_t x, int32_t y, int32_t w, int32_t h)
			{
				sp_x = x;
				sp_y = y;
				sp_w = w;
				sp_h = h;
			}

			void SetViewport(int32_t x, int32_t y, int32_t w, int32_t h)
			{
				sp_x = x;
				sp_y = y;
				sp_w = w;
				sp_h = h;
				vp_x = x;
				vp_y = y;
				vp_w = w;
				vp_h = h;
			}

			intrusive_ptr<graph::Surface> GetSurface()
			{
				return m_surface;
			}

			int32_t GetDeviceScreenHeight() const
			{
				return m_surface->GetHeight();
			}

			int32_t GetDeviceScreenWidth() const
			{
				return m_surface->GetWidth();
			}

			void GetScissor(int32_t& x, int32_t& y, int32_t& w, int32_t& h) const
			{
				x = sp_x;
				y = sp_y;
				w = sp_w;
				h = sp_h;
			}

			void GetViewport(int32_t& x, int32_t& y, int32_t& w, int32_t& h) const
			{
				x = vp_x;
				y = vp_y;
				w = vp_w;
				h = vp_h;
			}

		protected:

			int32_t padding;
			math::v4 clear_color;
			bool is_auto_delete;
			bool is_cleared;
			int32_t vp_x;
			int32_t vp_y;
			int32_t vp_w;
			int32_t vp_h;
			int32_t sp_x;
			int32_t sp_y;
			int32_t sp_w;
			int32_t sp_h;
			int32_t clear_policy;
			intrusive_ptr<graph::Surface> m_surface;
			gutil::WinHandle m_whandle;
			int32_t unk_50;
			int32_t unk_54;

		private:

			__declspec (dllimport) static Screen *s_root_screen;
		};

		class EnvironmentParam
		{
		public:

			enum
			{
				RESOLUTION_AUTO,
				RESOLUTION_PSP2 = 1,
				RESOLUTION_HD_HALF = 2,
				RESOLUTION_HD_FULL = 4,
			};

			enum
			{
				ORIENTATION_LANDSCAPE_STANDARD = 0x1000000,
				ORIENTATION_PORTRAIT_RIGHTSIDEDONW = 0x2000000,
				ORIENTATION_LANDSCAPE_UPSIDEDOWN = 0x4000000,
				ORIENTATION_PORTRAIT_LEFTSIDEDOWN = 0x8000000,
			};

			EnvironmentParam(uint32_t option);

			virtual ~EnvironmentParam();

			virtual int32_t unkFun_08(int32_t width, int32_t height, int32_t mode);
			virtual int32_t unkFun_0C(int32_t mode1, int32_t mode2);
			virtual int32_t unkFun_10();

		private:

			char m_unk_04[0x10];
		};

		class Environment
		{
		public:

			enum
			{
				GESTURE_PRIO_TAP = 10,
				GESTURE_PRIO_LONG_PRESS = 15,
				GESTURE_PRIO_DRAG_PINCH = 20,
				GESTURE_PRIO_REGION_TRACK = 100,
				GESTURE_PRIO_MOCHI = 110
			};

			Environment(EnvironmentParam *param, uint32_t screen_orientation);

			virtual ~Environment();

			void EventLoop();

			int32_t ShowSceneEntry(int32_t entry);

			int32_t HideSceneEntry(int32_t entry);

			int32_t GetSceneNum(int32_t entry);

			int32_t GetSceneTop(int32_t entry, list<Widget*>::iterator& it);

			int32_t GetSceneEnd(int32_t entry, list<Widget*>::iterator& it);

			void ShowFocus(int32_t focus_id);

			void HideFocus(int32_t focus_id);

			int32_t RegisterModalWidget(Widget *w, uint32_t mode);

			int32_t SetScreen(Screen *scr);

			void Init();

			void UpdateRestructScene();

			bool IsTermAvailable();

			void RequestTerm();

			void Term();

			int32_t GetHitStack(HitInfo *h_info, Widget *widget);

			bool IsHitStackParent(Widget *widget);

			void ClearHitInfo(Widget *widget);

			int32_t GetLastHitStack(HitInfo *h_info);

			int32_t SetResolution(uint16_t width, uint16_t height);

			void UpdateOrientation();

			void SetDrawCutoff(bool on_off)
			{
				m_draw_cutoff = on_off;
			}

			bool GetDrawCutoff()
			{
				return m_draw_cutoff;
			}

			Screen *GetScreen()
			{
				return m_screen;
			}

			EventQueue& GetEventQueue()
			{
				return m_ev_queue;
			}

			bool IsTermRequested() const
			{
				return m_term_requested;
			}

			int32_t GetOrientation() const
			{
				return m_current_orientation;
			}

		protected:

			int32_t RegisterTouchDeviceRegion(uint32_t entry, Widget *w);

			int32_t RegisterTouchDeviceRegion(Widget *w);

			void RemoveTouchDeviceRegion(Widget *w);

			void OnDraw();

			void OnUpdateTouchDeviceRegion();

			void OnUpdatePost();

			void OnUpdatePre();

			char m_unk_004[0xB0];
			int32_t m_current_orientation;
			int32_t m_shell_orientation;
			char m_unk_0BC[0x19];
			bool m_term_requested;
			bool m_draw_cutoff;
			int32_t m_unk_0D8;
			char m_unk_0DC[0x1F4];
			EventQueue m_ev_queue;
			list<Event> m_ev_subrouting;
			list<Event> m_ev_doevent;
			list<Widget*> m_scenes_onupdate;
			Screen *m_screen;
			char m_unk_330[0x2A6C];
		};

		class FocusInfo
		{
		public:

			enum
			{
				MAX_HISTORIES = 2
			};

			class History
			{
			public:

				Widget *src;
				Widget *dst;
				uint32_t key_code;
			};

			void Hide();

			void AddFocusHistory(Widget *src, Widget *dst, uint32_t key_code);

			void RemoveFocusHistory(Widget *w);

			Widget *FindFocusHistory(Widget *dst, uint32_t key_code);

		private:

			FocusInfo();

			~FocusInfo();

			Widget *focus_view;
			/*
			Widget *focused_widget;
			Widget *focused_scene;
			math::v4 focus_pos;
			math::v4 focus_size;
			bool focus_visible : 1;
			*/
			char m_unk_04[0x74];
			History m_histories[MAX_HISTORIES];
			size_t m_num_histories;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_CORE_ENVIRONMENT_H */
