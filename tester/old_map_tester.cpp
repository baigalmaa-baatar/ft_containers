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
using namespace std::literals;

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
        first['b'] = 30;
        first['c'] = 50;
        first['d'] = 70;

        std::map<char, int> second(first.begin(), first.end());

        std::map<char, int> third(second);

        std::map<char, int, classcomp> fourth; // class as Compare

        bool (*fn_pt)(char, char) = fncomp;
        std::map<char, int, bool (*)(char, char)> fifth(fn_pt); // function pointer as Compare
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
        std::map<char, int>::iterator it = mymap.begin();
        // mymap.insert(it, std::pair<char, int>('b', 300)); // max efficiency inserting
        // mymap.insert(it, std::pair<char, int>('c', 400)); // no max efficiency inserting

        // // third insert function version (range insertion):
        // std::map<char, int> anothermap;
        // anothermap.insert(mymap.begin(), mymap.find('c'));

        // showing contents:
        std::cout << "mymap contains:\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        // std::cout << "anothermap contains:\n";
        // for (it = anothermap.begin(); it != anothermap.end(); ++it)
        //     std::cout << it->first << " => " << it->second << '\n';
    }
    {
        std::map<std::string, float> heights;

        // Overload 3: insert from rvalue reference
        const auto [it_hinata, success] = heights.insert({"Hinata"s, 162.8});
        print_insertion_status(it_hinata, success);

        {
            // Overload 1: insert from lvalue reference
            const auto [it, success2] = heights.insert(*it_hinata);
            print_insertion_status(it, success2);
        }
        {
            // Overload 2: insert via forwarding to emplace
            const auto [it, success] = heights.insert(std::pair{"Kageyama", 180.6});
            print_insertion_status(it, success);
        }

        {
            // Overload 6: insert from rvalue reference with positional hint
            const std::size_t n = std::size(heights);
            const auto it = heights.insert(it_hinata, {"Azumane"s, 184.7});
            print_insertion_status(it, std::size(heights) != n);
        }
        {
            // Overload 4: insert from lvalue reference with positional hint
            const std::size_t n = std::size(heights);
            const auto it = heights.insert(it_hinata, *it_hinata);
            print_insertion_status(it, std::size(heights) != n);
        }
        {
            // Overload 5: insert via forwarding to emplace with positional hint
            const std::size_t n = std::size(heights);
            const auto it = heights.insert(it_hinata, std::pair{"Tsukishima", 188.3});
            print_insertion_status(it, std::size(heights) != n);
        }

        auto node_hinata = heights.extract(it_hinata);
        std::map<std::string, float> heights2;

        // Overload 7: insert from iterator range
        heights2.insert(std::begin(heights), std::end(heights));

        // Overload 8: insert from initializer_list
        heights2.insert({{"Kozume"s, 169.2}, {"Kuroo", 187.7}});

        // Overload 9: insert node
        const auto status = heights2.insert(std::move(node_hinata));
        print_insertion_status(status.position, status.inserted);

        node_hinata = heights2.extract(status.position);
        {
            // Overload 10: insert node with positional hint
            const std::size_t n = std::size(heights2);
            const auto it = heights2.insert(std::begin(heights2), std::move(node_hinata));
            print_insertion_status(it, std::size(heights2) != n);
        }

        // Print resulting map
        std::cout << std::left << '\n';
        for (const auto &[name, height] : heights2)
            std::cout << std::setw(10) << name << " | " << height << "cm\n";
    }
    return 0;
}