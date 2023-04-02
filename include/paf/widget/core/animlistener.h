/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_CORE_ANIMLISTENER_H
#define _VDSUITE_USER_PAF_WIDGET_CORE_ANIMLISTENER_H

#include <stdint.h>
#include <paf/math/math.h>
#include <paf/timer/timerlistener.h>
#include <paf/timer/timerqueue.h>

namespace paf {

	class Timer;

	namespace graph {

		class DrawObj;
	}

	namespace ui {

		class AnimListener;
		class Widget;

		typedef void(*AnimCB)(Timer*, AnimListener*, void*, void*, void*);

		typedef void(*AnimSetV4)(AnimListener*, math::v4);
		typedef math::v4(*AnimGetV4)(AnimListener*);

		typedef void(*AnimSetF)(AnimListener*, float);
		typedef float(*AnimGetF)(AnimListener*);

		class AnimListener : public TimerListener
		{
		public:

			enum
			{
				SEMANTIC_NONE = 0,
				SEMANTIC_V4 = 1,
				SEMANTIC_FLOAT = 2
			};

			enum
			{
				FLAG_NONE = 0,
				FLAG_NOTIFY_LAYOUT = 1
			};

			static void PropRotSet(AnimListener *anim, math::v4 data);

			static math::v4 PropRotGet(AnimListener *anim);

			static void PropQuatSet(AnimListener *anim, math::v4 data);

			static math::v4 PropQuatGet(AnimListener *anim);

			static void PropSizeSet(math::v4 data);

			static math::v4 *PropSizeGet(AnimListener *anim);

			static void PropScaleSet(math::v4 data);

			static math::v4 PropScaleGet(AnimListener *anim);

			static void PropAlignSet(AnimListener *anim, math::v4 data);

			static math::v4 PropAlignGet(AnimListener *anim);

			static void PropOriginSet(AnimListener *anim, math::v4 data);

			static math::v4 PropOriginGet(AnimListener *anim);

			static void PropAnchorSet(AnimListener *anim, math::v4 data);

			static math::v4 PropAnchorGet(AnimListener *anim);

			static void PropMetaAlphaSet(AnimListener *anim, float data);

			static float PropMetaAlphaGet(AnimListener *anim);

			static void PropShowAlphaSet(AnimListener *anim, float data);

			static float PropShowAlphaGet(AnimListener *anim);

			static void PropPosSet(AnimListener *anim, math::v4 data);

			static math::v4 PropPosGet(AnimListener *anim);

			static void PropColorSet(AnimListener *anim, math::v4 data);

			static math::v4 PropColorGet(AnimListener *anim);

			AnimListener(Timer *t, Widget *w, AnimCB cb_anim, AnimCB cb_fin, void *data);

			virtual ~AnimListener()
			{

			}

			virtual void OnTick(void *data1, void *data2)
			{
				if (m_cb_anim)
				{
					m_cb_anim(m_timer, this, m_widget, m_data, NULL);
				}
			}

			virtual void OnFinish(void *data1, void *data2)
			{
				if (m_cb_finish)
				{
					m_cb_finish(m_timer, this, m_widget, m_data, NULL);
				}
			}

			virtual float *GetTargetF()
			{
				return NULL;
			}

			virtual math::v4 *GetTargetV4()
			{
				return NULL;
			}

			virtual float *GetStartF()
			{
				return NULL;
			}

			virtual math::v4 *GetStartV4()
			{
				return NULL;
			}

			uint32_t GetFlags()
			{
				return m_flags;
			}

			uint32_t GetSemanticType()
			{
				return m_semantic;
			}

			uint32_t GetType()
			{
				return m_type;
			}

			void SetSlotType(uint32_t type)
			{
				m_slot_type = type;
			}

		protected:

			Widget *m_widget;
			AnimCB m_cb_anim;
			AnimCB m_cb_finish;
			uint32_t m_flags;
			uint32_t m_type;
			uint32_t m_semantic : 8;
			uint32_t m_slot_type : 8;
		};

		class AnimPropertyV4
		{
		public:

			uint32_t m_type;
			AnimSetV4 m_cb_set;
			AnimGetV4 m_cb_get;
		};

		class AnimListenerV4 : public AnimListener
		{
		public:

			AnimListenerV4(Timer *t, Widget *w, math::v4 const& src, math::v4 const& dst, AnimPropertyV4 *cb_prop, AnimCB cb_fin, void *data) :
				AnimListener(t, w, NULL, cb_fin, data), m_herm_data(NULL), m_prop(cb_prop)
			{
				m_anim_data[0] = src;
				m_anim_data[1] = src;
				if (m_prop)
				{
					m_type = m_prop->m_type;
				}
				m_semantic = 1;
			}

			virtual ~AnimListenerV4()
			{
				delete m_herm_data;
			}

			virtual void OnTick(void *data1, void *data2);

			virtual math::v4 *GetTargetV4()
			{
				return &m_anim_data[1];
			}

			virtual math::v4 *GetStartV4()
			{
				return &m_anim_data[0];
			}

			math::v4 GetCurrV4()
			{
				if (m_prop == NULL)
				{
					return math::v4::_0000();
				}
				return m_prop->m_cb_get(this);
			}

		protected:

			int32_t m_padding;
			math::v4 m_anim_data[2];
			math::v4 *m_herm_data;
			AnimPropertyV4 *m_prop;
		};

		class AnimPropertyF
		{
		public:

			uint32_t m_type;
			AnimSetF m_cb_set;
			AnimGetF m_cb_get;
		};

		class AnimListenerF1 : public AnimListener
		{
		public:

			AnimListenerF1(Timer *t, Widget *w, float src, float dst, AnimPropertyF *cb_prop, AnimCB cb_fin, void *data) :
				AnimListener(t, w, NULL, cb_fin, data), m_herm_data(NULL), m_prop(cb_prop)
			{
				m_anim_data[0] = src;
				m_anim_data[1] = src;
				if (m_prop)
				{
					m_type = m_prop->m_type;
				}
				m_semantic = 2;
			}

			virtual ~AnimListenerF1()
			{
				delete m_herm_data;
			}

			virtual void OnTick(void *data1, void *data2);

			virtual float *GetTargetF()
			{
				return &m_anim_data[1];
			}

			virtual float *GetStartF()
			{
				return &m_anim_data[0];
			}

			float GetCurrF()
			{
				if (m_prop == NULL)
				{
					return 0.0f;
				}
				return m_prop->m_cb_get(this);
			}

		protected:

			float m_anim_data[2];
			float *m_herm_data;
			AnimPropertyF *m_prop;
		};

		class AnimListenerObj : public AnimListenerV4
		{
		public:

			static void PropObjColorSet(AnimListener *anim, math::v4 data);

			static math::v4 PropObjColorGet(AnimListener *anim);

			static void PropObjPosSet(AnimListener *anim, math::v4 data);

			static math::v4 PropObjPosGet(AnimListener *anim);

			static void PropObjRotSet(AnimListener *anim, math::v4 data);

			static math::v4 PropObjRotGet(AnimListener *anim);

			static void PropObjSizeSet(AnimListener *anim, math::v4 data);

			static math::v4 PropObjSizeGet(AnimListener *anim);

			AnimListenerObj(Timer *t, Widget *w, graph::DrawObj *obj, math::v4 const& src, math::v4 const& dst, AnimPropertyV4 *cb_prop, AnimCB cb_fin, void *data) :
				AnimListenerV4(t, w, src, dst, cb_prop, cb_fin, data)
			{
				m_obj = obj;
			}

			virtual ~AnimListenerObj()
			{

			}

			graph::DrawObj *GetDrawObj()
			{
				return m_obj;
			}

		protected:

			graph::DrawObj *m_obj;
		};

		class TexAnimListenerObj : public AnimListenerObj
		{
		public:

			TexAnimListenerObj(Timer *t, Widget *w, graph::DrawObj *obj, int32_t column_num, int32_t row_num, int32_t start_frame, int32_t end_frame, AnimCB cb_fin, void *data);

			virtual ~TexAnimListenerObj()
			{

			}

			virtual void OnTick(void *data1, void *data2)
			{
				TexAnim(m_timer->GetValue());
			}

			void TexAnim(float rate);

		protected:

			int32_t m_column_num;
			int32_t m_row_num;
			int32_t m_start_frame;
			int32_t m_end_frame;
			int32_t m_frame_distance;
			float m_unit_u;
			float m_unit_v;
		};

		class AnimQueueBase : public TimerQueue
		{
		public:

			AnimQueueBase()
			{

			}

			virtual ~AnimQueueBase()
			{

			}

			int32_t EraseType(int32_t type, bool auto_delete);

			void SetFinishedLoopBack(bool hermete);

			float *GetTargetF()
			{
				AnimListener *listener = (AnimListener*)GetBack();
				if (listener == NULL)
				{
					return NULL;
				}
				return listener->GetTargetF();
			}

			math::v4 *GetTargetV4()
			{
				AnimListener *listener = (AnimListener*)GetBack();
				if (listener == NULL)
				{
					return NULL;
				}
				return listener->GetTargetV4();
			}
		};

		class AnimQueue
		{
		public:

			enum
			{
				SLOT_MAIN = 0,
				SLOT_ADD = 1,
				SLOT_HERMETE = 2,
				SLOT_MAX = 3
			};

			AnimQueue()
			{
				for (int i = 0; i < 3; i++)
				{
					m_queue[i] = NULL;
				}
			}

			virtual ~AnimQueue()
			{

			}

			int32_t PushBack(TimerListener *t, uint32_t slot);

			int32_t PushFront(TimerListener *t, uint32_t slot);

			int32_t EraseFront(bool auto_delete, uint32_t slot);

			int32_t EraseType(int32_t type, bool auto_delete);

			float DoTick(void *data1, void *data2);

			void Clear(uint32_t slot)
			{
				if ((slot < 3) && (m_queue[slot] != NULL))
				{
					m_queue[slot]->Clear();
				}
			}

			void ClearAll(uint32_t slot)
			{
				if ((slot < 3) && (m_queue[slot] != NULL))
				{
					m_queue[slot]->ClearAll();
				}
			}

			void ClearAll()
			{
				for (int i = 0; i < 3; i++)
				{
					if (m_queue[i] != NULL)
					{
						delete m_queue[i];
					}
					m_queue[i] = NULL;
				}
			}

			TimerListener *GetFront(uint32_t slot)
			{
				TimerListener *ret = NULL;
				if (slot < 3)
				{
					if (m_queue[slot] != NULL)
					{
						ret = m_queue[slot]->GetFront();
					}
				}
				return ret;
			}

			bool IsFinished()
			{
				int i = 0;
				while ((m_queue[i] == NULL || m_queue[i]->IsFinished()))
				{
					i++;
					if (2 < i)
					{
						return true;
					}
				}
				return false;
			}

			void SetFinishedLoopBack()
			{
				for (int i = 0; i < 3; i++)
				{
					if (m_queue[i] != NULL)
					{
						m_queue[i]->SetFinishedLoopBack(i == 2);
					}
				}
			}

			void SwapSlot(uint32_t slot0, uint32_t slot1)
			{
				if ((slot0 < 3) && (slot1 < 3))
				{
					AnimQueueBase *to_swap = m_queue[slot0];
					m_queue[slot0] = m_queue[slot1];
					m_queue[slot1] = to_swap;
				}
			}

			float *GetTargetF(uint32_t slot)
			{
				float *ret = NULL;
				if (slot < 3) {
					if (m_queue[slot] != NULL)
					{
						ret = m_queue[slot]->GetTargetF();
					}
				}
				return ret;
			}

			math::v4 *GetTargetV4(uint32_t slot)
			{
				math::v4 *ret = NULL;
				if (slot < 3) {
					if (m_queue[slot] != NULL)
					{
						ret = m_queue[slot]->GetTargetV4();
					}
				}
				return ret;
			}

		protected:

			AnimQueueBase *m_queue[3];
		};
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_CORE_ANIMLISTENER_H */
