#include <iostream>
// #include <iterator>

namespace ft
{
    typedef __PTRDIFF_TYPE__ ptrdiff_t;
    // typedef decltype(nullptr) nullptr_t;
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
    /**
     *  @brief  Common %iterator class.
     *
     *  This class does nothing but define nested typedefs.  %Iterator classes
     *  can inherit from this class to save some work.  The typedefs are then
     *  used in specializations and overloading.
     *
     *  In particular, there are no default implementations of requirements
     *  such as @c operator++ and the like.  (How could there be?)
     */
    template <typename Category, typename T, typename Distance = ptrdiff_t,
              typename Pointer = T *, typename Reference = T &>
    struct random_access_iterator
    {
        /// One of the @link iterator_tags tag types@endlink.
        typedef Category iterator_category;
        /// The type "pointed to" by the iterator.
        typedef T value_type;
        /// Distance between iterators is represented as this type.
        typedef Distance difference_type;
        /// This type represents a pointer-to-value_type.
        typedef Pointer pointer;
        /// This type represents a reference-to-value_type.
        typedef Reference reference;
    };
}

// typedef struct s_stack {int value; } t_stack;

namespace ft
{
    template <typename T>
    class MyIterator : ft::random_access_iterator<ft::random_access_iterator_tag, T>
    {
    public:
        typedef T value_type;
        // typedef typename ft::random_access_iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::ptrdiff_t difference_type;
        // typedef T const *const_pointer;
        // typedef T const &const_reference;

        // typedef T value_type;
        // typedef value_type *pointer;
        // typedef value_type const *const_pointer;
        // typedef value_type &reference;
        // typedef value_type const &const_reference;
        // typedef std::ptrdiff_t difference_type;

    protected:
        pointer _ptr;

    public:
        MyIterator(void) : _ptr(ft_nullptr)
        {
        }
        MyIterator(pointer x) : _ptr(x)
        {
        }
        MyIterator(MyIterator const &obj) : _ptr(obj._ptr)
        {
        }
        // MyIterator &operator=(MyIterator &rhs)
        // {
        //     this->_ptr = rhs._ptr;
        //     return (*this);
        // }
        ~MyIterator(void) {}
        /**
         * "=="
         */
        bool operator==(MyIterator &rhs)
        {
            return (this->_ptr == rhs._ptr);
        }
        /**
         * "!="
         */
        bool operator!=(MyIterator &rhs)
        {
            return (this->_ptr != rhs._ptr);
        }
        /**
         * "*a=t"?
         */
        T &operator*()
        {
            return *_ptr;
        }
        /**
         * "a++"
         */
        MyIterator operator++(int)
        {
            MyIterator tmp = *this;
            operator++();
            return (tmp);
        }
        /**
         * "++a"
         */
        MyIterator &operator++()
        {
            _ptr++;
            return (*this);
        }
        /**
         * "a--"
         */
        MyIterator operator--(int)
        {
            MyIterator tmp = *this;
            operator--();
            return (tmp);
        }
        /**
         * "--a"
         */
        MyIterator &operator--()
        {
            _ptr--;
            return (*this);
        }
        /**
         * "a < b"
         */
        bool operator<(MyIterator &rhs)
        {
            return (this->_ptr < rhs._ptr);
        }
        /**
         * "a > b"
         */
        bool operator>(MyIterator &rhs)
        {
            return (this->_ptr > rhs._ptr);
        }
        /**
         * "a <= b"
         */
        bool operator<=(MyIterator &rhs)
        {
            return (this->_ptr <= rhs._ptr);
        }
        /**
         * "a >= b"
         */
        bool operator>=(MyIterator &rhs)
        {
            return (this->_ptr >= rhs._ptr);
        }
        /**
         * "a += n"
         */
        MyIterator &operator+=(difference_type n)
        {
            this->_ptr += n;
            return (*this);
        }
        /**
         * "a += n"
         */
        MyIterator &operator-=(difference_type n)
        {
            this->_ptr -= n;
            return (*this);
        }
        /**
         * "a + n" ene hurtel!!
         */
        MyIterator &operator-=(difference_type n)
        {
            this->_ptr -= n;
            return (*this);
        }
    };
}

int main(void)
{
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1};
        std::cout << "\nThe first test: " << '\n';
        ft::MyIterator<float> from(numbers);
        ft::MyIterator<float> until(numbers + 5);
        for (ft::MyIterator<float> it = from; it != until; it++)
            std::cout << *it << '\n';
    }
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1};
        std::cout << "\nThe second test: " << '\n';
        ft::MyIterator<float> from(numbers);
        ft::MyIterator<float> newFrom;
        newFrom = from;
        ft::MyIterator<float> until(numbers + 5);
        ft::MyIterator<float> newUntil = until;
        for (ft::MyIterator<float> it = newFrom; it != newUntil; it++)
            std::cout << *it << '\n';
    }
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1};
        std::cout << "\nThe third test: " << '\n';
        ft::MyIterator<float> test3_end(numbers + 4);
        ft::MyIterator<float> test3_start(numbers - 1);
        for (ft::MyIterator<float> it = test3_end; it != test3_start; --it)
            std::cout << *it << '\n';
    }
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1};
        std::cout << "\nThe fourth test: " << '\n';
        ft::MyIterator<float> test4_end(numbers + 4);
        ft::MyIterator<float> test4_start(numbers - 1);
        for (ft::MyIterator<float> it = test4_end; it != test4_start; --it)
            std::cout << (*it <= *it) << '\n';
    }
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1}; //, 60.1};
        std::cout << "\nThe fifth test: " << '\n';
        ft::MyIterator<float> from(numbers);
        ft::MyIterator<float> until(numbers + 5);
        for (ft::MyIterator<float> it = from; it != until; it += 2)
        {
            std::cout << "Let's see how many times it has called" << '\n';
            std::cout << *it << '\n';
        }
    }
    {
        float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1}; //, 60.1};
        std::cout << "\nThe fifth test: " << '\n';
        ft::MyIterator<float> from(numbers + 5);
        ft::MyIterator<float> until(numbers);
        for (ft::MyIterator<float> it = from; it != until; it -= 2)
        {
            std::cout << "Let's see how many times it has called" << '\n';
            std::cout << *it << '\n';
        }
    }
    std::cout << '\n';
    return 0;
}