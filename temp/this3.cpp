#include <iostream>
using namespace std;

class Test
{
private:
    int x;
    int y;

public:
    Test(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    Test& setX(int a)
    {
        this->x = a;
        std::cout << "Inside of setX x is : " << x << '\n';
        std::cout << "Inside of setX y is : " << y << '\n';
        return *this;
    }
    Test& setY(int b)
    {
        this->y = b;
        std::cout << "Inside of setY x is : " << x << '\n';
        std::cout << "Inside of setY y is : " << y << '\n';
        return *this;
    }
    void print()
    {
        std::cout << "Inside of print : " << x << " " << y << '\n';
        cout << "x = " << x << " y = " << y << endl;
    }
};

int main()
{
    Test obj1;
    obj1.setX(10).setY(20);
    obj1.print();
    return 0;
}