/*
	ScePaf-RE Project
*/

#ifndef _PAF_DATETIME_DATETIME_H
#define _PAF_DATETIME_DATETIME_H

#include <stdint.h>
#include <paf/rtc/rtc.h>
#include <paf/std/stdcxx.h>

#undef GetTimeFormat
#undef GetDateFormat

namespace paf {
	namespace datetime {

		class DateTime
		{
		public:

			DateTime
			(
				uint16_t year,
				uint16_t month,
				uint16_t day,
				uint16_t hour,
				uint16_t minute,
				uint16_t second,
				uint32_t microsecond
			);

			DateTime()
			{
				m_year = 2011;
				m_month = 1;
				m_day = 1;
				m_hour = 0;
				m_minute = 0;
				m_second = 0;
				m_microsecond = 0;
				m_tz_offset = 0;
				m_parse_failed = true;
				m_unk_02 = 0;
			};

			~DateTime();

			static void SetTimeFormat(const wchar_t *format);
			static wstring& GetTimeFormat();

			static void SetDateFormat(const wchar_t *format);
			static wstring& GetDateFormat();

			static void SetDateTimeFormat(const wchar_t *format);

			static rtc::Tick ConvertDateTimeToRtcTick(DateTime& dt);

			static DateTime ConvertRtcTickToDateTime(rtc::Tick *tick);

			static DateTime UTC();

			static DateTime Now();

			static DateTime NetworkUTC();

			static DateTime ParseRFC3339(const char *pszDateTime);

			static DateTime ParseSQLiteDateTime(const char *pszDateTime);

			static int32_t DayOfWeek(uint16_t year, uint16_t month, uint16_t day);

			size_t Wcsftime(wchar_t *buf, int32_t maxLen, wchar_t *format, int32_t flags = 0);

			DateTime operator+(const DateTime& r) const;

			bool operator<(const DateTime& r) const;

			bool operator>=(const DateTime& r) const
			{
				return !operator<(r);
			}

			uint16_t Year() const
			{
				return m_year;
			}

			uint16_t Month() const
			{
				return m_month;
			}

			uint16_t Day() const
			{
				return m_day;
			}

			uint16_t Hour() const
			{
				return m_hour;
			}

			uint16_t Minute() const
			{
				return m_minute;
			}

			uint16_t Second() const
			{
				return m_second;
			}

			uint32_t Microsecond() const
			{
				return m_microsecond;
			}

			int32_t TzOffset() const
			{
				return m_tz_offset;
			}

			int16_t unk() const
			{
				return m_unk_02;
			}

		private:

			uint16_t m_year;
			uint16_t m_month;
			uint16_t m_day;
			uint16_t m_hour;
			uint16_t m_minute;
			uint16_t m_second;
			uint32_t m_microsecond;
			int32_t m_tz_offset;
			bool    m_parse_failed;
			int16_t m_unk_02;
		};
	}
}

#endif /* _PAF_DATETIME_DATETIME_H */
