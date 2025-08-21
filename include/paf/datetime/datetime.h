/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_DATETIME_DATETIME_H
#define _VDSUITE_USER_PAF_DATETIME_DATETIME_H

#include <stdint.h>
#include <paf/rtc/rtc.h>

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

			DateTime() { };

			~DateTime();

			static void SetTimeFormat(const wchar_t *format);
			static wstring& GetTimeFormat();

			static void SetDateFormat(const wchar_t *format);
			static wstring& GetDateFormat();

			static void SetDateTimeFormat(const wchar_t *format);

			rtc::Tick ConvertDateTimeToRtcTick(DateTime& dt);

			void ConvertRtcTickToDateTime(rtc::Tick *tick);

			static DateTime ParseRFC3339(const char *pszDateTime);

			void ParseSQLiteDateTime(const char *pszDateTime);

			static DateTime UTC();

			void Now();

			void NetworkUTC();

			void DayOfWeek(uint16_t a1, uint16_t a2, uint16_t a3);

			uint32_t Wcsftime(wchar_t *buf, int32_t maxLen, wchar_t *format, int32_t flags = 0);

			DateTime& operator+(const DateTime& r) const;

			bool operator<(const DateTime& r) const;

			uint16_t Year() const
			{
				return year;
			}

			uint16_t Month() const
			{
				return month;
			}

			uint16_t Day() const
			{
				return day;
			}

			uint16_t Hour() const
			{
				return hour;
			}

			uint16_t Minute() const
			{
				return minute;
			}

			uint16_t Second() const
			{
				return second;
			}

			uint32_t Microsecond() const
			{
				return microsecond;
			}

			int32_t TzOffset() const
			{
				return tz_offset;
			}

			int16_t unk() const
			{
				return unk_02;
			}

		private:

			uint16_t year;
			uint16_t month;
			uint16_t day;
			uint16_t hour;
			uint16_t minute;
			uint16_t second;
			uint32_t microsecond;
			int32_t tz_offset;
			bool    parse_failed;
			int16_t unk_02;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_DATETIME_DATETIME_H */
