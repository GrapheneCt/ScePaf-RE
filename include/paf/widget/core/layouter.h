/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_CORE_LAYOUTER_H
#define _VDSUITE_USER_PAF_WIDGET_CORE_LAYOUTER_H

#include <stdint.h>
#include <stddef.h>
#include <paf/std/stdcxx.h>

namespace paf {
	namespace ui {

		class Widget;
		class Layouter;
		class Animator;

		typedef int32_t(*LayoutCB)(Layouter*, Widget*, void*, void*, void*);
		typedef int32_t(*AnimatorCB)(Animator*, Widget*, void*, void*, void*);

		class Layouter
		{
		public:

			static void Finish();

			static void Enter();

			static bool IsEnter();

			Layouter(LayoutCB cb_layout, void *data) : m_widget(NULL), m_cb_layout(cb_layout), m_dirty(1), m_first(1), m_reso_dirty_begin(false), m_reso_dirty_end(false)
			{

			}

			virtual ~Layouter();

			virtual int32_t OnUpdate_core();

			int32_t OnUpdate();

			void BindWidget(Widget *w)
			{
				m_widget = w;
			}

			bool IsDirty(uint32_t val)
			{
				return ((m_dirty & val) != 0);
			}

			void SetDirty(uint32_t val)
			{
				m_dirty |= val;
			}

			__declspec (dllimport) static bool s_enter_layout;

		protected:

			Widget *m_widget;
			LayoutCB m_cb_layout;
			uint32_t m_dirty : 8;
			uint32_t m_first : 8;
			bool m_reso_dirty_begin : 1;
			bool m_reso_dirty_end : 1;
		};

		class Animator
		{
		public:

			static void Finish();

			static void Enter();

			static bool IsEnter();

			Animator(AnimatorCB cb_anim, void *data) : m_widget(NULL), m_cb_anim(cb_anim), m_dirty(1), m_first(1)
			{

			}

			virtual ~Animator();

			virtual int32_t OnUpdate_core();

			int32_t OnUpdate();

			void BindWidget(Widget *w)
			{
				m_widget = w;
			}

			bool IsDirty(uint32_t val)
			{
				return ((m_dirty & val) != 0);
			}

			void SetDirty(uint32_t val)
			{
				m_dirty |= val;
			}

			__declspec (dllimport) static bool s_enter_animator;

		protected:

			Widget *m_widget;
			AnimatorCB m_cb_anim;
			uint32_t m_dirty : 16;
			uint32_t m_first : 16;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_CORE_LAYOUTER_H */
