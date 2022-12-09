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
#include <iomanip>
#include <list>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>

#ifdef STD
	#include <map>
	namespace ft = std;
#else
	#include "../map.hpp"
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

void	testing_constructors()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      1-1.  Constructor" << '\n';
    std::cout << "\n            Default" << '\n';
    std::cout << "\n***************************************" << '\n';

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
    std::cout << "STD mymap contains:\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    for (it = third.begin(); it != third.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}
void testing_operator_equal()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      2-1.  operator=() " << '\n';
    std::cout << "\n            Default" << '\n';
    std::cout << "\n***************************************" << '\n';

    ft::map<char, int> first;
    ft::map<char, int> second;

    first['x'] = 8;
    first['y'] = 16;
    first['z'] = 32;

    second = first;                // second now contains 3 ints
    first = ft::map<char, int>(); // and first is now empty

    std::cout << "Size of first: " << first.size() << '\n';
    std::cout << "Size of second: " << second.size() << '\n';
    ft::map<char, int>::iterator s_it = second.begin();
    std::cout << '\n';
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout << "STD mymap contains:\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    for (s_it = second.begin(); s_it != second.end(); ++s_it)
        std::cout << s_it->first << " => " << s_it->second << '\n';
}
void testing_iterator()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      3-1.  iterator " << '\n';
    std::cout << "\n            begin, end" << '\n';
    std::cout << "\n***************************************" << '\n';

    ft::map<char, int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    std::cout << '\n';
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout << "STD mymap contains:\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}
void testing_iterator2()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      3-1.  iterator " << '\n';
    std::cout << "\n            rbegin, rend" << '\n';
    std::cout << "\n***************************************" << '\n';

    ft::map<char, int> mymap;

    mymap['x'] = 100;
    mymap['y'] = 200;
    mymap['z'] = 300;

    std::cout << '\n';
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout << "STD mymap contains:\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    ft::map<char, int>::reverse_iterator rit;
    for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
        std::cout << rit->first << " => " << rit->second << '\n';
}
void testing_insert()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n       4-1.  insert " << '\n';
    std::cout << "\n                   " << '\n';
    std::cout << "\n***************************************" << '\n';

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
void testing_erase()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n       5-1.  erase " << '\n';
    std::cout << "\n                   " << '\n';
    std::cout << "\n***************************************" << '\n';

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
    std::cout << "STD mymap contains:\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    for (it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}
void testing_bounds()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n       6-1.  lower bound " << '\n';
    std::cout << "\n                   " << '\n';
    std::cout << "\n***************************************" << '\n';

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
    std::cout << " STD mymap contains:\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}
void testing_empty()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n       7-1.  empty " << '\n';
    std::cout << "\n                   " << '\n';
    std::cout << "\n***************************************" << '\n';

    ft::map<char, int> mymap;

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
void testing_iterator3()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n       8-1.iterator " << '\n';
    std::cout << "\n           begin        " << '\n';
    std::cout << "\n***************************************" << '\n';

    ft::map<char, int> mymap;
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
void testing_size()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n       9. size" << '\n';
    std::cout << "\n                   " << '\n';
    std::cout << "\n***************************************" << '\n';

    ft::map<char, int> mymap;
    mymap['a'] = 101;
    mymap['b'] = 202;
    mymap['c'] = 302;

    std::cout << '\n';
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout << " STD mymap contains:\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout << "mymap.size() is " << mymap.size() << '\n';
}
void testing_size2()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n       10. size" << '\n';
    std::cout << "\n                   " << '\n';
    std::cout << "\n***************************************" << '\n';

    ft::map<char, std::string> mymap;

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
void testing_swap()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n       11. swap" << '\n';
    std::cout << "\n                   " << '\n';
    std::cout << "\n***************************************" << '\n';
    ft::map<char, int> foo, bar;

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
    for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "bar contains:\n";
    for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}
void testing_clear()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n       12. clear" << '\n';
    std::cout << "\n                   " << '\n';
    std::cout << "\n***************************************" << '\n';

    ft::map<char, int> mymap;

    mymap['x'] = 100;
    mymap['y'] = 200;
    mymap['z'] = 300;

    std::cout << '\n';
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout << " STD mymap contains:\n";
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
void testing_key_comp()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n       13. key_comp" << '\n';
    std::cout << "\n                   " << '\n';
    std::cout << "\n***************************************" << '\n';

    ft::map<char, int> mymap;

    ft::map<char, int>::key_compare mycomp = mymap.key_comp();

    mymap['a'] = 100;
    mymap['b'] = 200;
    mymap['c'] = 300;

    std::cout << '\n';
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout << "STD mymap contains:\n";
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
void testing_value_comp()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n       14. value_comp" << '\n';
    std::cout << "\n                   " << '\n';
    std::cout << "\n***************************************" << '\n';

    ft::map<char, int> mymap;

    mymap['x'] = 1001;
    mymap['y'] = 2002;
    mymap['z'] = 3003;
    std::cout << '\n';
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout << "STD mymap contains:\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout << "mymap contains:\n";

    ft::pair<char, int> highest = *mymap.rbegin(); // last element

    ft::map<char, int>::iterator it = mymap.begin();
    do
    {
        std::cout << it->first << " => " << it->second << '\n';
    } while (mymap.value_comp()(*it++, highest));
}
void testing_find()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n       15. find" << '\n';
    std::cout << "\n                   " << '\n';
    std::cout << "\n***************************************" << '\n';

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
    std::cout << "STD mymap contains:\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << mymap.find('a')->second << '\n';
    std::cout << "c => " << mymap.find('c')->second << '\n';
    std::cout << "d => " << mymap.find('d')->second << '\n';
}
void testing_count()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n       16. count" << '\n';
    std::cout << "\n                   " << '\n';
    std::cout << "\n***************************************" << '\n';
    ft::map<char, int> mymap;
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
void testing_comp_const_iterator()
{
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n       17. comp const iterator" << '\n';
    std::cout << "\n                   " << '\n';
    std::cout << "\n***************************************" << '\n';

    ft::map<char, float> mp;

    mp['a'] = 2.3;
    mp['b'] = 1.4;
    mp['c'] = 0.3;
    mp['d'] = 4.2;

    ft::map<char, float>::const_iterator it1 = mp.begin();
    ft::map<char, float>::const_iterator it2 = mp.begin();

    for (it1 = mp.begin(); it1 != mp.end(); ++it1)
    {
        for (it2 = mp.begin(); it2 != mp.end(); ++it2)
        {
            std::cout << "it1 : << " << it1->first << " => " << it1->second << '\n';
            std::cout << "it2 : << " << it2->first << " => " << it2->second << '\n';
        }
    }
}

int main(void)
{
    // srand(SEED);

    std::cout << "Map test starts:" << std::endl;

    testing_constructors();
    testing_insert();
    testing_erase();
    testing_swap();
    testing_clear();
    testing_empty();
    testing_operator_equal();
    testing_key_comp();
    testing_value_comp();
    testing_find();
    testing_count();
    testing_bounds();
    // testing_getalloc();
    testing_iterator();
    testing_iterator2();
    testing_iterator3();
    testing_size();
    testing_size2();
    testing_comp_const_iterator();

    std::cout << "Map test finished." << std::endl;

    return (0);
}