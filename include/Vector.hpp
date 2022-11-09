/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <bbaatar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:01:23 by bbaatar           #+#    #+#             */
/*   Updated: 2022/10/11 11:01:24 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "./utils/randomAccessIterator.hpp"
#include "./utils/reverseIterator.hpp"
#include <vector>

namespace ft
{
  /**
   * generic template
   */
  template <class T, class Alloc = std::allocator<T>>
  class vector
  {
  public:
    // types:
    /**
     * 	The first template parameter (T)
     */
    typedef T value_type;
    /**
     * The second template parameter (Alloc)
     */
    typedef Alloc allocator_type;

    /**
     * Reference for the default allocator: value_type&
     */
    typedef typename allocator_type::reference reference;

    /**
     * Refernce for the default allocator: const value_type&
     */
    typedef typename allocator_type::const_reference const_reference;

    /**
     * Pointer for the default allocator: value_type*
     */
    typedef typename allocator_type::pointer pointer;

    /**
     * Const pointer for the default allocator: const value_type*
     */
    typedef typename allocator_type::const_pointer const_pointer;

    /**
     * A random access iterator to value_type
     */
    typedef ft::RandomAccessIterator<value_type> iterator;
    // typedef ft::RandomAccessIterator<T *> iterator; ask Marwa which one to use

    /**
     * A random access iterator to const value_type
     */
    typedef typename ft::RandomAccessIterator<const value_type> const_iterator;

    /**
     * reverse_iterator<iterator>
     */
    typedef ft::reverse_iterator<iterator> reverse_iterator;

    /**
     * Const reverse_iterator<iterator>
     */
    typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

    /**
     * A signed integral type,
     * identical to: iterator_traits<iterator>::difference_type
     * Usually the same as ptrdiff_t
     */
    typedef typename ft::iterator_traits<iterator>::difference_type difference_type;

    /**
     * An unsigned integral type that can represent
     * any non-negative value of difference_type
     * Usually the same as size_t
     */
    typedef typename allocator_type::size_type size_type;

    /**
     * Private members
     */
  private:
    Alloc _allocator;
    pointer _start;
    pointer _finish;
    pointer _end_of_storage;
    /**
     * capacity = _end_of_storage - _start
     * size = _finish - _start
     */

  public:
    /**
     * 1. Default constructor
     * Empty container constructor (default constructor)
       Constructs an empty container, with no elements.
     */
    explicit vector(const allocator_type &alloc = allocator_type())
        : _allocator(alloc),
          _start(ft_nullptr),
          _finish(ft_nullptr),
          _end_of_storage(ft_nullptr)
    {
    }

    /**
     * 2. Fill constructor
     * Constructs a container with n elements.
     * Each element is a copy of val.
     */
    explicit vector(size_type n, const value_type &val = value_type(),
                    const allocator_type &alloc = allocator_type())
        : _allocator(alloc),
          _start(ft_nullptr),
          _finish(ft_nullptr),
          _end_of_storage(ft_nullptr)
    {
      if (n > this->max_size())
        throw(std::length_error("cannot create std::vector larger than max_size()"));
      // returns a pointer to the initial element in the block of storage
      _start = _allocator.allocate(n);
      _finish = _start;
      _end_of_storage = _start + n;
      while (n--)
      {
        _allocator.construct(_finish, val);
        _finish++;
      }
    }

    // /**
    //  * 3. Range constructor
    //  * Constructs a container with as many elements as the range [first,last),
    //  * with each element constructed from its corresponding element in that range,
    //  * in the same order.
    //  */
    template <class InputIterator>
    vector(InputIterator first, InputIterator last,
           const allocator_type &alloc = allocator_type())
        : _allocator(alloc)
    {
      difference_type n = last - first;
      _start = _allocator.allocate(n);
      _finish = _start;
      _end_of_storage = _start + n;
      while (n--)
      {
        _allocator.construct(_finish, *(_finish));
        _finish++;
      }
    }

    // /**
    //  * 4. Copy constructor
    //  * Constructs a container with a copy of each of the elements in x,
    //  * in the same order.
    //  */

    // vector(const vector &x)
    // {
    // }

    // /**
    //  * Destructor
    //  */
    // ~vector();

    vector &operator=(const vector &x)
    {
      if (x == *this)
        return (*this);
      this->clear();
      this->insert(this->end(), x.begin(), x.end());
      return (*this);
    }
    // template <class InputIterator>
    // void assign(InputIterator first, InputIterator last);
    /**
     *  @brief  Assigns a given value to a %vector.
     *  @param  __n  Number of elements to be assigned.
     *  @param  __val  Value to be assigned.
     *
     *  This function fills a %vector with @a __n copies of the given
     *  value.  Note that the assignment completely changes the
     *  %vector and that the resulting %vector's size is the same as
     *  the number of elements assigned.
     */
    void assign(size_type n, const T &val)
    {
      this->clear();
      if (n > this->capacity())
      {
        _start = _allocator.allocate(n);
      }
      else
      {
        _start = _allocator.allocate(this->capacity());
      }
      _finish = _start;
      while (n--)
      {
        _allocator.construct(_finish, val);
        _finish++;
      }
      _end_of_storage = _start + n;
    }
    // allocator_type get_allocator() const;

    // iterators:
    iterator begin()
    {
      return (iterator(this->_start));
    }
    const_iterator begin() const
    {
      return (const_iterator(this->_start));
    }
    iterator end()
    {
      return (iterator(this->_finish));
    }
    const_iterator end() const
    {
      return (const_iterator(this->_finish));
    }
    reverse_iterator rbegin()
    {
      return (reverse_iterator(end()));
    }
    const_reverse_iterator rbegin() const
    {
      return (const_reverse_iterator(end()));
    }
    reverse_iterator rend()
    {
      return (reverse_iterator(begin()));
    }
    const_reverse_iterator rend() const
    {
      return (const_reverse_iterator(begin()));
    }

    // 23.2.4.2 capacity:
    size_type size() const
    {
      return size_type(this->_finish - this->_start);
    }
    size_type max_size() const
    {
      return (Alloc().max_size());
    }
    // void resize(size_type sz, T c = T())
    // {

    // }
    /**
     *  Returns the total number of elements that the %vector can
     *  hold before needing to allocate more memory.
     */
    size_type capacity() const
    {
      return size_type(_end_of_storage - _start);
    }
    // bool empty() const;
    void reserve(size_type n)
    {
      if (n > this->max_size())
        throw(std::length_error("vector::reserve"));
      if (n > this->capacity())
      {
        pointer new_start;
        new_start = _allocator.allocate(n);
        for (size_t i = 0; i < this->size(); i++)
        {
          _allocator.construct((new_start + i), *(_start + i));
        }
        for (size_t i = 0; i < this->size(); i++)
        {
          _allocator.destroy(_start + i);
        }
        _allocator.deallocate(_start, this->capacity());
        _start = new_start;
        _finish = new_start + this->size();
        _end_of_storage = _start + n;
      }
    }

    // element access:
    // reference operator[](size_type n);
    // const_reference operator[](size_type n) const;
    // const_reference at(size_type n) const;
    // reference at(size_type n);
    // reference front();
    // const_reference front() const;
    // reference back();
    // const_reference back() const;
    // 23.2.4.3 modifiers:

    /*
    ** @brief Add new element at the end of the vector.
    ** The content of "val" is copied (moved) to the new element.
    **
    ** @param val The value to be copied.
    */
    void push_back(const value_type &val)
    {
      if (_finish == _end_of_storage)
      {
        int new_capacity;
        if (this->size() > 0)
          new_capacity = (int)this->size() * 2;
        else
          new_capacity = 1;
        this->reserve(new_capacity);
      }
      _allocator.construct(_finish, val);
      _finish++; // which one is correct? ++_finish or _finish++??
    }

    // void pop_back();
    /**
     *  @brief  Inserts given rvalue into %vector before specified iterator.
     *  @param  position  A const_iterator into the %vector.
     *  @param  val  Data to be inserted.
     *  @return  An iterator that points to the inserted data.
     *
     *  This function will insert a copy of the given rvalue before
     *  the specified location.  Note that this kind of operation
     *  could be expensive for a %vector and if it is frequently
     *  used the user should consider using std::list.
     */
    iterator insert(iterator position, const T &val)
    {
      const size_type n = &(*position) - _start;
      // if (_finish != _end_of_storage)
      if (size_type(_end_of_storage - _finish) >= this->size() + 1)
      {
        // inserting 1 element at the start/head of the vector
        for (size_type i = 0; i < n; i++)
        {
          _allocator.construct(_finish - i, *(_finish - i - 1));
        }
        ++_finish;
        _allocator.construct(position, val);
      }
      else
      {
        iterator new_start;
        iterator new_finish = _finish;
        iterator new_end_of_storage = _end_of_storage;
        int new_capacity;
        if (this->size() > 0)
          new_capacity = (int)this->size() * 2;
        else
          new_capacity = 1;
        new_start = _allocator.allocate(new_capacity);
        for (size_type i = 0; i < n; i++)
        {
          _allocator.construct(new_start + i, *(_start + i));
        }
        _allocator.construct(position, val);
        for (size_type i = 1; i < n; i++)
        {
          _allocator.construct(new_start + n + i, *(_start + n + i - 1));
        }
        for (size_type i = 0; i < this->size(); i++)
        {
          _allocator.destroy(_start + i);
        }
        _allocator.deallocate(_start, this->size());
        _start = new_start;
        _finish = _start + this->size() + 1;
        _end_of_storage = 
      }
      return iterator(_start + n);
    }
    // void insert(iterator position, size_type n, const T &x);
    // template <class InputIterator>
    // template <class InputIterator>
    // void insert(iterator position,
    //             InputIterator first, InputIterator last)
    //             {

    //             }

    //  iterator erase(iterator position);
    //  iterator erase(iterator first, iterator last);
    //  void swap(vector<T, Alloc> &);
    /**
     *  Erases all the elements.  Note that this function only erases the
     *  elements, and that if the elements themselves are pointers, the
     *  pointed-to memory is not touched in any way.  Managing the pointer is
     *  the user's responsibility.
     */
    // { _M_erase_at_end(this->_M_impl._M_start); }
    // clear (_start) _start pointer-s ehelj destroy hiine.
    void clear()
    {
      // _allocator.destroy(_start, _finish);
      // _finish = _start;
      while (_finish != _start)
      {
        _finish--;
        _allocator.destroy(_finish);
      }
    }
  };
  // template <class T, class Alloc>
  // bool operator==(const vector<T, Alloc> &x,
  //                 const vector<T, Alloc> &y);
  // template <class T, class Alloc>
  // bool operator<(const vector<T, Alloc> &x,
  //                const vector<T, Alloc> &y);
  // template <class T, class Alloc>
  // bool operator!=(const vector<T, Alloc> &x,
  //                 const vector<T, Alloc> &y);
  template <typename T>
  bool operator!=(vector<T> const &lhs, vector<T> const &rhs)
  {
    return (!(lhs == rhs));
  }
  // template <class T, class Alloc>
  // bool operator>(const vector<T, Alloc> &x,
  //                const vector<T, Alloc> &y);
  // template <class T, class Alloc>
  // bool operator>=(const vector<T, Alloc> &x,
  //                 const vector<T, Alloc> &y);
  // template <class T, class Alloc>
  // bool operator<=(const vector<T, Alloc> &x,
  //                 const vector<T, Alloc> &y);
  // specialized algorithms:
  // template <class T, class Alloc>
  // void swap(vector<T, Alloc> &x, vector<T, Alloc> &y);
}

#endif