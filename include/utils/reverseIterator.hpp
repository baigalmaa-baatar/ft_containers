#ifndef REVITERATOR_HPP
#define REVITERATOR_HPP

#include "utils.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
                                             typename iterator_traits<Iterator>::value_type,
                                             typename iterator_traits<Iterator>::difference_type,
                                             typename iterator_traits<Iterator>::pointer,
                                             typename iterator_traits<Iterator>::reference>
    {
    protected:
        Iterator current;

    public:
        typedef Iterator iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef typename iterator_traits<Iterator>::reference reference;
        typedef typename iterator_traits<Iterator>::pointer pointer;
        /**
         * Default Constuctor
         */
        reverse_iterator(void) : current(ft_nullptr)
        {
        }
        /**
         * Default Constuctor with initializer parameter
         */
        explicit reverse_iterator(Iterator x) : current(x)
        {
        }

        /**
         * Default Constuctor with initializer object, huh? ask Marwa
         */

        template <class U>
        reverse_iterator(const reverse_iterator<U> &u) : current(u.current)
        {
        }

        /**
         * Destructor
         */
        ~reverse_iterator();

        /**
         * hey this is like getters() function
         */
        Iterator base() const
        {
            return (current);
        }

        /**
         * operator* (pointer) reverse_iterator is weird
         */
        reference operator*() const
        {
            Iterator tmp = current;
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
            --current;
            return (*this);
        }

        /**
         * operator++(int)
         * "a++"
         */
        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            --current;
            return (tmp);
        }

        /**
         * &operator--()
         * "--a"
         */
        reverse_iterator &operator--()
        {
            ++current;
            return (*this);
        }
        /**
         * operator--(int)
         * "a--"
         */
        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            ++current;
            return (tmp);
        }

        /**
         * operator+
         * "a+n"
         */
        reverse_iterator operator+(typename reverse_iterator<Iterator>::difference_type n) const
        {
            return (reverse_iterator(current - n));
        }

        /**
         * operator+=
         * "a += n"
         */
        reverse_iterator &operator+=(typename reverse_iterator<Iterator>::difference_type n)
        {
            current -= n;
            return (*this);
        }

        /**
         * operator-
         * "a - n"
         */
        reverse_iterator operator-(typename reverse_iterator<Iterator>::difference_type n) const
        {
            return (reverse_iterator(current + n));
        }

        /**
         * operator-=
         * "a -= n"
         */
        reverse_iterator &operator-=(typename reverse_iterator<Iterator>::difference_type n)
        {
            current += n;
            return (*this);
        }

        /**
         * operator[]
         * "a[n]"
         */
        reference operator[](typename reverse_iterator<Iterator>::difference_type n) const
        {
            return (current[-n - 1]);
        }
    };
    template <class Iterator>
    bool operator==(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.current() == rhs.current());
    }
    template <class Iterator>
    bool operator<(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.current() > rhs.current());
    }
    template <class Iterator>
    bool operator!=(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.current() != rhs.current());
    }
    template <class Iterator>
    bool operator>(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.current() < rhs.current());
    }
    template <class Iterator>
    bool operator>=(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.current() <= rhs.current());
    }
    template <class Iterator>
    bool operator<=(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.current() >= rhs.current());
    }
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (rhs.current() - lhs.current());
    }
    template <class Iterator>
    reverse_iterator<Iterator> operator+(
        typename reverse_iterator<Iterator>::difference_type n,
        const reverse_iterator<Iterator> &lhs)
    {
        return (reverse_iterator<Iterator>(lhs.current - n));
    }
}

#endif