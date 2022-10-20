#include <iostream>
#include <iterator>

class MyIterator : std::iterator<std::input_iterator_tag, int>
{
private:
    int *_ptr;

public:
    MyIterator(int *x) : _ptr(x)
    {
    }
    ~MyIterator(void) {}
    bool operator==(MyIterator &rhs)
    {
        return (this->_ptr == rhs._ptr);
    }
    bool operator!=(MyIterator &rhs)
    {
        return (this->_ptr != rhs._ptr);
    }
    int& operator*()
    {
        return *_ptr;
    }
    MyIterator operator++(int)
    {
        MyIterator tmp = *this;
        operator++();
        return (tmp);
    }
    MyIterator& operator++()
    {
        _ptr++;
        return (*this);
    }
    // void operator++(int)
    // {
    //    operator++();
    // }

    // void operator++()
    // {
    //     _ptr++;
    // }
};

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};

    MyIterator from(numbers);
    MyIterator until(numbers + 5);
    for (MyIterator it = from; it != until; it++)
    {
        std::cout << *it << '\n';
    }
    std::cout << '\n';

    return 0;
}