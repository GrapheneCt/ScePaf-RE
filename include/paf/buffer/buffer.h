/*
	Vita Development Suite Libraries
*/

#ifndef _VDSUITE_USER_PAF_BUFFER_BUFFER_H
#define _VDSUITE_USER_PAF_BUFFER_BUFFER_H

#include <stdint.h>
#include <stddef.h>
#include <paf/common/shared_ptr.h>

namespace paf {

	namespace memory {

		class HeapAllocator;
	}

	class Buffer
	{
	public:

		Buffer() : addr(NULL), size(0)
		{

		}

		virtual void* GetAddr()
		{
			return addr;
		}

		virtual const void* GetAddr() const
		{
			return addr;
		}

		virtual size_t GetSize() const
		{
			return size;
		}

		virtual ~Buffer()
		{

		};

	protected:

		void* addr;
		size_t size;
	};

	class SubBuffer : public Buffer
	{
	public:

		static common::SharedPtr<SubBuffer> Create(void *addr, size_t size, common::SharedPtr<Buffer> buffer);

	private:

		common::SharedPtr<Buffer> buffer;
	};

	class SubConstBuffer : public Buffer
	{
	public:

		virtual const void* GetAddr() const
		{
			return const_addr;
		}

		static common::SharedPtr<SubConstBuffer> Create(const void *addr, size_t size, common::SharedPtr<Buffer> buffer);

	private:

		const void* const_addr;
		common::SharedPtr<Buffer> buffer;
	};

	class UnmanagedBuffer : public Buffer
	{
	public:

		static common::SharedPtr<UnmanagedBuffer> Create(void *addr, size_t size);
	};

	class UnmanagedConstBuffer : public Buffer
	{
	public:

		virtual const void* GetAddr() const
		{
			return const_addr;
		}

		static common::SharedPtr<UnmanagedConstBuffer> Create(const void *addr, size_t size);

	private:

		const void* const_addr;
	};

	class MallocBuffer : public Buffer
	{
	public:

		static common::SharedPtr<MallocBuffer> Create(void *addr, size_t size);

		static common::SharedPtr<MallocBuffer> Allocate(size_t size);
	};

	class HeapAllocBuffer : public Buffer
	{
	public:

		static common::SharedPtr<HeapAllocBuffer> Create(void *addr, size_t size, memory::HeapAllocator *alloc);

		static common::SharedPtr<HeapAllocBuffer> Allocate(size_t size, memory::HeapAllocator *alloc);

	private:

		memory::HeapAllocator *allocator;
	};
}

#endif /* _VDSUITE_USER_PAF_BUFFER_BUFFER_H */
