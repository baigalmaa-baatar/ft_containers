/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <bbaatar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:01:16 by bbaatar           #+#    #+#             */
/*   Updated: 2022/10/11 11:01:17 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <map> // std::map
               // #include "../include/Map.hpp"

// template <typename T>
// void comparisonFuncVec(std::string testName, std::map<T> std_vector1, ft::map<T> ft_vector1)
// {
//   std::cout << "Comparision test of " << testName << " with standard func : " << '\n';

//   if (std_vector1 == ft_vector1)
//   {
//     std::cout << "matched" << std::endl;
//   }
// }

#include <iomanip>
#include <iostream>
#include <map>
#include <string>
// using namespace std::literals;

template <typename It>
void print_insertion_status(It it, bool success)
{
    std::cout << "Insertion of " << it->first
              << (success ? " succeeded\n" : " failed\n");
}

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

bool fncomp(char lhs, char rhs)
{
    return lhs < rhs;
}

struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};

int main(void)
{
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n      1-1.  Constructor" << '\n';
        std::cout << "\n            Default" << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> first;

        first['a'] = 10;
        first['b'] = 20;
        first['c'] = 30;
        first['d'] = 40;

        std::map<char, int>::iterator it = first.begin();
        std::cout << "first contains:\n";
        for (it = first.begin(); it != first.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        // std::map<char, int> second(first.begin(), first.end());

        // std::map<char, int> third(second);

        // std::map<char, int, classcomp> fourth; // class as Compare

        // bool (*fn_pt)(char, char) = fncomp;
        // std::map<char, int, bool (*)(char, char)> fifth(fn_pt); // function pointer as Compare
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n      1-1.  insert" << '\n';
        std::cout << "\n            fill" << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> mymap;

        // first insert function version (single parameter):
        mymap.insert(std::pair<char, int>('a', 10));
        mymap.insert(std::pair<char, int>('b', 20));
        mymap.insert(std::pair<char, int>('c', 30));
        mymap.insert(std::pair<char, int>('d', 40));
        mymap.insert(std::pair<char, int>('e', 50));
        mymap.insert(std::pair<char, int>('f', 25));

        // std::pair<std::map<char, int>::iterator, bool> ret;
        // ret = mymap.insert(std::pair<char, int>('z', 500));
        // if (ret.second == false)
        // {
        //     std::cout << "element 'z' already existed";
        //     std::cout << " with a value of " << ret.first->second << '\n';
        // }

        // // second insert function version (with hint position):
        // std::map<char, int>::iterator it = mymap.begin();
        // mymap.insert(it, std::pair<char, int>('b', 300)); // max efficiency inserting
        // mymap.insert(it, std::pair<char, int>('c', 400)); // no max efficiency inserting

        // // third insert function version (range insertion):
        // std::map<char, int> anothermap;
        // anothermap.insert(mymap.begin(), mymap.find('c'));

        // showing contents:
        // std::cout << "mymap contains:\n";
        // for (it = mymap.begin(); it != mymap.end(); ++it)
        //     std::cout << it->first << " => " << it->second << '\n';

        // std::cout << "anothermap contains:\n";
        // for (it = anothermap.begin(); it != anothermap.end(); ++it)
        //     std::cout << it->first << " => " << it->second << '\n';
    }
    return 0;
}