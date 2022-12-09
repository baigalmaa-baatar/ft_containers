/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:53:41 by bbaatar           #+#    #+#             */
/*   Updated: 2022/11/21 16:53:43 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP
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
        RandomAccessIterator(const RandomAccessIterator &obj) : _ptr(obj._ptr)
        {
        }
        RandomAccessIterator &operator=(const RandomAccessIterator &rhs)
        {
            if (this == &rhs)
                return (*this);
            this->_ptr = rhs._ptr;
            return (*this);
        }
        ~RandomAccessIterator(void) {}
        pointer base() const
        {
            return (this->_ptr);
        } // explicit

        /**
         * "*a=t"?
         */
        reference operator*()
        {
            // std::cout << "calling here *a=t" << '\n';
            return (*_ptr);
        }
        reference operator*() const
        {
            // std::cout << "calling here *a=t" << '\n';
            return (*_ptr);
        }
        pointer operator->() const
        {
            return &(operator*());
        }
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
            // std::cout << "calling here a--" << '\n';
            RandomAccessIterator tmp = *this;
            operator--();
            return (tmp);
        }
        /**
         * "--a"
         */
        RandomAccessIterator &operator--()
        {
            // std::cout << "calling here --a" << '\n';
            _ptr--;
            return (*this);
        }
        /**
         * "a < b"
         */
        RandomAccessIterator &operator+=(difference_type n)
        {
            // std::cout << "calling here a += n" << '\n';
            this->_ptr += n;
            return (*this);
        }
        /**
         * "a += n"
         */
        RandomAccessIterator &operator-=(difference_type n)
        {
            // std::cout << "calling here a -= n" << '\n';
            this->_ptr -= n;
            return (*this);
        }
        /**
         * "a + n"
         */
        RandomAccessIterator operator+(difference_type value) const
        {
            RandomAccessIterator tmp(*this);
            return (tmp += value);
        }
        /**
         * "a - n"
         */
        RandomAccessIterator operator-(difference_type value) const
        {
            RandomAccessIterator tmp(*this);
            return (tmp -= value);
        }
        /**
         * "a[n]"
         */
        reference operator[](difference_type n) const
        {
            // std::cout << "calling here a[n]" << '\n';
            RandomAccessIterator tmp = operator+(n);
            return (*tmp);
        }
        difference_type operator-(RandomAccessIterator const &y) const
        {
            return (this->_ptr - y._ptr);
        }
        operator RandomAccessIterator<const T>() const
        {
            return (RandomAccessIterator<const T>(this->_ptr));
        }
    };
    template <typename A>
    bool operator==(const ft::RandomAccessIterator<A> &lhs, const ft::RandomAccessIterator<A> &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    //const iterator
    template <typename A, typename B>
    bool operator==(const ft::RandomAccessIterator<A> &lhs, const ft::RandomAccessIterator<B> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <typename A, typename B>
    bool operator!=(const ft::RandomAccessIterator<A> &lhs, const ft::RandomAccessIterator<B> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <typename A, typename B>
    bool operator>(const ft::RandomAccessIterator<A> &lhs, const ft::RandomAccessIterator<B> &rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <typename A, typename B>
    bool operator<(const ft::RandomAccessIterator<A> &lhs, const ft::RandomAccessIterator<B> &rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <typename A, typename B>
    bool operator<=(const ft::RandomAccessIterator<A> &lhs, const ft::RandomAccessIterator<B> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <typename A, typename B>
    bool operator>=(const ft::RandomAccessIterator<A> &lhs, const ft::RandomAccessIterator<B> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <typename A, typename B>
    typename ft::RandomAccessIterator<A>::difference_type operator-(const ft::RandomAccessIterator<A> &lhs, const ft::RandomAccessIterator<B> &rhs)
    {
        return (lhs.base() - rhs.base());
    }

    template <typename A, typename B>
    typename ft::RandomAccessIterator<A>::difference_type operator+(const ft::RandomAccessIterator<A> &lhs, const ft::RandomAccessIterator<B> &rhs)
    {
        return (lhs.base() + rhs.base());
    }

    template <typename L>
    ft::RandomAccessIterator<L> operator+(const typename ft::RandomAccessIterator<L>::difference_type &a, const ft::RandomAccessIterator<L> &iter)
    {
        return (iter + a);
    }

    template <typename A>
    typename ft::RandomAccessIterator<A>::difference_type
    operator-(const ft::RandomAccessIterator<A> lhs,
              const ft::RandomAccessIterator<A> rhs)
    {
        return (lhs.base() - rhs.base());
    }
    template <typename L>
    ft::RandomAccessIterator<L> operator-(const typename ft::RandomAccessIterator<L>::difference_type &a, const ft::RandomAccessIterator<L> &iter)
    {
        return (iter - a);
    }
}
#endif
