/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_VERSATILEPARAM_IDPARAM_H
#define _VDSUITE_USER_PAF_VERSATILEPARAM_IDPARAM_H

#include <stddef.h>
#include <paf/std/stdcxx.h>

namespace paf {

	class IDParam
	{
	public:

		IDParam()
		{
			m_idhash = 0;
		}

		IDParam(uint32_t idhash)
		{
			m_idhash = idhash;
		}

		IDParam(const char* id)
		{
			if (id == NULL)
			{
				m_idhash = 0;
			}
			else
			{
				SetID(string(id));
			}
		}

		IDParam(const string& id)
		{
			SetID(string(id));
		}

		IDParam(const IDParam& idparam)
		{
			m_id = idparam.m_id;
			m_idhash = idparam.m_idhash;
		}

		~IDParam()
		{

		}

		uint32_t ID2IDHash(const string& id);

		void SetIDHash(uint32_t idhash)
		{
			m_idhash = idhash;
		}

		void SetID(const string& id)
		{
			m_id = id;
			m_idhash = ID2IDHash(id);
		}

		void SetID(const char *id)
		{
			m_id = id;
			m_idhash = ID2IDHash(m_id);
		}

		void SetIDOnly(const string& id)
		{
			m_id = id;
		}

		IDParam& operator=(uint32_t idhash)
		{
			m_idhash = idhash;
			return *this;
		}

		IDParam& operator=(const char* id)
		{
			if (id == NULL)
			{
				m_idhash = 0;
			}
			else
			{
				SetID(string(id));
			}
			return *this;
		}

		IDParam& operator=(const IDParam& idparam)
		{
			m_id = idparam.m_id;
			m_idhash = idparam.m_idhash;
			return *this;
		}

		string GetID() const
		{
			return m_id;
		}

		uint32_t GetIDHash() const
		{
			return m_idhash;
		}

		operator uint32_t() const
		{
			return m_idhash;
		}

		operator const char*() const
		{
			return m_id.c_str();
		}

		bool operator==(IDParam const& idparam) const
		{
			return (m_idhash == idparam.m_idhash);
		}

		bool operator<(IDParam const& idparam) const
		{
			return (m_idhash < idparam.m_idhash);
		}

		bool operator!=(IDParam const& idparam) const
		{
			return (m_idhash != idparam.m_idhash);
		}

	private:

		string m_id;
		uint32_t m_idhash;
	};

}

#endif /* _VDSUITE_USER_PAF_VERSATILEPARAM_IDPARAM_H */