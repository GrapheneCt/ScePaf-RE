#ifndef _VDSUITE_USER_PAF_STDCXX_LIST_H
#define _VDSUITE_USER_PAF_STDCXX_LIST_H
#ifndef _LIST_
#define _LIST_

#include <xmemory>
#include <stdexcept>

_STD_BEGIN
// TEMPLATE CLASS _List_unchecked_const_iterator
template<class _Mylist,
	class _Base = _Iterator0<bidirectional_iterator_tag,
	typename _Mylist::value_type,
	typename _Mylist::difference_type,
	typename _Mylist::const_pointer,
	typename _Mylist::const_reference> >
	class _List_unchecked_const_iterator
	: public _Base
{	// unchecked iterator for nonmutable list
public:
	typedef _List_unchecked_const_iterator<_Mylist, _Base> _Myiter;
	typedef bidirectional_iterator_tag iterator_category;

	typedef typename _Mylist::_Nodeptr _Nodeptr;
	typedef typename _Mylist::value_type value_type;
	typedef typename _Mylist::difference_type difference_type;
	typedef typename _Mylist::const_pointer pointer;
	typedef typename _Mylist::const_reference reference;

	_List_unchecked_const_iterator()
		: _Ptr(0)
	{	// construct with null node pointer
	}

	_List_unchecked_const_iterator(_Nodeptr _Pnode, const _Mylist *_Plist)
		: _Ptr(_Pnode)
	{	// construct with node pointer _Pnode
		this->_Adopt(_Plist);
	}

	reference operator*() const
	{	// return designated value
		return (_Mylist::_Myval(_Ptr));
	}

	pointer operator->() const
	{	// return pointer to class object
		return (_POINTER_TO(**this));
	}

	_Myiter& operator++()
	{	// preincrement
		_Ptr = _Mylist::_Nextnode(_Ptr);
		return (*this);
	}

	_Myiter operator++(int)
	{	// postincrement
		_Myiter _Tmp = *this;
		++*this;
		return (_Tmp);
	}

	_Myiter& operator--()
	{	// predecrement
		_Ptr = _Mylist::_Prevnode(_Ptr);
		return (*this);
	}

	_Myiter operator--(int)
	{	// postdecrement
		_Myiter _Tmp = *this;
		--*this;
		return (_Tmp);
	}

	bool operator==(const _Myiter& _Right) const
	{	// test for iterator equality
		return (_Ptr == _Right._Ptr);
	}

	bool operator!=(const _Myiter& _Right) const
	{	// test for iterator inequality
		return (!(*this == _Right));
	}

	_Nodeptr _Mynode() const
	{	// return node pointer
		return (_Ptr);
	}

	_Nodeptr _Ptr;	// pointer to node
};

// TEMPLATE CLASS _List_unchecked_iterator
template<class _Mylist>
class _List_unchecked_iterator
	: public _List_unchecked_const_iterator<_Mylist>
{	// unchecked iterator for mutable list
public:
	typedef _List_unchecked_iterator<_Mylist> _Myiter;
	typedef _List_unchecked_const_iterator<_Mylist> _Mybase;
	typedef bidirectional_iterator_tag iterator_category;

	typedef typename _Mylist::_Nodeptr _Nodeptr;
	typedef typename _Mylist::value_type value_type;
	typedef typename _Mylist::difference_type difference_type;
	typedef typename _Mylist::pointer pointer;
	typedef typename _Mylist::reference reference;

	_List_unchecked_iterator()
	{	// construct with null node
	}

	_List_unchecked_iterator(_Nodeptr _Pnode, const _Mylist *_Plist)
		: _Mybase(_Pnode, _Plist)
	{	// construct with node pointer _Pnode
	}

	reference operator*() const
	{	// return designated value
		return ((reference)**(_Mybase *)this);
	}

	pointer operator->() const
	{	// return pointer to class object
		return (_POINTER_TO(**this));
	}

	_Myiter& operator++()
	{	// preincrement
		++(*(_Mybase *)this);
		return (*this);
	}

	_Myiter operator++(int)
	{	// postincrement
		_Myiter _Tmp = *this;
		++*this;
		return (_Tmp);
	}

	_Myiter& operator--()
	{	// predecrement
		--(*(_Mybase *)this);
		return (*this);
	}

	_Myiter operator--(int)
	{	// postdecrement
		_Myiter _Tmp = *this;
		--*this;
		return (_Tmp);
	}
};

// TEMPLATE CLASS _List_const_iterator
template<class _Mylist>
class _List_const_iterator
#if 0 < _ITERATOR_DEBUG_LEVEL
	: public _List_unchecked_const_iterator<_Mylist,
	_Iterator12<bidirectional_iterator_tag,
	typename _Mylist::value_type,
	typename _Mylist::difference_type,
	typename _Mylist::const_pointer,
	typename _Mylist::const_reference> >
#else /* 0 < _ITERATOR_DEBUG_LEVEL */
	: public _List_unchecked_const_iterator<_Mylist>
#endif /* 0 < _ITERATOR_DEBUG_LEVEL */
{	// iterator for nonmutable list
public:
	typedef _List_const_iterator<_Mylist> _Myiter;
#if 0 < _ITERATOR_DEBUG_LEVEL
	typedef _List_unchecked_const_iterator<_Mylist,
						   _Iterator12<bidirectional_iterator_tag,
						   typename _Mylist::value_type,
						   typename _Mylist::difference_type,
						   typename _Mylist::const_pointer,
						   typename _Mylist::const_reference> > _Mybase;
#else /* 0 < _ITERATOR_DEBUG_LEVEL */
	typedef _List_unchecked_const_iterator<_Mylist> _Mybase;
#endif /* 0 < _ITERATOR_DEBUG_LEVEL */
	typedef bidirectional_iterator_tag iterator_category;

	typedef typename _Mylist::_Nodeptr _Nodeptr;
	typedef typename _Mylist::value_type value_type;
	typedef typename _Mylist::difference_type difference_type;
	typedef typename _Mylist::const_pointer pointer;
	typedef typename _Mylist::const_reference reference;

	_List_const_iterator()
		: _Mybase()
		{	// construct with null node pointer
		}

	_List_const_iterator(_Nodeptr _Pnode, const _Mylist *_Plist)
		: _Mybase(_Pnode, _Plist)
		{	// construct with node pointer _Pnode
		}

	typedef _List_unchecked_const_iterator<_Mylist> _Unchecked_type;

	_Myiter& _Rechecked(_Unchecked_type _Right)
		{	// reset from unchecked iterator
		this->_Ptr = _Right._Ptr;
		return (*this);
		}

	_Unchecked_type _Unchecked() const
		{	// make an unchecked iterator
		return (_Unchecked_type(this->_Ptr, (_Mylist *)this->_Getcont()));
		}

	reference operator*() const
		{	// return designated value
 #if _ITERATOR_DEBUG_LEVEL == 2
		if (this->_Getcont() == 0
			|| this->_Ptr == 0
			|| this->_Ptr == ((_Mylist *)this->_Getcont())->_Myhead)
			{	// report error
			_DEBUG_ERROR("list iterator not dereferencable");
			_SCL_SECURE_OUT_OF_RANGE;
			}

 #elif _ITERATOR_DEBUG_LEVEL == 1
		_SCL_SECURE_VALIDATE(this->_Getcont() != 0 && this->_Ptr != 0);
		_SCL_SECURE_VALIDATE_RANGE(this->_Ptr !=
			((_Mylist *)this->_Getcont())->_Myhead);
 #endif /* _ITERATOR_DEBUG_LEVEL */

		return (_Mylist::_Myval(this->_Ptr));
		}

	_Myiter& operator++()
		{	// preincrement
 #if _ITERATOR_DEBUG_LEVEL == 2
		if (this->_Getcont() == 0
			|| this->_Ptr == 0
			|| this->_Ptr == ((_Mylist *)this->_Getcont())->_Myhead)
			{	// report error
			_DEBUG_ERROR("list iterator not incrementable");
			_SCL_SECURE_OUT_OF_RANGE;
			}

 #elif _ITERATOR_DEBUG_LEVEL == 1
		_SCL_SECURE_VALIDATE(this->_Getcont() != 0 && this->_Ptr != 0);
		_SCL_SECURE_VALIDATE_RANGE(this->_Ptr !=
			((_Mylist *)this->_Getcont())->_Myhead);
 #endif /* _ITERATOR_DEBUG_LEVEL */

		this->_Ptr = _Mylist::_Nextnode(this->_Ptr);
		return (*this);
		}

	_Myiter operator++(int)
		{	// postincrement
		_Myiter _Tmp = *this;
		++*this;
		return (_Tmp);
		}

	_Myiter& operator--()
		{	// predecrement
 #if _ITERATOR_DEBUG_LEVEL == 2
		if (this->_Getcont() == 0
			|| this->_Ptr == 0
			|| (this->_Ptr = _Mylist::_Prevnode(this->_Ptr))
				== ((_Mylist *)this->_Getcont())->_Myhead)
			{	// report error
			_DEBUG_ERROR("list iterator not decrementable");
			_SCL_SECURE_OUT_OF_RANGE;
			}

 #elif _ITERATOR_DEBUG_LEVEL == 1
		_SCL_SECURE_VALIDATE(this->_Getcont() != 0 && this->_Ptr != 0);
		this->_Ptr = _Mylist::_Prevnode(this->_Ptr);
		_SCL_SECURE_VALIDATE_RANGE(this->_Ptr !=
			((_Mylist *)this->_Getcont())->_Myhead);

 #else /* _ITERATOR_DEBUG_LEVEL */
		this->_Ptr = _Mylist::_Prevnode(this->_Ptr);
 #endif /* _ITERATOR_DEBUG_LEVEL */

		return (*this);
		}

	_Myiter operator--(int)
		{	// postdecrement
		_Myiter _Tmp = *this;
		--*this;
		return (_Tmp);
		}

	bool operator==(const _Myiter& _Right) const
		{	// test for iterator equality
 #if _ITERATOR_DEBUG_LEVEL == 2
		if (this->_Getcont() == 0
			|| this->_Getcont() != _Right._Getcont())
			{	// report error
			_DEBUG_ERROR("list iterators incompatible");
			_SCL_SECURE_INVALID_ARGUMENT;
			}

 #elif _ITERATOR_DEBUG_LEVEL == 1
		_SCL_SECURE_VALIDATE(this->_Getcont() != 0
			&& this->_Getcont() == _Right._Getcont());
 #endif /* _ITERATOR_DEBUG_LEVEL */

		return (this->_Ptr == _Right._Ptr);
		}

	bool operator!=(const _Myiter& _Right) const
		{	// test for iterator inequality
		return (!(*this == _Right));
		}
};

template<class _Mylist> inline
typename _List_const_iterator<_Mylist>::_Unchecked_type
_Unchecked(_List_const_iterator<_Mylist> _Iter)
{	// convert to unchecked
	return (_Iter._Unchecked());
}

template<class _Mylist> inline
_List_const_iterator<_Mylist>&
_Rechecked(_List_const_iterator<_Mylist>& _Iter,
	typename _List_const_iterator<_Mylist>
	::_Unchecked_type _Right)
{	// convert to checked
	return (_Iter._Rechecked(_Right));
}

// TEMPLATE CLASS _List_iterator
template<class _Mylist>
class _List_iterator
	: public _List_const_iterator<_Mylist>
{	// iterator for mutable list
public:
	typedef _List_iterator<_Mylist> _Myiter;
	typedef _List_const_iterator<_Mylist> _Mybase;
	typedef bidirectional_iterator_tag iterator_category;

	typedef typename _Mylist::_Nodeptr _Nodeptr;
	typedef typename _Mylist::value_type value_type;
	typedef typename _Mylist::difference_type difference_type;
	typedef typename _Mylist::pointer pointer;
	typedef typename _Mylist::reference reference;

	_List_iterator()
	{	// construct with null node
	}

	_List_iterator(_Nodeptr _Pnode, const _Mylist *_Plist)
		: _Mybase(_Pnode, _Plist)
	{	// construct with node pointer _Pnode
	}

	typedef _List_unchecked_iterator<_Mylist> _Unchecked_type;

	_Myiter& _Rechecked(_Unchecked_type _Right)
	{	// reset from unchecked iterator
		this->_Ptr = _Right._Ptr;
		return (*this);
	}

	_Unchecked_type _Unchecked() const
	{	// make an unchecked iterator
		return (_Unchecked_type(this->_Ptr, (_Mylist *)this->_Getcont()));
	}

	reference operator*() const
	{	// return designated value
		return ((reference)**(_Mybase *)this);
	}

	pointer operator->() const
	{	// return pointer to class object
		return (_POINTER_TO(**this));
	}

	_Myiter& operator++()
	{	// preincrement
		++(*(_Mybase *)this);
		return (*this);
	}

	_Myiter operator++(int)
	{	// postincrement
		_Myiter _Tmp = *this;
		++*this;
		return (_Tmp);
	}

	_Myiter& operator--()
	{	// predecrement
		--(*(_Mybase *)this);
		return (*this);
	}

	_Myiter operator--(int)
	{	// postdecrement
		_Myiter _Tmp = *this;
		--*this;
		return (_Tmp);
	}
};

template<class _Mylist> inline
typename _List_iterator<_Mylist>::_Unchecked_type
_Unchecked(_List_iterator<_Mylist> _Iter)
{	// convert to unchecked
	return (_Iter._Unchecked());
}

template<class _Mylist> inline
_List_iterator<_Mylist>&
_Rechecked(_List_iterator<_Mylist>& _Iter,
	typename _List_iterator<_Mylist>
	::_Unchecked_type _Right)
{	// convert to checked
	return (_Iter._Rechecked(_Right));
}

// list TYPE WRAPPERS
template<class _Value_type,
	class _Size_type,
	class _Difference_type,
	class _Pointer,
	class _Const_pointer,
	class _Reference,
	class _Const_reference,
	class _Nodeptr_type>
	struct _List_iter_types
{	// wraps types needed by iterators
	typedef _Value_type value_type;
	typedef _Size_type size_type;
	typedef _Difference_type difference_type;
	typedef _Pointer pointer;
	typedef _Const_pointer const_pointer;
	typedef _Reference reference;
	typedef _Const_reference const_reference;
	typedef _Nodeptr_type _Nodeptr;
};

template<class _Value_type,
	class _Voidptr>
	struct _List_node
{	// list node
	_Voidptr _Next;	// successor node, or first element if head
	_Voidptr _Prev;	// predecessor node, or last element if head
	_Value_type _Myval;	// the stored value, unused if head

private:
	_List_node& operator=(const _List_node&);
};

template<class _Value_type>
struct _List_node<_Value_type, void *>
{	// list node
	typedef _List_node<_Value_type, void *> *_Nodeptr;
	_Nodeptr _Next;	// successor node, or first element if head
	_Nodeptr _Prev;	// predecessor node, or last element if head
	_Value_type _Myval;	// the stored value, unused if head

private:
	_List_node& operator=(const _List_node&);
};

template<class _Ty>
struct _List_simple_types
	: public _Simple_types<_Ty>
{	// wraps types needed by iterators
	typedef _List_node<_Ty, void *> _Node;
	typedef _Node *_Nodeptr;
};

template<class _Ty,
	class _Alloc0>
	struct _List_base_types
{	// types needed for a container base
	typedef _Alloc0 _Alloc;
	typedef _List_base_types<_Ty, _Alloc> _Myt;

#if _HAS_CPP0X
	typedef allocator_traits<_Alloc> _Alty0;
	typedef typename _Alty0::template rebind_alloc<_Ty> _Alty;
	typedef _Wrap_alloc<_Alty> _WAlty;

	typedef typename _Get_voidptr<_WAlty, typename _WAlty::pointer>::type
		_Voidptr;
	typedef _List_node<typename _WAlty::value_type,
		_Voidptr> _Node;

	typedef typename _Alty0::template rebind_alloc<_Node> _Alnod_type;
	typedef typename _WAlty::template rebind<_Node>::other _WAlnod_type;
	typedef typename _WAlnod_type::pointer _Nodeptr;
	typedef typename _Alty0::template rebind_alloc<_Nodeptr> _Alptr_type;
	typedef _Nodeptr& _Nodepref;

	typedef typename _If<_Is_simple_alloc<_WAlty>::value,
		_List_simple_types<typename _WAlty::value_type>,
		_List_iter_types<typename _WAlty::value_type,
		typename _WAlty::size_type,
		typename _WAlty::difference_type,
		typename _WAlty::pointer,
		typename _WAlty::const_pointer,
		typename _WAlty::reference,
		typename _WAlty::const_reference,
		_Nodeptr> >::type
		_Val_types;
#else /* _HAS_CPP0X */
	typedef typename _Alloc::template rebind<_Ty>::other _Alty;

	typedef typename _Get_voidptr<_Alty, typename _Alty::pointer>::type
		_Voidptr;
	typedef _List_node<typename _Alty::value_type,
		_Voidptr> _Node;

	typedef typename _Alty::template rebind<_Node>::other _Alnod_type;
	typedef typename _Alnod_type::pointer _Nodeptr;
	typedef typename _Alty::template rebind<_Nodeptr>::other _Alptr_type;
	typedef _Nodeptr& _Nodepref;

	typedef typename _If<_Is_simple_alloc<_Alty>::value,
		_List_simple_types<typename _Alty::value_type>,
		_List_iter_types<typename _Alty::value_type,
		typename _Alty::size_type,
		typename _Alty::difference_type,
		typename _Alty::pointer,
		typename _Alty::const_pointer,
		typename _Alty::reference,
		typename _Alty::const_reference,
		_Nodeptr> >::type
		_Val_types;
#endif /* _HAS_CPP0X */
};

// TEMPLATE CLASS _List_val

#if _HAS_BACKWARD_COMPATIBILITY
template<class _Val_types,
	class _Alty,
	class _Alptr_type,
	class _Alnod_type>
	class _List_val
	: public _Container_base
{	// base class for list to hold data
public:
	typedef _List_val<_Val_types, _Alty, _Alptr_type, _Alnod_type> _Myt;

	typedef typename _Val_types::_Nodeptr _Nodeptr;
	typedef _Nodeptr& _Nodepref;

	typedef typename _Val_types::size_type size_type;

	_Nodeptr _Myhead;	// pointer to head node
	size_type _Mysize;	// number of elements

#if _HAS_CPP0X
	typedef _Wrap_alloc<_Alnod_type> _Alnod_type0;
	typedef _Wrap_alloc<_Alptr_type> _Alptr_type0;
	typedef _Wrap_alloc<_Alty> _Alty0;
	_Alnod_type0 _Alnod;
	_Alptr_type0 _Alptr;
	_Alty0 _Alval;
#else /* _HAS_CPP0X */
	_Alnod_type _Alnod;	// allocator object
	_Alptr_type _Alptr;
	_Alty _Alval;
#endif /* _HAS_CPP0X */

#else /* _HAS_BACKWARD_COMPATIBILITY */
template<class _Val_types>
class _List_val
	: public _Container_base
{	// base class for list to hold data
public:
	typedef _List_val<_Val_types> _Myt;
#endif /* _HAS_BACKWARD_COMPATIBILITY */

	typedef typename _Val_types::value_type value_type;
	typedef typename _Val_types::difference_type difference_type;
	typedef typename _Val_types::pointer pointer;
	typedef typename _Val_types::const_pointer const_pointer;
	typedef typename _Val_types::reference reference;
	typedef typename _Val_types::const_reference const_reference;

	typedef _List_const_iterator<_Myt> const_iterator;
	typedef _List_iterator<_Myt> iterator;

	typedef _List_unchecked_const_iterator<_Myt> _Unchecked_const_iterator;
	typedef _List_unchecked_iterator<_Myt> _Unchecked_iterator;

	_List_val()
	{	// initialize data
		this->_Myhead = 0;
		this->_Mysize = 0;
	}

	static _Nodepref _Nextnode(_Nodeptr _Pnode)
	{	// return reference to successor pointer in node
		return ((_Nodepref)_Pnode->_Next);
	}

	static _Nodepref _Prevnode(_Nodeptr _Pnode)
	{	// return reference to predecessor pointer in node
		return ((_Nodepref)_Pnode->_Prev);
	}

	static reference _Myval(_Nodeptr _Pnode)
	{	// return reference to value in node
		return ((reference)_Pnode->_Myval);
	}
};

// TEMPLATE CLASS _List_alloc
template<bool _Al_has_storage,
	class _Alloc_types>
	class _List_alloc

#if _HAS_BACKWARD_COMPATIBILITY
	: public _List_val<typename _Alloc_types::_Val_types,
	typename _Alloc_types::_Alty,
	typename _Alloc_types::_Alptr_type,
	typename _Alloc_types::_Alnod_type>
{	// base class for list to hold allocator with storage
public:
 #else /* _HAS_BACKWARD_COMPATIBILITY */
		: public _List_val<typename _Alloc_types::_Val_types>
	{	// base class for list to hold allocator with storage
public:
	typename _Alloc_types::_Alnod_type _Alnod;	// allocator object
 #endif /* _HAS_BACKWARD_COMPATIBILITY */

	typedef _List_alloc<_Al_has_storage, _Alloc_types> _Myt;
	typedef typename _Alloc_types::_Alloc _Alloc;
#if _HAS_CPP0X
	typedef _Wrap_alloc<typename _Alloc_types::_Alnod_type> _Alty;
#else /* _HAS_CPP0X */
	typedef typename _Alloc_types::_Alnod_type _Alty;
#endif /* _HAS_CPP0X */
	typedef typename _Alloc_types::_Node _Node;
	typedef typename _Alloc_types::_Nodeptr _Nodeptr;

 #if _ITERATOR_DEBUG_LEVEL == 0
	_List_alloc(const _Alloc& _Al = _Alloc())
		{	// construct head node, allocator from _Al
		this->_Alnod = _Al;
#if _HAS_BACKWARD_COMPATIBILITY
		this->_Alptr = _Al;
		this->_Alval = _Al;
#endif /* _HAS_BACKWARD_COMPATIBILITY */
		this->_Myhead = _Buyheadnode();
		}

	~_List_alloc() _NOEXCEPT
		{	// destroy head node
		_Freeheadnode(this->_Myhead);
		}

	void _Change_alloc(const _Alty& _Al)
		{	// replace old allocator
		this->_Alnod = _Al;
#if _HAS_BACKWARD_COMPATIBILITY
		this->_Alptr = _Al;
		this->_Alval = _Al;
#endif /* _HAS_BACKWARD_COMPATIBILITY */
		}

	void _Swap_alloc(_Myt& _Right)
		{	// swap allocators
		_Swap_adl(this->_Alnod, _Right._Alnod);
#if _HAS_BACKWARD_COMPATIBILITY
		_Swap_adl(this->_Alptr, _Right._Alptr);
		_Swap_adl(this->_Alval, _Right._Alval);
#endif /* _HAS_BACKWARD_COMPATIBILITY */
		}

 #else /* _ITERATOR_DEBUG_LEVEL == 0 */
	_List_alloc(const _Alloc& _Al = _Alloc())
		{	// construct head node, allocator from _Al
		this->_Alnod = _Al;
		this->_Myhead = _Buyheadnode();
		_TRY_BEGIN
		_Alloc_proxy();
		_CATCH_ALL
		_Freeheadnode(this->_Myhead);
		_RERAISE;
		_CATCH_END
		}

	~_List_alloc() _NOEXCEPT
		{	// destroy proxy
		_Freeheadnode(this->_Myhead);
		_Free_proxy();
		}

	void _Change_alloc(const _Alty& _Al)
		{	// replace old allocator
		_Free_proxy();
		this->_Alnod = _Al;
		_Alloc_proxy();
		}

	void _Swap_alloc(_Myt& _Right)
		{	// swap allocators
		_Swap_adl(this->_Alnod, _Right._Alnod);
		_Swap_adl(this->_Myproxy, _Right._Myproxy);
		}

	void _Alloc_proxy()
		{	// construct proxy from _Alnod
		typename _Alty::template rebind<_Container_proxy>::other
			_Alproxy(this->_Alnod);
		this->_Myproxy = _Alproxy.allocate(1);
		_Alproxy.construct(this->_Myproxy, _Container_proxy());
		this->_Myproxy->_Mycont = this;
		}

	void _Free_proxy()
		{	// destroy proxy
		typename _Alty::template rebind<_Container_proxy>::other
			_Alproxy(this->_Alnod);
		this->_Orphan_all();
		_Alproxy.destroy(this->_Myproxy);
		_Alproxy.deallocate(this->_Myproxy, 1);
		this->_Myproxy = 0;
		}
 #endif /* _ITERATOR_DEBUG_LEVEL == 0 */

	_Nodeptr _Buyheadnode()
		{	// get head node using current allocator
		return (_Buynode0(_Nodeptr(), _Nodeptr()));
		}

	void _Freeheadnode(_Nodeptr _Pnode)
		{	// free head node using current allocator
#if _HAS_BACKWARD_COMPATIBILITY
		this->_Alptr.destroy(
			_STD addressof(this->_Nextnode(_Pnode)));
		this->_Alptr.destroy(
			_STD addressof(this->_Prevnode(_Pnode)));
#else /* _HAS_BACKWARD_COMPATIBILITY */
		this->_Alnod.destroy(
			_STD addressof(this->_Nextnode(_Pnode)));
		this->_Alnod.destroy(
			_STD addressof(this->_Prevnode(_Pnode)));
#endif /* _HAS_BACKWARD_COMPATIBILITY */
		this->_Alnod.deallocate(_Pnode, 1);
		}

	_Nodeptr _Buynode0(_Nodeptr _Next,
		_Nodeptr _Prev)
		{	// allocate a node and set links
		_Nodeptr _Pnode = this->_Alnod.allocate(1);
#if _HAS_BACKWARD_COMPATIBILITY
		int _Linkcnt = 0;
#endif /* _HAS_BACKWARD_COMPATIBILITY */

		if (_Next == _Nodeptr())
			{	// point at self
			_Next = _Pnode;
			_Prev = _Pnode;
			}
		_TRY_BEGIN
#if _HAS_BACKWARD_COMPATIBILITY
		this->_Alptr.construct(
			_STD addressof(this->_Nextnode(_Pnode)), _Next);
		++_Linkcnt;
		this->_Alptr.construct(
			_STD addressof(this->_Prevnode(_Pnode)), _Prev);
#else /* _HAS_BACKWARD_COMPATIBILITY */
		this->_Alnod.construct(
			_STD addressof(this->_Nextnode(_Pnode)), _Next);
		this->_Alnod.construct(
			_STD addressof(this->_Prevnode(_Pnode)), _Prev);
#endif /* _HAS_BACKWARD_COMPATIBILITY */
		_CATCH_ALL
#if _HAS_BACKWARD_COMPATIBILITY
		if (0 < _Linkcnt)
			this->_Alptr.destroy(
				_STD addressof(this->_Nextnode(_Pnode)));
#endif /* _HAS_BACKWARD_COMPATIBILITY */
		this->_Alnod.deallocate(_Pnode, 1);
		_RERAISE;
		_CATCH_END

		return (_Pnode);
		}

	_Alty& _Getal()
		{	// get reference to allocator
		return (this->_Alnod);
		}

	const _Alty& _Getal() const
		{	// get reference to allocator
		return (this->_Alnod);
		}
	};

 #if _HAS_BACKWARD_COMPATIBILITY

 #else /* _HAS_BACKWARD_COMPATIBILITY */
// TEMPLATE CLASS _List_alloc
template<class _Alloc_types>
	class _List_alloc<false, _Alloc_types>
		: public _List_val<typename _Alloc_types::_Val_types>
	{	// base class for list to hold allocator with no storage
public:
	typedef _List_alloc<false, _Alloc_types> _Myt;
	typedef typename _Alloc_types::_Alloc _Alloc;
	typedef typename _Alloc_types::_Alnod_type _Alty;
	typedef typename _Alloc_types::_Node _Node;
	typedef typename _Alloc_types::_Nodeptr _Nodeptr;

 #if _ITERATOR_DEBUG_LEVEL == 0
	_List_alloc(const _Alloc& = _Alloc())
		{	// construct head node, allocator from _Al
		this->_Myhead = _Buyheadnode();
		}

	~_List_alloc() _NOEXCEPT
		{	// destroy head node
		_Freeheadnode(this->_Myhead);
		}

	void _Change_alloc(const _Alty&)
		{	// replace old allocator
		}

	void _Swap_alloc(_Myt&)
		{	// swap allocators
		}

 #else /* _ITERATOR_DEBUG_LEVEL == 0 */
	_List_alloc(const _Alloc& = _Alloc())
		{	// construct allocators from _Al
		this->_Myhead = _Buyheadnode();
		_TRY_BEGIN
		_Alloc_proxy();
		_CATCH_ALL
		_Freeheadnode(this->_Myhead);
		_RERAISE;
		_CATCH_END
		}

	~_List_alloc() _NOEXCEPT
		{	// destroy proxy
		_Freeheadnode(this->_Myhead);
		_Free_proxy();
		}

	void _Change_alloc(const _Alty&)
		{	// replace old allocator
		}

	void _Swap_alloc(_Myt& _Right)
		{	// swap allocators
		_Swap_adl(this->_Myproxy, _Right._Myproxy);
		}

	void _Alloc_proxy()
		{	// construct proxy from _Alnod
		typename _Alty::template rebind<_Container_proxy>::other
			_Alproxy;
		this->_Myproxy = _Alproxy.allocate(1);
		_Alproxy.construct(this->_Myproxy, _Container_proxy());
		this->_Myproxy->_Mycont = this;
		}

	void _Free_proxy()
		{	// destroy proxy
		typename _Alty::template rebind<_Container_proxy>::other
			_Alproxy;
		this->_Orphan_all();
		_Alproxy.destroy(this->_Myproxy);
		_Alproxy.deallocate(this->_Myproxy, 1);
		this->_Myproxy = 0;
		}
 #endif /* _ITERATOR_DEBUG_LEVEL == 0 */

	_Nodeptr _Buyheadnode()
		{	// get head node using current allocator
		return (_Buynode0(_Nodeptr(), _Nodeptr()));
		}

	void _Freeheadnode(_Nodeptr _Pnode)
		{	// free head node using current allocator
		this->_Getal().destroy(
			_STD addressof(this->_Nextnode(_Pnode)));
		this->_Getal().destroy(
			_STD addressof(this->_Prevnode(_Pnode)));
		this->_Getal().deallocate(_Pnode, 1);
		}

	_Nodeptr _Buynode0(_Nodeptr _Next,
		_Nodeptr _Prev)
		{	// allocate a node and set links
		_Nodeptr _Pnode = this->_Getal().allocate(1);

		if (_Next == _Nodeptr())
			{	// point at self
			_Next = _Pnode;
			_Prev = _Pnode;
			}
		_TRY_BEGIN
		this->_Getal().construct(
			_STD addressof(this->_Nextnode(_Pnode)), _Next);
		this->_Getal().construct(
			_STD addressof(this->_Prevnode(_Pnode)), _Prev);
		_CATCH_ALL
		this->_Getal().deallocate(_Pnode, 1);
		_RERAISE;
		_CATCH_END

		return (_Pnode);
		}

	_Alty _Getal() const
		{	// get reference to allocator
		return (_Alty());
		}
	};
 #endif /* _HAS_BACKWARD_COMPATIBILITY */

	// TEMPLATE CLASS _List_buy
template<class _Ty,
	class _Alloc>
	class _List_buy
		: public _List_alloc<!is_empty<_Alloc>::value,
			_List_base_types<_Ty, _Alloc> >
	{	// base class for list to hold buynode/freenode functions
public:
	typedef _List_alloc<!is_empty<_Alloc>::value,
		_List_base_types<_Ty, _Alloc> > _Mybase;
	typedef typename _Mybase::_Alty _Alty;
	typedef typename _Mybase::_Nodeptr _Nodeptr;

	_List_buy(const _Alloc& _Al = _Alloc())
		: _Mybase(_Al)
		{	// construct from allocator
		}

 #if _HAS_RVALUE_REFERENCES

 #if _HAS_VARIADIC_TEMPLATES
	template<class... _Valty>
		_Nodeptr _Buynode(_Nodeptr _Next, _Nodeptr _Prev,
			_Valty&&... _Val)
		{	// allocate a node and set links and value
		_Nodeptr _Pnode = this->_Buynode0(_Next, _Prev);

		_TRY_BEGIN
		this->_Getal().construct(
			_STD addressof(this->_Myval(_Pnode)),
				_STD forward<_Valty>(_Val)...);
		_CATCH_ALL
		this->_Getal().deallocate(_Pnode, 1);
		_RERAISE;
		_CATCH_END

		return (_Pnode);
		}

 #else /* _HAS_VARIADIC_TEMPLATES */
#define _LIST_BUYNODE( \
	TEMPLATE_LIST, PADDING_LIST, LIST, C, X1, X2, X3, X4) \
	TEMPLATE_LIST(_CLASS_TYPE) \
		_Nodeptr _Buynode(_Nodeptr _Next, \
			_Nodeptr _Prev _EX(C) LIST(_TYPE_REFREF_ARG)) \
		{	/* allocate a node and set links and value */ \
		_Nodeptr _Pnode = this->_Buynode0(_Next, _Prev); \
		_TRY_BEGIN \
		this->_Getal().construct( \
			_STD addressof(this->_Myval(_Pnode)) \
				_EX(C) LIST(_FORWARD_ARG)); \
		_CATCH_ALL \
		this->_Getal().deallocate(_Pnode, 1); \
		_RERAISE; \
		_CATCH_END \
		return (_Pnode); \
		}

_VARIADIC_EXPAND_0X(_LIST_BUYNODE, , , ,)
#undef _LIST_BUYNODE
 #endif /* _HAS_VARIADIC_TEMPLATES */

 #else /* _HAS_RVALUE_REFERENCES */
	_Nodeptr _Buynode(_Nodeptr _Next, _Nodeptr _Prev,
		const _Ty& _Val)
		{	// allocate a node and set links and value
		_Nodeptr _Pnode = this->_Buynode0(_Next, _Prev);

		_TRY_BEGIN
#if _HAS_BACKWARD_COMPATIBILITY
		this->_Alval.construct(
			_STD addressof(this->_Myval(_Pnode)), _Val);
#else /* _HAS_BACKWARD_COMPATIBILITY */
		this->_Getal().construct(
			_STD addressof(this->_Myval(_Pnode)), _Val);
#endif /* _HAS_BACKWARD_COMPATIBILITY */
		_CATCH_ALL
		this->_Getal().deallocate(_Pnode, 1);
		_RERAISE;
		_CATCH_END

		return (_Pnode);
		}

	_Nodeptr _Buynode(_Nodeptr _Next, _Nodeptr _Prev)
		{	// allocate a node and set links and default value
		_Nodeptr _Pnode = this->_Buynode0(_Next, _Prev);

		_TRY_BEGIN
		this->_Getal().construct(
			_STD addressof(this->_Myval(_Pnode)));
		_CATCH_ALL
		this->_Getal().deallocate(_Pnode, 1);
		_RERAISE;
		_CATCH_END

		return (_Pnode);
		}
 #endif /* _HAS_RVALUE_REFERENCES */

	void _Freenode(_Nodeptr _Pnode)
		{	// give node back
#if _HAS_BACKWARD_COMPATIBILITY
		this->_Getal().destroy(_Pnode);
#else /* _HAS_BACKWARD_COMPATIBILITY */
		this->_Getal().destroy(
			_STD addressof(this->_Nextnode(_Pnode)));
		this->_Getal().destroy(
			_STD addressof(this->_Prevnode(_Pnode)));
		this->_Getal().destroy(
			_STD addressof(this->_Myval(_Pnode)));
#endif /* _HAS_BACKWARD_COMPATIBILITY */
		this->_Getal().deallocate(_Pnode, 1);
		}
	};

// TEMPLATE CLASS list
template<class _Ty,
	class _Alloc = allocator<_Ty> >
	class list
		: public _List_buy<_Ty, _Alloc>
	{	// bidirectional linked list
public:
	typedef list<_Ty, _Alloc> _Myt;
	typedef _List_buy<_Ty, _Alloc> _Mybase;
	typedef typename _Mybase::_Node _Node;
	typedef typename _Mybase::_Nodeptr _Nodeptr;
	typedef typename _Mybase::_Alty _Alty;

	typedef _Alloc allocator_type;
	typedef typename _Mybase::size_type size_type;
	typedef typename _Mybase::difference_type difference_type;
	typedef typename _Mybase::pointer pointer;
	typedef typename _Mybase::const_pointer const_pointer;
	typedef typename _Mybase::reference reference;
	typedef typename _Mybase::const_reference const_reference;
	typedef typename _Mybase::value_type value_type;

	typedef typename _Mybase::const_iterator const_iterator;
	typedef typename _Mybase::iterator iterator;
	typedef typename _Mybase::_Unchecked_const_iterator
		_Unchecked_const_iterator;
	typedef typename _Mybase::_Unchecked_iterator
		_Unchecked_iterator;

	typedef _STD reverse_iterator<iterator> reverse_iterator;
	typedef _STD reverse_iterator<const_iterator> const_reverse_iterator;

	list()
		: _Mybase()
		{	// construct empty list
		}

	explicit list(const _Alloc& _Al)
		: _Mybase(_Al)
		{	// construct empty list, allocator
		}

	explicit list(size_type _Count)
		: _Mybase()
		{	// construct list from _Count * _Ty()
		resize(_Count);
		}

	list(size_type _Count, const _Ty& _Val)
		: _Mybase()
		{	// construct list from _Count * _Val
		_Construct_n(_Count, _Val);
		}

	list(size_type _Count, const _Ty& _Val, const _Alloc& _Al)
		: _Mybase(_Al)
		{	// construct list from _Count * _Val, allocator
		_Construct_n(_Count, _Val);
		}

	list(const _Myt& _Right)

 #if _HAS_CPP0X
		: _Mybase(_Right._Getal().select_on_container_copy_construction())

 #else /* _HAS_CPP0X */
		: _Mybase(_Right._Getal())
 #endif /* _HAS_CPP0X */

		{	// construct list by copying _Right
		_TRY_BEGIN
		insert(begin(), _Right.begin(), _Right.end());
		_CATCH_ALL
		_Tidy();
		_RERAISE;
		_CATCH_END
		}

	list(const _Myt& _Right, const _Alloc& _Al)
		: _Mybase(_Al)
		{	// construct list by copying _Right, allocator
		_TRY_BEGIN
		insert(begin(), _Right.begin(), _Right.end());
		_CATCH_ALL
		_Tidy();
		_RERAISE;
		_CATCH_END
		}

	template<class _Iter>
		list(_Iter _First, _Iter _Last,
			typename enable_if<_Is_iterator<_Iter>::value,
				void>::type ** = 0)
		: _Mybase()
		{	// construct list from [_First, _Last,
		_Construct(_First, _Last);
		}

	template<class _Iter>
		list(_Iter _First, _Iter _Last, const _Alloc& _Al,
			typename enable_if<_Is_iterator<_Iter>::value,
				void>::type ** = 0)
		: _Mybase(_Al)
		{	// construct list, allocator from [_First, _Last)
		_Construct(_First, _Last);
		}

	template<class _Iter>
		void _Construct(_Iter _First, _Iter _Last)
		{	// construct list from [_First, _Last), input iterators
		_TRY_BEGIN
		insert(begin(), _First, _Last);
		_CATCH_ALL
		_Tidy();
		_RERAISE;
		_CATCH_END
		}

	void _Construct_n(size_type _Count,
		const _Ty& _Val)
		{	// construct from _Count * _Val
		_TRY_BEGIN
		_Insert_n(_Unchecked_begin(), _Count, _Val);
		_CATCH_ALL
		_Tidy();
		_RERAISE;
		_CATCH_END
		}

 #if _HAS_RVALUE_REFERENCES
	list(_Myt&& _Right)
		: _Mybase(_Right._Getal())
		{	// construct list by moving _Right
		_Assign_rv(_STD forward<_Myt>(_Right));
		}

	list(_Myt&& _Right, const _Alloc& _Al)
		: _Mybase(_Al)
		{	// construct list by moving _Right, allocator
		_Assign_rv(_STD forward<_Myt>(_Right));
		}

	_Myt& operator=(_Myt&& _Right)
		{	// assign by moving _Right
		if (this != &_Right)
			{	// different, assign it
			clear();

 #if _HAS_CPP0X
			if (this->_Getal() != _Right._Getal()
				&& _Alty::propagate_on_container_move_assignment::value)
				this->_Change_alloc(_Right._Getal());
 #endif /* _HAS_CPP0X */

			_Assign_rv(_STD forward<_Myt>(_Right));
			}
		return (*this);
		}

	void _Assign_rv(_Myt&& _Right)
		{	// swap with empty *this, same allocator
		this->_Swap_all(_Right);
		_Swap_adl(this->_Myhead, _Right._Myhead);
		_STD swap(this->_Mysize, _Right._Mysize);
		}

	void push_front(_Ty&& _Val)
		{	// insert element at beginning
		_Insert(_Unchecked_begin(), _STD forward<_Ty>(_Val));
		}

	void push_back(_Ty&& _Val)
		{	// insert element at end
		_Insert(_Unchecked_end(), _STD forward<_Ty>(_Val));
		}

	iterator insert(const_iterator _Where, _Ty&& _Val)
		{	// insert _Val at _Where
		return (emplace(_Where, _STD forward<_Ty>(_Val)));
		}

 #if _HAS_VARIADIC_TEMPLATES
	template<class... _Valty>
		void emplace_front(_Valty&&... _Val)
		{	// insert element at beginning
		_Insert(_Unchecked_begin(), _STD forward<_Valty>(_Val)...);
		}

	template<class... _Valty>
		void emplace_back(_Valty&&... _Val)
		{	// insert element at end
		_Insert(_Unchecked_end(), _STD forward<_Valty>(_Val)...);
		}

	template<class... _Valty>
		iterator emplace(const_iterator _Where, _Valty&&... _Val)
		{	// insert element at _Where
 #if _ITERATOR_DEBUG_LEVEL == 2
		if (_Where._Getcont() != this)
			_DEBUG_ERROR("list emplace iterator outside range");
 #endif /* _ITERATOR_DEBUG_LEVEL == 2 */

		_Insert(_Where._Unchecked(), _STD forward<_Valty>(_Val)...);
		return (_Make_iter(--_Where));
		}

	template<class... _Valty>
		void _Insert(_Unchecked_const_iterator _Where,
		_Valty&&... _Val)
		{	// insert element at _Where
		_Nodeptr _Pnode = _Where._Mynode();
		_Nodeptr _Newnode =
			this->_Buynode(_Pnode, this->_Prevnode(_Pnode),
				_STD forward<_Valty>(_Val)...);
		_Incsize(1);
		this->_Prevnode(_Pnode) = _Newnode;
		this->_Nextnode(this->_Prevnode(_Newnode)) = _Newnode;
		}

 #else /* _HAS_VARIADIC_TEMPLATES */
#define _LIST_EMPLACE_INSERT( \
	TEMPLATE_LIST, PADDING_LIST, LIST, C, X1, X2, X3, X4) \
	TEMPLATE_LIST(_CLASS_TYPE) \
		void emplace_front(LIST(_TYPE_REFREF_ARG)) \
		{	/* insert element at beginning */ \
		_Insert(_Unchecked_begin() _EX(C) LIST(_FORWARD_ARG)); \
		} \
	TEMPLATE_LIST(_CLASS_TYPE) \
		void emplace_back(LIST(_TYPE_REFREF_ARG)) \
		{	/* insert element at end */ \
		_Insert(_Unchecked_end() _EX(C) LIST(_FORWARD_ARG)); \
		} \
	TEMPLATE_LIST(_CLASS_TYPE) \
		iterator emplace(const_iterator _Where \
			_EX(C) LIST(_TYPE_REFREF_ARG)) \
		{	/* insert element at _Where */ \
		_LIST_EMPLACE_CHECK \
		_Insert(_Where._Unchecked() _EX(C) LIST(_FORWARD_ARG)); \
		return (_Make_iter(--_Where)); \
		} \
	TEMPLATE_LIST(_CLASS_TYPE) \
		void _Insert(_Unchecked_const_iterator _Where \
			_EX(C) LIST(_TYPE_REFREF_ARG)) \
		{	/* insert element at _Where */ \
		_Nodeptr _Pnode = _Where._Mynode(); \
		_Nodeptr _Newnode = this->_Buynode(_Pnode, \
			this->_Prevnode(_Pnode) _EX(C) LIST(_FORWARD_ARG)); \
		_Incsize(1); \
		this->_Prevnode(_Pnode) = _Newnode; \
		this->_Nextnode(this->_Prevnode(_Newnode)) = _Newnode; \
		}

 #if _ITERATOR_DEBUG_LEVEL == 2
#define _LIST_EMPLACE_CHECK \
		if (_Where._Getcont() != this) \
			_DEBUG_ERROR("list emplace iterator outside range");

 #else /* _ITERATOR_DEBUG_LEVEL == 2 */
#define _LIST_EMPLACE_CHECK
 #endif /* _ITERATOR_DEBUG_LEVEL == 2 */

_VARIADIC_EXPAND_0X(_LIST_EMPLACE_INSERT, , , ,)
#undef _LIST_EMPLACE_CHECK
#undef _LIST_EMPLACE_INSERT
 #endif /* _HAS_VARIADIC_TEMPLATES */

 #else /* _HAS_RVALUE_REFERENCES */
	void _Insert(_Unchecked_const_iterator _Where,
		const _Ty& _Val)
		{	// insert _Val at _Where
		_Nodeptr _Pnode = _Where._Mynode();
		_Nodeptr _Newnode =
			this->_Buynode(_Pnode, this->_Prevnode(_Pnode), _Val);
		_Incsize(1);
		this->_Prevnode(_Pnode) = _Newnode;
		this->_Nextnode(this->_Prevnode(_Newnode)) = _Newnode;
		}
 #endif /* _HAS_RVALUE_REFERENCES */

 #if _HAS_INITIALIZER_LISTS
	list(_XSTD initializer_list<_Ty> _Ilist,
		const _Alloc& _Al = allocator_type())
		: _Mybase(_Al)
		{	// construct from initializer_list
		insert(begin(), _Ilist.begin(), _Ilist.end());
		}

	_Myt& operator=(_XSTD initializer_list<_Ty> _Ilist)
		{	// assign initializer_list
		assign(_Ilist.begin(), _Ilist.end());
		return (*this);
		}

	void assign(_XSTD initializer_list<_Ty> _Ilist)
		{	// assign initializer_list
		assign(_Ilist.begin(), _Ilist.end());
		}

	iterator insert(const_iterator _Where,
		_XSTD initializer_list<_Ty> _Ilist)
		{	// insert initializer_list
		return (insert(_Where, _Ilist.begin(), _Ilist.end()));
		}
 #endif /* _HAS_INITIALIZER_LISTS */

	~list() _NOEXCEPT
		{	// destroy the object
		_Tidy();
		}

	_Myt& operator=(const _Myt& _Right)
		{	// assign _Right
		if (this != &_Right)
			{	// different, assign it
 #if _HAS_CPP0X
			if (this->_Getal() != _Right._Getal()
				&& _Alty::propagate_on_container_copy_assignment::value)
				{	// change allocator before copying
				clear();
				this->_Change_alloc(_Right._Getal());
				}
 #endif /* _HAS_CPP0X */

			assign(_Right.begin(), _Right.end());
			}
		return (*this);
		}

	iterator begin() _NOEXCEPT
		{	// return iterator for beginning of mutable sequence
		return (iterator(this->_Nextnode(this->_Myhead), this));
		}

	const_iterator begin() const _NOEXCEPT
		{	// return iterator for beginning of nonmutable sequence
		return (const_iterator(this->_Nextnode(this->_Myhead), this));
		}

	iterator end() _NOEXCEPT
		{	// return iterator for end of mutable sequence
		return (iterator(this->_Myhead, this));
		}

	const_iterator end() const _NOEXCEPT
		{	// return iterator for end of nonmutable sequence
		return (const_iterator(this->_Myhead, this));
		}

	_Unchecked_iterator _Unchecked_begin()
		{	// return iterator for beginning of mutable sequence
		return (_Unchecked_iterator(this->_Nextnode(this->_Myhead),
			this));
		}

	_Unchecked_const_iterator _Unchecked_begin() const
		{	// return iterator for beginning of nonmutable sequence
		return (_Unchecked_const_iterator(this->_Nextnode(this->_Myhead),
			this));
		}

	_Unchecked_iterator _Unchecked_end()
		{	// return unchecked iterator for end of mutable sequence
		return (_Unchecked_iterator(this->_Myhead, this));
		}

	_Unchecked_const_iterator _Unchecked_end() const
		{	// return unchecked iterator for end of nonmutable sequence
		return (_Unchecked_const_iterator(this->_Myhead, this));
		}

	iterator _Make_iter(const_iterator _Where) const _NOEXCEPT
		{	// make iterator from const_iterator
		return (iterator(_Where._Ptr, this));
		}

	iterator _Make_iter(_Unchecked_const_iterator _Where) const
		{	// make iterator from _Unchecked_const_iterator
		return (iterator(_Where._Ptr, this));
		}

	reverse_iterator rbegin() _NOEXCEPT
		{	// return iterator for beginning of reversed mutable sequence
		return (reverse_iterator(end()));
		}

	const_reverse_iterator rbegin() const _NOEXCEPT
		{	// return iterator for beginning of reversed nonmutable sequence
		return (const_reverse_iterator(end()));
		}

	reverse_iterator rend() _NOEXCEPT
		{	// return iterator for end of reversed mutable sequence
		return (reverse_iterator(begin()));
		}

	const_reverse_iterator rend() const _NOEXCEPT
		{	// return iterator for end of reversed nonmutable sequence
		return (const_reverse_iterator(begin()));
		}

 #if _HAS_CPP0X
	const_iterator cbegin() const _NOEXCEPT
		{	// return iterator for beginning of nonmutable sequence
		return (((const _Myt *)this)->begin());
		}

	const_iterator cend() const _NOEXCEPT
		{	// return iterator for end of nonmutable sequence
		return (((const _Myt *)this)->end());
		}

	const_reverse_iterator crbegin() const _NOEXCEPT
		{	// return iterator for beginning of reversed nonmutable sequence
		return (((const _Myt *)this)->rbegin());
		}

	const_reverse_iterator crend() const _NOEXCEPT
		{	// return iterator for end of reversed nonmutable sequence
		return (((const _Myt *)this)->rend());
		}
 #endif /* _HAS_CPP0X */

	void resize(size_type _Newsize)
		{	// determine new length, padding with _Ty() elements as needed
		if (this->_Mysize < _Newsize)
			{	// pad to make larger
			size_type _Count = 0;
			_TRY_BEGIN
			for (; this->_Mysize < _Newsize; ++_Count)
#if _HAS_VARIADIC_TEMPLATES
				_Insert(_Unchecked_end());
#else /* _HAS_VARIADIC_TEMPLATES */
				_Insert(_Unchecked_end(), _Ty());
#endif /* _HAS_VARIADIC_TEMPLATES */
			_CATCH_ALL
			for (; 0 < _Count; --_Count)
				pop_back();	// undo inserts
			_RERAISE;
			_CATCH_END
			}
		else
			while (_Newsize < this->_Mysize)
				pop_back();
		}

	void resize(size_type _Newsize, const _Ty& _Val)
		{	// determine new length, padding with _Val elements as needed
		if (this->_Mysize < _Newsize)
			_Insert_n(_Unchecked_end(), _Newsize - this->_Mysize, _Val);
		else
			while (_Newsize < this->_Mysize)
				pop_back();
		}

	size_type size() const _NOEXCEPT
		{	// return length of sequence
		return (this->_Mysize);
		}

	size_type max_size() const _NOEXCEPT
		{	// return maximum possible length of sequence
		return (this->_Getal().max_size());
		}

	bool empty() const _NOEXCEPT
		{	// test if sequence is empty
		return (this->_Mysize == 0);
		}

	allocator_type get_allocator() const _NOEXCEPT
		{	// return allocator object for values
		return (this->_Getal());
		}

	reference front()
		{	// return first element of mutable sequence
		return (*begin());
		}

	const_reference front() const
		{	// return first element of nonmutable sequence
		return (*begin());
		}

	reference back()
		{	// return last element of mutable sequence
		return (*(--end()));
		}

	const_reference back() const
		{	// return last element of nonmutable sequence
		return (*(--end()));
		}

	void push_front(const _Ty& _Val)
		{	// insert element at beginning
		_Insert(_Unchecked_begin(), _Val);
		}

	void pop_front()
		{	// erase element at beginning
		erase(begin());
		}

	void push_back(const _Ty& _Val)
		{	// insert element at end
		_Insert(_Unchecked_end(), _Val);
		}

	void pop_back()
		{	// erase element at end
		erase(--end());
		}

#if _HAS_CPP0X
	template<class _Iter>
		typename enable_if<_Is_iterator<_Iter>::value,
			void>::type
		assign(_Iter _First, _Iter _Last)
		{	// assign [_First, _Last), input iterators
		iterator _Old = begin();
		_TRY_BEGIN
		for (; _First != _Last && _Old != end(); ++_First, ++_Old)
			*_Old = *_First;
		for (; _First != _Last; ++_First)
			_Insert(_Unchecked_end(), *_First);
		_CATCH_ALL
		clear();
		_RERAISE;
		_CATCH_END
		erase(_Old, end());
		}
#else /* _HAS_CPP0X */
	template<class _Iter>
		void assign(_Iter _First, _Iter _Last)
		{	// assign [_First, _Last)
		_Assign(_First, _Last, _Iter_cat(_First));
		}

	template<class _Iter>
		void _Assign(_Iter _Count, _Iter _Val, _Int_iterator_tag)
		{	// assign _Count * _Val
		_Assign_n((size_type)_Count, (_Ty)_Val);
		}

	template<class _Iter>
		void _Assign(_Iter _First, _Iter _Last, input_iterator_tag)
		{	// assign [_First, _Last), input iterators
		iterator _Old = begin();
		_TRY_BEGIN
		for (; _First != _Last && _Old != end(); ++_First, ++_Old)
			*_Old = *_First;
		for (; _First != _Last; ++_First)
			_Insert(_Unchecked_end(), *_First);
		_CATCH_ALL
		clear();
		_RERAISE;
		_CATCH_END
		erase(_Old, end());
		}
#endif /* _HAS_CPP0X */

	void assign(size_type _Count, const _Ty& _Val)
		{	// assign _Count * _Val
		_Assign_n(_Count, _Val);
		}

	iterator insert(const_iterator _Where, const _Ty& _Val)
		{	// insert _Val at _Where
 #if _ITERATOR_DEBUG_LEVEL == 2
		if (_Where._Getcont() != this)
			_DEBUG_ERROR("list insert iterator outside range");
 #endif /* _ITERATOR_DEBUG_LEVEL == 2 */

		_Insert(_Where._Unchecked(), _Val);
		return (_Make_iter(--_Where));
		}

	iterator insert(const_iterator _Where, size_type _Count, const _Ty& _Val)
		{	// insert _Count * _Val at _Where
 #if _ITERATOR_DEBUG_LEVEL == 2
		if (_Where._Getcont() != this)
			_DEBUG_ERROR("list insert iterator outside range");
 #endif /* _ITERATOR_DEBUG_LEVEL == 2 */

		iterator _Prev = _Make_iter(_Where);
		if (_Prev == begin())
			{	// insert sequence at beginning
			_Insert_n(_Where._Unchecked(), _Count, _Val);
			return (begin());
			}
		else
			{	// insert sequence not at beginning
			--_Prev;
			_Insert_n(_Where._Unchecked(), _Count, _Val);
			return (++_Prev);
			}
		}

#if _HAS_CPP0X
	template<class _Iter>
		typename enable_if<_Is_iterator<_Iter>::value,
			iterator>::type
		insert(const_iterator _Where, _Iter _First, _Iter _Last)
		{	// insert [_First, _Last) at _Where
 #if _ITERATOR_DEBUG_LEVEL == 2
		if (_Where._Getcont() != this)
			_DEBUG_ERROR("list insert iterator outside range");
 #endif /* _ITERATOR_DEBUG_LEVEL == 2 */

		iterator _Prev = _Make_iter(_Where);
		if (_Prev == begin())
			{	// insert sequence at beginning
			_Insert_range(_Where._Unchecked(), _First, _Last,
				_Iter_cat(_First));
			return (begin());
			}
		else
			{	// insert sequence not at beginning
			--_Prev;
			_Insert_range(_Where._Unchecked(), _First, _Last,
				_Iter_cat(_First));
			return (++_Prev);
			}
		}
#else /* _HAS_CPP0X */
	template<class _Iter>
		void insert(const_iterator _Where, _Iter _First, _Iter _Last)
		{	// insert [_First, _Last) at _Where
		_Insert_range(_Where._Unchecked(), _First, _Last, _Iter_cat(_First));
		}

	template<class _Iter>
		void _Insert_range(_Unchecked_const_iterator _Where,
			_Iter _Count, _Iter _Val, _Int_iterator_tag)
		{	// insert _Count * _Val at _Where
		_Insert_n(_Where, (size_type)_Count, (_Ty)_Val);
		}
#endif /* _HAS_CPP0X */

	template<class _Iter>
		void _Insert_range(_Unchecked_const_iterator _Where,
			_Iter _First, _Iter _Last, input_iterator_tag)
		{	// insert [_First, _Last) at _Where, input iterators
		size_type _Num = 0;

		_TRY_BEGIN
		for (; _First != _Last; ++_First, ++_Num)
			_Insert(_Where, *_First);
		_CATCH_ALL
		for (; 0 < _Num; --_Num)
			{	// undo inserts
			_Unchecked_const_iterator _Before = _Where;
			_Unchecked_erase(--_Before);
			}
		_RERAISE;
		_CATCH_END
		}

	template<class _Iter>
		void _Insert_range(_Unchecked_const_iterator _Where,
			_Iter _First, _Iter _Last, forward_iterator_tag)
		{	// insert [_First, _Last) at _Where, forward iterators
		_DEBUG_RANGE(_First, _Last);
		_Iter _Next = _First;

		_TRY_BEGIN
		for (; _First != _Last; ++_First)
			_Insert(_Where, *_First);
		_CATCH_ALL
		for (; _Next != _First; ++_Next)
			{	// undo inserts
			_Unchecked_const_iterator _Before = _Where;
			_Unchecked_erase(--_Before);
			}
		_RERAISE;
		_CATCH_END
		}

	iterator erase(const_iterator _Where)
		{	// erase element at _Where
 #if _ITERATOR_DEBUG_LEVEL == 2
		if (_Where._Getcont() != this || _Where._Ptr == this->_Myhead)
			_DEBUG_ERROR("list erase iterator outside range");
		_Nodeptr _Pnode = (_Where++)._Mynode();
		_Orphan_ptr(*this, _Pnode);

 #else /* _ITERATOR_DEBUG_LEVEL == 2 */
		_Nodeptr _Pnode = (_Where++)._Mynode();
 #endif /* _ITERATOR_DEBUG_LEVEL == 2 */

		if (_Pnode != this->_Myhead)
			{	// not list head, safe to erase
			this->_Nextnode(this->_Prevnode(_Pnode)) =
				this->_Nextnode(_Pnode);
			this->_Prevnode(this->_Nextnode(_Pnode)) =
				this->_Prevnode(_Pnode);
			this->_Freenode(_Pnode);
			--this->_Mysize;
			}
		return (_Make_iter(_Where));
		}

	void _Unchecked_erase(_Unchecked_const_iterator _Where)
		{	// erase element at _Where
		_Nodeptr _Pnode = _Where._Mynode();

		if (_Pnode != this->_Myhead)
			{	// not list head, safe to erase
			this->_Nextnode(this->_Prevnode(_Pnode)) =
				this->_Nextnode(_Pnode);
			this->_Prevnode(this->_Nextnode(_Pnode)) =
				this->_Prevnode(_Pnode);
			this->_Freenode(_Pnode);
			--this->_Mysize;
			}
		}

	iterator erase(const_iterator _First, const_iterator _Last)
		{	// erase [_First, _Last)
		if (_First == begin() && _Last == end())
			{	// erase all and return fresh iterator
			clear();
			return (end());
			}
		else
			{	// erase subrange
			while (_First != _Last)
				_First = erase(_First);
			return (_Make_iter(_Last));
			}
		}

	void clear() _NOEXCEPT
		{	// erase all
 #if _ITERATOR_DEBUG_LEVEL == 2
		this->_Orphan_all();
 #endif /* _ITERATOR_DEBUG_LEVEL == 2 */

		_Nodeptr _Pnode = this->_Nextnode(this->_Myhead);
		this->_Nextnode(this->_Myhead) = this->_Myhead;
		this->_Prevnode(this->_Myhead) = this->_Myhead;
		this->_Mysize = 0;

		for (_Nodeptr _Pnext; _Pnode != this->_Myhead; _Pnode = _Pnext)
			{	// delete an element
			_Pnext = this->_Nextnode(_Pnode);
			this->_Freenode(_Pnode);
			}
		}

	void swap(_Myt& _Right)
		{	// exchange contents with _Right
		if (this == &_Right)
			;	// same object, do nothing
		else if (this->_Getal() == _Right._Getal())
			{	// same allocator, swap control information
			this->_Swap_all(_Right);
			_Swap_adl(this->_Myhead, _Right._Myhead);
			_STD swap(this->_Mysize, _Right._Mysize);
			}

 #if _HAS_CPP0X
		else if (_Alty::propagate_on_container_swap::value)
			{	// swap allocators and control information
			this->_Swap_alloc(_Right);
			_Swap_adl(this->_Myhead, _Right._Myhead);
			_STD swap(this->_Mysize, _Right._Mysize);
			}
 #endif /* _HAS_CPP0X */

		else
			{	// different allocator, do splices
			iterator _Where = begin();
			splice(_Where, _Right);
			_Right.splice(_Right.begin(), *this, _Where, end());
			}
		}

	void splice(const_iterator _Where, _Myt& _Right)
		{	// splice all of _Right at _Where
		if (this != &_Right && !_Right.empty())
			{	// worth splicing, do it
			_Splice(_Where, _Right, _Right.begin(), _Right.end(),
				_Right._Mysize);
			}
		}

 #if _HAS_RVALUE_REFERENCES
	void splice(const_iterator _Where, _Myt&& _Right)
		{	// splice all of _Right at _Where
		splice(_Where, (_Myt&)_Right);
		}
 #endif /* _HAS_RVALUE_REFERENCES */

	void splice(const_iterator _Where, _Myt& _Right,
		const_iterator _First)
		{	// splice _Right [_First, _First + 1) at _Where
 #if _ITERATOR_DEBUG_LEVEL == 2
		if (_First == _Right.end())
			_DEBUG_ERROR("list splice iterator outside range");
		else

 #else /* _ITERATOR_DEBUG_LEVEL == 2 */
		if (_First != _Right.end())
 #endif /* _ITERATOR_DEBUG_LEVEL == 2 */

			{	// element exists, try splice
			const_iterator _Last = _First;
			++_Last;
			if (this != &_Right
				|| (_Where != _First && _Where != _Last))
				_Splice(_Where, _Right, _First, _Last, 1);
			}
		}

 #if _HAS_RVALUE_REFERENCES
	void splice(const_iterator _Where, _Myt&& _Right,
		const_iterator _First)
		{	// splice _Right [_First, _First + 1) at _Where
		splice(_Where, (_Myt&)_Right, _First);
		}
 #endif /* _HAS_RVALUE_REFERENCES */

	void splice(const_iterator _Where,
		_Myt& _Right, const_iterator _First, const_iterator _Last)
		{	// splice _Right [_First, _Last) at _Where
		if (_First != _Last && (this != &_Right || _Where != _Last))
			{	// worth splicing, do it
			size_type _Count = 0;

			if (this == &_Right)
				;	// just rearrange this list
			else if (_First == _Right.begin() && _Last == _Right.end())
				_Count = _Right._Mysize;	// splice in whole list
			else
				{	// count nodes and check for knot
				const_iterator _Next = _First;

				for (; _Next != _Last; ++_Next, ++_Count)
					if (_Next == _Right.end())
						_Xlength_error("list<T> bad splice");
				}
			_Splice(_Where, _Right, _First, _Last, _Count);
			}
		}

 #if _HAS_RVALUE_REFERENCES
	void splice(const_iterator _Where,
		_Myt&& _Right, const_iterator _First, const_iterator _Last)
		{	// splice _Right [_First, _Last) at _Where
		splice(_Where, (_Myt&)_Right, _First, _Last);
		}
 #endif /* _HAS_RVALUE_REFERENCES */

	void remove(const _Ty& _Val_arg)
		{	// erase each element matching _Val
		const _Ty _Val = _Val_arg;	// in case it's removed along the way
		const _Nodeptr _Phead = this->_Myhead;
		_Nodeptr _Pnode = this->_Nextnode(_Phead);

		while (_Pnode != _Phead)
			if (_Pnode->_Myval == _Val)
				{	// match, remove it
				const _Nodeptr _Pprev = this->_Prevnode(_Pnode);
				const _Nodeptr _Perase = _Pnode;
				_Pnode = this->_Nextnode(_Pnode);

				this->_Nextnode(_Pprev) = _Pnode;
				this->_Prevnode(_Pnode) = _Pprev;
				this->_Freenode(_Perase);

				--this->_Mysize;
				}
			else
				_Pnode = this->_Nextnode(_Pnode);
		}

	template<class _Pr1>
		void remove_if(_Pr1 _Pred)
		{	// erase each element satisfying _Pred
		const _Nodeptr _Phead = this->_Myhead;
		_Nodeptr _Pnode = this->_Nextnode(_Phead);

		while (_Pnode != _Phead)
			if (_Pred(_Pnode->_Myval))
				{	// match, remove it
				const _Nodeptr _Pprev = this->_Prevnode(_Pnode);
				const _Nodeptr _Perase = _Pnode;
				_Pnode = this->_Nextnode(_Pnode);

				this->_Nextnode(_Pprev) = _Pnode;
				this->_Prevnode(_Pnode) = _Pprev;
				this->_Freenode(_Perase);

				--this->_Mysize;
				}
			else
				_Pnode = this->_Nextnode(_Pnode);
		}

	void unique()
		{	// erase each element matching previous
		const _Nodeptr _Phead = this->_Myhead;
		_Nodeptr _Pprev = this->_Nextnode(_Phead);
		_Nodeptr _Pnode = this->_Nextnode(_Pprev);

		while (_Pnode != _Phead)
			if (_Pprev->_Myval == _Pnode->_Myval)
				{	// match, remove it
				const _Nodeptr _Perase = _Pnode;
				_Pnode = this->_Nextnode(_Pnode);

				this->_Nextnode(_Pprev) = _Pnode;
				this->_Prevnode(_Pnode) = _Pprev;
				this->_Freenode(_Perase);

				--this->_Mysize;
				}
			else
				{	// no match, advance
				_Pprev = _Pnode;
				_Pnode = this->_Nextnode(_Pnode);
				}
		}

	template<class _Pr2>
		void unique(_Pr2 _Pred)
		{	// erase each element satisfying _Pred with previous
		const _Nodeptr _Phead = this->_Myhead;
		_Nodeptr _Pprev = this->_Nextnode(_Phead);
		_Nodeptr _Pnode = this->_Nextnode(_Pprev);

		while (_Pnode != _Phead)
			if (_Pred(_Pprev->_Myval, _Pnode->_Myval))
				{	// match, remove it
				const _Nodeptr _Perase = _Pnode;
				_Pnode = this->_Nextnode(_Pnode);

				this->_Nextnode(_Pprev) = _Pnode;
				this->_Prevnode(_Pnode) = _Pprev;
				this->_Freenode(_Perase);

				--this->_Mysize;
				}
			else
				{	// no match, advance
				_Pprev = _Pnode;
				_Pnode = this->_Nextnode(_Pnode);
				}
		}

	void merge(_Myt& _Right)
		{	// merge in elements from _Right, both ordered by operator<
		if (&_Right != this)
			{	// safe to merge, do it
			iterator _First1 = begin(), _Last1 = end();
			iterator _First2 = _Right.begin(), _Last2 = _Right.end();
			_DEBUG_ORDER(_First1, _Last1);
			_DEBUG_ORDER(_First2, _Last2);

			while (_First1 != _Last1 && _First2 != _Last2)
				if (_DEBUG_LT(*_First2, *_First1))
					{	// splice in an element from _Right
					iterator _Mid2 = _First2;
					_Splice(_First1, _Right, _First2, ++_Mid2, 1);
					_First2 = _Mid2;
					}
				else
					++_First1;

			if (_First2 != _Last2)
				_Splice(_Last1, _Right, _First2, _Last2,
					_Right._Mysize);	// splice remainder of _Right
			}
		}

 #if _HAS_RVALUE_REFERENCES
	void merge(_Myt&& _Right)
		{	// merge in elements from _Right, both ordered by operator<
		merge((_Myt&)_Right);
		}
 #endif /* _HAS_RVALUE_REFERENCES */

	template<class _Pr2>
		void merge(_Myt& _Right, _Pr2 _Pred)
		{	// merge in elements from _Right, both ordered by _Pred
		if (&_Right != this)
			{	// safe to merge, do it
			iterator _First1 = begin(), _Last1 = end();
			iterator _First2 = _Right.begin(), _Last2 = _Right.end();
			_DEBUG_ORDER_PRED(_First1, _Last1, _Pred);
			_DEBUG_ORDER_PRED(_First2, _Last2, _Pred);

			while (_First1 != _Last1 && _First2 != _Last2)
				if (_DEBUG_LT_PRED(_Pred, *_First2, *_First1))
					{	// splice in an element from _Right
					iterator _Mid2 = _First2;
					_Splice(_First1, _Right, _First2, ++_Mid2, 1);
					_First2 = _Mid2;
					}
				else
					++_First1;

			if (_First2 != _Last2)
				_Splice(_Last1, _Right, _First2, _Last2,
					_Right._Mysize);	// splice remainder of _Right
			}
		}

 #if _HAS_RVALUE_REFERENCES
	template<class _Pr2>
		void merge(_Myt&& _Right, _Pr2 _Pred)
		{	// merge in elements from _Right, both ordered by _Pred
		merge((_Myt&)_Right, _Pred);
		}
 #endif /* _HAS_RVALUE_REFERENCES */

	void sort()
		{	// order sequence, using operator<
		if (2 <= this->_Mysize)
			{	// worth sorting, do it
			const size_t _MAXBINS = 25;
			_Myt _Templist(this->_Getal()), _Binlist[_MAXBINS + 1];
			size_t _Maxbin = 0;

			while (!empty())
				{	// sort another element, using bins
				_Templist._Splice_same(_Templist.begin(), *this, begin(),
					++begin(), 1);

				size_t _Bin;
				for (_Bin = 0; _Bin < _Maxbin && !_Binlist[_Bin].empty();
					++_Bin)
					{	// merge into ever larger bins
					_Binlist[_Bin].merge(_Templist);
					_Binlist[_Bin].swap(_Templist);
					}

				if (_Bin == _MAXBINS)
					_Binlist[_Bin - 1].merge(_Templist);
				else
					{	// spill to new bin, while they last
					_Binlist[_Bin].swap(_Templist);
					if (_Bin == _Maxbin)
						++_Maxbin;
					}
				}

			for (size_t _Bin = 1; _Bin < _Maxbin; ++_Bin)
				_Binlist[_Bin].merge(_Binlist[_Bin - 1]);	// merge up
			splice(begin(), _Binlist[_Maxbin - 1]);	// result in last bin
			}
		}

	template<class _Pr2>
		void sort(_Pr2 _Pred)
		{	// order sequence, using _Pred
		if (2 <= this->_Mysize)
			{	// worth sorting, do it
			const size_t _MAXBINS = 25;
			_Myt _Templist(this->_Getal()), _Binlist[_MAXBINS + 1];
			size_t _Maxbin = 0;

			while (!empty())
				{	// sort another element, using bins
				_Templist._Splice_same(_Templist.begin(), *this, begin(),
					++begin(), 1);

				size_t _Bin;
				for (_Bin = 0; _Bin < _Maxbin && !_Binlist[_Bin].empty();
					++_Bin)
					{	// merge into ever larger bins
					_Binlist[_Bin].merge(_Templist, _Pred);
					_Binlist[_Bin].swap(_Templist);
					}

				if (_Bin == _MAXBINS)
					_Binlist[_Bin - 1].merge(_Templist, _Pred);
				else
					{	// spill to new bin, while they last
					_Binlist[_Bin].swap(_Templist);
					if (_Bin == _Maxbin)
						++_Maxbin;
					}
				}

			for (size_t _Bin = 1; _Bin < _Maxbin; ++_Bin)
				_Binlist[_Bin].merge(_Binlist[_Bin - 1],
					_Pred);	// merge up
			splice(begin(), _Binlist[_Maxbin - 1]);	// result in last bin
			}
		}

	void reverse() _NOEXCEPT
		{	// reverse sequence
		const _Nodeptr _Phead = this->_Myhead;
		_Nodeptr _Pnode = _Phead;

		for (; ; )
			{	// flip pointers in a node
			const _Nodeptr _Pnext = this->_Nextnode(_Pnode);
			this->_Nextnode(_Pnode) = this->_Prevnode(_Pnode);
			this->_Prevnode(_Pnode) = _Pnext;

			if (_Pnext == _Phead)
				break;
			_Pnode = _Pnext;
			}
		}

	void _Splice(const_iterator _Where,
		_Myt& _Right, const_iterator _First, const_iterator _Last,
		size_type _Count)
		{	// splice _Right [_First, _Last) before _Where
 #if _ITERATOR_DEBUG_LEVEL == 2
		if (_Where._Getcont() != this)
			_DEBUG_ERROR("list splice iterator outside range");
		if (this->_Getal() == _Right._Getal())
			{	// same allocator, just relink
			if (this != &_Right)
				for (const_iterator _Next = _First; _Next != _Last; )
					{	// transfer ownership
					const_iterator _Iter = _Next++;
					_Orphan_ptr(_Right, _Iter._Ptr);
					_Iter._Adopt(this);
					}
			_Splice_same(_Where, _Right, _First, _Last, _Count);
			}

 #else /* _ITERATOR_DEBUG_LEVEL == 2 */
		if (this->_Getal() == _Right._Getal())
			_Splice_same(_Where, _Right, _First, _Last, _Count);
 #endif /* _ITERATOR_DEBUG_LEVEL == 2 */

		else
			{	// different allocator, copy nodes then erase source
			for (const_iterator _Next = _First; _Next != _Last; ++_Next)
				insert(_Where, (_Ty _REFREF)*_Next);
			_Right.erase(_First, _Last);
			}
		}

	void _Splice_same(const_iterator _Where,
		_Myt& _Right, const_iterator _First, const_iterator _Last,
		size_type _Count)
		{	// splice _Right [_First, _Last) before _Where
		if (this != &_Right)
			{	// splicing from another list, adjust counts
			_Incsize(_Count);
			_Right._Mysize -= _Count;
			}
		this->_Nextnode(this->_Prevnode(_First._Mynode())) =
			_Last._Mynode();
		this->_Nextnode(this->_Prevnode(_Last._Mynode())) =
			_Where._Mynode();
		this->_Nextnode(this->_Prevnode(_Where._Mynode())) =
			_First._Mynode();

		_Nodeptr _Pnode = this->_Prevnode(_Where._Mynode());
		this->_Prevnode(_Where._Mynode()) =
			this->_Prevnode(_Last._Mynode());
		this->_Prevnode(_Last._Mynode()) =
			this->_Prevnode(_First._Mynode());
		this->_Prevnode(_First._Mynode()) = _Pnode;
		}

	void _Unchecked_splice(_Unchecked_const_iterator _Where,
		_Unchecked_const_iterator _First,
		_Unchecked_const_iterator _Last)
		{	// splice [_First, _Last) before _Where
		this->_Nextnode(this->_Prevnode(_First._Mynode())) =
			_Last._Mynode();
		this->_Nextnode(this->_Prevnode(_Last._Mynode())) =
			_Where._Mynode();
		this->_Nextnode(this->_Prevnode(_Where._Mynode())) =
			_First._Mynode();

		_Nodeptr _Pnode = this->_Prevnode(_Where._Mynode());
		this->_Prevnode(_Where._Mynode()) =
			this->_Prevnode(_Last._Mynode());
		this->_Prevnode(_Last._Mynode()) =
			this->_Prevnode(_First._Mynode());
		this->_Prevnode(_First._Mynode()) = _Pnode;
		}

	void _Assign_n(size_type _Count, const _Ty& _Val)
		{	// assign _Count * _Val
		_Ty _Tmp = _Val;	// in case _Val is in sequence
		clear();
		_Insert_n(_Unchecked_begin(), _Count, _Tmp);
		}

	void _Tidy()
		{	// free all storage
		clear();
		}

	void _Insert_n(_Unchecked_const_iterator _Where,
		size_type _Count, const _Ty& _Val)
		{	// insert _Count * _Val at _Where
		size_type _Countsave = _Count;

		_TRY_BEGIN
		for (; 0 < _Count; --_Count)
			_Insert(_Where, _Val);
		_CATCH_ALL
		for (; _Count < _Countsave; ++_Count)
			{	// undo inserts
			_Unchecked_const_iterator _Before = _Where;
			_Unchecked_erase(--_Before);
			}
		_RERAISE;
		_CATCH_END
		}

	void _Incsize(size_type _Count)
		{	// alter element count, with checking
		if (max_size() - this->_Mysize - 1 < _Count)
			_Xlength_error("list<T> too long");
		this->_Mysize += _Count;
		}

 #if _ITERATOR_DEBUG_LEVEL == 2
	void _Orphan_ptr(_Myt& _Cont, _Nodeptr _Ptr) const
		{	// orphan iterators with specified node pointers
		_Lockit _Lock(_LOCK_DEBUG);
		const_iterator **_Pnext = (const_iterator **)_Cont._Getpfirst();
		if (_Pnext != 0)
			while (*_Pnext != 0)
				if ((*_Pnext)->_Ptr == this->_Myhead
					|| _Ptr != 0 && (*_Pnext)->_Ptr != _Ptr)
					_Pnext = (const_iterator **)(*_Pnext)->_Getpnext();
				else
					{	// orphan the iterator
					(*_Pnext)->_Clrcont();
					*_Pnext = *(const_iterator **)(*_Pnext)->_Getpnext();
					}
		}
 #endif /* _ITERATOR_DEBUG_LEVEL == 2 */
	};

// list TEMPLATE OPERATORS
template<class _Ty,
	class _Alloc> inline
	void swap(list<_Ty, _Alloc>& _Left, list<_Ty, _Alloc>& _Right)
	{	// swap _Left and _Right lists
	_Left.swap(_Right);
	}

template<class _Ty,
	class _Alloc> inline
	bool operator==(const list<_Ty, _Alloc>& _Left,
		const list<_Ty, _Alloc>& _Right)
	{	// test for list equality
	return (_Left.size() == _Right.size()
		&& equal(_Left.begin(), _Left.end(), _Right.begin()));
	}

template<class _Ty,
	class _Alloc> inline
	bool operator!=(const list<_Ty, _Alloc>& _Left,
		const list<_Ty, _Alloc>& _Right)
	{	// test for list inequality
	return (!(_Left == _Right));
	}

template<class _Ty,
	class _Alloc> inline
	bool operator<(const list<_Ty, _Alloc>& _Left,
		const list<_Ty, _Alloc>& _Right)
	{	// test if _Left < _Right for lists
	return (lexicographical_compare(_Left.begin(), _Left.end(),
		_Right.begin(), _Right.end()));
	}

template<class _Ty,
	class _Alloc> inline
	bool operator>(const list<_Ty, _Alloc>& _Left,
		const list<_Ty, _Alloc>& _Right)
	{	// test if _Left > _Right for lists
	return (_Right < _Left);
	}

template<class _Ty,
	class _Alloc> inline
	bool operator<=(const list<_Ty, _Alloc>& _Left,
		const list<_Ty, _Alloc>& _Right)
	{	// test if _Left <= _Right for lists
	return (!(_Right < _Left));
	}

template<class _Ty,
	class _Alloc> inline
	bool operator>=(const list<_Ty, _Alloc>& _Left,
		const list<_Ty, _Alloc>& _Right)
	{	// test if _Left >= _Right for lists
	return (!(_Left < _Right));
	}

 #if _HAS_TRADITIONAL_STL
 #define __list__	list
 #endif /* _HAS_TRADITIONAL_STL */
_STD_END
#endif /* _LIST_ */

namespace paf {
	template<class _Ty,
		class _Alloc = paf::allocator<_Ty>>
		class list : public std::list<_Ty, _Alloc>
	{

	};
}

#endif