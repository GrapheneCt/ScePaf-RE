/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_W_PROGRESSBAR_H
#define _VDSUITE_USER_PAF_WIDGET_W_PROGRESSBAR_H

#include <paf/widget/core/widget.h>
#include <paf/widget/factory.h>

__declspec(dllimport) extern paf::ui::FactoryFuncTable g_factoryProgressBar;

namespace paf {

	namespace ui {

		class HitInfo;

		class ProgressBar : public Widget
		{
		public:

			enum
			{
				OBJ_BASE = 0,
				OBJ_BAR_FORE = 1,
				OBJ_BAR_BACK = 2,
				OBJ_SIGNAL = 3,
				OBJ_GLOW = 4,
				OBJ_BASE_SHADOW = 5,
				OBJ_BAR_SHADOW = 6,
				OBJ_PROGRESSBAR_END = 7
			};

			enum
			{
				CB_PROGRESSBAR_IMMEDIATE_UPDATE_LABEL = 0x20000000,
				CB_PROGRESSBAR_IMMEDIATE_END = 0x20000001
			};

			enum BarMode
			{
				BAR_MODE_SINGLE = 0,
				BAR_MODE_DOUBLE = 1
			};

			enum BarId
			{
				BAR_FORE = 0,
				BAR_BACK = 1
			};

			enum LabelMode
			{
				LABEL_MODE_PERCENTAGE = 0,
				LABEL_MODE_VALUE = 1,
				LABEL_MODE_MANUAL = 2
			};

			enum LabelPosMode
			{
				LABEL_POS_MODE_CENTER = 0,
				LABEL_POS_MODE_LEFT = 1,
				LABEL_POS_MODE_RIGHT = 2,
				LABEL_POS_MODE_UP = 3,
				LABEL_POS_MODE_DOWN = 4,
				LABEL_POS_MODE_LEFT_UP = 5,
				LABEL_POS_MODE_LEFT_DOWN = 6,
				LABEL_POS_MODE_RIGHT_UP = 7,
				LABEL_POS_MODE_RIGHT_DOWN = 8,
				LABEL_POS_MODE_MANUAL = 9
			};

			enum
			{
				PARTS_BASE = 0,
				PARTS_BAR_FORE = 1,
				PARTS_BAR_BACK = 2,
				PARTS_SIGNAL = 3,
				PARTS_GLOW = 4,
				PARTS_LABEL = 5,
				PARTS_BASE_SHADOW = 6,
				PARTS_BAR_SHADOW = 7,
				PARTS_PROGRESSBAR_END = 8
			};

			enum
			{
				DIRTY_FLAG_BAR_FORE = 0,
				DIRTY_FLAG_BAR_BACK = 1,
				DIRTY_FLAG_LABEL = 2,
				DIRTY_FLAG_LABEL_POS = 3,
				DIRTY_FLAG_PROGRESSBAR_END = 4
			};

			static const char *TypeName();

			ProgressBar(Widget *_parent, CreateParam *_param);

			virtual ~ProgressBar();

			virtual int32_t SetObjColor(math::v4 const& color, int32_t obj);
			virtual int32_t GetObjColor(math::v4& color, int32_t obj);
			virtual int32_t SetBarMode(BarMode mode);
			virtual BarMode GetBarMode();
			virtual int32_t SetMaxValue(float val);
			virtual int32_t SetMaxValue(int32_t val);
			virtual int32_t SetMaxValueAsync(float val);
			virtual int32_t SetMaxValueAsync(int32_t val);
			virtual float GetMaxValue();
			virtual int32_t SetMinValue(float val);
			virtual int32_t SetMinValue(int32_t val);
			virtual int32_t SetMinValueAsync(float val);
			virtual int32_t SetMinValueAsync(int32_t val);
			virtual float GetMinValue();
			virtual int32_t SetValue(float val, bool bWithAnim = false, BarId id = BAR_FORE);
			virtual int32_t SetValue(int32_t val, bool bWithAnim = false, BarId id = BAR_FORE);
			virtual int32_t SetValueAsync(float val, bool bWithAnim = false, BarId id = BAR_FORE);
			virtual int32_t SetValueAsync(int32_t val, bool bWithAnim = false, BarId id = BAR_FORE);
			virtual float GetValue(BarId id = BAR_FORE);
			virtual int32_t SetBarAnim(float animTime, int32_t animFunc);
			virtual int32_t AttachLabelWidget(Widget *pWidget);
			virtual int32_t DetachLabelWidget();
			virtual Widget *GetLabelWidget();
			virtual int32_t SetLabelMode(LabelMode mode);
			virtual LabelMode GetLabelMode();
			virtual int32_t SetLabelPosMode(LabelPosMode mode);
			virtual LabelPosMode GetLabelPosMode();
			virtual int32_t SetLabelMargin(float margin);
			virtual float GetLabelMargin();
			virtual Widget *GetPartsWidget(int32_t obj, int32_t *pChildObj);
			virtual int32_t unkFun_1E8();
			virtual void Sync();
			virtual void CheckDirtyFlag();
			virtual void UpdateBaseShadow();
			virtual void UpdateBar(BarId id = BAR_FORE, bool bWithAnim = false);
			virtual void UpdateLabel();
			virtual void UpdateLabelPos();

			void SetGlowVisible(bool bShow);

			void SetSignalAnim(bool onoff);

			bool IsSignalAnim();

			void SetSignalAnimTime(float animTime);

			void SetShadowVisible(bool bShow);

			void ClearDirtyFlag(uint32_t flag)
			{
				m_dirty = m_dirty & ~(1 << (flag & 0xFF));
			}

			bool IsDirty(uint32_t flag)
			{
				return ((m_dirty & 1 << (flag & 0xFF)) != 0);
			}

			void GetBarAnim(float *pAnimTime, int32_t *pAnimFunc)
			{
				if (pAnimTime != NULL)
				{
					*pAnimTime = m_animTime;
				}
				if (pAnimFunc != NULL)
				{
					*pAnimFunc = m_animFunc;
				}
			}

		protected: //0x2F0

			char m_unk_27C[0x20];
			float m_max;
			float m_min;
			float m_value[2];
			float m_animTime;
			int32_t m_animFunc;
			char m_unk_2B4[0x20];
			uint32_t m_dirty;
			char m_unk_2D8[0x18];

			__declspec(dllimport) static const char m_widget_type[];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_W_PROGRESSBAR_H */