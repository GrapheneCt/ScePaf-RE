/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_INPUTDEVICE_PAD_PAD_H
#define _VDSUITE_USER_PAF_INPUTDEVICE_PAD_PAD_H

#include <stdint.h>

namespace paf {
	namespace inputdevice {
		namespace pad {

			class InitParam
			{
			public:

				enum Mode
				{
					Mode_Normal = 0,
					Mode_DigitalAnalog = 1,
					Mode_CommonDialog = 2,
					Mode_DigitalOnly = 3,
				};

				int32_t m_mode;
			};

			class Data
			{
			public:

				enum Keycode
				{
					PAD_UP = 0x1,
					PAD_DOWN = 0x2,
					PAD_LEFT = 0x4,
					PAD_RIGHT = 0x8,
					PAD_ENTER = 0x10,		// cross
					PAD_ESCAPE = 0x20,		// circle
					PAD_MENU = 0x40,		// triangle
					PAD_DISPLAY = 0x80,		// square
					PAD_SELECT = 0x100,
					PAD_START = 0x200,
					PAD_L = 0x400,
					PAD_R = 0x800,
					PAD_PS = 0x1000,
					PAD_KEY_OPEN = 0x2000,
					PAD_VOL_PLUS = 0x4000,
					PAD_VOL_MINUS = 0x8000
				};

				uint32_t unk_00;  // probably 64bit timestamp
				uint32_t unk_04;
				uint32_t paddata;
				uint16_t lx;
				uint16_t ly;
				uint16_t rx;
				uint16_t ry;
			};

			typedef void(*DeviceHandler)(Data*);

			extern int32_t Init(InitParam& init_param);

			extern int32_t End();

			extern uint32_t SetMask(uint32_t mask);

			extern int32_t Update(float diff_time, const Data **data, const Data **data_pre);

			extern uint32_t GetMask();

			extern void Lock();

			extern void Unlock();

			extern bool IsLocked();

			extern DeviceHandler SetDeviceHandler(DeviceHandler new_handler);
		}
	}
}

#endif /* _VDSUITE_USER_PAF_INPUTDEVICE_PAD_PAD_H */