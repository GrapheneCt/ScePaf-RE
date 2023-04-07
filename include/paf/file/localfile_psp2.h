/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_FILE_LOCALFILE_PSP2_H
#define _VDSUITE_USER_PAF_FILE_LOCALFILE_PSP2_H

#include <stdint.h>
#include <stddef.h>
#include <kernel.h>
#include <paf/paf_types.h>
#include <paf/file/file.h>
#include <paf/file/localfile_types.h>
#include <paf/file/localfile_impl.h>

namespace paf {

	class LocalFilePsp2Impl : public LocalFileImpl
	{
	public:

		LocalFilePsp2Impl();

		virtual ~LocalFilePsp2Impl();

		virtual int32_t Open(const char *filename, uint32_t flag, uint32_t mode);
		virtual int32_t Close();
		virtual int32_t Read(void *buf, size_t nbyte);
		virtual int32_t Write(const void *buf, size_t nbyte);
		virtual off_t   Seek(off_t offset, int32_t whence);
		virtual int32_t Flush();
		virtual int32_t OpenAsync(const char *filename, uint32_t flag, uint32_t mode);
		virtual int32_t CloseAsync();
		virtual int32_t ReadAsync(void *buf, size_t nbyte);
		virtual int32_t WriteAsync(const void *buf, size_t nbyte);
		virtual int32_t SeekAsync(off_t offset, int32_t whence);
		virtual int32_t FlushAsync();
		virtual int32_t WaitAsync(int32_t *result);
		virtual int32_t PollAsync(int32_t *result);
		virtual bool    IsOpened();
		virtual bool    IsEof();
		virtual int32_t Abort();
		virtual off_t   GetFileSize();
		virtual int32_t Getstat(FileStat *stat);
		virtual int32_t SetPriority(int32_t priority);

		static int32_t RenameFile(const char *oldname, const char *newname);

		static int32_t RemoveFile(const char *path);

		static off_t GetFileSize(const char *path);

		static int32_t Getstat(const char *path, LocalFileStat *buf);

		static int32_t Chstat(const char *path, LocalFileStat *stat, uint32_t cbit);

		static int32_t SetDefaultPriority(int32_t priority);

	private:

		enum AsyncType
		{
			TYPE_NONE = 0,
			TYPE_OPEN = 1,
			TYPE_CLOSE = 2,
			TYPE_READ = 3,
			TYPE_WRITE = 4,
			TYPE_SEEK = 5
		};

		bool is_opened;
		SceUID fd;
		char async[24]; // SceIoAsync async;
		AsyncType async_type;
	};
}

#endif /* _VDSUITE_USER_PAF_FILE_LOCALFILE_PSP2_H */
