#include <iostream>
// #include <>

class MyIterator : std::iterator<std::input_iterator_tag, int>
{
private:
    int *_ptr;

public:
    // MyIterator(void) : _ptr(nullptr) {}
    MyIterator(int *x) : _ptr(x)
    {
        // std::cout << "Initializing constructor THIS: " << this << '\n';
        // std::cout << "Initializing constructor _ptr: " << _ptr << '\n';
        // std::cout << "Initializing constructor *_ptr: " << *_ptr << '\n';
    }
    ~MyIterator(void) {}
    bool operator==(MyIterator &rhs)
    {
        // std::cout << "This is operator==: " << *_ptr << '\n';
        return (this->_ptr == rhs._ptr);
    }
    bool operator!=(MyIterator &rhs)
    {
        // std::cout << "This is operator!=: " << *_ptr << '\n';
        return (this->_ptr != rhs._ptr);
    }
    int& operator*()
    {
        // std::cout << "This is operator*: " << *_ptr << '\n';
        return *_ptr;
    }

    /**
     * Post-increment should return by-value
     * Should return actual value
     * "*a++" 
     */
    // MyIterator operator++(int) 
    // {

    //     std::cout << "operator BEFORE THIS: " << this << '\n';
    //     std::cout << "operator BEFORE _ptr: " << _ptr << '\n';
    //     std::cout << "operator BEFORE *_ptr: " << *_ptr << '\n';
    //     MyIterator tmp = *this;
    //     ++*this;
    //     std::cout << "operator THIS: " << this << '\n';
    //     std::cout << "operator _ptr: " << _ptr << '\n';
    //     std::cout << "operator *_ptr: " << *_ptr << '\n';
    //     return (tmp);
    // }

    /**
     * Pre-increment should return a reference
     * move the pointer return just the reference
     * "++a"
     * This is referencing, changing the private value.
     */
    // MyIterator& operator++() 
    // {
    //     // std::cout << "operator BEFORE THIS: " << this << '\n';
    //     // std::cout << "operator BEFORE _ptr: " << _ptr << '\n';
    //     // std::cout << "operator BEFORE *_ptr: " << *_ptr << '\n';
    //     ++_ptr;
    //     // std::cout << "operator THIS: " << this << '\n';
    //     // std::cout << "operator _ptr: " << _ptr << '\n';
    //     // std::cout << "operator *_ptr: " << *_ptr << '\n';
    //     return (*this);
    // }

    //In tutorial, I should write like this:
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

    //But I can write like this, still I get same result.
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
    std::cout << "Printing from : " << *from << '\n';
    MyIterator until(numbers + 5);
    for (MyIterator it = from; it != until; it++)
    {
        std::cout << "this is from : " << *until-1 << '\n';
        // from++;
        std::cout << *it << '\n';
    }
    std::cout << '\n';

    return 0;
}