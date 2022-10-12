// #include <string>

// namespace Test
// {
//     namespace old_ns
//     {
//         std::string Func() { return std::string("Hello from old"); }
//     }

//     inline namespace new_ns
//     {
//         std::string Func() { return std::string("Hello from new"); }
//     }
// }

#include "testing.hpp"
#include <string>
#include <iostream>

int main()
{
    using namespace std;

    string s = Test::Func();
    std::cout << s << std::endl; // "Hello from new"
    return 0;
}