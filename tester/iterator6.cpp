#include <iostream>
#include <vector>

/**
 * array iin dotorhi utguudiig butsaadag function:
*/
template <typename T> 
int first_elem(T &container)
{
    int *pointer;
    typename T::iterator it = container.begin();
    *pointer = *it;
    return (*pointer);
}
template <typename T> 
int next_elem(T &container)
{
    int pointer;
    typename T::iterator it = container.begin();
    pointer = *(++it);
    return (pointer);
}

int main(void) {
    
    int const mylist[]={12,13,14,15,15};

    std::vector<int> myvec(mylist, mylist + 5);

    std::cout << "first element is " << first_elem(myvec) << '\n';
    std::cout << "first element is " << next_elem(myvec) << '\n';

    return 0;
}
