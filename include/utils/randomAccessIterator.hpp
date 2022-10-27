#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP
#include <iostream>
#include "utils.hpp"

namespace ft
{
    template <typename T>
    class RandomAccessIterator
    {
    public:
        typedef typename ft::iterator_traits<T *>::value_type value_type;
        typedef typename ft::iterator_traits<T *>::pointer pointer;
        typedef typename ft::iterator_traits<T *>::reference reference;
        typedef typename ft::iterator_traits<T *>::difference_type difference_type;
        typedef pointer iterator_type;
        // this is for std::functions ask Marwa
        typedef std::random_access_iterator_tag iterator_category;

    protected:
        pointer _ptr;

    public:
        RandomAccessIterator(void) : _ptr(ft_nullptr)
        {
        }
        explicit RandomAccessIterator(pointer x) : _ptr(x)
        {
        }
        RandomAccessIterator(RandomAccessIterator const &obj) : _ptr(obj._ptr)
        {
        }
        RandomAccessIterator &operator=(RandomAccessIterator &rhs)
        {
            this->_ptr = rhs._ptr;
            return (*this);
        }
        ~RandomAccessIterator(void) {}
        RandomAccessIterator base() const
        {
            return (_ptr);
        } // explicit
        /**
         * "*a=t"?
         */
        reference operator*()
        {
            std::cout << "calling here *a=t" << '\n';
            return (*_ptr);
        }
        pointer operator->() const
        {
            return &(operator*());
        }
        /**
         * "=="
         */
        bool operator==(RandomAccessIterator &rhs)
        {
            std::cout << "calling here a == b" << '\n';
            return (this->_ptr == rhs._ptr);
        }
        /**
         * "!="
         */
        bool operator!=(RandomAccessIterator &rhs)
        {
            // std::cout << "calling here a != b" << '\n';
            return (this->_ptr != rhs._ptr);
        }
        /**
         * "a++"
         */
        RandomAccessIterator operator++(int)
        {
            // std::cout << "calling here a++" << '\n';
            RandomAccessIterator tmp = *this;
            operator++();
            return (tmp);
        }
        /**
         * "++a"
         */
        RandomAccessIterator &operator++()
        {
            // std::cout << "calling here ++a" << '\n';
            _ptr++;
            return (*this);
        }
        /**
         * "a--"
         */
        RandomAccessIterator operator--(int)
        {
            std::cout << "calling here a--" << '\n';
            RandomAccessIterator tmp = *this;
            operator--();
            return (tmp);
        }
        /**
         * "--a"
         */
        RandomAccessIterator &operator--()
        {
            std::cout << "calling here --a" << '\n';
            _ptr--;
            return (*this);
        }
        /**
         * "a < b"
         */
        bool operator<(RandomAccessIterator &rhs)
        {
            std::cout << "calling here a < b" << '\n';
            return (this->_ptr < rhs._ptr);
        }
        /**
         * "a > b"
         */
        bool operator>(RandomAccessIterator &rhs)
        {
            std::cout << "calling here a > b" << '\n';
            return (this->_ptr > rhs._ptr);
        }
        /**
         * "a <= b"
         */
        bool operator<=(RandomAccessIterator &rhs)
        {
            std::cout << "calling here a <= b" << '\n';
            return (this->_ptr <= rhs._ptr);
        }
        /**
         * "a >= b"
         */
        bool operator>=(RandomAccessIterator &rhs)
        {
            std::cout << "calling here a >= b" << '\n';
            return (this->_ptr >= rhs._ptr);
        }
        /**
         * "a += n"
         */
        RandomAccessIterator &operator+=(difference_type n)
        {
            std::cout << "calling here a += n" << '\n';
            this->_ptr += n;
            return (*this);
        }
        /**
         * "a += n"
         */
        RandomAccessIterator &operator-=(difference_type n)
        {
            std::cout << "calling here a -= n" << '\n';
            this->_ptr -= n;
            return (*this);
        }
        /**
         * "a + n"
         */
        RandomAccessIterator operator+(difference_type n) const
        {
            std::cout << "calling here a + n" << '\n';
            return (this->_ptr + n);
        }
        /**
         * "a - n"
         */
        RandomAccessIterator operator-(difference_type n) const
        {
            std::cout << "calling here a - n" << '\n';
            return (this->_ptr - n);
        }
        /**
         * "a[n]"
         */
        reference operator[](difference_type n) const
        {
            std::cout << "calling here a[n]" << '\n';
            RandomAccessIterator tmp = operator+(n);
            return (*tmp);
        }
    };
    template <typename T>
    bool operator==(
        const RandomAccessIterator<T> &x,
        const RandomAccessIterator<T> &y)
    {
        return (x._ptr == y._ptr);
    }
    template <typename T>
    bool operator<(
        const RandomAccessIterator<T> &x,
        const RandomAccessIterator<T> &y)
    {
        return (x._ptr < y._ptr);
    }
    template <typename T>
    bool operator!=(
        const RandomAccessIterator<T> &x,
        const RandomAccessIterator<T> &y)
    {
        return (x._ptr != y._ptr);
    }
    template <typename T>
    bool operator>(
        const RandomAccessIterator<T> &x,
        const RandomAccessIterator<T> &y)
    {
        return (x._ptr > y._ptr);
    }
    template <typename T>
    bool operator>=(
        const RandomAccessIterator<T> &x,
        const RandomAccessIterator<T> &y)
    {
        return (x._ptr >= y._ptr);
    }
    template <typename T>
    bool operator<=(
        const RandomAccessIterator<T> &x,
        const RandomAccessIterator<T> &y)
    {
        return (x._ptr <= y._ptr);
    }
    template <typename T>
    typename RandomAccessIterator<T>::difference_type operator-(
        const RandomAccessIterator<T> &x,
        const RandomAccessIterator<T> &y)
    {
        // return (x._ptr == y._ptr);
    }
    template <typename T>
    typename RandomAccessIterator<T>::difference_type operator+(
        const RandomAccessIterator<T> &x,
        const RandomAccessIterator<T> &y)
    {
        // return (x._ptr == y._ptr);
    }
}

#endif