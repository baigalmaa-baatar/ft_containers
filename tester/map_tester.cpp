/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <bbaatar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:01:10 by bbaatar           #+#    #+#             */
/*   Updated: 2022/10/11 11:01:11 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map> // std::map
// #include "../include/Map.hpp"

template <typename T>
// void comparisonFuncVec(std::string testName, std::vector<T> std_vector1, ft::vector<T> ft_vector1)
// {
//   std::cout << "Comparision test of " << testName << " with standard func : " << '\n';

//   if (std_vector1 == ft_vector1)
//   {
//     std::cout << "matched" << std::endl;
//   }
// }

void comparisonFunc(std::string testName, int std, int ft)
{
    std::cout << "Comparision test of " << testName << " with standard func : " << '\n';

    std::cout << "Standard result: "
              << std << '\n';
    std::cout << "ft result: "
              << ft << '\n';
    if (std == ft)
        std::cout << "✅" << '\n';
    else
        std::cout << "❌" << '\n';
}

void nonMemberComparison(std::string testName, bool std, bool ft)
{
    std::cout << "Comparision test of " << testName << " with standard func : " << '\n';
    if (std == true)
        std::cout << "Standard result: "
                  << "true" << '\n';
    else
        std::cout << "Standard result: "
                  << "false" << '\n';
    if (ft == true)
        std::cout << "ft result: "
                  << "true" << '\n';
    else
        std::cout << "ft result: "
                  << "false" << '\n';
    if (std == ft)
        std::cout << "✅" << '\n';
    else
        std::cout << "❌" << '\n';
}

int main(void)
{
    {
        std::map<char, int> mymap;

        // first insert function version (single parameter):
        mymap.insert(std::pair<char, int>('a', 100));
        mymap.insert(std::pair<char, int>('z', 200));

        std::pair<std::map<char, int>::iterator, bool> ret;
        ret = mymap.insert(std::pair<char, int>('z', 500));
        if (ret.second == false)
        {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }

        // second insert function version (with hint position):
        std::map<char, int>::iterator it = mymap.begin();
        mymap.insert(it, std::pair<char, int>('b', 300)); // max efficiency inserting
        mymap.insert(it, std::pair<char, int>('c', 400)); // no max efficiency inserting

        // third insert function version (range insertion):
        std::map<char, int> anothermap;
        anothermap.insert(mymap.begin(), mymap.find('c'));

        // showing contents:
        std::cout << "mymap contains:\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "anothermap contains:\n";
        for (it = anothermap.begin(); it != anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        return 0;
    }
    {
        typedef const char cc;
        std::remove_const<cc>::type a;           // char a
        std::remove_const<const char *>::type b; // const char* b
        std::remove_const<char *const>::type c;  // char* c

        a = 'x';
        b = "remove_const";
        c = new char[10];

        std::cout << b << std::endl;
    }
    
}