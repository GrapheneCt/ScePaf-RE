/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_FILE_HTTPFILE_H
#define _VDSUITE_USER_PAF_FILE_HTTPFILE_H

#include <stdint.h>
#include <stddef.h>
#include <kernel.h>
#include <paf/std/string>
#include <paf/thread/rmutex.h>
#include <paf/thread/rwlock.h>
#include <paf/common/shared_ptr.h>
#include <paf/file/file.h>
#include <paf/file/httpfile_types.h>

namespace paf {

	class Url;

	class HttpFile : public File
	{
	public:

		class Reader;

		class OpenArg : public File::OpenArg
		{
		public:

			enum HttpFileOpenFlag
			{
				ENABLE_RANGE_GET = 0x1000000,
				ENABLE_HALF_RANGE_GET = 0x2000000,
				DISABLE_HTTPS_CHECK = 0x4000000,
				IGNORE_PROXY_SETTING = 0x8000000,
				SUPPRESS_WIFI_ACCESS = 0x20000000,
				SUPPRESS_3G_ACCESS = 0x40000000
			};

			enum HttpsFlag
			{
				HTTPS_FLAG_SERVER_VERIFY = 1,
				HTTPS_FLAG_CLIENT_VERIFY = 2,
				HTTPS_FLAG_CN_CHECK = 4,
				HTTPS_FLAG_NOT_AFTER_CHECK = 8,
				HTTPS_FLAG_NOT_BEFORE_CHECK = 16,
				HTTPS_FLAG_KNOWN_CA_CHECK = 32,
				HTTPS_FLAG_DEFAULT = 63,
				HTTPS_FLAG_MASK = 63
			};

			enum OptionType
			{
				OptionType_ResolveTimeOut = 1,
				OptionType_ConnectTimeOut = 2,
				OptionType_SendTimeOut = 4,
				OptionType_RecvTimeOut = 8,
			};

			OpenArg();

			~OpenArg() {};

			int32_t ParseUrl(const char *url);

			int32_t ParseUrl(const wchar_t *url);

			int32_t ParseUrl(Url *url);

			int32_t SetOption(int32_t value, OptionType type);

			int32_t AddRequestHeader(const char *name, const char *value);

			uint32_t file_type;
			string scheme;
			string host;
			uint16_t port;
			string method;
			string uri;
			string version;
			string user_agent;
			string referer;
			string user;
			string passwd;
			vector<string> header;
			void *msg_body;
			size_t msg_body_len;
			int32_t unk_8C;
			uint32_t open_flag;
			char unk_94[0x24];
		};

		HttpFile();

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

		virtual ~HttpFile();

		int32_t GetResponseCode(uint16_t& code) const;

		int32_t GetResponseHeader(const char *name, string& value) const;

		int32_t GetResponsePhrase(string& phrase) const;

		int32_t GetResponseVersion(uint8_t& major, uint8_t& minor);

		static int32_t Getstat(const char *url, HttpFileStat *stat);

		static common::SharedPtr<HttpFile> Open(Url *url, int32_t *result, uint32_t flag);

		static common::SharedPtr<HttpFile> Open(const char *path, uint32_t flag, uint32_t mode, int32_t *result);

		static common::SharedPtr<HttpFile> Open(const wchar_t *url, int32_t *result, uint32_t flag);

	private:

		bool m_is_opened;
		thread::RWLock m_lock_rwlock;
		thread::RMutex m_lock_mutex;
		/*
		thread::Thread *m_io_thread;
		Reader *m_http_reader;
		*/
		char unk_30[0x1C];
	};
}

#endif /* _VDSUITE_USER_PAF_FILE_HTTPFILE_H */
