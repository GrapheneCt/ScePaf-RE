/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_MODULE_MODULE_H
#define _VDSUITE_USER_PAF_MODULE_MODULE_H

#include <stdint.h>
#include <scetypes.h>
#include <paf/std/stdcxx.h>

namespace paf {

	class ModuleImpl;

	class Module
	{
	public:

		enum Option
		{
			Option_None = 0,
			Option_UseInterface = 1,
			Option_LoadTypeCdlg = 2
		};

		class ExtraOption
		{

		};

		Module(const char *_name, const char *funcname = NULL, int32_t option = 0, const ExtraOption *extra_option = NULL);

		~Module();

		void SetInterface(int32_t version, void *_interface);

		void *GetInterface(int32_t version) const;

		int32_t GetHandle();

	private:

		ModuleImpl *impl;
	};

	class ModuleImpl
	{
	public:

		string GetName() const
		{
			return name;
		}

		int32_t GetHandle() const
		{
			return handle;
		}

		int32_t GetResult() const
		{
			return result;
		}

	private:

		ModuleImpl(const char *_name, int _option, const Module::ExtraOption *extra_option);

		~ModuleImpl();

		void Start(Module *referer, char *funcname);

		string name;
		SceUID handle;
		map<int, void*> interface_table;
		int32_t ref_count;
		int32_t option;
		int32_t result;
	};

	inline int32_t Module::GetHandle()
	{
		return impl->GetHandle();
	}
}

#endif /* _VDSUITE_USER_PAF_MODULE_MODULE_H */
