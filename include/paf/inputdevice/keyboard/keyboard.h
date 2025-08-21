/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_INPUTDEVICE_KEYBOARD_KEYBOARD_H
#define _VDSUITE_USER_PAF_INPUTDEVICE_KEYBOARD_KEYBOARD_H

#include <stdint.h>

namespace paf {
	namespace inputdevice {
		namespace keyboard {

			class Data
			{
			public:

				enum Keycode
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

#endif /* _VDSUITE_USER_PAF_INPUTDEVICE_KEYBOARD_KEYBOARD_H */