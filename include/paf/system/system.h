/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_SYSTEM_SYSTEM_H
#define _VDSUITE_USER_PAF_SYSTEM_SYSTEM_H

#include <stdint.h>
#include <stddef.h>

namespace paf {
	namespace system {

		enum ModelType
		{
			ModelType_Vita = 0,
			ModelType_Dolce = 1
		};

		extern bool SupportsMultiController(); //vsh capability 1

		extern bool SupportsCamera(); //vsh capability 2

		extern bool SupportsWiredEthernet(); //vsh capability 5 OR 6

		//ScePafMisc_C74F989D
		extern bool c8(); //vsh capability 7

		//ScePafMisc_D8D642F5
		extern bool c10(); //vsh capability 8

		//ScePafMisc_9DE7DA6D
		extern bool c20(); //vsh capability 9

		extern bool SupportsLocalOutputs(); //vsh capability 10, true if system has screen and speakers

		extern bool IsDolce();

		extern ModelType GetModelType();

		#define SCE_PAF_IS_DOLCE (paf::system::GetModelType() == paf::system::ModelType_Dolce)
	}
}

#endif /* _VDSUITE_USER_PAF_SYSTEM_SYSTEM_H */
