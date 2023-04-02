/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_CORE_UIINPUTLISTENER_H
#define _VDSUITE_USER_PAF_WIDGET_CORE_UIINPUTLISTENER_H

#include <stdint.h>
#include <paf/inputdevice/inputdevice.h>
#include <paf/inputdevice/inputlistener.h>

namespace paf {
	namespace ui {

		class Environment;
		class Widget;

		class UIInputGestureListener : public paf::inputdevice::InputGestureListener
		{
		public:

			UIInputGestureListener(Environment *_env) : m_env(_env)
			{

			}

			virtual ~UIInputGestureListener()
			{

			}

			virtual void Init()
			{
				for (int i = 0; i < 8; i++)
				{
					m_binded_widget[i] = NULL;
				}
			}

			int32_t BindWidget(uint32_t touch_id, Widget *w)
			{
				if (touch_id < 8)
				{
					m_binded_widget[touch_id] = w;
					return 0;
				}
				return -1;
			}

			Widget *GetBindedWidget(uint32_t touch_id)
			{
				if (touch_id < 8)
				{
					return m_binded_widget[touch_id];
				}
				return NULL;
			}

			Environment *GetEnvironment()
			{
				return m_env;
			}

			bool IsBindedWidget()
			{
				for (int i = 0; i < 8; i++)
				{
					if (m_binded_widget[i] != NULL)
					{
						return true;
					}
				}
				return false;
			}

			/*
			int32_t UnbindWidget(Widget *w)
			{
				for (int i = 0; i < 8; i++)
				{
					if (this->m_binded_widget[i] == w)
					{
						m_binded_widget[i] = NULL;
						DelGestureListener(i, -1, NULL);
						return 0;
					}
				}
				return -1;
			}
			*/

		protected:

			Environment *m_env;
			Widget *m_binded_widget[8];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_CORE_UIINPUTLISTENER_H */
