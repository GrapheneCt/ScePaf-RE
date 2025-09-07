/*
	ScePaf-RE Project
*/

#ifndef _PAF_INPUTDEVICE_KEYBOARD_KEYBOARD_H
#define _PAF_INPUTDEVICE_KEYBOARD_KEYBOARD_H

#include <stdint.h>

namespace paf {
	namespace inputdevice {
		namespace keyboard {

			class Data
			{
			public:

				enum Keycode : int32_t
				{
					KB_UP = 1,
					KB_DOWN,
					KB_LEFT,
					KB_RIGHT,
					KB_RETURN,
					KB_ESCAPE
				};

				uint32_t keycode;
			};
		}
	}
}

#endif /* _PAF_INPUTDEVICE_KEYBOARD_KEYBOARD_H */