#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP
#include "utils.hpp"

namespace ft
{
    template <typename T>
    class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
    {
    public:
        typedef typename ft::iterator::difference_type difference_type;
        typedef typename ft::iterator::value_type value_type;
        typedef typename ft::iterator::iterator_category iterator_category;
        typedef T *pointer;
        typedef T &reference;

    private:
        pointer _ptr;

    public:
        /**
         * Constructor
         */
        random_access_iterator(void) : _ptr()
        {
        }
        /**
         * Constructor with initializing ptr
        */
        random_access_iterator(pointer ptr) : _ptr(ptr)
        {
        }
        /**
         * Destructor
         */
        virtual ~random_access_iterator()
        {
        }
    };
    
}

#endif
