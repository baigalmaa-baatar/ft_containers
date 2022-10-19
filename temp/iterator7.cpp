#include <iostream>
#include <vector>
#include <list>

template <typename T>
void my_reverse(T first, T last)
{
    int n = 5;
    for (--n; n > 0; n -= 2)
    {
        int tmp = *first;
        *first++ = *--last;
        *last = tmp;
    }
}

// typename std::iterator_traits<T>::difference_type n = std::distance(first, last);
// for (--n; n > 0; n -= 2) {
//     typename std::iterator_traits<T>::value_type tmp = *first;
//     *first++ = *--last;
//     *last = tmp;
// }

int main()
{
    /**
     * Testing vector
     */

    std::vector<int> v{1, 2, 3, 4, 5};

    my_reverse(v.begin(), v.end());
    for (std::vector<int>::iterator it = v.begin(); it < v.end(); it++)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    /**
     * Testing list
     */
    std::list<int> l{10, 11, 12, 13, 14, 15};

    my_reverse(l.begin(), l.end());
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    // int a[] = {1, 2, 3, 4, 5};
    // my_relerse(a, a + std::size(a));
    // for (int n : a) {
    //     std::cout << n << ' ';
    // }
    // std::cout << '\n';

    //    std::istreambuf_iterator<char> i1(std::cin), i2;
    //    my_reverse(i1, i2); // compilation error
}