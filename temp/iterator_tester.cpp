#include <iostream>

namespace ft
{
    typedef __PTRDIFF_TYPE__ ptrdiff_t;
    static class nullptr_t
    {
    public:
        template <class T>   /* convertible to any type       */
        operator T *() const /* of null non-member            */
        {
            return 0;
        } /* pointer...                    */

        template <class C, class T> /* or any type of null           */
        operator T C::*() const     /* member pointer...             */
        {
            return 0;
        }

    private:
        void operator&() const; /* Can't take address of nullptr */

    } ft_nullptr = {}; /* and whose name is nullptr     */

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
}

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
        // this is for std::functions
        typedef std::random_access_iterator_tag iterator_category;

    protected:
        pointer _ptr;

    public:
        RandomAccessIterator(void) : _ptr(ft_nullptr)
        {
        }
        RandomAccessIterator(pointer x) : _ptr(x)
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

int main(void)
{
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1};
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n              X b(a): " << '\n';
        std::cout << "\n***************************************" << '\n';
        ft::RandomAccessIterator<float> from(numbers);
        ft::RandomAccessIterator<float> until(numbers + 5);
        for (ft::RandomAccessIterator<float> it = from; it != until; it++)
            std::cout << *it << '\n';
    }
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1};
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n              b = a: " << '\n';
        std::cout << "\n***************************************" << '\n';
        ft::RandomAccessIterator<float> from(numbers);
        ft::RandomAccessIterator<float> newFrom;
        newFrom = from;
        ft::RandomAccessIterator<float> until(numbers + 5);
        ft::RandomAccessIterator<float> newUntil = until;
        for (ft::RandomAccessIterator<float> it = newFrom; it != newUntil; it++)
            std::cout << *it << '\n';
    }
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1};
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n              --a: " << '\n';
        std::cout << "\n***************************************" << '\n';
        ft::RandomAccessIterator<float> test3_end(numbers + 4);
        ft::RandomAccessIterator<float> test3_start(numbers - 1);
        for (ft::RandomAccessIterator<float> it = test3_end; it != test3_start; --it)
            std::cout << *it << '\n';
    }
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1};
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n              a--: " << '\n';
        std::cout << "\n***************************************" << '\n';
        ft::RandomAccessIterator<float> test4_end(numbers + 4);
        ft::RandomAccessIterator<float> test4_start(numbers - 1);
        for (ft::RandomAccessIterator<float> it = test4_end; it != test4_start; --it)
            std::cout << (*it <= *it) << '\n';
    }
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1, 60.1};
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n              a += n: " << '\n';
        std::cout << "\n***************************************" << '\n';
        ft::RandomAccessIterator<float> from(numbers);
        ft::RandomAccessIterator<float> until(numbers + 6);
        for (ft::RandomAccessIterator<float> it = from; it != until; it += 2)
            std::cout << *it << '\n';
    }
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1, 60.1};
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n              a -= n: " << '\n';
        std::cout << "\n***************************************" << '\n';
        ft::RandomAccessIterator<float> from(numbers + 5);
        ft::RandomAccessIterator<float> until(numbers - 1);
        for (ft::RandomAccessIterator<float> it = from; it != until; it -= 2)
            std::cout << *it << '\n';
    }
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1, 60.1};
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n              a + n: " << '\n';
        std::cout << "\n***************************************" << '\n';
        ft::RandomAccessIterator<float> from(numbers);
        for (int i = 0; i < 6; i++)
            std::cout << *(from + i) << '\n';
    }
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1, 60.1};
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n              a - n: " << '\n';
        std::cout << "\n***************************************" << '\n';
        ft::RandomAccessIterator<float> from(numbers + 6);
        for (int i = 6; i > 0; i--)
            std::cout << *(from - i) << '\n';
    }
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1, 60.1};
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n              a[n]: " << '\n';
        std::cout << "\n***************************************" << '\n';
        ft::RandomAccessIterator<float> from(numbers);
        for (int i = 0; i < 6; i++)
            std::cout << from[i] << '\n';
    }
    std::cout << '\n';
    return 0;
}