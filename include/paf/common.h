/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_COMMON_H
#define _VDSUITE_USER_PAF_COMMON_H

#include <scetypes.h>
#include <sce_atomic.h>
#include <wchar.h>

namespace paf {

	namespace common {

		template<class T>
		class SharedPtrImpl
		{
		public:

			typedef void(*Deleter)(T *p);

			static void default_deleter(T *ptr)
			{
				delete ptr;
			}

			SharedPtrImpl(T *ptr = NULL) : obj(ptr), ref_count(1), self_ref_count(1), deleter(default_deleter)
			{
			}

			~SharedPtrImpl()
			{
				SceInt32 old = sceAtomicDecrement32AcqRel(&ref_count);
				if (old == 1) {
					deleter(obj);
				}
			}

			bool release(void)
			{
				SceInt32 old = sceAtomicDecrement32AcqRel(&ref_count);
				if (old == 1) {
					deleter(obj);
					return true;
				}
				return false;
			}

			SceInt32 hold()
			{
				sceAtomicIncrement32AcqRel(&ref_count);
				return ref_count;
			}

			T*          obj;             //!< Native pointer
			SceInt32    ref_count;       //!< Reference counter
			SceInt32    self_ref_count;  //!< Self reference counter
			Deleter     deleter;
		};

		template<class T>
		class SharedPtr
		{
		public:

			explicit SharedPtr() : obj(NULL), impl(NULL)
			{
			}

			explicit SharedPtr(SharedPtrImpl<T> * impl) : obj(impl->obj), impl(impl)
			{
			}

			explicit SharedPtr(T *ptr) : obj(ptr), impl(new SharedPtrImpl<T>(ptr))
			{
			}
			/*
			template <typename U, typename D = DefaultDeleter>
			explicit SharedPtr(U *ptr = NULL, D deleter = D()) : obj(ptr), impl(new SharedPtrImpl<T>(ptr, deleter))
			{
			}
			*/
			~SharedPtr()
			{
				if (obj == NULL)
					return;
				if (impl->release()) {
					SceInt32 old = sceAtomicDecrement32AcqRel(&impl->self_ref_count);
					if (old == 1) {
						delete impl;
					}
				}
			}

			SharedPtr(const SharedPtr<T> &other)
			{
				impl = other.impl;
				obj = other.obj;
				if (impl != NULL)
					impl->hold();
			}

			SharedPtr<T> & operator=(const SharedPtr<T> &other)
			{
				if (obj != NULL && obj != other.obj) {
					if (impl->release()) {
						SceInt32 old = sceAtomicDecrement32AcqRel(&impl->self_ref_count);
						if (old == 1) {
							delete impl;
						}
					}
				}

				obj = other.obj;
				impl = other.impl;
				if (impl != NULL)
					impl->hold();

				return *this;
			}

			T * operator->() const
			{
				return obj;
			}

			T & operator*() const
			{
				return *obj;
			}

			template <typename U>
			bool operator<(const SharedPtr<U> &other)
			{
				return obj < other.obj;
			}

			T * get() const
			{
				return obj;
			}

			SharedPtrImpl<T> * getImpl() const
			{
				return impl;
			}

			void reset(T *ptr = NULL)
			{
				if (obj != NULL) {
					if (impl->release()) {
						SceInt32 old = sceAtomicDecrement32AcqRel(&impl->self_ref_count);
						if (old == 1) {
							delete impl;

						}
					}
				}

				obj = ptr;
				if (obj != NULL)
					impl = new SharedPtrImpl<T>(ptr);
				else
					impl = NULL;
			}

		private:

			T *obj;
			SharedPtrImpl<T> *impl;
		};

		class String
		{
		public:

			String();

			String(const char *str);

			String(const wchar_t *str);

			String(string const& src);

			String(wstring const& src);

			~String();

			SceVoid Split(char delim);

			SceVoid Split(paf::string const& delim);

			SceVoid SetFormattedString(char const* format, ...);

			SceVoid SetFormattedString(wchar_t const* format, ...);

			String& operator+=(const String& rhs);

			String& operator+(const String& rhs);

			bool operator==(const String& s);

			bool operator!=(const String& s);

			wstring GetWString() const
			{
				return this->wstring;
			}

			string GetString() const
			{
				return this->string;
			}

		private:

			string string;
			wstring wstring;
		};

		namespace path {

			SceVoid Split(string const& path, string& base, string& file);

			SceVoid SplitExt(string const& path, string& filepath, string& ext);

			// WARNING: this function does not clear dst!
			SceVoid Join(string& dst, string const& filepath, string const& ext);
		}

		namespace string_util {

			extern string ToString(const ScePVoid data, SceSize len);

			extern SceVoid tokenize(list<string>& dst, string const& src, SceUInt32 maxlen, char tok);

			extern SceVoid mapping(paf::map<string, string>& dst, string const& src, SceUInt32 maxlen, char tok1, char tok2);

			extern SceVoid dissolve(list<string>& dst, string const& src, SceUInt32 maxlen, char tok1, char tok2);

			// WARNING: this function does not clear dst!
			extern SceVoid setf(string& dst, char const* format, ...);

			// WARNING: this function does not clear dst!
			extern SceVoid SizeToString(string& dst, SceSize memsize);

			// WARNING: this function does not clear dst!
			extern SceVoid FloatToString(string& dst, SceFloat32 val, bool f1, bool f2, bool f3);

			/**
			 * WARNING: this function does not clear dst!
			 * Possible fmt:
			 * "P" - path
			 * "F" - filename
			 * "E" - extensions
			 * Possible fmt combinations:
			 * "PFE", "PF", "FE" 
			 */
			extern SceVoid ParsePath(string& dst, string const& src, string const& fmt);

			extern SceBool Equal(string const& s1, string const& s2);

			extern SceInt32 ToInt32(const char *s, SceSize len);

			extern SceFloat ToFloat(const char *s, SceSize len);
		}

		namespace frame {

			extern SceUInt32 Get();

			extern SceVoid Reset();

			extern SceVoid Increment();
		};

		class JobCallQueue
		{
		public:

			typedef void(*JobCallQueueEntryFunction)(void *pArgBlock);

			JobCallQueue(const paf::string& name, paf::job::JobQueue *queue);

			~JobCallQueue();

			SceVoid WaitEmpty();

			SceUInt32 GetSize();

			SceVoid Enqueue(const char *pName, JobCallQueueEntryFunction entry, ScePVoid pArgBlock);

			SceVoid Check();

			paf::string name;
			paf::job::JobQueue *queue;

		private:

			SceChar8 m_work[0x28];
		};

		class CallList
		{
		public:

			typedef void(*CallListEntryFunction)(void *pArgBlock);

			CallList();

			virtual ~CallList() = 0;

			SceUInt32 GetNum();

			SceVoid Register(CallListEntryFunction entry, ScePVoid pArgBlock);

			SceUInt32 Unregister(CallListEntryFunction entry, ScePVoid pArgBlock);

			SceVoid Update(paf::thread::Mutex *extMtx);
		};

		class MainThreadCallList
		{
		public:

			typedef void(*MainThreadCallListEntryFunction)(void *pArgBlock);

			static SceVoid Register(MainThreadCallListEntryFunction entry, ScePVoid pArgBlock);

			static SceVoid Unregister(MainThreadCallListEntryFunction entry, ScePVoid pArgBlock);
		};

		class MainThreadCall
		{
		public:

			typedef void(*MainThreadCallEntryFunction)(void *pArgBlock);

			MainThreadCall(MainThreadCallEntryFunction entry, ScePVoid pArgBlock);

			~MainThreadCall();

			SceVoid Run();
		};

		enum UtfConvertFlag
		{
			UtfConvertFlag_AllowIllegalCode = 0x2,
			UtfConvertFlag_AllowOutOfCodeRange = 0x4,
			UtfConvertFlag_AllowInvalidEncode = 0x8,
			UtfConvertFlag_AllowSrcBufferEnd = 0x10
		};

		extern SceSSize Utf16ToUtf8(const wchar_t *src, string *dst);
		extern SceSSize Utf16ToUtf8(const wchar_t *src, string *dst, SceInt32 flags);

		extern SceSSize Utf16ToUtf8(wstring const& src, string *dst);
		extern SceSSize Utf16ToUtf8(wstring const& src, string *dst, SceInt32 flags);

		extern SceSSize Utf8ToUtf16(const char *src, wstring *dst);
		extern SceSSize Utf8ToUtf16(const char *src, wstring *dst, SceInt32 flags);

		extern SceSSize Utf8ToUtf16(string const& src, wstring *dst);
		extern SceSSize Utf8ToUtf16(string const& src, wstring *dst, SceInt32 flags);
	}

	namespace effect
	{
		enum EffectType
		{
			EffectType_Reset = 0xFF,
			EffectType_Fadein1 = 0,
			EffectType_Popup1 = 1,
			EffectType_Popup2 = 2,
			EffectType_SlideFromBottom1 = 3,
			EffectType_SlideFromRight1 = 4,
			EffectType_Fadein2 = 5,
			EffectType_SlideFromTop1 = 6,
			EffectType_SlideFromTop2 = 7,
			EffectType_SlideFromBottom2 = 8,
			EffectType_SlideFromBottom3 = 9,
			EffectType_Popup3 = 0xA,
			EffectType_Popup4 = 0xB,
			EffectType_Popup5 = 0xD,
			EffectType_SlideFromTop3 = 0xE,
			EffectType_SlideFromBottom4 = 0xF,
			EffectType_SlideFromLeft1 = 0x10,
			EffectType_SlideFromRight2 = 0x11,
			EffectType_SlideFromTop4 = 0x12,
			EffectType_SlideFromBottom5 = 0x13,
			EffectType_SlideFromLeft2 = 0x14,
			EffectType_SlideFromRight3 = 0x15,
			EffectType_3D_SlideFromFront = 0x16,
			EffectType_3D_SlideToBack1 = 0x17,
			EffectType_18 = 0x18,
			EffectType_3D_SlideToBack2 = 0x19
		};

		extern SceFloat32 GetDefaultParameterValue(EffectType type);

		extern SceFloat32 GetDefaultParameterValueReverse(EffectType type, paf::ui::Widget *widget = SCE_NULL);

		extern SceFloat32 Play(SceFloat32 parameter, paf::ui::Widget *widget, EffectType effect, bool disableOnEnd, bool ignoreDefaultParameter);

		extern SceFloat32 PlayReverse(SceFloat32 parameter, paf::ui::Widget *widget, EffectType effect, bool disableOnEnd, bool ignoreDefaultParameter);
	}

	/*
	class MainPlugin
	{
	public:

		class Callbacks;

		class LoadArg
		{
		public:

			Callbacks *cb;
		};

		typedef void(*PluginCBWithArg)(LoadArg *arg, Plugin *plugin);
		typedef void(*PluginCB)();

		class Callbacks
		{
		public:

			SceInt32 unk_00;
			PluginCB pluginCreateCB;	//Called after plugin module is loaded and started
			PluginCB pluginInitCB;		//Called after plugin is fully initialized
			PluginCBWithArg pluginStartCB;
			PluginCB pluginStopCB;
			PluginCB pluginExitCB;
		};

		MainPlugin(paf::string *pluginName, paf::string *resourcePath, LoadArg *callbacks);

		//ScePafCommon_17280204 d1
		//ScePafCommon_ED9652F0 d0
		//ScePafCommon_8BC826E1 d2
		virtual ~MainPlugin();

		LoadArg *loadArg;

		SceInt32 unk[9];
	};
	*/
}

#endif /* _VDSUITE_USER_PAF_COMMON_H */
