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
    static void fun1()
    {
        cout << "Inside fun1()" << '\n';
    }
    static void fun2()
    {
        cout << "Inside fun2()" << '\n';
        fun1();
    }
};

int main()
{
    Test obj;
    obj.fun1();
    obj.fun2();
    return 0;
}