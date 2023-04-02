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

		template <typename T> class SharedPtr;

		// This class is an internal implementation detail for shared_ptr. If two
		// shared_ptrs point to the same object, they also share a control block.
		// An "empty" shared_pointer refers to NULL and also has a NULL control block.
		// It contains all of the state that's needed for reference counting or any
		// other kind of resource management. In this implementation the control block
		// happens to consist of two atomic words, the reference count (the number
		// of shared_ptrs that share ownership of the object) and the weak count
		// (the number of weak_ptrs that observe the object, plus 1 if the
		// refcount is nonzero).
		//
		// The "plus 1" is to prevent a race condition in the shared_ptr and
		// weak_ptr destructors. We need to make sure the control block is
		// only deleted once, so we need to make sure that at most one
		// object sees the weak count decremented from 1 to 0.
		template<class T>
		class SharedPtrControlBlock
		{
			template <typename T> friend class SharedPtr;

		private:

			typedef void(*Deleter)(T *p);

			static void default_deleter(T *ptr)
			{
				delete ptr;
			}

			SharedPtrControlBlock(T *ptr = SCE_NULL) : refcount_(1), weak_count_(1), deleter_(default_deleter) { }

			T* obj_; //Used only in SCE impl
			SceInt32 refcount_;
			SceInt32 weak_count_;
			Deleter deleter_;
		};

		template <typename T> class EnableSharedFromThis;
		template <typename T>
		class SharedPtr
		{
		public:

			typedef T element_type;

			SharedPtr() : ptr_(SCE_NULL), control_block_(SCE_NULL) {}

			explicit SharedPtr(T* ptr) : ptr_(ptr), control_block_(ptr != SCE_NULL ? new SharedPtrControlBlock<T>(ptr) : SCE_NULL)
			{
				// If p is non-null and T inherits from enable_shared_from_this, we
				// set up the data that shared_from_this needs.
				MaybeSetupWeakThis(ptr);
			}

			// Copy constructor: makes this object a copy of ptr, and increments
			// the reference count.
			template <typename U>
			SharedPtr(const SharedPtr<U>& ptr) : ptr_(SCE_NULL), control_block_(SCE_NULL)
			{
				Initialize(ptr);
			}

			// Need non-templated version to prevent the compiler-generated default
			SharedPtr(const SharedPtr<T>& ptr) : ptr_(SCE_NULL), control_block_(SCE_NULL)
			{
				Initialize(ptr);
			}

			// Assignment operator. Replaces the existing SharedPtr with ptr.
			// Increment ptr's reference count and decrement the one being replaced.
			template <typename U>
			SharedPtr<T>& operator=(const SharedPtr<U>& ptr)
			{
				if (ptr_ != ptr.ptr_)
				{
					SharedPtr<T> me(ptr);   // will hold our previous state to be destroyed.
					swap(me);
				}
				return *this;
			}

			// Need non-templated version to prevent the compiler-generated default
			SharedPtr<T>& operator=(const SharedPtr<T>& ptr)
			{
				if (ptr_ != ptr.ptr_)
				{
					SharedPtr<T> me(ptr);   // will hold our previous state to be destroyed.
					swap(me);
				}
				return *this;
			}

			~SharedPtr()
			{
				if (ptr_ != SCE_NULL)
				{
					if (sceAtomicDecrement32AcqRel(&control_block_->refcount_) == 1)
					{
						control_block_->deleter_(ptr_);

						// weak_count_ is defined as the number of weak_ptrs that observe
						// ptr_, plus 1 if refcount_ is nonzero.
						if (sceAtomicDecrement32AcqRel(&control_block_->weak_count_) == 1)
						{
							delete control_block_;
						}
					}
				}
			}

			// Replaces underlying raw pointer with the one passed in.  The reference
			// count is set to one (or zero if the pointer is NULL) for the pointer
			// being passed in and decremented for the one being replaced.
			//
			// If you have a compilation error with this code, make sure you aren't
			// passing NULL, nullptr, or 0 to this function.  Call reset without an
			// argument to reset to a null ptr.
			template <typename Y>
			void reset(Y* p)
			{
				if (p != ptr_)
				{
					SharedPtr<T> tmp(p);
					tmp.swap(*this);
				}
			}

			void reset()
			{
				reset(static_cast<T*>(SCE_NULL));
			}

			// Exchanges the contents of this with the contents of r.  This function
			// supports more efficient swapping since it eliminates the need for a
			// temporary SharedPtr object.
			void swap(SharedPtr<T>& r)
			{
				using std::swap;  // http://go/using-std-swap
				swap(ptr_, r.ptr_);
				swap(control_block_, r.control_block_);
			}

			// The following function is useful for gaining access to the underlying
			// pointer when a SharedPtr remains in scope so the reference-count is
			// known to be > 0 (e.g. for parameter passing).
			T* get() const
			{
				return ptr_;
			}

			T& operator*() const
			{
				return *ptr_;
			}

			T* operator->() const
			{
				return ptr_;
			}

			long use_count() const
			{
				return control_block_ ? control_block_->refcount_ : 1;
			}

			bool unique() const
			{
				return use_count() == 1;
			}

		private:
			// If r is non-empty, initialize *this to share ownership with r,
			// increasing the underlying reference count.
			// If r is empty, *this remains empty.
			// Requires: this is empty, namely this->ptr_ == NULL.
			template <typename U>
			void Initialize(const SharedPtr<U>& r)
			{
				// This performs a static_cast on r.ptr_ to U*, which is a no-op since it
				// is already a U*. So initialization here requires that r.ptr_ is
				// implicitly convertible to T*.
				InitializeWithStaticCast<U>(r);
			}

			// Initializes *this as described in Initialize, but additionally performs a
			// static_cast from r.ptr_ (V*) to U*.
			template <typename U, typename V>
			void InitializeWithStaticCast(const SharedPtr<V>& r)
			{
				if (r.control_block_ != SCE_NULL)
				{
					sceAtomicIncrement32AcqRel(&r.control_block_->refcount_);

					ptr_ = static_cast<U*>(r.ptr_);
					control_block_ = r.control_block_;
				}
			}

			// Helper function for the constructor that takes a raw pointer. If T
			// doesn't inherit from EnableSharedFromThis<T> then we have nothing to
			// do, so this function is trivial and inline. The other version is declared
			// out of line, after the class definition of EnableSharedFromThis.
			void MaybeSetupWeakThis(EnableSharedFromThis<T>* ptr);
			void MaybeSetupWeakThis(...) { }

			T* ptr_;
			SharedPtrControlBlock<T>* control_block_;

			template <typename U>
			friend class SharedPtr;

			template <typename U, typename V>
			friend SharedPtr<U> static_pointer_cast(const SharedPtr<V>& rhs);
		};

		template <typename T> void swap(SharedPtr<T>& r, SharedPtr<T>& s)
		{
			r.swap(s);
		}

		template <typename T, typename U>
		SharedPtr<T> static_pointer_cast(const SharedPtr<U>& rhs)
		{
			SharedPtr<T> lhs;
			lhs.template InitializeWithStaticCast<T>(rhs);
			return lhs;
		}

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
