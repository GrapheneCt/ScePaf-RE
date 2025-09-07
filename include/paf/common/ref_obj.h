/*
	ScePaf-RE Project
*/

#ifndef _PAF_COMMON_REF_OBJ_H
#define _PAF_COMMON_REF_OBJ_H

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

#endif /* _PAF_COMMON_REF_OBJ_H */
