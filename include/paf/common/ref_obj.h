/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_REF_OBJ_H
#define _VDSUITE_USER_PAF_COMMON_REF_OBJ_H

#include <stdint.h>

namespace paf {
	namespace common {

		class RefObj
		{
		public:

			RefObj();

			int AddRef();

			int Release();

			virtual ~RefObj()
			{

			}

		private:

			int32_t m_count;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_COMMON_REF_OBJ_H */
