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
#include <list>
#include <algorithm>

#ifndef NS
#define NS = ft
#endif
static unsigned int i = 0;

#define T1 char
#define T2 float
typedef ft::map<T1, T2> _map;
typedef _map::const_iterator const_it;

void ft_comp(const _map &mp, const const_it &it1, const const_it &it2)
{
    bool res[2];

    std::cout << "\t-- [" << ++i << "] --" << std::endl;
    res[0] = mp.key_comp()(it1->first, it2->first);
    res[1] = mp.value_comp()(*it1, *it2);
    std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
    std::cout << "key_comp: " << res[0] << " | "
              << "value_comp: " << res[1] << std::endl;
}

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};
bool mypredicate(int i, int j)
{
    return (i == j);
}

int main()
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
        std::map<char, int, classcomp> fourth;
        bool (*fn_pt)(char, char) = fncomp;
        std::map<char, int, bool (*)(char, char)> fifth(fn_pt);

        std::map<char, int>::iterator it = third.begin();
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
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
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
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
        std::map<char, int>::iterator s_it = second.begin();
        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
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
        first = ft::map<char, int>(); // and first is now empty //need to fix

        std::cout << "Size of first: " << first.size() << '\n';
        std::cout << "Size of second: " << second.size() << '\n';
        ft::map<char, int>::iterator s_it = second.begin();
        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
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

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        ft::map<char, int> mymap;

        mymap['b'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }

    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n      3-1.  iterator " << '\n';
        std::cout << "\n            rbegin, rend" << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::map<char, int>::reverse_iterator rit;
        for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
    }
    {
        ft::map<char, int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        ft::map<char, int>::reverse_iterator rit;
        for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       4-1.  insert " << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';

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
        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "STD another mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        for (it = anothermap.begin(); it != anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        ft::map<char, int> mymap;

        // first insert function version (single parameter):
        mymap.insert(ft::pair<char, int>('a', 100));
        mymap.insert(ft::pair<char, int>('z', 200));

        ft::pair<ft::map<char, int>::iterator, bool> ret;
        ret = mymap.insert(ft::pair<char, int>('z', 500));
        if (ret.second == false)
        {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }

        // second insert function version (with hint position):
        ft::map<char, int>::iterator it = mymap.begin();
        mymap.insert(it, ft::pair<char, int>('b', 300)); // max efficiency inserting
        mymap.insert(it, ft::pair<char, int>('c', 400)); // no max efficiency inserting

        // third insert function version (range insertion):
        ft::map<char, int> anothermap;
        anothermap.insert(mymap.begin(), mymap.find('c'));

        // showing contents:
        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " FT another mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        for (it = anothermap.begin(); it != anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       5-1.  erase " << '\n';
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

        it = mymap.find('b');
        mymap.erase(it); // erasing by iterator

        mymap.erase('c'); // erasing by key

        it = mymap.find('e');
        mymap.erase(it, mymap.end()); // erasing by range

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }

    {
        ft::map<char, int> mymap;
        ft::map<char, int>::iterator it;

        // insert some values:
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;
        mymap['d'] = 40;
        mymap['e'] = 50;
        mymap['f'] = 60;

        it = mymap.find('b');
        mymap.erase(it); // erasing by iterator

        mymap.erase('c'); // erasing by key

        it = mymap.find('e');
        mymap.erase(it, mymap.end()); // erasing by range

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
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

        mymap.erase(itlow, itup); // erases [itlow,itup)

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
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

        itlow = mymap.lower_bound('b'); // itlow points to b
        itup = mymap.upper_bound('d');  // itup points to e (not d!)

        mymap.erase(itlow, itup); // erases [itlow,itup)

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "  FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       7-1.  empty " << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> mymap;

        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        while (!mymap.empty())
        {
            std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
            mymap.erase(mymap.begin());
        }
    }
    {
        ft::map<char, int> mymap;

        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "  FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";

        while (!mymap.empty())
        {
            std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
            mymap.erase(mymap.begin());
        }
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       8-1.iterator " << '\n';
        std::cout << "\n           begin        " << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> mymap;
        mymap['a'] = 10;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        while (!mymap.empty())
        {
            std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
            mymap.erase(mymap.begin());
        }
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       8-1.iterator " << '\n';
        std::cout << "\n           begin        " << '\n';
        std::cout << "\n***************************************" << '\n';

        ft::map<char, int> mymap;
        mymap['a'] = 10;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        while (!mymap.empty())
        {
            std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
            mymap.erase(mymap.begin());
        }
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       9. size" << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> mymap;
        mymap['a'] = 101;
        mymap['b'] = 202;
        mymap['c'] = 302;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "mymap.size() is " << mymap.size() << '\n';
    }
    {
        ft::map<char, int> mymap;
        mymap['a'] = 101;
        mymap['b'] = 202;
        mymap['c'] = 302;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "mymap.size() is " << mymap.size() << '\n';
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       10. size" << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, std::string> mymap;

        mymap['a'] = "an element";
        mymap['b'] = "another element";
        mymap['c'] = mymap['b'];

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";

        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';

        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    }
    {
        ft::map<char, std::string> mymap;

        mymap['a'] = "an element";
        mymap['b'] = "another element";
        mymap['c'] = mymap['b'];

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "  FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";

        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';

        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       11. swap" << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';
        std::map<char, int> foo, bar;

        foo['x'] = 100;
        foo['y'] = 200;

        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;

        foo.swap(bar);

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";

        std::cout << "foo contains:\n";
        for (std::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "bar contains:\n";
        for (std::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        ft::map<char, int> foo, bar;

        foo['x'] = 100;
        foo['y'] = 200;

        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;

        foo.swap(bar);

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";

        std::cout << "foo contains:\n";
        for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "bar contains:\n";
        for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       12. clear" << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";

        std::cout << "mymap contains:\n";
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        mymap.clear();
        mymap['a'] = 1101;
        mymap['b'] = 2202;

        std::cout << "mymap contains:\n";
        for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        ft::map<char, int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";

        std::cout << "mymap contains:\n";
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        mymap.clear();
        mymap['a'] = 1101;
        mymap['b'] = 2202;

        std::cout << "mymap contains:\n";
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       13. key_comp" << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> mymap;

        std::map<char, int>::key_compare mycomp = mymap.key_comp();

        mymap['a'] = 100;
        mymap['b'] = 200;
        mymap['c'] = 300;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "mymap contains:\n";

        char highest = mymap.rbegin()->first; // key value of last element

        std::map<char, int>::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mycomp((*it++).first, highest));

        std::cout << '\n';
    }
    {
        ft::map<char, int> mymap;

        ft::map<char, int>::key_compare mycomp = mymap.key_comp();

        mymap['a'] = 100;
        mymap['b'] = 200;
        mymap['c'] = 300;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "mymap contains:\n";

        char highest = mymap.rbegin()->first; // key value of last element

        ft::map<char, int>::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mycomp((*it++).first, highest));

        std::cout << '\n';
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       14. value_comp" << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> mymap;

        mymap['x'] = 1001;
        mymap['y'] = 2002;
        mymap['z'] = 3003;
        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "mymap contains:\n";

        std::pair<char, int> highest = *mymap.rbegin(); // last element

        std::map<char, int>::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mymap.value_comp()(*it++, highest));
    }
    {
        ft::map<char, int> mymap;

        mymap['x'] = 1001;
        mymap['y'] = 2002;
        mymap['z'] = 3003;
        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " Ft mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "mymap contains:\n";

        ft::pair<char, int> highest = *mymap.rbegin(); // last element

        ft::map<char, int>::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mymap.value_comp()(*it++, highest));
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       15. find" << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, int> mymap;
        std::map<char, int>::iterator it;

        mymap['a'] = 50;
        mymap['b'] = 100;
        mymap['c'] = 150;
        mymap['d'] = 200;

        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase(it);

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "elements in mymap:" << '\n';
        std::cout << "a => " << mymap.find('a')->second << '\n';
        std::cout << "c => " << mymap.find('c')->second << '\n';
        std::cout << "d => " << mymap.find('d')->second << '\n';
    }
    {
        ft::map<char, int> mymap;
        ft::map<char, int>::iterator it;

        mymap['a'] = 50;
        mymap['b'] = 100;
        mymap['c'] = 150;
        mymap['d'] = 200;

        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase(it);

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "elements in mymap:" << '\n';
        std::cout << "a => " << mymap.find('a')->second << '\n';
        std::cout << "c => " << mymap.find('c')->second << '\n';
        std::cout << "d => " << mymap.find('d')->second << '\n';
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       16. count" << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';
        std::map<char, int> mymap;
        char c;

        mymap['a'] = 101;
        mymap['c'] = 202;
        mymap['f'] = 303;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        for (c = 'a'; c < 'h'; c++)
        {
            std::cout << c;
            if (mymap.count(c) > 0)
                std::cout << " is an element of mymap.\n";
            else
                std::cout << " is not an element of mymap.\n";
        }
    }
    {
        ft::map<char, int> mymap;
        char c;

        mymap['a'] = 101;
        mymap['c'] = 202;
        mymap['f'] = 303;

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << " FT mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        for (c = 'a'; c < 'h'; c++)
        {
            std::cout << c;
            if (mymap.count(c) > 0)
                std::cout << " is an element of mymap.\n";
            else
                std::cout << " is not an element of mymap.\n";
        }
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       17. comp const iterator" << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<char, float> mp;

        mp['a'] = 2.3;
        mp['b'] = 1.4;
        mp['c'] = 0.3;
        mp['d'] = 4.2;

        std::map<char, float>::const_iterator it1 = mp.begin();
        std::map<char, float>::const_iterator it2 = mp.begin();

        for (it1 = mp.begin(); it1 != mp.end(); ++it1)
        {
            for (it2 = mp.begin(); it2 != mp.end(); ++it2)
            {
                std::cout << "it1 : << " << it1->first << " => " << it1->second << '\n';
                std::cout << "it2 : << " << it2->first << " => " << it2->second << '\n';
            }
        }
    }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       18. comp const iterator" << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';

        std::map<int, std::string> mp2;

        mp2.insert(mp2.begin(), std::pair<int, std::string>(21, "fizz"));
        mp2.insert(mp2.begin(), std::pair<int, std::string>(1337, "beauty"));
        mp2.insert(mp2.begin(), std::pair<int, std::string>(1000, "Hello"));
        mp2.insert(mp2.begin(), std::pair<int, std::string>(1500, "World"));

        std::cout << '\n';
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "STD mymap contains:\n";
        std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        std::cout << "mymap contains:\n";
        for (std::map<int, std::string>::iterator it = mp2.begin(); it != mp2.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    // {
    //     ft::map<int, std::string> mp2;
    //     ft::map<int, std::string>::iterator it1 = mp2.begin();

    //     mp2.insert(mp2.begin(), ft::pair<int, std::string>(21, "fizz"));
    //     mp2.insert(mp2.begin(), ft::pair<int, std::string>(1337, "beauty"));
    //     mp2.insert(mp2.begin(), ft::pair<int, std::string>(1000, "Hello"));
    //     mp2.insert(mp2.begin(), ft::pair<int, std::string>(1500, "World"));

    //     std::cout << '\n';
    //     std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    //     std::cout << "STD mymap contains:\n";
    //     std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    //     std::cout << "mymap contains:\n";
    //     for (ft::map<int, std::string>::iterator it = mp2.begin(); it != mp2.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
    {
        std::cout << "\n***************************************" << '\n';
        std::cout << "\n       19. const iterator" << '\n';
        std::cout << "\n                   " << '\n';
        std::cout << "\n***************************************" << '\n';

        // std::map<char, float> mp;

        // mp['a'] = 2.3;
        // mp['b'] = 1.4;
        // mp['c'] = 0.3;
        // mp['d'] = 4.2;

        // // mp.printTree();
        // for (std::map<char, float>::const_iterator it1 = mp.begin(); it1 != mp.end(); ++it1)
        // {
        //     for (std::map<char, float>::const_iterator it2 = mp.begin(); it2 != mp.end(); ++it2)
        //     {
        //         ft_comp(mp, it1, it2);
        //     }
        // }
    }
    {
        ft::map<char, float> mp;

        mp['a'] = 2.3;
        mp['b'] = 1.4;
        mp['c'] = 0.3;
        mp['d'] = 4.2;

        // mp.printTree();
        for (ft::map<char, float>::const_iterator it1 = mp.begin(); it1 != mp.end(); ++it1)
        {
            for (ft::map<char, float>::const_iterator it2 = mp.begin(); it2 != mp.end(); ++it2)
            {
                ft_comp(mp, it1, it2);
            }
        }

    }
    return 0;
}