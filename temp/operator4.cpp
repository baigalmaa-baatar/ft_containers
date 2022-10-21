#include <iostream>
#include <string>

class Test
{
    std::string _name;
public:
    Test(std::string name) : _name(name) { }
    ~Test()
    {
        std::cout << "Destructor " << _name << std::endl;
    }
    Test& operator=(const Test& fellow)
    {
        // avoid changing the name of the object
        // std::cout << "Assignment operator " 
        //     << _name << "=" << fellow._name << std::endl;
        return *this;
    }
};

int main()
{
    Test t1("t1"), t2("t2");
    t1 = t2;
    return 0;
}