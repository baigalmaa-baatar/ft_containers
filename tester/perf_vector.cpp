/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perf_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:12:14 by bbaatar           #+#    #+#             */
/*   Updated: 2022/12/11 14:12:16 by bbaatar          ###   ########.fr       */
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
	#include <vector>
	namespace ft = std;
#else
	#include "../include/vector.hpp"
#endif

int main(void)
{
    ft::vector<int> myvector;

    srand(time(NULL));

    int sum (0);
    for (int i = 0; i < 20000000; i++)
    {
        myvector.push_back (rand() % 1000);
    }
    while (!myvector.empty())
    {
        sum+=myvector.back();
        myvector.pop_back();
    }

    std::cout << "The elements of myvector add up to " << sum << '\n';
    std::cout << myvector.size() << "\n";

    return 0;
}
