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
#include <map>
#include "../include/map.hpp"
#include <iomanip>
#include <string>

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};

int main()
{
    // {
    //     NS::map<char, int> first;

    //     first['a'] = 10;
    //     first['b'] = 30;
    //     first['c'] = 50;
    //     first['d'] = 70;

    //     NS::map<char, int> second(first.begin(), first.end());

    //     NS::map<char, int> third(second);

    //     // NS::map<char, int, classcomp> fourth; // class as Compare

    //     // bool (*fn_pt)(char, char) = fncomp;
    //     // NS::map<char, int, bool (*)(char, char)> fifth(fn_pt); // function pointer as Compare

    //     NS::map<char, int>::iterator it = third.begin();
    //     std::cout << "   mymap contains:\n";
    //     for (it = third.begin(); it != third.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
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
        std::map<char, int, classcomp> fourth;
        bool (*fn_pt)(char, char) = fncomp;
        std::map<char, int, bool (*)(char, char)> fifth(fn_pt);

        std::map<char, int>::iterator it = third.begin();
        std::cout << "   mymap contains:\n";
        for (it = third.begin(); it != third.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        ft::map<char, int> first;

        first['a'] = 10;
        first['b'] = 30;
        first['c'] = 50;
        first['d'] = 70;

        ft::map<char, int> second(first.begin(), first.end());
        ft::map<char, int> third(second);
        ft::map<char, int, classcomp> fourth;
        bool (*fn_pt)(char, char) = fncomp;
        ft::map<char, int, bool (*)(char, char)> fifth(fn_pt);

        ft::map<char, int>::iterator it = third.begin();
        std::cout << "   mymap contains:\n";
        for (it = third.begin(); it != third.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n      2-1.  operator=() " << '\n';
        std::cout << "\n            Default" << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> first;
        std::map<char, int> second;

        first['x'] = 8;
        first['y'] = 16;
        first['z'] = 32;

        second = first;                // second now contains 3 ints
        first = std::map<char, int>(); // and first is now empty

        std::cout << "Size of first: " << first.size() << '\n';
        std::cout << "Size of second: " << second.size() << '\n';

        std::map<char, int>::iterator it = first.begin();
        std::cout << "\nfirst contains:\n";
        for (it = first.begin(); it != first.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::map<char, int>::iterator s_it = second.begin();
        std::cout << "\nsecond contains:\n";
        for (s_it = second.begin(); s_it != second.end(); ++s_it)
            std::cout << s_it->first << " => " << s_it->second << '\n';
    }
    {
        ft::map<char, int> first;
        ft::map<char, int> second;

        first['x'] = 8;
        first['y'] = 16;
        first['z'] = 32;

        second = first;               // second now contains 3 ints
        first = ft::map<char, int>(); // and first is now empty

        std::cout << "Size of first: " << first.size() << '\n';
        std::cout << "Size of second: " << second.size() << '\n';

        ft::map<char, int>::iterator it = first.begin();
        std::cout << "\nfirst contains:\n";
        for (it = first.begin(); it != first.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        ft::map<char, int>::iterator s_it = second.begin();
        std::cout << "\nsecond contains:\n";
        for (s_it = second.begin(); s_it != second.end(); ++s_it)
            std::cout << s_it->first << " => " << s_it->second << '\n';
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n      3-1.  iterator " << '\n';
        std::cout << "\n            begin, end" << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> mymap;

        mymap['b'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;

        std::cout << "show content:" << '\n';
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        ft::map<char, int> mymap;

        mymap['b'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;

        std::cout << "show content:" << '\n';
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n      NOT GOOD 3-1.  iterator " << '\n';
        std::cout << "\n            rbegin, rend" << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> mymap;

        // mymap['d'] = 300;
        // mymap['e'] = 300;
        // mymap['f'] = 300;
        mymap['e'] = 100;
        mymap['d'] = 200;
        mymap['c'] = 300;
        mymap['b'] = 400;
        mymap['a'] = 500;

        std::cout << "show content:" << '\n';
        std::map<char, int>::reverse_iterator rit;
        for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
    }
    {
        ft::map<char, int> mymap;

        // mymap['d'] = 300;
        // mymap['e'] = 300;
        // mymap['f'] = 300;
        mymap['e'] = 100;
        mymap['d'] = 200;
        mymap['c'] = 300;
        mymap['b'] = 400;
        mymap['a'] = 500;

        std::cout << "show content:" << '\n';
        ft::map<char, int>::reverse_iterator rit;
        for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       4-1.  erase " << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> mymap;
        std::map<char, int>::iterator it;

        // insert some values:
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;
        mymap['d'] = 40;
        mymap['e'] = 50;
        mymap['f'] = 60;

        it = mymap.find('a');
        mymap.erase(it); // erasing by iterator

        mymap.erase('c'); // erasing by key

        it = mymap.find('e');
        mymap.erase(it, mymap.end()); // erasing by range

        std::cout << "std show content : " << '\n';
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    // {
    //     ft::map<char, int> mymap;
    //     ft::map<char, int>::iterator it;

    //     mymap['a'] = 10;
    //     mymap['b'] = 20;
    //     mymap['c'] = 30;
    //     mymap['d'] = 40;
    //     mymap['e'] = 50;
    //     mymap['f'] = 60;

    //     it = mymap.find('a');
    //     mymap.erase(it); // erasing by iterator

    //     mymap.erase('c'); // erasing by key

    //     it = mymap.find('e');
    //     mymap.erase(it, mymap.end()); // erasing by range

    //     std::cout << "ft show content : " << '\n';
    //     for (it = mymap.begin(); it != mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       6-1.  lower bound " << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> mymap;
        std::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;

        itlow = mymap.lower_bound('b'); // itlow points to b
        itup = mymap.upper_bound('d');  // itup points to e (not d!)

        std::cout << "itlow : " << itlow->first << '\n';
        std::cout << "itup : " << itup->first << '\n';
        mymap.erase(itlow, itup); // erases [itlow,itup)

        std::cout << "std show content : " << '\n';
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        ft::map<char, int> mymap;
        ft::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;

        mymap.erase('b'); // erases [itlow,itup)
        mymap.erase('c'); // erases [itlow,itup)
        mymap.erase('d'); // erases [itlow,itup)

        std::cout << "std show content : " << '\n';
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    return 0;
}