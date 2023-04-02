/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_INPUTDEVICE_INPUTDEVICE_H
#define _VDSUITE_USER_PAF_INPUTDEVICE_INPUTDEVICE_H

#include <stdint.h>
#include <paf/inputdevice/pad/pad.h>
#include <paf/inputdevice/touchscreen/touchscreen.h>
#include <paf/inputdevice/motionsensor/motionsensor.h>

namespace paf {
	namespace inputdevice {

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

			pad::Data *m_pad_data;
			pad::Data *m_pad_data_pre;
			touchscreen::Data *m_touch_data;
			touchscreen::Data *m_touch_data_pre;
			touchscreen::Data *m_touch_rear_data;
			touchscreen::Data *m_touch_rear_data_pre;
			motionsensor::Data *m_motion_data;
			motionsensor::Data *m_motion_data_pre;
		};

		extern int32_t Init(InitParam& init_param);

		int32_t End();

		int32_t Update(float diff_time);
	}
}

#endif /* _VDSUITE_USER_PAF_INPUTDEVICE_INPUTDEVICE_H */