#include <iostream>
#include <iterator>

// template <typename T>
class MyIterator : std::iterator<std::input_iterator_tag, int>
{
    int *_ptr;

public:
    /**
     * Default Constructor
     */
    MyIterator(void) : _ptr(nullptr) {}

    /**
     * Constructor with initializer
     * "X u(a);"
     */
    MyIterator(int *x) : _ptr(x) {}

    /**
     * Destructor
     */
    ~MyIterator(void) {}

    /**
     * Copy Constructor
     * "u = a"
     */
    MyIterator &operator=(MyIterator &rhs)
    {
        *this = rhs;
        return (*this);
    }

    /** 
     * ? What is this
    */
    MyIterator(const MyIterator &mit) : _ptr(mit._ptr) {}

    /**
     * Boolean operator
     * "=="
     */
    bool operator==(const MyIterator &rhs) const
    {
        return (_ptr == rhs._ptr);
    }

    /**
     * Boolean operator
     * "!="
     */
    bool operator!=(const MyIterator &rhs) const
    {
        return (_ptr != rhs._ptr);
    }

    /**
     * Get the value
     * "*a"
     */
    int &operator*(void)
    {
        return *_ptr;
    }

    /**
     * Get the value
     * "a->m"
     */
    int &operator->(void)
    {
        return *_ptr;
    }
    
    /**
     * The previous iterator value is not required to be derefenceable after the increase
     * "*++a"
     */
    MyIterator operator++(int)
    {
        MyIterator tmp = *this;
        // _ptr++;
        operator++();
        return (tmp);
    }

    /**
     * Can be incremented (if in a deferenceable state)
     * "++a"
     */
    MyIterator &operator++()
    {
        ++_ptr;
        return (*this);
    }
};

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};

    MyIterator from(numbers);
    std::cout << "Printing from : " << *from << '\n';
    MyIterator until(numbers + 5);

    for (MyIterator it = from; it != until; it++)
        std::cout << *it << ' ';
    std::cout << '\n';

    return 0;
}