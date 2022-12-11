/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:53:53 by bbaatar           #+#    #+#             */
/*   Updated: 2022/11/21 16:53:55 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVITERATOR_HPP
#define REVITERATOR_HPP

#include "utils.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
    private:
        Iterator _current;

    public:
        typedef Iterator iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef typename iterator_traits<Iterator>::reference reference;
        typedef typename iterator_traits<Iterator>::pointer pointer;
        /**
         * Default Constuctor
         */
        reverse_iterator() : _current(ft_nullptr) {}
        /**
         * Default Constuctor with initializer parameter
         */
        explicit reverse_iterator(Iterator x) : _current(x) {}
        /**
         * Default Constuctor with initializer object, huh? ask Marwa
         */

        template <class U>
        reverse_iterator(const reverse_iterator<U> &u) : _current(u.base()) {}
        /**
         * Destructor
         * but why??
         */
        // ~reverse_iterator();

        /**
         * hey this is like getters() function
         */
        Iterator base() const { return (_current); }

        /**
         * operator* (pointer) reverse_iterator is weird
         */
        reference operator*() const
        {
            Iterator tmp = _current;
            return (*--tmp);
        }

        /**
         * operator->
         */
        pointer operator->() const
        {
            return &(operator*());
        }

        /**
         * &operator++()
         * "++a"
         */
        reverse_iterator &operator++()
        {
            --_current;
            // std::cout << "here" << '\n';
            return (*this);
        }

        /**
         * operator++(int)
         * "a++"
         */
        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            --_current;
            return (tmp);
        }

        /**
         * &operator--()
         * "--a"
         */
        reverse_iterator &operator--()
        {
            ++_current;
            return (*this);
        }
        /**
         * operator--(int)
         * "a--"
         */
        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            ++_current;
            return (tmp);
        }

        /**
         * operator+
         * "a+n"
         */
        reverse_iterator operator+(typename reverse_iterator<Iterator>::difference_type n) const
        {
            return (reverse_iterator(_current - n));
        }

        /**
         * operator+=
         * "a += n"
         */
        reverse_iterator &operator+=(typename reverse_iterator<Iterator>::difference_type n)
        {
            _current -= n;
            return (*this);
        }

        /**
         * operator-
         * "a - n"
         */
        reverse_iterator operator-(typename reverse_iterator<Iterator>::difference_type n) const
        {
            return (reverse_iterator(_current + n));
        }

        /**
         * operator-=
         * "a -= n"
         */
        reverse_iterator &operator-=(typename reverse_iterator<Iterator>::difference_type n)
        {
            _current += n;
            return (*this);
        }

        /**
         * operator[]
         * "a[n]"
         */
        reference operator[](typename reverse_iterator<Iterator>::difference_type n) const
        {
            return (_current[-n - 1]);
        }
    };
    template <class Iterator>
    bool operator==(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    // iterator == const_iterator case
    template <class Iterator, class Iterator_const>
    bool operator==(const reverse_iterator<Iterator> &lhs,
                    const reverse_iterator<Iterator_const> &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator>
    bool operator!=(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() != rhs.base());
    }
    // iterator != const_iterator case
    template <class Iterator, class Iterator_const>
    bool operator!=(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator_const> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <class Iterator>
    bool operator<(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() > rhs.base());
    }
    // iterator < const_iterator case
    template <class Iterator, class Iterator_const>
    bool operator<(const reverse_iterator<Iterator> &lhs,
                   const reverse_iterator<Iterator_const> &rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator>
    bool operator<=(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    // iterator <= const_iterator case
    template <class Iterator, class Iterator_const>
    bool operator<=(const reverse_iterator<Iterator> &lhs,
                    const reverse_iterator<Iterator_const> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template <class Iterator>
    bool operator>(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() < rhs.base());
    }
    // iterator > const_iterator case
    template <class Iterator, class Iterator_const>
    bool operator>(const reverse_iterator<Iterator> &lhs,
                   const reverse_iterator<Iterator_const> &rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator>
    bool operator>=(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    // iterator >= const_iterator
    template <class Iterator, class Iterator_const>
    bool operator>=(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator_const> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (rhs.base() - lhs.base());
    }

    /* iterator - const_iterator */
    /* For reverser_iterator - const_reverse_iterator */
    template <class Iterator, class Iterator_const>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs,
                   const reverse_iterator<Iterator_const> &rhs)
    {
        return (rhs.base() - lhs.base());
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+(
        typename reverse_iterator<Iterator>::difference_type n,
        const reverse_iterator<Iterator> &lhs)
    {
        return (reverse_iterator<Iterator>(lhs.base() - n));
    }
    
}

#endif
