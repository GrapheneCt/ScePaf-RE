/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_DIR_DIR_H
#define _VDSUITE_USER_PAF_DIR_DIR_H

#include <stdint.h>
#include <paf/std/string>

namespace paf {

	class DirEnt
	{
	public:

		enum Type
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

#endif /* _VDSUITE_USER_PAF_DIR_DIR_H */
