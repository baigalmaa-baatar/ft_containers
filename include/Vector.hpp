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

namespace ft
{
    template <class T, class Allocator = std::allocator<T>> // ask Marwa
    class vector
    {
    public:
        // types:
        typedef T value_type;
        typedef typename Allocator::reference reference;
        typedef typename Allocator::const_reference const_reference;
        // typedef ft::RandomAccessIterator<value_type> iterator; ask Marwa
        typedef ft::RandomAccessIterator<T *> iterator;
        // typedef typename ft::RandomAccessIterator<const T*> const_iterator; ask Marwa
        typedef typename ft::RandomAccessIterator<const value_type> const_iterator;
        typedef typename std::size_type size_type;
        typedef typename std::difference_type difference_type;
        typedef Allocator allocator_type;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_pointer const_pointer typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        /**
         * Default Constructors
         */
        explicit vector(const Allocator & = Allocator())
        {
        }

        /**
         * Default Constructors
         */
        explicit vector(size_type n, const T &value = T(),
                        const Allocator & = Allocator())
        {
        }

        template <class InputIterator>
        vector(InputIterator first, InputIterator last,
               const Allocator & = Allocator())
        {
        }

        vector(const vector<T, Allocator> &x)
        {
        }

        /**
         * Destructor
         */
        ~vector();

        vector<T, Allocator> &operator=(const vector<T, Allocator> &x);
        template <class InputIterator>
        void assign(InputIterator first, InputIterator last);
        void assign(size_type n, const T &u);
        allocator_type get_allocator() const;

        // iterators:
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;

        // 23.2.4.2 capacity:
        size_type size() const;
        size_type max_size() const;
        void resize(size_type sz, T c = T());
        size_type capacity() const;
        bool empty() const;
        void reserve(size_type n);
        // element access:
        reference operator[](size_type n);
        const_reference operator[](size_type n) const;
        const_reference at(size_type n) const;
        reference at(size_type n);
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;
        // 23.2.4.3 modifiers:
        void push_back(const T &x);
        void pop_back();
        iterator insert(iterator position, const T &x);
        void insert(iterator position, size_type n, const T &x);
        template <class InputIterator>
        void insert(iterator position,
                    InputIterator first, InputIterator last);
        iterator erase(iterator position);
        iterator erase(iterator first, iterator last);
        void swap(vector<T, Allocator> &);
        void clear();
    };
    template <class T, class Allocator>
    bool operator==(const vector<T, Allocator> &x,
                    const vector<T, Allocator> &y);
    template <class T, class Allocator>
    bool operator<(const vector<T, Allocator> &x,
                   const vector<T, Allocator> &y);
    template <class T, class Allocator>
    bool operator!=(const vector<T, Allocator> &x,
                    const vector<T, Allocator> &y);
    template <class T, class Allocator>
    bool operator>(const vector<T, Allocator> &x,
                   const vector<T, Allocator> &y);
    template <class T, class Allocator>
    bool operator>=(const vector<T, Allocator> &x,
                    const vector<T, Allocator> &y);
    template <class T, class Allocator>
    bool operator<=(const vector<T, Allocator> &x,
                    const vector<T, Allocator> &y);
    // specialized algorithms:
    template <class T, class Allocator>
    void swap(vector<T, Allocator> &x, vector<T, Allocator> &y);
}

#endif