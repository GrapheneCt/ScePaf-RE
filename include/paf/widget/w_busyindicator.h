/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_BUSYINDICATOR_H
#define _VDSUITE_USER_PAF_WIDGET_W_BUSYINDICATOR_H

#include <paf/widget/core/widget.h>
#include <paf/widget/factory.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryBusyIndicator;

namespace paf {

	namespace ui {

		class BusyIndicator : public Widget
		{
		public:

			static const char *TypeName();

			BusyIndicator(Widget *_parent, CreateParam *_param);

			virtual ~BusyIndicator();

			virtual int32_t SetObjColor(math::v4 const& color, int32_t obj);
			virtual int32_t GetObjColor(math::v4& color, int32_t obj);

			void Start();

			void Stop();

			void SetBallSize(float size);

			float GetBallSize()
			{
				return m_ball_size;
			}

		protected: //0x2A8

			char m_unk_27C[0x24];
			float m_ball_size;
			int32_t m_unk_2A4;


			__declspec(dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_BUSYINDICATOR_H */