/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_TIMER_TIMER_H
#define _VDSUITE_USER_PAF_TIMER_TIMER_H

#include <stdint.h>
#include <paf/math/math.h>

namespace paf {

	class Timer
	{
	public:

		enum
		{
			STATE_STANDBY = 0,
			STATE_ACTIVE = 1,
			STATE_FINISHED = 2
		};

		enum Repeat
		{
			REPEAT_NONE = 0,
			REPEAT_LOOP = 1,
			REPEAT_ROUND = 4,
			REPEAT_RBACK = 12,
		};

		enum Func
		{
			FUNC_LINEAR = 0,
			FUNC_SLOWDOWN = 1,
			FUNC_FASTUP = 2,
			FUNC_ANGULAR = 3,
			FUNC_EXPONENT = 4,
			FUNC_BEZIER_3D = 5,
			FUNC_SWING = 6,
			FUNC_QUAD_IN = 7,
			FUNC_CUBIC_IN = 8,
			FUNC_QUART_IN = 9,
			FUNC_QUINT_IN = 10,
			FUNC_SINE_IN = 11,
			FUNC_EXPO_IN = 12,
			FUNC_CIRQ_IN = 13,
			FUNC_BACK_IN = 14,
			FUNC_ELASTIC_IN = 15,
			FUNC_BOUNCE_IN = 16,
			FUNC_QUAD_OUT = 17,
			FUNC_CUBIC_OUT = 18,
			FUNC_QUART_OUT = 19,
			FUNC_QUINT_OUT = 20,
			FUNC_SINE_OUT = 21,
			FUNC_EXPO_OUT = 22,
			FUNC_CIRQ_OUT = 23,
			FUNC_BACK_OUT = 24,
			FUNC_ELASTIC_OUT = 25,
			FUNC_BOUNCE_OUT = 26,
			FUNC_QUAD_INOUT = 27,
			FUNC_CUBIC_INOUT = 28,
			FUNC_QUART_INOUT = 29,
			FUNC_QUINT_INOUT = 30,
			FUNC_SINE_INOUT = 31,
			FUNC_EXPO_INOUT = 32,
			FUNC_CIRQ_INOUT = 33,
			FUNC_BACK_INOUT = 34,
			FUNC_ELASTIC_INOUT = 35,
			FUNC_BOUNCE_INOUT = 36,
			FUNC_CUSTOM_EXPO_IN = 37,
			FUNC_CUSTOM_EXPO_OUT = 38,
			FUNC_CUSTOM_EXPO_INOUT = 39,
			FUNC_CUSTOM_EXPO_OUTIN = 40,
			FUNC_CUSTOM_PARABOLIC_IN = 41,
			FUNC_CUSTOM_PARABOLIC_OUT = 42,
			FUNC_CUSTOM_PARABOLIC_INOUT = 43,
			FUNC_CUSTOM_PARABOLIC_OUTIN = 44,
			FUNC_CUSTOM_BOUNCE_IN = 45,
			FUNC_CUSTOM_BOUNCE_OUT = 46,
			FUNC_CUSTOM_BOUNCE_INOUT = 47,
			FUNC_CUSTOM_BOUNCE_OUTIN = 48,
			FUNC_CUSTOM_ELASTIC_IN = 49,
			FUNC_CUSTOM_ELASTIC_OUT = 50,
			FUNC_CUSTOM_ELASTIC_INOUT = 51,
			FUNC_CUSTOM_ELASTIC_OUTIN = 52,
			FUNC_CUSTOM = 53,
		};

		static float Cbrt(float input);

		static void InitTickUnit(float tick_unit);
		static void SetCurrTickInterval(float tick_interval);
		static float GetCurrTickInterval(void)
		{
			return s_tick_interval;
		}
		static float GetCurrTick(void)
		{
			return s_tick_unit * s_tick_interval;
		}

		static float DoFuncCustomParabolicOutIn(float _rate, float *_param);
		static float DoFuncCustomParabolicInOut(float _rate, float *_param);
		static float DoFuncCustomParabolicOut(float _rate, float *_param);
		static float DoFuncCustomElasticOutIn(float _rate, float *_param);
		static float DoFuncCustomElasticInOut(float _rate, float *_param);
		static float DoFuncCustomParabolicIn(float _rate, float *_param);
		static float DoFuncCustomElasticOut(float _rate, float *_param);
		static float DoFuncCustomExpoOutIn(float _rate, float *_param);
		static float DoFuncCustomExpoInOut(float _rate, float *_param);
		static float DoFuncCustomElasticIn(float _rate, float *_param);
		static float DoFuncCustomExpoOut(float _rate, float *_param);
		static float DoFuncCustomExpoIn(float _rate, float *_param);

		static float DoFuncElasticInOut(float _rate);
		static float DoFuncBounceInOut(float _rate);
		static float DoFuncQuintInOut(float _rate);
		static float DoFuncQuartInOut(float _rate);
		static float DoFuncExponent_i(float _curr, float _total, float *_param);
		static float DoFuncElasticOut(float _rate);
		static float DoFuncCubicInOut(float _rate);
		static float DoFuncSineInOut(float _rate);
		static float DoFuncQuadInOut(float _rate);
		static float DoFuncExpoInOut(float _rate);
		static float DoFuncElasticIn(float _rate);
		static float DoFuncCirqInOut(float _rate);
		static float DoFuncBounceOut(float _rate);
		static float DoFuncBackInOut(float _rate);
		static float DoFuncQuintOut(float _rate);
		static float DoFuncQuartOut(float _rate);
		static float DoFuncExponent(float _rate, float _total, float _initval, float *_param);
		static float DoFuncCubicOut(float _rate);
		static float DoFuncBounceIn(float _rate);
		static float DoFuncBezier3d(float _rate, float *_param);
		static float DoFuncSineOut(float _rate);
		static float DoFuncQuintIn(float _rate);
		static float DoFuncQuartIn(float _rate);
		static float DoFuncQuadOut(float _rate);
		static float DoFuncExpoOut(float _rate);
		static float DoFuncCubicIn(float _rate);
		static float DoFuncCirqOut(float _rate);
		static float DoFuncBackOut(float _rate);
		static float DoFuncAngular(float _rate);
		static float DoFuncSlower(float _rate);
		static float DoFuncSineIn(float _rate);
		static float DoFuncQuadIn(float _rate);
		static float DoFuncLinear(float _rate);
		static float DoFuncFaster(float _rate);
		static float DoFuncExpoIn(float _rate);
		static float DoFuncCirqIn(float _rate);
		static float DoFuncBackIn(float _rate);
		static float DoFuncSwing(float _rate);

		Timer(float total, int32_t func = FUNC_LINEAR, int32_t repeat = 0, int32_t rep_count = -1, float* param = NULL, int32_t userdata = 0)
		{
			m_is_2d = false;
			m_is_3d = false;
			m_param_x_num = 0;
			m_param_x = NULL;
			m_mapped_x = 0.0f;
			InitTimer(total, func, repeat, rep_count, param);
		}

		Timer(const Timer& other)
		{
			m_total = other.m_total;
			m_total_inv = other.m_total_inv;
			m_curr = other.m_curr;
			m_repeat_count = other.m_repeat_count;
			m_repeat = other.m_repeat;
			m_state = other.m_state;
			m_first_tick = other.m_first_tick;
			m_is_2d = other.m_is_2d;
			m_is_3d = other.m_is_3d;
			m_func_x = other.m_func_x;
			m_param_x_num = other.m_param_x_num;
			m_param_x = other.m_param_x;
			m_mapped_x = other.m_mapped_x;
		}

		virtual ~Timer();

		void InitTimer(float total, int32_t func, int32_t repeat, int32_t rep_count, const float* param);

		void SetRepeat(int32_t rep, char count)
		{
			m_repeat = rep;
			m_repeat_count = count;
		}

		void SetFuncX(int32_t func, const float* param);

		void DoFinish()
		{
			m_state = 2;
			if (GetRepeat() == REPEAT_RBACK)
			{
				m_curr = 0.0f;
				m_mapped_x = 0.0f;
			}
			else
			{
				m_curr = m_total;
				m_mapped_x = 1.0f;
			}
		}

		void SetTime(float curr)
		{
			m_curr = curr * 0.001f;
		}

		void SetFunc(int32_t func, float* param)
		{
			SetFuncX(func, param);
		}

		float DoTick();

		bool Is3D()
		{
			return m_is_3d;
		}

		bool Is2D()
		{
			return m_is_2d;
		}

		bool IsFinished()
		{
			return (m_state == 2);
		}

		bool IsAllFinished()
		{
			if (IsFinished() && GetRepeat() == REPEAT_NONE)
			{
				return true;
			}
			return false;
		}

		void ResetTimer();

		math::v4 GetValueV4();

		float GetValueX() const
		{
			return m_mapped_x;
		}

		float GetValue() const
		{
			return GetValueX();
		}

		int32_t GetRepeat() const
		{
			return m_repeat;
		}

		int32_t GetFuncX() const
		{
			return m_func_x;
		}

		int32_t GetFunc() const
		{
			return GetFuncX();
		}

		float GetTime() const
		{
			if (m_state == 0)
			{
				return 0.0f;
			}
			return m_curr * 1000.0f;
		}

		int32_t GetRepeatCount() const
		{
			return m_repeat_count;
		}

		float GetTimeNormal() const
		{
			if (m_state == 0)
			{
				return 0.0f;
			}
			return m_curr * m_total_inv;
		}

		float GetTotalTime() const
		{
			return m_total * 1000.0;
		}

		bool IsFirstTick() const
		{
			return m_first_tick;
		}

		float DoFunc(float _rate, int32_t _func, float _pre, float *_param) const;

		__declspec (dllimport) static float s_tick_interval;
		__declspec (dllimport) static float s_tick_unit;
		__declspec (dllimport) static float s_tick_inv;

	protected:

		float m_total;
		float m_total_inv;
		float m_curr;
		char m_repeat_count;
		uint32_t m_repeat : 4;
		uint32_t m_state : 4;
		bool m_first_tick : 1;
		bool m_unk_12_1 : 1;
		bool m_is_2d : 1;
		bool m_is_3d : 1;
		uint32_t m_func_x : 8;
		uint32_t m_param_x_num : 4;
		float *m_param_x;
		float m_mapped_x;
	};

	class Timer2D : public Timer
	{
	public:

	Timer2D(float total, int32_t func_x, int32_t func_y, int32_t repeat, int32_t rep_count, float *param_x, float *param_y, int32_t userdata) :
		Timer(total, func_x, repeat, rep_count, param_x, userdata)
	{
		m_is_2d = true;
		m_param_y_num = 0;
		m_param_y = NULL;
		m_mapped_y = 0.0f;
		SetFuncY(func_y, param_y);
	}

	virtual ~Timer2D();

	float DoTick();

	void SetFuncY(int32_t func, const float* param);

	float GetValueY() const
	{
		return m_mapped_y;
	}

	void ResetTimer()
	{
		Timer::ResetTimer();
		sync_mapped();
	}

	void sync_mapped()
	{
		m_mapped_y = m_mapped_x;
	}

	protected:

		uint32_t m_func_y : 8;
		uint32_t m_param_y_num : 4;
		float *m_param_y;
		float m_mapped_y;
	};

	class Timer3D : public Timer2D
	{
	public:

		Timer3D(float total, int32_t func_x, int32_t func_y, int32_t func_z, int32_t repeat, int32_t rep_count, float *param_x, float *param_y, float *param_z, int32_t userdata) :
			Timer2D(total, func_x, func_y, repeat, rep_count, param_x, param_y, userdata)
		{
			m_is_3d = true;
			m_param_z_num = 0;
			m_param_z = NULL;
			m_mapped_z = 0.0f;
			SetFuncZ(func_z, param_z);
		}

		virtual ~Timer3D();

		float DoTick();

		void SetFuncZ(int32_t func, const float* param);

		float GetValueZ() const
		{
			return m_mapped_z;
		}

		void ResetTimer()
		{
			Timer::ResetTimer();
			sync_mapped();
		}

		void sync_mapped()
		{
			Timer2D::sync_mapped();
			m_mapped_z = m_mapped_x;
		}

	protected:

		uint32_t m_func_z : 8;
		uint32_t m_param_z_num : 4;
		float *m_param_z;
		float m_mapped_z;
	};
}

#endif /* _VDSUITE_USER_PAF_TIMER_TIMER_H */