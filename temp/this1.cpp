#include <iostream>
using namespace std;

class Test
{
private:
    int x;

public:
    Test(int x = 0)
    {
        this->x = x;
    }
    void change(Test *t)
    {
        *this = t->x;
    }
    void print()
    {
        cout << "x = " << x << endl;
    }
};

int main()
{
    Test obj(5);
    obj.print();
    Test *ptr = new Test(10);
    obj.change(ptr);
    obj.print();
    return 0;
}