/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_INPUTDEVICE_MOTIONSENSOR_MOTIONSENSOR_H
#define _VDSUITE_USER_PAF_INPUTDEVICE_MOTIONSENSOR_MOTIONSENSOR_H

#include <stdint.h>
#include <paf/math/math.h>

namespace paf {
	namespace inputdevice {
		namespace motionsensor {

			class Data
			{
			public:

				uint32_t unk_00;
				uint32_t unk_04;
				math::v3 accelerometer;
				math::v3 gyroscope;
				math::quaternion device_quat;
				math::matrix rotation_matrix;
				math::v3 basic_orientation;
			};

			typedef void(*DeviceHandler)(Data*);

			extern int32_t Update(float diff_time, const Data **data, const Data **data_pre);

			extern void Lock();

			extern void Unlock();

			extern bool IsLocked();

			extern DeviceHandler SetDeviceHandler(DeviceHandler new_handler);
		}
	}
}

#endif /* _VDSUITE_USER_PAF_INPUTDEVICE_MOTIONSENSOR_MOTIONSENSOR_H */