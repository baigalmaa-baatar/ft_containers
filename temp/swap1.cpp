#include <iostream>

namespace ft
{
    template <typename T>
    void swap(T &a, T &b)
    {
        T tmp;
        tmp = a;
        a = b;
        b = tmp;
    };
    template <typename T>
    const T &min(T const &a, T const &b)
    {
        return (a < b ? a : b);
    };
    template <typename T>
    T &max(T &a, T &b)
    {
        return (a > b ? a : b);
    };
}

int main(void)
{
    int a = 2;
    int b = 3;
    ft::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ft::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ft::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ft::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ft::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ft::max(c, d) << std::endl;
    return 0;
}