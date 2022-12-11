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
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

#ifdef STD
	#include <map>
	namespace ft = std;
#else
	#include "../include/map.hpp"
#endif

int main(void)
{
    ft::map<int, int> mymap;

    srand(time(NULL));

    for (int i = 0; i < 10000000; i++)
    {
        int key1 = rand() % 1000;
        int val1 = rand() % 1000;
        int key2 = rand() % 1000;

        mymap[key1] = val1;
        mymap.erase(key2);
    }

    for (ft::map<int, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << ": " << it->second << ", ";
    std::cout << "\n";

    for (ft::map<int, int>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); it++)
        std::cout << it->first << ": " << it->second << ", ";
    std::cout << "\n";

    std::cout << mymap.size() << "\n";

    return 0;
}