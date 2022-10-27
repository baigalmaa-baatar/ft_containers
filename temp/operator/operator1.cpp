#include <iostream>

class myInt
{
private:
    int value;

public:
    myInt() : value{0} {}
    myInt(int x) : value{x} {}
    // myInt operator++()
    // {
    //     ++value;
    //     return *this;
    // }
    myInt operator++(int)
    {
        myInt tmp = *this;
        operator++();
        return (tmp);
    }
    myInt &operator++()
    {
        ++value;
        std::cout << "here " << '\n';
        return *this;
    }
    void show()
    {
        std::cout << value << std::endl;
    }
};

int main(int argc, char *argv[])
{
    myInt one(1);
    std::cout << "one.show(): ";
    one.show();
    // myInt two = ++(++one);
    myInt three = (one++)++;
    // std::cout << "two.show(): ";
    // two.show();
    std::cout << "Again one.show(): ";
    one.show(); // Difference shows here!
    std::cout << "three.show(): ";
    three.show(); // Difference shows here!
    std::cout << "Again one.show(): ";
    one.show(); // Difference shows here!
    return 0;
}