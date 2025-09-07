/*
	ScePaf-RE Project
*/

#ifndef _PAF_COMMON_HALT_ASSERT_H
#define _PAF_COMMON_HALT_ASSERT_H

#include <stdbool.h>
#include <paf/std/stdc.h>
#include <paf/common/string_misc.h>
#include <paf/paf_types.h>

#if defined(_WIN32) || defined(__SNC__)
#define FUNCNAME __FUNCDNAME__
#elif defined(__vita__)
#define FUNCNAME __PRETTY_FUNCTION__
#else
#define FUNCNAME __func__
#endif

namespace paf {

	typedef void(*ErrorCallback)(void *userdata);

	namespace common_internal {

		static bool s_enable_printf = false;

		static bool s_enable_log = false;

		inline bool printf_enabled()
		{
			return s_enable_printf;
		}

		inline void set_printf_enabled(bool enabled)
		{
			s_enable_printf = enabled;
		}

		inline bool log_enabled()
		{
			return s_enable_log;
		}

		inline void set_log_enabled(bool enabled)
		{
			s_enable_log = enabled;
		}
	}

	namespace common {

		class Log
		{
		public:

			Log()
			{

			}

			~Log()
			{

			}

			Log& operator<<(const char *value)
			{
				if (value)
				{
					if (common_internal::printf_enabled())
					{
						sce_paf_printf(value);
					}
					if (common_internal::log_enabled())
					{
						m_log += value;
					}
				}
				return *this;
			}

			Log& operator<<(string const& value)
			{
				*this << value.c_str();
				return *this;
			}

			Log& operator<<(const bool value)
			{
				*this << ToString(value);
				return *this;
			}

			Log& operator<<(const float value)
			{
				*this << ToString(value);
				return *this;
			}

			Log& operator<<(const int32_t value)
			{
				*this << ToString(value);
				return *this;
			}

			Log& operator<<(const uint32_t value)
			{
				*this << ToString(value);
				return *this;
			}

			/*
			Log& operator<<(const size_t value)
			{
				*this << ToString(value);
				return *this;
			}
			*/

			Log& operator<<(const void *value)
			{
				*this << ToString(value);
				return *this;
			}

			string str() const
			{
				return m_log;
			}

		private:

			string m_log;
		};

		static Log default_log;

		inline common::Log *GetLog()
		{
			return &default_log;
		}

		static ErrorCallback _error_callback;

		#define SCE_PAF_LOG(msg) *paf::common::GetLog() << msg;
	}

	namespace common_internal {

		static bool exit_halt_assert_loop = false;

		inline void set_exit_halt_assert_loop(bool enabled)
		{
			exit_halt_assert_loop = enabled;
		}

		// This method is dummy on PSP2, so we reimplement it here to help with debugging
		inline void on_error(void)
		{
			if (common::_error_callback)
			{
				common::_error_callback(NULL);
			}

			SCE_PAF_LOG(" *** error now entering infinite loop, waiting for you to break in debugger or set \'exit_halt_assert_loop\' to true\n");

			while (!exit_halt_assert_loop)
			{

			}

			abort();
		}

		// This method is dummy on PSP2, so we reimplement it here to help with debugging
		inline void assert_display(const char *_Prefix, const char *_Condition, const char *_File, const char *_Function, int _Line, const char *_Message)
		{
			*common::GetLog() << _Prefix << _File << ":" << _Line << ": " << _Function << ": assertion '" << _Condition << "\' failed: " << _Message << "\n";
		}

#ifdef NDEBUG
		#define SCE_PAF_ASSERT(prefix, msg, expr) \
		if (!(expr)) { \
			abort(); \
		}
#else
		#define SCE_PAF_ASSERT(prefix, msg, expr) \
		if (!(expr)) { \
			paf::common_internal::assert_display(prefix, #expr, __FILE__, FUNCNAME, __LINE__, msg); \
			paf::common_internal::on_error(); \
		}
#endif

#ifdef SCE_PAF_ABORT_UNIMPLEMENTED
		#define SCE_PAF_UNIMPLEMENTED(msg) \
		(*paf::common::GetLog() << "[unimplemented:" << FUNCNAME << "] " << msg << "\n"); \
		paf::common_internal::on_error();
#else
		#define SCE_PAF_UNIMPLEMENTED(msg) (*paf::common::GetLog() << "[unimplemented:" << FUNCNAME << "] " << msg << "\n")
#endif

		inline void SetErrorCallBack(ErrorCallback cb)
		{
			common::_error_callback = cb;
		}
	}
}

#endif /* _PAF_COMMON_HALT_ASSERT_H */
