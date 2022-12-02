/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:54:06 by bbaatar           #+#    #+#             */
/*   Updated: 2022/11/21 16:54:08 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iterator>

namespace ft
{
    typedef __PTRDIFF_TYPE__ ptrdiff_t;

    static class nullptr_t
    {
    public:
        /*
        ** @brief For conversion to any type
        ** of null non-member pointer.
        */
        template <class T>
        operator T *() const { return (0); }

        /*
        ** @brief For conversion to any type of null
        ** member pointer.
        */
        template <class C, class T>
        operator T C::*() const { return (0); }

    private:
        /*
        ** @brief It's imposible to get an address of
        ** a nullptr.
        */
        void operator&() const;

    } ft_nullptr = {};
    struct random_access_iterator_tag
    {
    };

    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
    };
    
    template <class T>
    struct iterator_traits<T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef random_access_iterator_tag iterator_category;
        typedef T *pointer;
        typedef T &reference;
    };

    template <class T>
    struct iterator_traits<const T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef random_access_iterator_tag iterator_category;
        typedef const T *pointer;
        typedef const T &reference;
    };

    // https://medium.com/@sidbhasin82/c-templates-what-is-std-enable-if-and-how-to-use-it-fd76d3abbabe
    /**
     *  templated struct enable_if which takes in a boolean non-type parameter and T a type parameter:
     */
    template <bool B, class T = void>
    struct enable_if
    {
    };
    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };
    /**
     * Checking if the object is integral or not:
     */
    template <typename T>
    struct is_integral
    {
        static const bool value = false;
    };
    /*
    ** @brief default template of the structure is_integral_type.
    ** If the type given in argument is from the list, the structure
    ** will be overide by nexts, in according to it type.
    ** If the type given is argument isn't in the list,
    ** stocked value will be false. So it's not a integral type.
    */

    template <>
    struct is_integral<bool>
    {
        static const bool value = false;
    };
    template <>
    struct is_integral<char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<wchar_t>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<signed char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<short int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<long int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<long long int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned short int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned long int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned long long int>
    {
        static const bool value = true;
    };

    // from official document C++98 : bidirectional iterator
    //  template <class T>
    //  struct iterator_traits<BinarySearchIterator<T> >
    //  {
    //      typedef ptrdiff_t difference_type;
    //      typedef T value_type;
    //      typedef T *pointer;
    //      typedef T &reference;
    //      typedef bidirectional_iterator_tag iterator_category;
    //  };

    // https://cplusplus.com/reference/type_traits/remove_const/

    // const_remove is for removing constness, without it it is not possible to use erase function:
    // template <typename T>
    // struct remove_const<const T>
    // {
    //     typedef T type;
    // };
    template <typename T>
    struct remove_const
    {
        typedef T type;
    };
    template <typename T>
    struct less : public std::binary_function<T, T, bool>
    {
        bool operator()(const T &x, const T &y) const
        {
            return (x < y);
        }
    };
    template <typename T1, typename T2>
    struct pair
    {
        typedef T1 first_type;  ///< The type of the `first` member
        typedef T2 second_type; ///< The type of the `second` member

        T1 first;  ///< The first member
        T2 second; ///< The second member

        pair() : first(), second() {}

        pair(const pair &p) : first(p.first), second(p.second) {}

        /// Two objects may be passed to a @c pair constructor to be copied.
        pair(const T1 &a, const T2 &b) : first(a), second(b) {}

        /// There is also a templated constructor to convert from other pairs.
        template <typename U1, typename U2>
        pair(const pair<U1, U2> &p) : first(p.first), second(p.second) {}

        // mymap.insert(std::pair<char, int>('a', 100));

        pair &operator=(const pair &p)
        {
            first = p.first;
            second = p.second;
            return *this;
        }
    };

    /// Two pairs of the same type are equal iff their members are equal.
    template <typename T1, typename T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    /** Defines a lexicographical order for pairs.
     *
     * For two pairs of the same type, `P` is ordered before `Q` if
     * `P.first` is less than `Q.first`, or if `P.first` and `Q.first`
     * are equivalent (neither is less than the other) and `P.second` is less
     * than `Q.second`.
     */
    template <typename T1, typename T2>
    inline bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }
    template <typename T1, typename T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs == rhs);
    }
    template <typename T1, typename T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return rhs < lhs;
    }

    template <typename T1, typename T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(rhs < lhs);
    }

    template <typename T1, typename T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs < rhs);
    }

    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (pair<T1, T2>(x, y));
    }
}

#endif
