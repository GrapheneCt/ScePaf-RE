/*
	ScePaf-RE Project
*/

#ifndef _PAF_TIMER_TIMER_H
#define _PAF_TIMER_TIMER_H

#include <stdint.h>
#include <paf/math/math.h>
#include <paf/paf_types.h>

namespace paf {

	class Timer
	{
	public:

		enum
		{
			STATE_STANDBY = 0,
			STATE_ACTIVE = 1,
			STATE_FINISHED = 2,
			STATE_UNK_3 = 3,
			STATE_UNK_4 = 4
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
			FUNC_LINEAR,
			FUNC_SLOWDOWN,
			FUNC_FASTUP,
			FUNC_ANGULAR,
			FUNC_EXPONENT,
			FUNC_BEZIER_3D,
			FUNC_SWING,
			FUNC_QUAD_IN,
			FUNC_CUBIC_IN,
			FUNC_QUART_IN,
			FUNC_QUINT_IN,
			FUNC_SINE_IN,
			FUNC_EXPO_IN,

			FUNC_EXPO_IN_UNK_13,
			FUNC_EXPO_IN_UNK_14,
			FUNC_EXPO_IN_UNK_15,
			FUNC_EXPO_IN_UNK_16,

			FUNC_CIRQ_IN,
			FUNC_BACK_IN,
			FUNC_ELASTIC_IN,
			FUNC_BOUNCE_IN,
			FUNC_QUAD_OUT,
			FUNC_CUBIC_OUT,
			FUNC_QUART_OUT,
			FUNC_QUINT_OUT,
			FUNC_SINE_OUT,
			FUNC_EXPO_OUT,

			FUNC_EXPO_OUT_UNK_27,
			FUNC_EXPO_OUT_UNK_28,
			FUNC_EXPO_OUT_UNK_29,
			FUNC_EXPO_OUT_UNK_30,

			FUNC_CIRQ_OUT,
			FUNC_BACK_OUT,
			FUNC_ELASTIC_OUT,
			FUNC_BOUNCE_OUT,
			FUNC_QUAD_INOUT,
			FUNC_CUBIC_INOUT,
			FUNC_QUART_INOUT,
			FUNC_QUINT_INOUT,
			FUNC_SINE_INOUT,
			FUNC_EXPO_INOUT,

			FUNC_EXPO_INOUT_UNK_41,
			FUNC_EXPO_INOUT_UNK_42,
			FUNC_EXPO_INOUT_UNK_43,
			FUNC_EXPO_INOUT_UNK_44,

			FUNC_CIRQ_INOUT,
			FUNC_BACK_INOUT,
			FUNC_ELASTIC_INOUT,
			FUNC_BOUNCE_INOUT,

			FUNC_UNK_49,
			FUNC_UNK_50,
			FUNC_UNK_51,
			FUNC_UNK_52,
			FUNC_UNK_53,
			FUNC_UNK_54,

			FUNC_CUSTOM_EXPO_IN,
			FUNC_CUSTOM_EXPO_OUT,
			FUNC_CUSTOM_EXPO_INOUT,
			FUNC_CUSTOM_EXPO_OUTIN,
			FUNC_CUSTOM_PARABOLIC_IN,
			FUNC_CUSTOM_PARABOLIC_OUT,
			FUNC_CUSTOM_PARABOLIC_INOUT,
			FUNC_CUSTOM_PARABOLIC_OUTIN,
			FUNC_CUSTOM_BOUNCE_IN,
			FUNC_CUSTOM_BOUNCE_OUT,
			FUNC_CUSTOM_BOUNCE_INOUT,
			FUNC_CUSTOM_BOUNCE_OUTIN,
			FUNC_CUSTOM_ELASTIC_IN,
			FUNC_CUSTOM_ELASTIC_OUT,
			FUNC_CUSTOM_ELASTIC_INOUT,
			FUNC_CUSTOM_ELASTIC_OUTIN,

			FUNC_CUSTOM_UNK_71,
			FUNC_CUSTOM_UNK_72,
			FUNC_CUSTOM_UNK_73,
			FUNC_CUSTOM_UNK_74,
			FUNC_CUSTOM_UNK_75,
			FUNC_CUSTOM_UNK_76,
			FUNC_CUSTOM_UNK_77,
			FUNC_CUSTOM_UNK_78,

			FUNC_CUSTOM,
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
			m_state = STATE_FINISHED;
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

		void SetFunc(int32_t func, const float* param)
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
			return (m_state == STATE_FINISHED);
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
			if (m_state == STATE_STANDBY)
			{
				return 0.0f;
			}
			return m_curr * 1000.0f;
		}

		int32_t GetState() const
		{
			return m_state;
		}

		int32_t GetRepeatCount() const
		{
			return m_repeat_count;
		}

		float GetTimeNormal() const
		{
			if (m_state == STATE_STANDBY)
			{
				return 0.0f;
			}
			return m_curr * m_total_inv;
		}

		float GetTotalTime() const
		{
			return m_total * 1000.0f;
		}

		bool IsFirstTick() const
		{
			return m_first_tick;
		}

		float DoFunc(float _rate, int32_t _func, float _pre, float *_param) const;

		SCE_PAF_IMPORTED_FROM_PRX static float s_tick_unit;
		SCE_PAF_IMPORTED_FROM_PRX static float s_tick_inv;
		SCE_PAF_IMPORTED_FROM_PRX static float s_tick_interval;

	protected:

		int32_t init_func_param(int32_t func, const float *param, float **ret_param, int32_t *ret_param_num);

		float m_total;
		float m_total_inv;
		float m_curr;
		uint8_t m_repeat_count;
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

	private:

		int32_t check_bezier_param(float *param);

		int32_t check_custom_param(float *param);
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

	protected:

		void sync_mapped()
		{
			m_mapped_y = m_mapped_x;
		}

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

	protected:

		void sync_mapped()
		{
			Timer2D::sync_mapped();
			m_mapped_z = m_mapped_x;
		}

		uint32_t m_func_z : 8;
		uint32_t m_param_z_num : 4;
		float *m_param_z;
		float m_mapped_z;
	};
}

#endif /* _PAF_TIMER_TIMER_H */