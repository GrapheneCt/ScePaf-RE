/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_IMAGE_RESOURCE_TYPES_H
#define _VDSUITE_USER_PAF_IMAGE_RESOURCE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <paf/paf_types.h>

namespace paf {
	namespace resource {

		enum TableType
		{
			TableType_Unknown = -1,
			TableType_Page = 0,
			TableType_Style = 1,
			TableType_String = 2,
			TableType_Texture = 3,
			TableType_Model = 4,
			TableType_Sound = 5,
			TableType_File = 6,
			TableType_Anim = 7,
			TableType_Shader = 8,
			TableType_Template = 9
		};

		enum SoundType
		{
			SoundType_Unknown = -1,
			SoundType_WAV,
			SoundType_VAG,
			SoundType_MP3,
			SoundType_AT3,
			SoundType_AAC,
		};
	}
}

#endif /* _VDSUITE_USER_PAF_IMAGE_RESOURCE_TYPES_H */
