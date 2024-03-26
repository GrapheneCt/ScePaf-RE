/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_DIRECTBAR_H
#define _VDSUITE_USER_PAF_WIDGET_W_DIRECTBAR_H

#include <paf/widget/core/widget.h>
#include <paf/widget/factory.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryDirectBar;

namespace paf {

	namespace ui {

		class HitInfo;

		class DirectBar : public Widget
		{
		public:

			enum
			{
				OBJ_BG = 0,
				OBJ_BALLOON = 1,
				OBJ_LABEL = 2,
				OBJ_DIRECT_BAR_END = 3
			};

			enum
			{
				CB_DIRECT_BAR_BEGIN = 0x10000000,
				CB_DIRECT_BAR_DECIDE = 0x10000001,
				CB_DIRECT_BAR_PRESS = 0x10000002,
				CB_DIRECT_BAR_DRAG_OUT = 0x10000003,
				CB_DIRECT_BAR_END = 0x10000004
			};

			static const char *TypeName();

			DirectBar(Widget *_parent, CreateParam *_param);

			virtual ~DirectBar();
		
			virtual int32_t SetObjColor(math::v4 const& color, int32_t obj);
			virtual int32_t GetObjColor(math::v4& color, int32_t obj);
			virtual int32_t unkFun_178();
			virtual int32_t unkFun_17C();

			void OrientDragOutState(Event *e);

			void SendEvent(int32_t type, int32_t v0, int32_t v1, int32_t v2, int32_t v3);

			math::v4 GetPartsSize();

			int32_t GetHitNumber(HitInfo *hitInfo);

			void OrientDragState(Event *e);

			void OrientNormalState(Event *e);

			void UpdateDBarLayout();

			int32_t GetBtnNum();

		protected: //0x2F8

			char m_unk_27C[0x20];
			uint32_t m_btnNum;
			char m_unk_2A0[0x58];

			__declspec(dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_DIRECTBAR_H */