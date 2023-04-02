/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_INPUTDEVICE_INPUTLISTENER_H
#define _VDSUITE_USER_PAF_INPUTDEVICE_INPUTLISTENER_H

#include <stdint.h>
#include <paf/inputdevice/inputdevice.h>
#include <paf/common/shared_ptr.h>

namespace paf {
	namespace inputdevice {

		class InputListener
		{
		public:

			InputListener() : m_init(false)
			{
				Init();
			}

			virtual ~InputListener()
			{

			}

			virtual void Init()
			{
				m_init = true;
			}

			virtual void OnUpdate(Data *data)
			{

			}

		protected:

			bool m_init;
		};

		class InputGestureListener;

		class GestureParam
		{
		public:

			GestureParam()
			{

			}

			virtual ~GestureParam()
			{

			}

			virtual void AdjustParam()
			{

			}
		};

		class GestureListener
		{
		public:

			GestureListener() : m_input(NULL), m_on_delete(false), m_attached_bitmap(0), m_attached_bitmap_pre(0), m_attached_counter(0), m_orientation(0), m_user_data(NULL)
			{

			}

			virtual ~GestureListener()
			{

			}

			virtual void Init()
			{

			}

			virtual void PreUpdate()
			{

			}

			virtual int32_t OnUpdate(const Data *data)
			{
				m_attached_bitmap_pre = m_attached_bitmap;
				return 0;
			}

			virtual void SetGestureParam(const GestureParam *param)
			{

			}

			virtual int32_t Attach(uint32_t attach_id);

			virtual int32_t Detach(uint32_t attach_id);

			void AddUserDataList(void *data);

			void DelUserDataList(void *data);

			void IncrUserDataList(void *data);

			void DecrUserDataList(void *data);

			bool IsValidUserData(void *data);

		protected:

			int32_t get_id_from_bitmap(uint32_t bitmap, uint32_t idx);

			InputGestureListener *m_input;
			bool m_on_delete;
			uint32_t m_attached_bitmap;
			uint32_t m_attached_bitmap_pre;
			uint32_t m_attached_counter;
			uint32_t m_orientation;
			void *m_user_data;
		};

		class GestureListenerPack
		{
		public:

			common::SharedPtr<GestureListener> gesture_listener;
			bool on_detach;
		};

		class InputGestureListener : public InputListener
		{
		public:

			InputGestureListener()
			{

			}

			virtual ~InputGestureListener()
			{

			}

			virtual void Init();

			virtual void PreUpdateGesturePort(uint32_t port_id);

			virtual int32_t OnUpdateGesturePort(const Data *data, uint32_t port_id);

			virtual int32_t SetInputMask(uint32_t port, uint32_t mask)
			{
				return 0;
			}
			
			common::SharedPtr<GestureListener> GetGestureListener(uint32_t port_id, int32_t priority, void *user_data);

			int32_t DetachGestureListener(uint32_t port_id, common::SharedPtr<GestureListener> listener);

		protected:

			void update_gesture_delete(uint32_t port_id);

			map<int32_t, GestureListenerPack> m_gesture[8];
		};

		extern int32_t AddInputListener(common::SharedPtr<InputListener>& input_listener);

		extern int32_t DelInputListener(common::SharedPtr<InputListener>& input_listener);
	}
}

#endif /* _VDSUITE_USER_PAF_INPUTDEVICE_INPUTLISTENER_H */