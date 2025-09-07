/*
	ScePaf-RE Project
*/

#ifndef _PAF_FILE_FILE_H
#define _PAF_FILE_FILE_H

#include <stdint.h>
#include <stddef.h>
#include <paf/paf_types.h>
#include <paf/datetime/datetime.h>
#if defined(__SNC__)
#include <kernel.h>
#elif defined(__vita__)
#include <psp2/io/stat.h>
#define SCE_STM_FREG		(0x2  <<  12)
#define SCE_STM_FDIR		(0x1  <<  12)
#define SCE_CST_ATTR		0x0000
#elif defined(_WIN32)
#include <sys/stat.h>
#include <fcntl.h>
#else
#error Current target platform is not supported or no target platform defined
#endif

namespace paf {

	struct FileStat
	{
		uint16_t				st_mode;
		uint32_t				st_attr;
		int64_t					st_size;
		datetime::DateTime		st_ctime;
		datetime::DateTime		st_atime;
		datetime::DateTime		st_mtime;
	};

	class File
	{
	public:

		enum Type : int32_t
		{
			Type_None = 0,
			Type_Local = 1,
			Type_Mem = 2,
			Type_Http = 3
		};

		enum Priority : int32_t
		{
			Priority_Normal = 14,
		};

		//TODO: check vitasdk
#if defined(__SNC__) || defined(__vita__)

		enum
		{
			SET = SCE_SEEK_SET,
			CUR = SCE_SEEK_CUR,
			END = SCE_SEEK_END
		};

		enum
		{
			RWX = 0777,
			RWU = 0666,
			RU = 0
		};

		static constexpr int32_t FREG = SCE_STM_FREG;
		static constexpr int32_t FDIR = SCE_STM_FDIR;

		static constexpr int32_t RDONLY = SCE_O_RDONLY;
		static constexpr int32_t WRONLY = SCE_O_WRONLY;
		static constexpr int32_t RDWR = RDONLY | WRONLY;
		static constexpr int32_t APPEND = SCE_O_APPEND;
		static constexpr int32_t CREAT = SCE_O_CREAT;
		static constexpr int32_t TRUNC = SCE_O_TRUNC;
		static constexpr int32_t EXCL = SCE_O_EXCL;
		static constexpr int32_t FDEXCL = SCE_O_FDEXCL;

		static constexpr int32_t MODE = SCE_CST_MODE;
		static constexpr int32_t ATTR = SCE_CST_ATTR;
		static constexpr int32_t SIZE = SCE_CST_SIZE;
		static constexpr int32_t CT = SCE_CST_CT;
		static constexpr int32_t AT = SCE_CST_AT;
		static constexpr int32_t MT = SCE_CST_MT;

#elif defined(_WIN32)

		enum
		{
			SET = SEEK_SET,
			CUR = SEEK_CUR,
			END = SEEK_END
		};

		enum
		{
			RWX = S_IREAD | S_IWRITE | S_IEXEC,
			RWU = S_IREAD | S_IWRITE,
			RU = S_IREAD
		};

		static constexpr int32_t FREG = S_IFREG;
		static constexpr int32_t FDIR = S_IFDIR;

		static constexpr int32_t RDONLY = O_RDONLY;
		static constexpr int32_t WRONLY = O_WRONLY;
		static constexpr int32_t RDWR = RDONLY | WRONLY;
		static constexpr int32_t APPEND = O_APPEND;
		static constexpr int32_t CREAT = O_CREAT;
		static constexpr int32_t TRUNC = O_TRUNC;
		static constexpr int32_t EXCL = O_EXCL;
		static constexpr int32_t FDEXCL = EXCL;

		static constexpr int32_t MODE = 0x0001;
		static constexpr int32_t ATTR = 0x0000;
		static constexpr int32_t SIZE = 0x0004;
		static constexpr int32_t CT = 0x0008;
		static constexpr int32_t AT = 0x0010;
		static constexpr int32_t MT = 0x0020;

#endif

		class OpenArg
		{
		public:

			OpenArg() {};

			~OpenArg() {};
		};

		virtual int32_t GetFileType() const = 0;
		virtual int32_t GetCapability() const = 0;
		virtual int64_t GetFileSize() const = 0;
		virtual int32_t Open(const File::OpenArg *param) = 0;
		virtual int32_t OpenAsync(const File::OpenArg *param) = 0;
		virtual int32_t Close() = 0;
		virtual int32_t CloseAsync() = 0;
		virtual bool    IsOpened() const = 0;
		virtual bool    IsEof() = 0;
		virtual int32_t Abort() = 0;
		virtual int32_t Read(void *buf, size_t nbyte) = 0;
		virtual int32_t ReadAsync(void *buf, size_t nbyte) = 0;
		virtual int32_t Write(const void *buf, size_t nbyte) = 0;
		virtual int32_t WriteAsync(const void *buf, size_t nbyte) = 0;
		virtual int64_t Seek(int64_t offset, int32_t whence) = 0;
		virtual int32_t SeekAsync(int64_t offset, int32_t whence) = 0;
		virtual int32_t Flush() = 0;
		virtual int32_t FlushAsync() = 0;
		virtual int32_t WaitAsync(int64_t *result) = 0;
		virtual int32_t PollAsync(int64_t *result) = 0;
		virtual int32_t Getstat(FileStat *stat) = 0;
		virtual int32_t SetPriority(int32_t priority) = 0;

		virtual ~File()
		{

		}
	};
}

#endif /* _PAF_FILE_FILE_H */
