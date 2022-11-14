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
  template <class T, class Alloc = std::allocator<T> >
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
    explicit vector(size_type n, const value_type &val = value_type())
        : _start(ft_nullptr),
          _finish(ft_nullptr),
          _end_of_storage(ft_nullptr)
    {
      if (n > this->max_size())
        throw(std::length_error("cannot create std::vector larger than max_size()"));
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
    vector(iterator first, iterator last,
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
    //  * Constructs a container with a copy of each of the elements in other,
    //  * in the same order.
    //  */

    vector(const vector &other)
    {
      this->_allocator = other._allocator;
      this->_start = other._start;
      this->_finish = other._finish;
      this->_end_of_storage = other._end_of_storage;
    }
    // /**
    //  * Destructor
    //  */
    ~vector() {}

    vector &operator=(const vector &other)
    {
      if (other == *this)
        return (*this);
      this->clear();
      this->insert(this->end(), other.begin(), other.end());
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
     *  Returns the total number of elements that the vector can
     *  hold before needing to allocate more memory.
     */
    size_type capacity() const
    {
      return size_type(_end_of_storage - _start);
    }

    bool empty() const
    {
      return ((this->size() == 0) ? true : false);
    }
    void reserve(size_type n)
    {
      if (n > this->max_size())
        throw(std::length_error("vector::reserve"));
      if (n > this->capacity())
      {
        pointer prev_start = _start;
        pointer prev_finish = _finish;
        size_type prev_size = this->size();
        size_type prev_capacity = this->capacity();
        _start = _allocator.allocate(n);
        _end_of_storage = _start + n;
        _finish = _start;
        while (prev_start != prev_finish)
        {
          _allocator.construct(_finish, *prev_start);
          _finish++;
          prev_start++;
        }
        for (size_t i = 0; i < prev_size; i++)
        {
          _allocator.destroy(prev_start - prev_size + i);
        }
        _allocator.deallocate(prev_start - prev_size, prev_capacity);
      }
    }
    // element access:
    reference operator[](size_type n)
    {
      return (*(_start + n));
    }
    const_reference operator[](size_type n) const
    {
      return (*(_start + n));
    }
    const_reference at(size_type n) const
    {
      return (*(_start + n));
    }
    reference at(size_type n)
    {
      return (*(_start + n));
    }
    reference front()
    {
      return (*(_start));
    }
    const_reference front() const
    {
      return (*(_start));
    }
    reference back()
    {
      return (*(_finish - 1));
    }
    const_reference back() const
    {
      return (*(_finish - 1));
    }
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
      _finish++;
    }

    void pop_back()
    {
      _allocator.destroy(_finish--);
    }
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
      this->insert(position, 1, val);
      return (++position);
    }

    void insert(iterator position, size_type insert_size, const T &val)
    {
      const size_type n = &(*position) - _start;
      pointer new_start;
      pointer new_finish;
      pointer new_end_of_storage;
      int new_capacity = this->size() + insert_size;
      new_start = _allocator.allocate(new_capacity);
      new_end_of_storage = new_start + new_capacity;
      new_finish = new_start + this->size() + insert_size;
      for (size_type i = 0; i < n; i++)
      {
        _allocator.construct(new_start + i, *(_start + i));
      }
      for (size_type j = 0; j < insert_size; j++)
      {
        _allocator.construct(new_start + n + j, val);
      }
      for (size_type k = 0; k < (this->size() - n); k++)
      {
        _allocator.construct(new_start + n + insert_size + k, *(_start + n + k));
      }
      for (size_type i = 0; i < this->size(); i++)
      {
        _allocator.destroy(_start + i);
      }
      if (_start)
        _allocator.deallocate(_start, this->capacity());
      _start = new_start;
      _finish = new_finish;
      _end_of_storage = new_end_of_storage;
    }

    void insert(iterator position, iterator another_first, iterator another_last)
    {
      const size_type n = &(*position) - _start;
      size_type insert_size = another_last - another_first;
      pointer new_start;
      pointer new_finish = _finish;
      pointer new_end_of_storage;
      int new_capacity = this->size() + insert_size;
      new_start = _allocator.allocate(new_capacity);
      new_end_of_storage = new_start + new_capacity;
      new_finish = new_start + this->size() + insert_size;
      for (size_type i = 0; i < n; i++)
      {
        _allocator.construct(new_start + i, *(_start + i));
      }
      for (size_type j = 0; j < insert_size; j++)
      {
        _allocator.construct(new_start + n + j, *(another_first + j));
      }
      for (size_type k = 0; k < (this->size() - n); k++)
      {
        _allocator.construct(new_start + n + insert_size + k, *(_start + n + k));
      }
      // destroy and deallocate old vector's memory
      for (size_type i = 0; i < this->size(); i++)
      {
        _allocator.destroy(_start + i);
      }
      if (_start)
        _allocator.deallocate(_start, this->size());
      _start = new_start;
      _finish = new_finish;
      _end_of_storage = new_end_of_storage;
    }

    iterator erase(iterator position)
    {
      pointer new_start = _start;
      size_type n = &(*position) - _start;
      for (size_type i = 0; i < this->size() - n; i++)
      {
        _allocator.construct((&(*position) + i), *(&(*position) + i + 1));
        _allocator.destroy((&(*position) + i));
      }
      _allocator.destroy(_finish--);
      _start = new_start;
      return (position);
    }
    iterator erase(iterator first, iterator last)
    {
      pointer new_start = _start;
      size_type n = &(*last) - &(*first);
      for (size_type i = 0; i < this->size() - n; i++)
      {
        _allocator.construct((&(*first) + i), *(&(*first) + i + n));
        _allocator.destroy((&(*first) + i));
      }
      for (size_type i = 0; i < n; i++)
      {
        _allocator.destroy(_finish);
        _finish--;
      }
      _start = new_start;
      return (iterator(_start + n));
    }
    void swap(vector &other)
    {
      if (*this != other)
      {
        pointer tmp_start = this->_start;
        pointer tmp_finish = this->_finish;
        pointer tmp_end_of_storage = this->_end_of_storage;
        Alloc tmp_allocator = this->_allocator;

        this->_start = other._start;
        this->_finish = other._finish;
        this->_end_of_storage = other._end_of_storage;
        this->_allocator = other._allocator;

        other._start = tmp_start;
        other._finish = tmp_finish;
        other._end_of_storage = tmp_end_of_storage;
        other._allocator = tmp_allocator;
      }
    }
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
  template <typename T>
  bool operator==(vector<T> const &lhs, vector<T> const &rhs)
  {
    if (lhs.size() != rhs.size())
      return (false);
    for (size_t i = 0; i < lhs.size(); i++)
      if (lhs[i] != rhs[i])
        return (false);
    return (true);
  }
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