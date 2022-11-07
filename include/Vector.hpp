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
    pointer _first;
    pointer _last;
    size_type _size;
    size_type _capacity;

  public:
    /**
     * 1. Default constructor
     * Empty container constructor (default constructor)
       Constructs an empty container, with no elements.
     */
    explicit vector() : _first(ft_nullptr), _last(ft_nullptr), _size(0), _capacity(0)
    {
    }

    /**
     * 2. Fill constructor
     * Constructs a container with n elements.
     * Each element is a copy of val.
     */
    explicit vector(size_type n, const value_type &val = value_type(),
                    const allocator_type &alloc = allocator_type()) : size_type(n), value_type(val), allocator_type(alloc)
    {
      if (n > _capacity)
        std::cout << "size is too small, need to increase the capacity" << '\n';
      push_back(val);
    }

    // /**
    //  * 3. Range constructor
    //  * Constructs a container with as many elements as the range [first,last),
    //  * with each element constructed from its corresponding element in that range,
    //  * in the same order.
    //  */
    // template <class InputIterator>
    // vector(InputIterator first, InputIterator last,
    //        const allocator_type &alloc = allocator_type())
    // {
    // }

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

    // vector<T, Alloc> &operator=(const vector<T, Alloc> &x);
    // template <class InputIterator>
    // void assign(InputIterator first, InputIterator last);
    // void assign(size_type n, const T &u);
    // allocator_type get_allocator() const;

    // // iterators:
    // iterator begin();
    // const_iterator begin() const;
    // iterator end();
    // const_iterator end() const;
    // reverse_iterator rbegin();
    // const_reverse_iterator rbegin() const;
    // reverse_iterator rend();
    // const_reverse_iterator rend() const;

    // // 23.2.4.2 capacity:
    // size_type size() const;
    size_type max_size() const
    {
      return (Alloc().max_size());
    }
    // void resize(size_type sz, T c = T());
    // size_type capacity() const;
    // bool empty() const;
    void reserve(size_type n)
    {
      if (n > this->max_size())
        throw(std::length_error("vector::reserve"));
      if (n > _capacity)
      {
        pointer new_first;
        new_first = _allocator.allocate(n);
        for (size_t i = 0; i < _size; i++)
        {
          _allocator.construct((new_first + i), *(_first + i));
        }
        for (size_t i = 0; i < _size; i++)
        {
          _allocator.destroy(_first + i);
        }
        if (_capacity)
          _allocator.deallocate(_first, _capacity);
        _first = new_first;
        _last = new_first + _size;
        _capacity = n;
      }
    }

    // // element access:
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
      if (_size == _capacity)
      {
        int new_capacity;
        if (_size > 0)
          new_capacity = (int)_size * 2;
        else
          new_capacity = 1;
        this->reserve(new_capacity);
      }
      _allocator.construct(_last, val);
      _last++;
    }

    // void pop_back();
    // iterator insert(iterator position, const T &x);
    // void insert(iterator position, size_type n, const T &x);
    // template <class InputIterator>
    // void insert(iterator position,
    //             InputIterator first, InputIterator last);
    // iterator erase(iterator position);
    // iterator erase(iterator first, iterator last);
    // void swap(vector<T, Alloc> &);
    // void clear();
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
  // template <class T, class Alloc>
  // bool operator>(const vector<T, Alloc> &x,
  //                const vector<T, Alloc> &y);
  // template <class T, class Alloc>
  // bool operator>=(const vector<T, Alloc> &x,
  //                 const vector<T, Alloc> &y);
  // template <class T, class Alloc>
  // bool operator<=(const vector<T, Alloc> &x,
  //                 const vector<T, Alloc> &y);
  // // specialized algorithms:
  // template <class T, class Alloc>
  // void swap(vector<T, Alloc> &x, vector<T, Alloc> &y);
}

#endif