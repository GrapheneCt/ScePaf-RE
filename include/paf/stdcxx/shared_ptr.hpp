#ifndef _VDSUITE_USER_PAF_STDCXX_SharedPtr_H
#define _VDSUITE_USER_PAF_STDCXX_SharedPtr_H

#include <scetypes.h>
#include <sce_atomic.h>

namespace paf {
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
}

#endif