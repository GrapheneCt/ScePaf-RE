#ifndef _VDSUITE_USER_PAF_STDCXX_STRING_H
#define _VDSUITE_USER_PAF_STDCXX_STRING_H

#include <paf/stdcxx/memory.hpp>

#define _HAS_BACKWARD_COMPATIBILITY 0

namespace paf {
template<class _Elem,
	class _Traits = char_traits<_Elem>,
	class _Ax = allocator<_Elem> >
	class basic_string;

		// TEMPLATE CLASS basic_string
template<class _Elem,
	class _Traits,
	class _Alloc>
	class basic_string
	{	// null-terminated transparent array of elements
public:
	typedef basic_string<_Elem, _Traits, _Alloc> _Myt;
	typedef _Traits traits_type;
	typedef _Alloc allocator_type;

	typedef typename _Alloc::value_type value_type;
	typedef typename _Alloc::size_type size_type;
	typedef typename _Alloc::difference_type difference_type;
	typedef typename _Alloc::pointer pointer;
	typedef typename _Alloc::const_pointer const_pointer;
	typedef typename _Alloc::reference reference;
	typedef typename _Alloc::const_reference const_reference;

#define _Myres _Mysize

	basic_string(const _Myt& _Right)
		{	// construct by copying _Right
		_Tidy();
		assign(_Right, 0, npos);
		}

	basic_string()
		{	// construct empty string
		_Tidy();
		}

	explicit basic_string(const _Alloc& _Al)
		{	// construct empty string with allocator
		_Tidy();
		}

	basic_string(const _Myt& _Right, size_type _Roff,
		size_type _Count = npos)
		{	// construct from _Right [_Roff, _Roff + _Count)
		_Tidy();
		assign(_Right, _Roff, _Count);
		}

	basic_string(const _Myt& _Right, size_type _Roff, size_type _Count,
		const _Alloc& _Al)
		{	// construct from _Right [_Roff, _Roff + _Count) with allocator
		_Tidy();
		assign(_Right, _Roff, _Count);
		}

	basic_string(const _Elem *_Ptr, size_type _Count)
		{	// construct from [_Ptr, _Ptr + _Count)
		_Tidy();
		assign(_Ptr, _Count);
		}

	basic_string(const _Elem *_Ptr, size_type _Count, const _Alloc& _Al)
		{	// construct from [_Ptr, _Ptr + _Count) with allocator
		_Tidy();
		assign(_Ptr, _Count);
		}

	basic_string(const _Elem *_Ptr)
		{	// construct from [_Ptr, <null>)
		_Tidy();
		assign(_Ptr);
		}

	basic_string(const _Elem *_Ptr, const _Alloc& _Al)
		{	// construct from [_Ptr, <null>) with allocator
		_Tidy();
		assign(_Ptr);
		}

	basic_string(size_type _Count, _Elem _Ch)
		{	// construct from _Count * _Ch
		_Tidy();
		assign(_Count, _Ch);
		}

	basic_string(size_type _Count, _Elem _Ch, const _Alloc& _Al)
		{	// construct from _Count * _Ch with allocator
		_Tidy();
		assign(_Count, _Ch);
		}

	~basic_string()
		{	// destroy the string
		_Tidy(true);
		}

#define npos ((size_t)(-1))	// bad/missing length/position

	_Myt& operator=(const _Myt& _Right)
		{	// assign _Right
		if (this != &_Right)
			{	// different, assign it
			assign(_Right);
			}
		return (*this);
		}

	_Myt& operator=(const _Elem *_Ptr)
		{	// assign [_Ptr, <null>)
		return (assign(_Ptr));
		}

	_Myt& operator=(_Elem _Ch)
		{	// assign 1 * _Ch
		return (assign(1, _Ch));
		}

	_Myt& operator+=(const _Myt& _Right)
		{	// append _Right
		return (append(_Right));
		}

	_Myt& operator+=(const _Elem *_Ptr)
		{	// append [_Ptr, <null>)
		return (append(_Ptr));
		}

	_Myt& operator+=(_Elem _Ch)
		{	// append 1 * _Ch
		return (append((size_type)1, _Ch));
		}

	_Myt& append(const _Myt& _Right)
		{	// append _Right
		return (append(_Right, 0, npos));
		}

	_Myt& append(const _Myt& _Right,
		size_type _Roff, size_type _Count)
		{	// append _Right [_Roff, _Roff + _Count)
		if (_Right.size() < _Roff)
			_Xran();	// _Roff off end
		size_type _Num = _Right.size() - _Roff;
		if (_Num < _Count)
			_Count = _Num;	// trim _Count to size
		if (npos - this->_Mysize <= _Count)
			_Xlen();	// result too long

		if (0 < _Count && _Grow(_Num = this->_Mysize + _Count))
			{	// make room and append new stuff
			_Traits::copy(this->_Myptr() + this->_Mysize,
				_Right._Myptr() + _Roff, _Count);
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& append(const _Elem *_Ptr, size_type _Count)
		{	// append [_Ptr, _Ptr + _Count)
		if (_Inside(_Ptr))
			return (append(*this,
				_Ptr - this->_Myptr(), _Count));	// substring
		if (npos - this->_Mysize <= _Count)
			_Xlen();	// result too long

		size_type _Num;
		if (0 < _Count && _Grow(_Num = this->_Mysize + _Count))
			{	// make room and append new stuff
			_Traits::copy(this->_Myptr() + this->_Mysize, _Ptr, _Count);
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& append(const _Elem *_Ptr)
		{	// append [_Ptr, <null>)
		return (append(_Ptr, _Traits::length(_Ptr)));
		}

	_Myt& append(size_type _Count, _Elem _Ch)
		{	// append _Count * _Ch
		if (npos - this->_Mysize <= _Count)
			_Xlen();	// result too long

		size_type _Num;
		if (0 < _Count && _Grow(_Num = this->_Mysize + _Count))
			{	// make room and append new stuff using assign
			_Chassign(this->_Mysize, _Count, _Ch);
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& assign(const _Myt& _Right)
		{	// assign _Right
		return (assign(_Right, 0, npos));
		}

	_Myt& assign(const _Myt& _Right,
		size_type _Roff, size_type _Count)
		{	// assign _Right [_Roff, _Roff + _Count)
		if (_Right.size() < _Roff)
			_Xran();	// _Roff off end
		size_type _Num = _Right.size() - _Roff;
		if (_Count < _Num)
			_Num = _Count;	// trim _Num to size

		if (this == &_Right)
			erase((size_type)(_Roff + _Num)), erase(0, _Roff);	// substring
		else if (_Grow(_Num))
			{	// make room and assign new stuff
			_Traits::copy(this->_Myptr(),
				_Right._Myptr() + _Roff, _Num);
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& assign(const _Elem *_Ptr, size_type _Count)
		{	// assign [_Ptr, _Ptr + _Count)
		if (_Inside(_Ptr))
			return (assign(*this,
				_Ptr - this->_Myptr(), _Count));	// substring

		if (_Grow(_Count))
			{	// make room and assign new stuff
			_Traits::copy(this->_Myptr(), _Ptr, _Count);
			_Eos(_Count);
			}
		return (*this);
		}

	_Myt& assign(const _Elem *_Ptr)
		{	// assign [_Ptr, <null>)
		_DEBUG_POINTER(_Ptr);
		return (assign(_Ptr, _Traits::length(_Ptr)));
		}

	_Myt& assign(size_type _Count, _Elem _Ch)
		{	// assign _Count * _Ch
		if (_Count == npos)
			_Xlen();	// result too long

		if (_Grow(_Count))
			{	// make room and assign new stuff
			_Chassign(0, _Count, _Ch);
			_Eos(_Count);
			}
		return (*this);
		}

	_Myt& insert(size_type _Off, const _Myt& _Right)
		{	// insert _Right at _Off
		return (insert(_Off, _Right, 0, npos));
		}

	_Myt& insert(size_type _Off,
		const _Myt& _Right, size_type _Roff, size_type _Count)
		{	// insert _Right [_Roff, _Roff + _Count) at _Off
		if (this->_Mysize < _Off || _Right.size() < _Roff)
			_Xran();	// _Off or _Roff off end
		size_type _Num = _Right.size() - _Roff;
		if (_Num < _Count)
			_Count = _Num;	// trim _Count to size
		if (npos - this->_Mysize <= _Count)
			_Xlen();	// result too long

		if (0 < _Count && _Grow(_Num = this->_Mysize + _Count))
			{	// make room and insert new stuff
			_Traits::move(this->_Myptr() + _Off + _Count,
				this->_Myptr() + _Off,
				this->_Mysize - _Off);	// empty out hole
			if (this == &_Right)
				_Traits::move(this->_Myptr() + _Off,
					this->_Myptr() + (_Off < _Roff ? _Roff + _Count : _Roff),
						_Count);	// substring
			else
				_Traits::copy(this->_Myptr() + _Off,
					_Right._Myptr() + _Roff, _Count);	// fill hole
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& insert(size_type _Off,
		const _Elem *_Ptr, size_type _Count)
		{	// insert [_Ptr, _Ptr + _Count) at _Off
		if (_Inside(_Ptr))
			return (insert(_Off, *this,
				_Ptr - this->_Myptr(), _Count));	// substring
		if (this->_Mysize < _Off)
			_Xran();	// _Off off end
		if (npos - this->_Mysize <= _Count)
			_Xlen();	// result too long
		size_type _Num;
		if (0 < _Count && _Grow(_Num = this->_Mysize + _Count))
			{	// make room and insert new stuff
			_Traits::move(this->_Myptr() + _Off + _Count,
				this->_Myptr() + _Off,
				this->_Mysize - _Off);	// empty out hole
			_Traits::copy(this->_Myptr() + _Off, _Ptr, _Count);	// fill hole
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& insert(size_type _Off, const _Elem *_Ptr)
		{	// insert [_Ptr, <null>) at _Off
		return (insert(_Off, _Ptr, _Traits::length(_Ptr)));
		}

	_Myt& insert(size_type _Off,
		size_type _Count, _Elem _Ch)
		{	// insert _Count * _Ch at _Off
		if (this->_Mysize < _Off)
			_Xran();	// _Off off end
		if (npos - this->_Mysize <= _Count)
			_Xlen();	// result too long
		size_type _Num;
		if (0 < _Count && _Grow(_Num = this->_Mysize + _Count))
			{	// make room and insert new stuff
			_Traits::move(this->_Myptr() + _Off + _Count,
				this->_Myptr() + _Off,
				this->_Mysize - _Off);	// empty out hole
			_Chassign(_Off, _Count, _Ch);	// fill hole
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& erase(size_type _Off = 0)
		{	// erase elements [_Off, ...)
		if (this->_Mysize < _Off)
			_Xran();	// _Off off end
		_Eos(_Off);
		return (*this);
		}

	_Myt& erase(size_type _Off, size_type _Count)
		{	// erase elements [_Off, _Off + _Count)
		if (this->_Mysize < _Off)
			_Xran();	// _Off off end
		if (this->_Mysize - _Off <= _Count)
			_Eos(_Off);	// erase elements [_Off, ...)
		else if (0 < _Count)
			{	// move elements down
			value_type *_Ptr = this->_Myptr() + _Off;
			size_type _Newsize = this->_Mysize - _Count;
			_Traits::move(_Ptr, _Ptr + _Count, _Newsize - _Off);
			_Eos(_Newsize);
			}
		return (*this);
		}

	void clear()
		{	// erase all
		_Eos(0);
		}

	_Myt& replace(size_type _Off, size_type _N0, const _Myt& _Right)
		{	// replace [_Off, _Off + _N0) with _Right
		return (replace(_Off, _N0, _Right, 0, npos));
		}

	_Myt& replace(size_type _Off,
		size_type _N0, const _Myt& _Right, size_type _Roff, size_type _Count)
		{	// replace [_Off, _Off + _N0) with _Right [_Roff, _Roff + _Count)
		if (this->_Mysize < _Off || _Right.size() < _Roff)
			_Xran();	// _Off or _Roff off end
		if (this->_Mysize - _Off < _N0)
			_N0 = this->_Mysize - _Off;	// trim _N0 to size
		size_type _Num = _Right.size() - _Roff;
		if (_Num < _Count)
			_Count = _Num;	// trim _Count to size
		if (npos - _Count <= this->_Mysize - _N0)
			_Xlen();	// result too long

		size_type _Nm = this->_Mysize - _N0 - _Off;	// length of kept tail
		size_type _Newsize = this->_Mysize + _Count - _N0;
		if (this->_Mysize < _Newsize)
			_Grow(_Newsize);

		if (this != &_Right)
			{	// no overlap, just move down and copy in new stuff
			_Traits::move(this->_Myptr() + _Off + _Count,
				this->_Myptr() + _Off + _N0, _Nm);	// empty hole
			_Traits::copy(this->_Myptr() + _Off,
				_Right._Myptr() + _Roff, _Count);	// fill hole
			}
		else if (_Count <= _N0)
			{	// hole doesn't get larger, just copy in substring
			_Traits::move(this->_Myptr() + _Off,
				this->_Myptr() + _Roff, _Count);	// fill hole
			_Traits::move(this->_Myptr() + _Off + _Count,
				this->_Myptr() + _Off + _N0, _Nm);	// move tail down
			}
		else if (_Roff <= _Off)
			{	// hole gets larger, substring begins before hole
			_Traits::move(this->_Myptr() + _Off + _Count,
				this->_Myptr() + _Off + _N0, _Nm);	// move tail down
			_Traits::move(this->_Myptr() + _Off,
				this->_Myptr() + _Roff, _Count);	// fill hole
			}
		else if (_Off + _N0 <= _Roff)
			{	// hole gets larger, substring begins after hole
			_Traits::move(this->_Myptr() + _Off + _Count,
				this->_Myptr() + _Off + _N0, _Nm);	// move tail down
			_Traits::move(this->_Myptr() + _Off,
				this->_Myptr() + (_Roff + _Count - _N0),
				_Count);	// fill hole
			}
		else
			{	// hole gets larger, substring begins in hole
			_Traits::move(this->_Myptr() + _Off,
				this->_Myptr() + _Roff, _N0);	// fill old hole
			_Traits::move(this->_Myptr() + _Off + _Count,
				this->_Myptr() + _Off + _N0, _Nm);	// move tail down
			_Traits::move(this->_Myptr() + _Off + _N0,
				this->_Myptr() + _Roff + _Count,
				_Count - _N0);	// fill rest of new hole
			}

		_Eos(_Newsize);
		return (*this);
		}

	_Myt& replace(size_type _Off,
		size_type _N0, const _Elem *_Ptr, size_type _Count)
		{	// replace [_Off, _Off + _N0) with [_Ptr, _Ptr + _Count)
		if (_Inside(_Ptr))
			return (replace(_Off, _N0, *this,
				_Ptr - this->_Myptr(),
				_Count));	// substring, replace carefully
		if (this->_Mysize < _Off)
			_Xran();	// _Off off end
		if (this->_Mysize - _Off < _N0)
			_N0 = this->_Mysize - _Off;	// trim _N0 to size
		if (npos - _Count <= this->_Mysize - _N0)
			_Xlen();	// result too long
		size_type _Nm = this->_Mysize - _N0 - _Off;

		if (_Count < _N0)
			_Traits::move(this->_Myptr() + _Off + _Count,
				this->_Myptr() + _Off + _N0,
				_Nm);	// smaller hole, move tail up
		size_type _Num;
		if ((0 < _Count || 0 < _N0)
			&& _Grow(_Num = this->_Mysize + _Count - _N0))
			{	// make room and rearrange
			if (_N0 < _Count)
				_Traits::move(this->_Myptr() + _Off + _Count,
					this->_Myptr() + _Off + _N0, _Nm);	// move tail down
			_Traits::copy(this->_Myptr() + _Off, _Ptr, _Count);	// fill hole
			_Eos(_Num);
			}
		return (*this);
		}

	_Myt& replace(size_type _Off, size_type _N0, const _Elem *_Ptr)
		{	// replace [_Off, _Off + _N0) with [_Ptr, <null>)
		return (replace(_Off, _N0, _Ptr, _Traits::length(_Ptr)));
		}

	_Myt& replace(size_type _Off,
		size_type _N0, size_type _Count, _Elem _Ch)
		{	// replace [_Off, _Off + _N0) with _Count * _Ch
		if (this->_Mysize < _Off)
			_Xran();	// _Off off end
		if (this->_Mysize - _Off < _N0)
			_N0 = this->_Mysize - _Off;	// trim _N0 to size
		if (npos - _Count <= this->_Mysize - _N0)
			_Xlen();	// result too long
		size_type _Nm = this->_Mysize - _N0 - _Off;

		if (_Count < _N0)
			_Traits::move(this->_Myptr() + _Off + _Count,
				this->_Myptr() + _Off + _N0,
				_Nm);	// smaller hole, move tail up
		size_type _Num;
		if ((0 < _Count || 0 < _N0)
			&& _Grow(_Num = this->_Mysize + _Count - _N0))
			{	// make room and rearrange
			if (_N0 < _Count)
				_Traits::move(this->_Myptr() + _Off + _Count,
					this->_Myptr() + _Off + _N0, _Nm);	// move tail down
			_Chassign(_Off, _Count, _Ch);	// fill hole
			_Eos(_Num);
			}
		return (*this);
		}

	reference at(size_type _Off)
		{	// subscript mutable sequence with checking
		if (this->_Mysize <= _Off)
			_Xran();	// _Off off end
		return (this->_Myptr()[_Off]);
		}

	const_reference at(size_type _Off) const
		{	// subscript nonmutable sequence with checking
		if (this->_Mysize <= _Off)
			_Xran();	// _Off off end
		return (this->_Myptr()[_Off]);
		}

	reference operator[](size_type _Off)
		{	// subscript mutable sequence
		return (this->_Myptr()[_Off]);
		}

	const_reference operator[](size_type _Off) const
		{	// subscript nonmutable sequence
		return (this->_Myptr()[_Off]);
		}

	void push_back(_Elem _Ch)
		{	// insert element at end
		insert(end(), _Ch);
		}

	const _Elem *c_str() const
		{	// return pointer to null-terminated nonmutable array
		return (this->_Myptr());
		}

	const _Elem *data() const
		{	// return pointer to nonmutable array
		return (c_str());
		}

	size_type length() const
		{	// return length of sequence
		return (this->_Mysize);
		}

	size_type size() const
		{	// return length of sequence
		return (this->_Mysize);
		}

	size_type max_size() const
		{	// return maximum possible length of sequence
#ifdef _DEBUG
		size_type _Num = memory::HeapAllocator::GetGlobalHeapAllocator()->GetFreeSize() / sizeof(_Elem);
#else
		size_type _Num = size_t(-1) / sizeof(_Elem);
#endif
		return (_Num <= 1 ? 1 : _Num - 1);
		}

	void resize(size_type _Newsize)
		{	// determine new length, padding with null elements as needed
		resize(_Newsize, _Elem());
		}

	void resize(size_type _Newsize, _Elem _Ch)
		{	// determine new length, padding with _Ch elements as needed
		if (_Newsize <= this->_Mysize)
			_Grow(_Newsize, true);
		else
			append(_Newsize - this->_Mysize, _Ch);
		}

	size_type capacity() const _NOEXCEPT
		{	// return current length of allocated storage
		return (this->_Myres);
		}

	bool empty() const _NOEXCEPT
		{	// test if sequence is empty
		return (this->_Myptr == &empty_string);
		}

	size_type copy(_Elem *_Ptr,
		size_type _Count, size_type _Off = 0) const
		{	// copy [_Off, _Off + _Count) to [_Ptr, _Ptr + _Count)
		if (this->_Mysize < _Off)
			_Xran();	// _Off off end
		if (this->_Mysize - _Off < _Count)
			_Count = this->_Mysize - _Off;
		_Traits::copy(_Ptr, this->_Myptr() + _Off, _Count);
		return (_Count);
		}

	size_type find(const _Myt& _Right, size_type _Off = 0) const
		{	// look for _Right beginning at or after _Off
		return (find(_Right._Myptr(), _Off, _Right.size()));
		}

	size_type find(const _Elem *_Ptr,
		size_type _Off, size_type _Count) const
		{	// look for [_Ptr, _Ptr + _Count) beginning at or after _Off
		if (_Count == 0 && _Off <= this->_Mysize)
			return (_Off);	// null string always matches (if inside string)

		size_type _Nm;
		if (_Off < this->_Mysize && _Count <= (_Nm = this->_Mysize - _Off))
			{	// room for match, look for it
			const _Elem *_Uptr, *_Vptr;
			for (_Nm -= _Count - 1, _Vptr = this->_Myptr() + _Off;
				(_Uptr = _Traits::find(_Vptr, _Nm, *_Ptr)) != 0;
				_Nm -= _Uptr - _Vptr + 1, _Vptr = _Uptr + 1)
				if (_Traits::compare(_Uptr, _Ptr, _Count) == 0)
					return (_Uptr - this->_Myptr());	// found a match
			}

		return (npos);	// no match
		}

	size_type find(const _Elem *_Ptr, size_type _Off = 0) const
		{	// look for [_Ptr, <null>) beginning at or after _Off
		return (find(_Ptr, _Off, _Traits::length(_Ptr)));
		}

	size_type find(_Elem _Ch, size_type _Off = 0) const
		{	// look for _Ch at or after _Off
		return (find((const _Elem *)&_Ch, _Off, 1));
		}

	size_type rfind(const _Myt& _Right, size_type _Off = npos) const
		{	// look for _Right beginning before _Off
		return (rfind(_Right._Myptr(), _Off, _Right.size()));
		}

	size_type rfind(const _Elem *_Ptr,
		size_type _Off, size_type _Count) const
		{	// look for [_Ptr, _Ptr + _Count) beginning before _Off
		if (_Count == 0)
			return (_Off < this->_Mysize ? _Off
				: this->_Mysize);	// null always matches
		if (_Count <= this->_Mysize)
			{	// room for match, look for it
			const _Elem *_Uptr = this->_Myptr() +
				(_Off < this->_Mysize - _Count ? _Off
					: this->_Mysize - _Count);
			for (; ; --_Uptr)
				if (_Traits::eq(*_Uptr, *_Ptr)
					&& _Traits::compare(_Uptr, _Ptr, _Count) == 0)
					return (_Uptr - this->_Myptr());	// found a match
				else if (_Uptr == this->_Myptr())
					break;	// at beginning, no more chance for match
			}

		return (npos);	// no match
		}

	size_type rfind(const _Elem *_Ptr, size_type _Off = npos) const
		{	// look for [_Ptr, <null>) beginning before _Off
		return (rfind(_Ptr, _Off, _Traits::length(_Ptr)));
		}

	size_type rfind(_Elem _Ch, size_type _Off = npos) const
		{	// look for _Ch before _Off
		return (rfind((const _Elem *)&_Ch, _Off, 1));
		}

	size_type find_first_of(const _Myt& _Right,
		size_type _Off = 0) const
		{	// look for one of _Right at or after _Off
		return (find_first_of(_Right._Myptr(), _Off, _Right.size()));
		}

	size_type find_first_of(const _Elem *_Ptr,
		size_type _Off, size_type _Count) const
		{	// look for one of [_Ptr, _Ptr + _Count) at or after _Off
		if (0 < _Count && _Off < this->_Mysize)
			{	// room for match, look for it
			const _Elem *const _Vptr = this->_Myptr() + this->_Mysize;
			for (const _Elem *_Uptr = this->_Myptr() + _Off;
				_Uptr < _Vptr; ++_Uptr)
				if (_Traits::find(_Ptr, _Count, *_Uptr) != 0)
					return (_Uptr - this->_Myptr());	// found a match
			}

		return (npos);	// no match
		}

	size_type find_first_of(const _Elem *_Ptr,
		size_type _Off = 0) const
		{	// look for one of [_Ptr, <null>) at or after _Off
		return (find_first_of(_Ptr, _Off, _Traits::length(_Ptr)));
		}

	size_type find_first_of(_Elem _Ch,
		size_type _Off = 0) const
		{	// look for _Ch at or after _Off
		return (find((const _Elem *)&_Ch, _Off, 1));
		}

	size_type find_last_of(const _Myt& _Right,
		size_type _Off = npos) const
		{	// look for one of _Right before _Off
		return (find_last_of(_Right._Myptr(), _Off, _Right.size()));
		}

	size_type find_last_of(const _Elem *_Ptr,
		size_type _Off, size_type _Count) const
		{	// look for one of [_Ptr, _Ptr + _Count) before _Off
		if (0 < _Count && 0 < this->_Mysize)
			{	// worth searching, do it
			const _Elem *_Uptr = this->_Myptr()
				+ (_Off < this->_Mysize ? _Off : this->_Mysize - 1);
			for (; ; --_Uptr)
				if (_Traits::find(_Ptr, _Count, *_Uptr) != 0)
					return (_Uptr - this->_Myptr());	// found a match
				else if (_Uptr == this->_Myptr())
					break;	// at beginning, no more chance for match
			}

		return (npos);	// no match
		}

	size_type find_last_of(const _Elem *_Ptr,
		size_type _Off = npos) const
		{	// look for one of [_Ptr, <null>) before _Off
		return (find_last_of(_Ptr, _Off, _Traits::length(_Ptr)));
		}

	size_type find_last_of(_Elem _Ch,
		size_type _Off = npos) const
		{	// look for _Ch before _Off
		return (rfind((const _Elem *)&_Ch, _Off, 1));
		}

	size_type find_first_not_of(const _Myt& _Right,
		size_type _Off = 0) const
		{	// look for none of _Right at or after _Off
		return (find_first_not_of(_Right._Myptr(), _Off,
			_Right.size()));
		}

	size_type find_first_not_of(const _Elem *_Ptr,
		size_type _Off, size_type _Count) const
		{	// look for none of [_Ptr, _Ptr + _Count) at or after _Off
		if (_Off < this->_Mysize)
			{	// room for match, look for it
			const _Elem *const _Vptr = this->_Myptr() + this->_Mysize;
			for (const _Elem *_Uptr = this->_Myptr() + _Off;
				_Uptr < _Vptr; ++_Uptr)
				if (_Traits::find(_Ptr, _Count, *_Uptr) == 0)
					return (_Uptr - this->_Myptr());
			}
		return (npos);
		}

	size_type find_first_not_of(const _Elem *_Ptr,
		size_type _Off = 0) const
		{	// look for one of [_Ptr, <null>) at or after _Off
		return (find_first_not_of(_Ptr, _Off, _Traits::length(_Ptr)));
		}

	size_type find_first_not_of(_Elem _Ch,
		size_type _Off = 0) const
		{	// look for non _Ch at or after _Off
		return (find_first_not_of((const _Elem *)&_Ch, _Off, 1));
		}

	size_type find_last_not_of(const _Myt& _Right,
		size_type _Off = npos) const
		{	// look for none of _Right before _Off
		return (find_last_not_of(_Right._Myptr(), _Off, _Right.size()));
		}

	size_type find_last_not_of(const _Elem *_Ptr,
		size_type _Off, size_type _Count) const
		{	// look for none of [_Ptr, _Ptr + _Count) before _Off
		if (0 < this->_Mysize)
			{	// worth searching, do it
			const _Elem *_Uptr = this->_Myptr()
				+ (_Off < this->_Mysize ? _Off : this->_Mysize - 1);
			for (; ; --_Uptr)
				if (_Traits::find(_Ptr, _Count, *_Uptr) == 0)
					return (_Uptr - this->_Myptr());
				else if (_Uptr == this->_Myptr())
					break;
			}
		return (npos);
		}

	size_type find_last_not_of(const _Elem *_Ptr,
		size_type _Off = npos) const
		{	// look for none of [_Ptr, <null>) before _Off
		return (find_last_not_of(_Ptr, _Off, _Traits::length(_Ptr)));
		}

	size_type find_last_not_of(_Elem _Ch,
		size_type _Off = npos) const
		{	// look for non _Ch before _Off
		return (find_last_not_of((const _Elem *)&_Ch, _Off, 1));
		}

	_Myt substr(size_type _Off = 0, size_type _Count = npos) const
		{	// return [_Off, _Off + _Count) as new string
		return (_Myt(*this, _Off, _Count, get_allocator()));
		}

	int compare(const _Myt& _Right) const
		{	// compare [0, _Mysize) with _Right
		return (compare(0, this->_Mysize, _Right._Myptr(), _Right.size()));
		}

	int compare(size_type _Off, size_type _N0,
		const _Myt& _Right) const
		{	// compare [_Off, _Off + _N0) with _Right
		return (compare(_Off, _N0, _Right, 0, npos));
		}

	int compare(size_type _Off,
		size_type _N0, const _Myt& _Right,
		size_type _Roff, size_type _Count) const
		{	// compare [_Off, _Off + _N0) with _Right [_Roff, _Roff + _Count)
		if (_Right.size() < _Roff)
			_Xran();	// _Off off end
		if (_Right._Mysize - _Roff < _Count)
			_Count = _Right._Mysize - _Roff;	// trim _Count to size
		return (compare(_Off, _N0, _Right._Myptr() + _Roff, _Count));
		}

	int compare(const _Elem *_Ptr) const
		{	// compare [0, _Mysize) with [_Ptr, <null>)
		return (compare(0, this->_Mysize, _Ptr, _Traits::length(_Ptr)));
		}

	int compare(size_type _Off, size_type _N0, const _Elem *_Ptr) const
		{	// compare [_Off, _Off + _N0) with [_Ptr, <null>)
		return (compare(_Off, _N0, _Ptr, _Traits::length(_Ptr)));
		}

	int compare(size_type _Off,
		size_type _N0, const _Elem *_Ptr, size_type _Count) const
		{	// compare [_Off, _Off + _N0) with [_Ptr, _Ptr + _Count)
		if (this->_Mysize < _Off)
			_Xran();	// _Off off end
		if (this->_Mysize - _Off < _N0)
			_N0 = this->_Mysize - _Off;	// trim _N0 to size

		size_type _Ans = _Traits::compare(this->_Myptr() + _Off, _Ptr,
			_N0 < _Count ? _N0 : _Count);
		return (_Ans != 0 ? (int)_Ans : _N0 < _Count ? -1
			: _N0 == _Count ? 0 : +1);
		}

	allocator_type get_allocator() const
		{	// return allocator object for values
		return SCE_NULL;
		}

	void _Chassign(size_type _Off, size_type _Count, _Elem _Ch)
		{	// assign _Count copies of _Ch beginning at _Off
		if (_Count == 1)
			_Traits::assign(*(this->_Myptr() + _Off), _Ch);
		else
			_Traits::assign(this->_Myptr() + _Off, _Count, _Ch);
		}

	void _Copy(size_type _Newsize, size_type _Oldlen)
		{	// copy _Oldlen elements to newly allocated buffer
		_Elem *_Ptr = 0;
		_Ptr = (_Elem *)sce_paf_malloc(sizeof(_Elem) * (_Newsize + 1));
		if (0 < _Oldlen)
			_Traits::copy(_Ptr, this->_Myptr(),
				_Oldlen);	// copy existing elements
		_Tidy(true);
		this->_Myptr = _Ptr;
		this->_Myres = _Newsize;
		_Eos(_Oldlen);
		}

	void _Eos(size_type _Newsize)
		{	// set new length and null terminator
		_Traits::assign(this->_Myptr()[this->_Mysize = _Newsize], _Elem());
		}

	bool _Grow(size_type _Newsize,
		bool _Trim = false)
		{	// ensure buffer is big enough, trim to size if _Trim is true
		if (max_size() < _Newsize)
			_Xlen();	// result too long
		if (_Newsize != 0)
			_Copy(_Newsize, this->_Mysize);	// reallocate to grow
		else
			_Eos(0);	// new size is zero, just null terminate
		return (0 < _Newsize);	// return true only if more work to do
		}

	bool _Inside(const _Elem *_Ptr)
		{	// test if _Ptr points inside string
		if (_Ptr == 0 || _Ptr < this->_Myptr()
			|| this->_Myptr() + this->_Mysize <= _Ptr)
			return (false);	// don't ask
		else
			return (true);
		}

	void _Tidy(bool _Built = false)
		{	// initialize buffer, deallocating any storage
		if (!_Built)
			;
		else if (this->_Myptr != &this->empty_string)
			{
			sce_paf_free((void *)this->_Myptr);
			}
		this->_Myptr = &this->empty_string;
		this->_Mysize = 0;
		}

		_NO_RETURN_MEMBER(_Xlen()) const
		{	// report a length_error
			sceClibPrintf("string too long");
			abort();
		}

		_NO_RETURN_MEMBER(_Xran()) const
		{	// report an out_of_range error
			sceClibPrintf("invalid string position");
			abort();
		}

		_Elem* _Myptr;
		size_type _Mysize;
		unsigned int _Myhash;

		__declspec(dllimport) static _Elem empty_string;

#undef _Myres
#undef npos
	};

		// STATIC npos OBJECT

		// basic_string TEMPLATE OPERATORS
template<class _Elem,
	class _Traits,
	class _Alloc> inline
	void swap(basic_string<_Elem, _Traits, _Alloc>& _Left,
		basic_string<_Elem, _Traits, _Alloc>& _Right)
	{	// swap _Left and _Right strings
	_Left.swap(_Right);
	}

typedef basic_string<char, char_traits<char>, allocator<char> >
	string;
typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >
	wstring;

 #if _HAS_CPP0X
typedef basic_string<char16_t, char_traits<char16_t>, allocator<char16_t> >
	u16string;
typedef basic_string<char32_t, char_traits<char32_t>, allocator<char32_t> >
	u32string;
 #endif /* _HAS_CPP0X */
}
#endif