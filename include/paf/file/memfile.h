/*
	ScePaf-RE Project
*/

#ifndef _PAF_FILE_MEMFILE_H
#define _PAF_FILE_MEMFILE_H

#include <stdint.h>
#include <stddef.h>
#include <paf/paf_types.h>
#include <paf/common/shared_ptr.h>
#include <paf/thread/rmutex.h>
#include <paf/job/job.h>
#include <paf/file/file.h>

namespace paf {

	class Buffer;

	class MemFile : public File
	{
	public:

		class OpenArg : public File::OpenArg
		{
		public:

			OpenArg() : file_type(Type_Mem) {};

			uint32_t file_type;
			common::SharedPtr<Buffer const> buffer;
		};

		MemFile();

		virtual int32_t GetFileType() const;
		virtual int32_t GetCapability() const;
		virtual int64_t GetFileSize() const;
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
		virtual int64_t Seek(int64_t offset, int32_t whence);
		virtual int32_t SeekAsync(int64_t offset, int32_t whence);
		virtual int32_t Flush();
		virtual int32_t FlushAsync();
		virtual int32_t WaitAsync(int64_t *result);
		virtual int32_t PollAsync(int64_t *result);
		virtual int32_t Getstat(FileStat *stat);
		virtual int32_t SetPriority(int32_t priority);

		virtual ~MemFile();

		void SetWritable(bool writable)
		{
			m_is_writable = writable;
		}

		bool IsWritable() const
		{
			return m_is_writable;
		}

		static common::SharedPtr<MemFile> Open(const void *ptr, size_t size, int32_t *error);

		static common::SharedPtr<MemFile> Open(common::SharedPtr<Buffer const> buffer, int32_t *error);

	private:

		bool m_is_opened;
		bool m_is_writable;
		common::SharedPtr<Buffer const> m_buffer;
		const void *m_mem_addr;
		size_t m_mem_size;
		int64_t m_mem_pos;
		bool m_waiting_for_sync;
		int64_t m_io_result;
		mutable thread::RMutex m_lock_mutex;
#if defined(_WIN32)
		common::SharedPtr<job::JobItem> m_as_job;
#endif
	};
}

#endif /* _PAF_FILE_MEMFILE_H */
