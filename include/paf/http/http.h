#ifndef _PAF_HTTP_HTTP_H
#define _PAF_HTTP_HTTP_H

#ifndef SCE_PAF_NO_NETWORK

namespace paf {
	namespace http {

		extern int32_t Download(const char *url, const char *localfile, string *somestuff);

		class Client
		{
		public:

			class Option
			{
			public:

				Option()
				{
					debugFlags = 1;
					resolveTimeout = 0;
					resolveRetry = 0;
					connectTimeout = 0;
					sendTimeout = 0;
					recvTimeout = 0;
					unk_48 = 1;
				}

				~Option() { }

				string userAgent;
				int32_t debugFlags; // can be 2, 4 or 8
				string username;
				string password;
				string referer;
				int32_t resolveTimeout;
				int32_t resolveRetry;
				int32_t connectTimeout;
				int32_t sendTimeout;
				int32_t recvTimeout;
				int32_t unk_48;
			};

			Client(Option& opt);

			~Client();

		protected:

			string userAgent;
			int32_t debugFlags;
			string username;
			string password;
			string referer;
			int32_t resolveTimeout;
			int32_t resolveRetry;
			int32_t connectTimeout;
			int32_t sendTimeout;
			int32_t recvTimeout;
			int32_t unk_48;
			int32_t templateId;
		};

		class Transaction
		{
		public:

			Transaction(Client& cl);

			~Transaction();

			int32_t SetRequestHeader(const char *name, const char *value);

			int32_t SendRequest(const void *postData = NULL, size_t size = 0);

			int32_t GetStatusCode(int32_t& statusCode);

			int32_t GetFileName(string& filename);

			int32_t GetMimeType(string& mimeType);

			int32_t GetContentLength(uint64_t& contentLength);

			int32_t GetAutoRedirect(bool& Enabled);

			int32_t SetAutoRedirect(bool enabled);

			int32_t SetResponseHeaderMaxSize(size_t size);

			int32_t DumpResponseHeaders();

			int32_t GetResponseHeader(const char *fieldName, string& fieldValue);

			// Bad names ahead

			int32_t Connect(const char *url, const char *method, void *unkCbClass = NULL);

			int32_t Connect(const char *url, const char *method, void *unkCbClass, uint64_t postContentLength);

			int32_t Read(common::SharedPtr<Buffer>& pBuf, int32_t *pReadSize = NULL);

			int32_t Abort();

			int32_t GetUrl(string& pUrl);

		protected:

			Client& cl;
			void *cbTask;
			int32_t connectionId;
			int32_t requestId;
			int32_t unk_10;
			string url;
		};

	}
}

#endif

#endif /* _PAF_HTTP_HTTP_H */
