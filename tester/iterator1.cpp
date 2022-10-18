#include <iostream>
#include <vector>


int main(){
    std::vector<int> myvect;
    
    for (int i = 0; i < 10; i++)
        myvect.push_back(i);
    
    // for (std::vector<int>::iterator it=myvect.begin(); it < myvect.end(); it++)
    //     // std::cout << *it << '\n';
    std::vector<int>::iterator ite=myvect.begin();
    std::cout << "this is 5th element in list:" << *(5 + ite) << '\n';
    std::cout << "this is 3th element in list:" << ite[2] << '\n';

    return 0;
}