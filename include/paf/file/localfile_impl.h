/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_FILE_LOCALFILE_IMPL_H
#define _VDSUITE_USER_PAF_FILE_LOCALFILE_IMPL_H

#include <stdint.h>
#include <stddef.h>
#include <paf/paf_types.h>
#include <paf/file/file.h>

namespace paf {

	class LocalFileImpl
	{
	public:

		virtual ~LocalFileImpl()
		{

		}

		virtual int32_t Open(const char *filename, uint32_t flag, uint32_t mode) = 0;
		virtual int32_t Close() = 0;
		virtual int32_t Read(void *buf, size_t nbyte) = 0;
		virtual int32_t Write(const void *buf, size_t nbyte) = 0;
		virtual off_t   Seek(off_t offset, int32_t whence) = 0;
		virtual int32_t Flush() = 0;
		virtual int32_t OpenAsync(const char *filename, uint32_t flag, uint32_t mode) = 0;
		virtual int32_t CloseAsync() = 0;
		virtual int32_t ReadAsync(void *buf, size_t nbyte) = 0;
		virtual int32_t WriteAsync(const void *buf, size_t nbyte) = 0;
		virtual int32_t SeekAsync(off_t offset, int32_t whence) = 0;
		virtual int32_t FlushAsync() = 0;
		virtual int32_t WaitAsync(int64_t *result) = 0;
		virtual int32_t PollAsync(int64_t *result) = 0;
		virtual bool    IsOpened() = 0;
		virtual bool    IsEof() = 0;
		virtual int32_t Abort() = 0;
		virtual off_t   GetFileSize() = 0;
		virtual int32_t Getstat(FileStat *stat) = 0;
		virtual int32_t SetPriority(int32_t priority) = 0;
	};
}

#endif /* _VDSUITE_USER_PAF_FILE_LOCALFILE_IMPL_H */
