/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_FILE_FILE_H
#define _VDSUITE_USER_PAF_FILE_FILE_H

#include <stdint.h>
#include <stddef.h>
#include <paf/paf_types.h>
#ifdef __SNC__
#include <kernel.h>
#else
#include <psp2/io/stat.h>
#endif

namespace paf {

	class FileStat : public SceIoStat
	{
	};

	class File
	{
	public:

		enum Type
		{
			Type_None,
			Type_Local,
			Type_Mem,
			Type_Http
		};

		class OpenArg
		{
		public:

			OpenArg() {};

			~OpenArg() {};
		};

		virtual int32_t GetFileType() const = 0;
		virtual int32_t GetCapability() const = 0;
		virtual off_t   GetFileSize() const = 0;
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
		virtual off_t   Seek(off_t offset, int32_t whence) = 0;
		virtual int32_t SeekAsync(off_t offset, int32_t whence) = 0;
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

#endif /* _VDSUITE_USER_PAF_FILE_FILE_H */
