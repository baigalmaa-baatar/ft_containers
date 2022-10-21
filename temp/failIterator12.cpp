#include <iostream>
#include <cstddef>
#include "../include/utils.hpp"

// class MyIterator : std::iterator<std::bidirectional_iterator_tag, int>
namespace ft
{
    template <typename T>
    class MyIterator : ft::iterator<ft::random_access_iterator_tag, T>
    {
    private:
        // typedef T *_ptr;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer _ptr;

    public:
        MyIterator(void) : _ptr()
        {
        }
        MyIterator(T &ptr) : _ptr(ptr)
        {
        }
        ~MyIterator(void) {}
        bool operator==(MyIterator &rhs)
        {
            return (*this == rhs);
        }
        bool operator!=(MyIterator &rhs)
        {
            return (*this != rhs);
        }
        // T &operator*()
        // {
        //     return *_ptr;
        // }
        MyIterator operator++(int)
        {
            MyIterator tmp = *this;
            operator++();
            return (tmp);
        }
        MyIterator &operator++()
        {
            *_ptr++;
            return (*this);
        }
    };
}

int main(void)
{
    const int numbers[] = {10, 20, 30, 40, 50};

    ft::MyIterator<const int*> from(numbers);
    ft::MyIterator<const int*> until(numbers + 5);
    for (ft::MyIterator<const int*> it = from; it != until; it++)
    {
        std::cout << *it << '\n';
    }
    std::cout << '\n';

    return 0;
}