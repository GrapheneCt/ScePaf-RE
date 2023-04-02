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

			static rtc::Tick ConvertDateTimeToRtcTick(DateTime& dt);

			void ConvertRtcTickToDateTime(rtc::Tick *tick);

			void ParseRFC3339(const char *pszDateTime);

			void ParseSQLiteDateTime(const char *pszDateTime);

			void UTC();

			void Now();

			void NetworkUTC();

			void DayOfWeek(uint16_t a1, uint16_t a2, uint16_t a3);

			uint32_t Wcsftime(wchar_t *buf, int32_t maxLen, wchar_t *format, int32_t flags = 0);

			DateTime& operator+(const DateTime& r) const;

			bool operator<(const DateTime& r) const;

		private:

			uint16_t year;
			uint16_t month;
			uint16_t day;
			uint16_t hour;
			uint16_t minute;
			uint16_t second;
			uint32_t microsecond;
			uint32_t unk_10;
			uint8_t unk_14;
		};
	}
}

#endif /* _VDSUITE_USER_PAF_DATETIME_DATETIME_H */
