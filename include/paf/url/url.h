/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_URL_URL_H
#define _VDSUITE_USER_PAF_URL_URL_H

#include <stdint.h>
#include <libhttp.h>
#include <paf/common/string_util.h>

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

		SceHttpUriElement m_url;
		int32_t m_unk_30;
		bool m_unk_34;
		bool m_unk_35;
		common::String m_urlstring;
	};
}

#endif /* _VDSUITE_USER_PAF_URL_URL_H */
