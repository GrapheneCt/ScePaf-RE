/*
	ScePaf-RE Project
*/

#ifndef _PAF_FILE_LOCALFILE_PLATFORM_H
#define _PAF_FILE_LOCALFILE_PLATFORM_H

#include <stdint.h>
#include <stddef.h>
#include <paf/paf_types.h>
#include <paf/file/file.h>
#include <paf/file/localfile_types.h>
#include <paf/file/localfile_impl.h>

#if defined(__SNC__) || defined(__vita__)

#if defined(__SNC__)
#include <scetypes.h>
#elif defined(__vita__)
#include <psp2/types.h>
#endif

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
		virtual int64_t Seek(int64_t offset, int32_t whence);
		virtual int32_t Flush();
		virtual int32_t OpenAsync(const char *filename, uint32_t flag, uint32_t mode);
		virtual int32_t CloseAsync();
		virtual int32_t ReadAsync(void *buf, size_t nbyte);
		virtual int32_t WriteAsync(const void *buf, size_t nbyte);
		virtual int32_t SeekAsync(int64_t offset, int32_t whence);
		virtual int32_t FlushAsync();
		virtual int32_t WaitAsync(int64_t *result);
		virtual int32_t PollAsync(int64_t *result);
		virtual bool    IsOpened();
		virtual bool    IsEof();
		virtual int32_t Abort();
		virtual int64_t GetFileSize();
		virtual int32_t Getstat(FileStat *stat);
		virtual int32_t SetPriority(int32_t priority);

		static int32_t RenameFile(const char *oldname, const char *newname);

		static int32_t RemoveFile(const char *path);

		static int64_t GetFileSize(const char *path);

		static int32_t Getstat(const char *path, LocalFileStat *buf);

		static int32_t Chstat(const char *path, LocalFileStat *stat, uint32_t cbit);

		static int32_t SetDefaultPriority(int32_t priority);

	private:

		enum
		{
			TYPE_NONE = 0,
			TYPE_OPEN = 1,
			TYPE_CLOSE = 2,
			TYPE_READ = 3,
			TYPE_WRITE = 4,
			TYPE_SEEK = 5,
			TYPE_FLUSH = 6
		};

		bool m_is_opened;
		SceUID m_fd;
		char m_async[24]; // SceIoAsync async;
		int32_t m_as_result;
		uint32_t m_async_type;
	};
}

#elif defined(_WIN32)

namespace paf {

	class LocalFilePlatformImpl : public LocalFileImpl
	{
	public:

		LocalFilePlatformImpl();

		virtual ~LocalFilePlatformImpl();

		virtual int32_t Open(const char *filename, uint32_t flag, uint32_t mode);
		virtual int32_t Close();
		virtual int32_t Read(void *buf, size_t nbyte);
		virtual int32_t Write(const void *buf, size_t nbyte);
		virtual int64_t Seek(int64_t offset, int32_t whence);
		virtual int32_t Flush();
		virtual int32_t OpenAsync(const char *filename, uint32_t flag, uint32_t mode);
		virtual int32_t CloseAsync();
		virtual int32_t ReadAsync(void *buf, size_t nbyte);
		virtual int32_t WriteAsync(const void *buf, size_t nbyte);
		virtual int32_t SeekAsync(int64_t offset, int32_t whence);
		virtual int32_t FlushAsync();
		virtual int32_t WaitAsync(int64_t *result);
		virtual int32_t PollAsync(int64_t *result);
		virtual bool    IsOpened();
		virtual bool    IsEof();
		virtual int32_t Abort();
		virtual int64_t GetFileSize();
		virtual int32_t Getstat(FileStat *stat);
		virtual int32_t SetPriority(int32_t priority);

		static int32_t RenameFile(const char *oldname, const char *newname);

		static int32_t RemoveFile(const char *path);

		static int64_t GetFileSize(const char *path);

		static int32_t Getstat(const char *path, LocalFileStat *buf);

		static int32_t Chstat(const char *path, LocalFileStat *stat, uint32_t cbit);

		static int32_t SetDefaultPriority(int32_t priority);

	private:

		enum
		{
			TYPE_NONE = 0,
			TYPE_OPEN = 1,
			TYPE_CLOSE = 2,
			TYPE_READ = 3,
			TYPE_WRITE = 4,
			TYPE_SEEK = 5,
			TYPE_FLUSH = 6
		};

		bool m_is_opened;
		HANDLE m_win_fd;
		int32_t m_posix_fd;
		OVERLAPPED m_async;
		int64_t m_as_result;
		uint32_t m_async_type;
	};
}

#else
#error Current target platform is not supported or no target platform defined
#endif

#endif /* _PAF_FILE_LOCALFILE_PLATFORM_H */
