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
#include "utils/randomAccessIterator.hpp"
#include "utils/reverseIterator.hpp"

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
    typedef ft::RandomAccessIterator<const value_type> const_iterator;

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
    /**
     * 3. Range constructor
     * Constructs a container with as many elements as the range [first,last),
     * with each element constructed from its corresponding element in that range,
     * in the same order.
     */
    template <class InputIterator>
    vector(InputIterator first, InputIterator last,
           typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 0)
    {
      size_type n = 0;
      for (InputIterator it = first; it != last; it++)
        n++;

      _start = _allocator.allocate(n);
      _finish = _start;
      _end_of_storage = _start + n;
      while (n--)
      {
        _allocator.construct(_finish, *(first));
        _finish++;
        first++;
      }
    }
    /**
     * 4. Copy constructor
     * Constructs a container with a copy of each of the elements in other,
     * in the same order.
     */
    vector(const vector &other)
        : _allocator(other._allocator),
          _start(ft_nullptr),
          _finish(ft_nullptr),
          _end_of_storage(ft_nullptr)
    {
      this->insert(this->begin(), other.begin(), other.end());
    }
    /**
     * Destructor
     */
    ~vector()
    {
      this->clear();
      if (this->capacity())
        _allocator.deallocate(_start, this->capacity());
    }
    vector &operator=(const vector &other)
    {
      if (other == *this)
        return (*this);
      this->clear();
      this->insert(this->end(), other.begin(), other.end());
      return (*this);
    }
    void assign(size_type n, const T &val)
    {
      this->clear();
      if (n > this->capacity())
      {
        if (_start)
          _allocator.deallocate(_start, this->capacity());
        _start = _allocator.allocate(n);
        _end_of_storage = _start + n;
      }
      _finish = _start;
      while (n--)
      {
        _allocator.construct(_finish, val);
        _finish++;
      }
    }
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last,
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 0)
    {
      this->clear();
      size_type n = 0;
      for (InputIterator it = first; it != last; it++)
        n++;

      if (n > this->capacity())
      {
        if (_start)
          _allocator.deallocate(_start, this->capacity());
        _start = _allocator.allocate(n);
        _end_of_storage = _start + n;
      }
      _finish = _start;
      while (first != last)
      {
        _allocator.construct(_finish, *first);
        _finish++;
        first++;
      }
      _end_of_storage = _start + n;
    }
    allocator_type get_allocator() const                { return (this->_allocator);}
    // iterators:
    iterator begin()                                    {return (iterator(this->_start));}
    const_iterator begin() const                        { return (const_iterator(this->_start));}
    iterator end()                                      { return (iterator(this->_finish));}
    const_iterator end() const                          { return (const_iterator(this->_finish));}
    reverse_iterator rbegin()                           { return (reverse_iterator(end()));}
    const_reverse_iterator rbegin() const               { return (const_reverse_iterator(end())); }
    reverse_iterator rend()                             { return (reverse_iterator(begin()));}
    const_reverse_iterator rend() const                 { return (const_reverse_iterator(begin()));}
    // capacity:
    size_type size() const                              { return size_type(this->_finish - this->_start);}
    size_type max_size() const                          { return (Alloc().max_size());}
    /**
     *  Returns the total number of elements that the vector can
     *  hold before needing to allocate more memory.
     */
    void resize(size_type n, value_type val = value_type())
    {
      if (n > this->max_size())
        throw(std::length_error("vector::resize"));
      else if (n < this->size())
      {
        while (this->size() > n)
        {
          --_finish;
          _allocator.destroy(_finish);
        }
      }
      else
        this->insert(this->end(), n - this->size(), val);
    }

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
    reference operator[](size_type n)                     { return (*(_start + n));}
    const_reference operator[](size_type n) const         { return (*(_start + n));}
    const_reference at(size_type n) const
    {
      if (size() <= n || n < 0)
        throw std::out_of_range("out of range");
      return (*(_start + n));
    }
    reference at(size_type n)
    {
      if (size() <= n || n < 0)
        throw std::out_of_range("out of range");
      return (*(_start + n));
    }
    reference front()                                     { return (*(_start));}
    const_reference front() const                         { return (*(_start));}
    reference back()                                      { return (*(_finish - 1));}
    const_reference back() const                          { return (*(_finish - 1));}
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
    void pop_back()                                       { _allocator.destroy(--_finish);}
    iterator _insert(iterator position, size_type insert_size, const T &val)
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

      return iterator(_start + n);
    }
    iterator insert(iterator position, const T &val)                    { return this->_insert(position, 1, val);}

    void insert(iterator position, size_type insert_size, const T &val) { _insert(position, insert_size, val);}
    template <class InputIterator>
    void insert(iterator position, InputIterator another_first, InputIterator another_last,
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type = 0)
    {
      const size_type n = &(*position) - _start;
      size_type insert_size = 0;
      for (InputIterator it = another_first; it != another_last; it++)
        insert_size++;
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
        _allocator.construct(new_start + n + j, *another_first);
        another_first++;
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

    iterator erase(iterator position)                                 { return erase(position, ++position);}

    iterator erase(iterator first, iterator last)
    {
      iterator result = first;
      if (_finish <= &(*first))
        return end();
      if (_finish <= &(*last))
        last = end();
      size_type n = &(*last) - &(*first);
      // destroys
      for (size_type i = 0; i < n; i++)
        _allocator.destroy(&(*first) + i);
      // shifts
      while (&(*last) != _finish)
      {
        _allocator.construct(&(*first), *(&(*last)));
        _allocator.destroy(&(*last));
        first++;
        last++;
      }
      _finish -= n;
      return (result);
    }
    void swap(vector &other)
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
    /**
     *  Erases all the elements.  Note that this function only erases the
     *  elements, and that if the elements themselves are pointers, the
     *  pointed-to memory is not touched in any way.  Managing the pointer is
     *  the user's responsibility.
     */
    void clear()
    {
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

  template <typename T> bool operator!=(vector<T> const &lhs, vector<T> const &rhs)                   { return (!(lhs == rhs));}
  template <typename T> bool operator<(const vector<T> &lhs, const vector<T> &rhs)                    { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}
  template <typename T> bool operator<=(const vector<T> &lhs, const vector<T> &rhs)                   { return (!(rhs < lhs));}
  template <typename T> bool operator>(const vector<T> &lhs, const vector<T> &rhs)                    { return (rhs < lhs);}
  template <typename T> bool operator>=(const vector<T> &lhs, const vector<T> &rhs)                   { return (!(lhs < rhs));}
  template <typename T> void swap(vector<T> &x, vector<T> &y)                                         { x.swap(y);}
}

#endif