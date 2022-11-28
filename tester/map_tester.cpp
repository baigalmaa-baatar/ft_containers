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
#include "../include/map.hpp"

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

// void comparisonFunc(std::string testName, int std, int ft)
// {
//     std::cout << "Comparision test of " << testName << " with standard func : " << '\n';

//     std::cout << "Standard result: "
//               << std << '\n';
//     std::cout << "ft result: "
//               << ft << '\n';
//     if (std == ft)
//         std::cout << "✅" << '\n';
//     else
//         std::cout << "❌" << '\n';
// }

// void nonMemberComparison(std::string testName, bool std, bool ft)
// {
//     std::cout << "Comparision test of " << testName << " with standard func : " << '\n';
//     if (std == true)
//         std::cout << "Standard result: "
//                   << "true" << '\n';
//     else
//         std::cout << "Standard result: "
//                   << "false" << '\n';
//     if (ft == true)
//         std::cout << "ft result: "
//                   << "true" << '\n';
//     else
//         std::cout << "ft result: "
//                   << "false" << '\n';
//     if (std == ft)
//         std::cout << "✅" << '\n';
//     else
//         std::cout << "❌" << '\n';
// }

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

        ft::map<char, int> ft_first;
        ft_first['a'] = 10;
        ft::map<char, int>::iterator ft_it = ft_first.begin();
        std::cout << '\n';
        std::cout << ft_it->first << " => " << ft_it->second << '\n';
     
    }
    {
        // std::cout << "\n***************************************" << '\n';
        // std::cout << "\n      2-1.  clear" << '\n';
        // std::cout << "\n             " << '\n';
        // std::cout << "\n***************************************" << '\n';

        // std::map<char, int> mymap;
        // mymap['x'] = 100;
        // mymap['y'] = 200;
        // mymap['z'] = 300;

        // ft::map<char, int> ft_mymap;
        // ft_mymap['x'] = 100;
        // ft_mymap['y'] = 200;
        // ft_mymap['z'] = 300;

        // std::cout << "  mymap contains:\n";
        // for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        //     std::cout << it->first << " => " << it->second << '\n';

        // std::cout << "ft_mymap contains:\n";
        // for (ft::map<char, int>::iterator ft_it = ft_mymap.begin(); ft_it != ft_mymap.end(); ++ft_it)
        //     std::cout << ft_it->first << " => " << ft_it->second << '\n';
        // mymap.clear();
        // ft_mymap.clear();

        // mymap['a'] = 1101;
        // mymap['b'] = 2202;

        // ft_mymap['a'] = 1101;
        // ft_mymap['b'] = 2202;

        // std::cout << "  mymap contains:\n";
        // for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        //     std::cout << it->first << " => " << it->second << '\n';

        // std::cout << "ft_mymap contains:\n";
        // for (ft::map<char, int>::iterator ft_it = ft_mymap.begin(); ft_it != ft_mymap.end(); ++ft_it)
        //     std::cout << ft_it->first << " => " << ft_it->second << '\n';
    }
    return 0;
}