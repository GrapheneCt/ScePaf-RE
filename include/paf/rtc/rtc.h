/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_RTC_RTC_H
#define _VDSUITE_USER_PAF_RTC_RTC_H

#include <paf/paf_types.h>
#include <stdint.h>

namespace paf {
	namespace rtc {

		typedef uint64_t Tick;

		class SQLiteDateTimeFormatType;
		class DateTime;
		class DateTimeEx;

		extern int32_t IsLeapYear(uint16_t year);

		extern int32_t IsLeapYear(const Tick *pTick);

		extern int32_t GetDaysInMonth(const Tick *pTick);

		extern int32_t GetDaysInMonth(const uint16_t *pA1, uint16_t a2);

		extern int32_t ParseSQLiteDateTime(Tick *pTick, const char *dt);

		extern int32_t ParseSQLiteDateTime(Tick *pTick, SQLiteDateTimeFormatType *ftype, const char *dt);

		extern int32_t ConvertDateTimeToTick(DateTime const* src, Tick *pTick);

		extern int32_t ConvertTickToDateTime(Tick *pTick, DateTime *dst);

		extern int32_t GetCurrentLocalTick(Tick *pTick);

		extern int32_t GetCurrentTick(Tick *pTick);

		extern int32_t GetCurrentNetworkTick(Tick *pTick);

		extern int32_t TickAddMicroseconds(Tick *pTick0, const Tick *pTick1, off_t lAdd);

		extern int32_t TickAddSeconds(Tick *pTick0, const Tick *pTick1, off_t lAdd);

		extern int32_t TickAddMinutes(Tick *pTick0, const Tick *pTick1, off_t lAdd);

		extern int32_t TickAddHours(Tick *pTick0, const Tick *pTick1, int32_t iAdd);

		extern int32_t TickAddDays(Tick *pTick0, const Tick *pTick1, int32_t iAdd);

		extern int32_t TickAddWeeks(Tick *pTick0, const Tick *pTick1, int32_t iAdd);

		extern int32_t TickAddMonths(Tick *pTick0, const Tick *pTick1, int32_t iAdd);

		extern int32_t TickAddYears(Tick *pTick0, const Tick *pTick1, int32_t iAdd);

		extern int32_t ConvertUtcToLocalTime(const Tick *pUtc, Tick *pLocalTime);

		extern int32_t ConvertLocalTimeToUtc(const Tick *pLocalTime, Tick *pUtc);

		extern int32_t ParseRFC3339(Tick *pUtc, const char *pszDateTime);

		extern int32_t ParseRFC3339LocalTime(Tick *pUtc, const char *pszDateTime);

		extern int32_t FormatRFC3339(char *pszDateTime, const Tick *pUtc, int32_t iTimeZoneMinutes);

		extern int32_t FormatRFC3339LocalTime(char *pszDateTime, const Tick *pUtc);
	}
}

#endif /* _VDSUITE_USER_PAF_RTC_RTC_H */
