/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_VERSATILEPARAM_VERSATILEPARAMMANAGER_H
#define _VDSUITE_USER_PAF_VERSATILEPARAM_VERSATILEPARAMMANAGER_H

#include <stddef.h>
#include <paf/std/stdcxx.h>
#include <paf/math/math.h>
#include <paf/common/shared_ptr.h>
#include <paf/versatileparam/idparam.h>

namespace paf {

	class VersatileParam;

	class VersatileParamManager
	{
	public:

		typedef VersatileParam*(*VersatileParamFactory)();

		VersatileParamManager()
		{

		}

		~VersatileParamManager();

		void AddFactory(const char *tag, VersatileParamFactory func);

		void AddParam(const char *tag, IDParam const& id, VersatileParam *vp);

		VersatileParam *FindParam(const char *tag, IDParam const& id);

		VersatileParam *FindParam(IDParam const& id);

	private:

		typedef map<IDParam, VersatileParam*> IdVp;
		typedef map<string, VersatileParamManager::IdVp> TagIdVp;

		map<string, VersatileParamFactory> m_factories;
		TagIdVp m_data;
	};

}

#endif /* _VDSUITE_USER_PAF_VERSATILEPARAM_VERSATILEPARAMMANAGER_H */