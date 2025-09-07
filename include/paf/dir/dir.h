/*
	ScePaf-RE Project
*/

#ifndef _PAF_DIR_DIR_H
#define _PAF_DIR_DIR_H

#include <stdint.h>
#include <paf/std/stdcxx.h>
#if defined(__SNC__)
#include <scetypes.h>
#elif defined(__vita__)
#include <psp2/types.h>
#endif

namespace paf {

	class DirEnt
	{
	public:

		enum Type : int32_t
		{
			Type_Dir,
			Type_File,
			Type_Reg,
			Type_Lnk
		};

		Type type;
		string name;
		int32_t size;
		uint32_t creation_year;
	};

	class Dir
	{
	public:

		static int32_t Create(const char *dirname, uint32_t mode);

		//dot-separated path list
		static int32_t CreateRecursive(const char *dirnameList, uint32_t mode);

		//default mode RWSYS
		static int32_t Create(const char *dirname);

		//default mode RWSYS, dot-separated path list
		static int32_t CreateRecursive(const char *dirnameList);

		static bool IsDirectory(const char *path);

		static bool IsExist(const char *path);

		static int32_t RemoveRecursive(const char *path);

		static int32_t Remove(const char *path);

		Dir();

		~Dir()
		{
			Close();
		};

		int32_t Open(const char *dirname);

		int32_t Close();

		int32_t Read(DirEnt *entry);

	private:

		SceUID m_handle;
	};
}

#endif /* _PAF_DIR_DIR_H */
