/*
	ScePaf-RE Project
*/

#ifndef _PAF_URL_URL_H
#define _PAF_URL_URL_H

#ifndef SCE_PAF_NO_NETWORK

#include <stdint.h>
#include <paf/common/string_util.h>
#if defined(__SNC__)
#include <libhttp.h>
#define SCE_PAF_URL_TYPE SceHttpUriElement
#elif defined(__vita__)
#include <psp2/net/http.h>
#define SCE_PAF_URL_TYPE SceHttpUriElement
#elif defined(_WIN32)
#define SCE_PAF_URL_TYPE void*
#else
#error Current target platform is not supported or no target platform defined
#endif

namespace paf {
	
	class Url
	{
	public:

		Url();

		Url(Url const& r);

		Url(string const& url);

		Url(wstring const& url);

		virtual ~Url();

		Url& operator=(string const& url);

		Url& operator=(wstring const& url);

		string GetUrlString() const;

		wstring GetUrlWString() const;

		string GetBaseUrlString() const;

		wstring GetBaseUrlWString() const;

		string GetHostString() const;

		wstring GetHostWString() const;

		string GetParamaterString() const;

		wstring GetParamaterWString() const;

		string GetAnchorString() const;

		wstring GetAnchorWString() const;

		string GetPasswordString() const;

		wstring GetPasswordWString() const;

		string GetPathString() const;

		wstring GetPathWString() const;

		int32_t GetPort() const;

		string GetQueryString() const;

		wstring GetQueryWString() const;

		string GetRelativePathString() const;

		wstring GetRelativePathWString() const;

		string GetUserString() const;

		wstring GetUserWString() const;

		string GetSchemeString() const;

		wstring GetSchemeWString() const;

	private:

		void ParseUrl();

		SCE_PAF_URL_TYPE m_url;
		int32_t m_unk_30;
		bool m_unk_34;
		bool m_unk_35;
		common::String m_urlstring;
	};
}

#endif /* SCE_PAF_NO_NETWORK */

#endif /* _PAF_URL_URL_H */
