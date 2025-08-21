/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_FILE_BUFFEREDFILE_H
#define _VDSUITE_USER_PAF_FILE_BUFFEREDFILE_H

#include <stdint.h>
#include <stddef.h>
#include <paf/paf_types.h>
#include <paf/common/shared_ptr.h>
#include <paf/thread/rmutex.h>
#include <paf/file/file.h>

namespace paf {

	class Buffer;

	// Default buffer size is 4KiB
	class BufferedFile : public File
	{
	public:

		class OpenArg : public File::OpenArg
		{
		public:

			OpenArg() : fileType(0), filename(NULL), flag(SCE_O_RDONLY), mode(0) {};

			uint32_t fileType;
			const char *filename;
			uint32_t flag;
			uint32_t mode;
		};

		BufferedFile();

		virtual int32_t GetFileType() const;
		virtual int32_t GetCapability() const;
		virtual off_t   GetFileSize() const;
		virtual int32_t Open(const File::OpenArg *param);
		virtual int32_t OpenAsync(const File::OpenArg *param);
		virtual int32_t Close();
		virtual int32_t CloseAsync();
		virtual bool    IsOpened() const;
		virtual bool    IsEof();
		virtual int32_t Abort();
		virtual int32_t Read(void *buf, size_t nbyte);
		virtual int32_t ReadAsync(void *buf, size_t nbyte);
		virtual int32_t Write(const void *buf, size_t nbyte);
		virtual int32_t WriteAsync(const void *buf, size_t nbyte);
		virtual off_t   Seek(off_t offset, int32_t whence);
		virtual int32_t SeekAsync(off_t offset, int32_t whence);
		virtual int32_t Flush();
		virtual int32_t FlushAsync();
		virtual int32_t WaitAsync(int32_t *result);
		virtual int32_t PollAsync(int32_t *result);
		virtual int32_t Getstat(FileStat *stat);
		virtual int32_t SetPriority(int32_t priority);

		virtual ~BufferedFile();

		virtual int unkFun_060();
		virtual int unkFun_064();
		virtual int unkFun_068();
		virtual int32_t Open(const File::OpenArg *param, common::SharedPtr<Buffer> buffer);

		static common::SharedPtr<BufferedFile> Open(common::SharedPtr<File> file, int32_t *error, common::SharedPtr<Buffer> buffer);

	private:

		SceInt32 unk_04;
		SceInt32 unk_08;
		SceInt32 unk_0C;
		thread::RMutex lock_mutex;
		SceInt32 unk_30;
		SceInt32 unk_34;
		SceInt32 unk_38;
		SceInt32 unk_3C;
	};
}

#endif /* _VDSUITE_USER_PAF_FILE_BUFFEREDFILE_H */
