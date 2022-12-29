#ifndef _VDSUITE_USER_PAF_STDCXX_MEMORY_H
#define _VDSUITE_USER_PAF_STDCXX_MEMORY_H

#include <stddef.h>

namespace paf {
	template <typename T>
	class allocator
	{
	public:
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T value_type;

		allocator() {}

		~allocator() {}

		template <class U> allocator(const allocator<U>&) {}

		template <class U>
		struct rebind { typedef allocator<U> other; };

		pointer address(reference x) const { return &x; }

		const_pointer address(const_reference x) const { return &x; }

		size_type max_size() const { return memory::HeapAllocator::GetGlobalHeapAllocator()->GetFreeSize() / sizeof(value_type); }

		pointer allocate(size_type n, const void * hint = 0)
		{
			return static_cast<pointer>(sce_paf_malloc(n * sizeof(T)));
		}

		void deallocate(pointer p, size_type n)
		{
			sce_paf_free(p);
		}

		void construct(pointer p, const T& val)
		{
			new(static_cast<void*>(p)) T(val);
		}

		void construct(pointer p)
		{
			new(static_cast<void*>(p)) T();
		}

		void destroy(pointer p)
		{
			p->~T();
		}
	};
}

#endif