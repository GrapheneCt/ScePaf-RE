/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_FILE_MEMFILE_H
#define _VDSUITE_USER_PAF_FILE_MEMFILE_H

#include <stdint.h>
#include <stddef.h>
#include <kernel.h>
#include <paf/paf_types.h>
#include <paf/common/shared_ptr.h>
#include <paf/thread/rmutex.h>
#include <paf/file/file.h>

namespace paf {

	class Buffer;

	class MemFile : public File
	{
	public:

		class OpenArg : public File::OpenArg
		{
		public:

			OpenArg() : file_type(2) {};

			uint32_t file_type;
			common::SharedPtr<Buffer> buffer;
		};

		MemFile();

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

		virtual ~MemFile();

		static common::SharedPtr<MemFile> Open(const void *ptr, size_t size, int32_t *error);

		static common::SharedPtr<MemFile> Open(common::SharedPtr<Buffer const> buffer, int32_t *error);

	private:

		bool is_opened;
		common::SharedPtr<Buffer const> buffer;
		void *mem_addr;
		size_t mem_size;
		off_t mem_pos;
		bool waiting_for_sync;
		int32_t io_result;
		int32_t unk_28;
		thread::RMutex lock_mutex;
	};
}

#endif /* _VDSUITE_USER_PAF_FILE_MEMFILE_H */
