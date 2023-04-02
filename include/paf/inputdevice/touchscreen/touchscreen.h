/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_INPUTDEVICE_TOUCHSCREEN_TOUCHSCREEN_H
#define _VDSUITE_USER_PAF_INPUTDEVICE_TOUCHSCREEN_TOUCHSCREEN_H

#include <stdint.h>

namespace paf {
	namespace inputdevice {
		namespace touchscreen {

			enum
			{
				PORT_FRONT = 0,
				PORT_BACK = 1,
				MAX_PORT = 2
			};

			enum
			{
				MAX_REGION_NUM = 6
			};

			class InitParam
			{
			public:

				enum Mode
				{
					Mode_Normal = 0,
					Mode_CommonDialog = 2,
				};

				int32_t m_mode;
			};

			class Data
			{
			public:

				enum
				{
					STATE_NONE = 0,
					STATE_PRESS = 1,
					STATE_RELEASE = 2,
					STATE_MOVE = 3
				};

				uint32_t time_stamp;
				int32_t x;
				int32_t y;
				int32_t force;
				int32_t state;
			};

			class DeviceInfo
			{
			public:

				float pixel_per_mm;
			};

			typedef void(*DeviceHandler)(Data*);

			extern int32_t Init(InitParam& init_param);

			extern int32_t End();

			extern uint32_t SetMask(uint32_t port, uint32_t mask);

			extern int32_t Update(float diff_time, const Data **front_data, const Data **back_data, const Data **front_data_pre, const Data **back_data_pre);

			extern uint32_t GetMask(uint32_t port);

			extern void Lock(uint32_t port);

			extern void Unlock(uint32_t port);

			extern bool IsLocked(uint32_t port);

			extern DeviceHandler SetDeviceHandler(uint32_t port, DeviceHandler new_handler);

			extern void SetScreenResolution(uint32_t width, uint32_t height);

			extern void GetScreenResolution(uint32_t& width, uint32_t& height);

			extern void SetScreenViewport(int32_t x, int32_t y, uint32_t width, uint32_t height);

			extern void GetScreenViewport(int32_t& x, int32_t& y, uint32_t& width, uint32_t& height);

			extern void GetDeviceInfo(uint32_t port, DeviceInfo *info);

			extern int32_t ActivateDefaultRegion(uint32_t port, bool activate);

			extern int32_t GetPointFromTopleft(uint32_t port, uint32_t id, float& x, float& y);

			extern int32_t GetPointFromCenter(uint32_t port, uint32_t id, float& x, float& y);

			extern void GetData(uint32_t port, uint32_t id, const Data **data);

			extern void GetDataPre(uint32_t port, uint32_t id, const Data **data);
		}
	}
}

#endif /* _VDSUITE_USER_PAF_INPUTDEVICE_TOUCHSCREEN_TOUCHSCREEN_H */