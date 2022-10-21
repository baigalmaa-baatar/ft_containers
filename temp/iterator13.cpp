#include <iostream>
#include <iterator>

template <typename T>
class MyIterator : std::iterator<std::input_iterator_tag, T>
{
private:
    T *_ptr;

public:
    MyIterator(T *x) : _ptr(x)
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
    T& operator*()
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
};

int main(void)
{
    float numbers[] = {10.1, 20.1, 30.1, 40.1, 50.1};

    MyIterator<float> from(numbers);
    MyIterator<float> until(numbers + 5);
    for (MyIterator<float> it = from; it != until; it++)
    {
        std::cout << *it << '\n';
    }
    std::cout << '\n';

    return 0;
}