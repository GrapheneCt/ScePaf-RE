/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_FILE_LOCALFILE_H
#define _VDSUITE_USER_PAF_FILE_LOCALFILE_H

#include <stdint.h>
#include <stddef.h>
#include <kernel.h>
#include <paf/thread/rmutex.h>
#include <paf/common/shared_ptr.h>
#include <paf/file/file.h>
#include <paf/file/localfile_types.h>

namespace paf {

	class LocalFileImpl;

	namespace memory {

		class HeapAllocator;
	}

	class LocalFile : public File
	{
	public:

		class OpenArg : public File::OpenArg
		{
		public:

			OpenArg() : file_type(1), filename(NULL), flag(SCE_O_RDONLY), mode(0) {};

			uint32_t file_type;
			const char *filename;
			uint32_t flag;
			uint32_t mode;
		};

		LocalFile();

		LocalFile(memory::HeapAllocator *allocator);

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

		virtual ~LocalFile();

		void CreateImpl();

		void DeleteImpl();

		static common::SharedPtr<LocalFile> Open(const char *path, uint32_t flag, uint32_t mode, int32_t *error);

		static common::SharedPtr<LocalFile> OpenUrl(const char *path, uint32_t flag, uint32_t mode, int32_t *error, bool *ignored);

		static int32_t Getstat(const char *path, LocalFileStat *buf);

		static int32_t Chstat(const char *path, LocalFileStat *stat, uint32_t cbit);

		static int32_t RemoveFile(const char *path);

		static int32_t RenameFile(const char *oldname, const char *newname);

		static SceOff GetFileSize(const char *path);

		static bool Exists(const char *path);

		static bool IsDirectory(const char *path);

		static bool IsFile(const char *path);

		static int32_t SetDefaultPriority(int32_t ioPriority);

	private:

		thread::RMutex m_lock_mutex;
		LocalFileImpl *m_pimpl;
		memory::HeapAllocator *m_allocator;
	};
}

#endif /* _VDSUITE_USER_PAF_FILE_LOCALFILE_H */
