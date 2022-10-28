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
#include <vector> // std::vector
// #include "../include/Vector.hpp"

int main(void)
{
  {
    std::vector<int> ft_vector;
    std::vector<int> std_vector;

    // Testing member functions:
    for (int i = 0; i < 5; i++)
      ft_vector.push_back(i);
    for (int i = 0; i < 5; i++)
      std_vector.push_back(i);

    std::cout << '\n'
              << "0.empty" << '\n';
    std::cout << "ft empty: " << ft_vector.empty() << '\n';
    std::cout << "std empty: " << std_vector.empty() << '\n';

    std::cout << '\n'
              << "1.size" << '\n';
    std::cout << "ft size: " << ft_vector.size() << '\n';
    std::cout << "std size: " << std_vector.size() << '\n';

    std::cout << '\n'
              << "2.top" << '\n';
    //   std::cout << "ft top: " << ft_vector.top() << '\n';
    //   std::cout << "std top: " << std_vector.top() << '\n';

    std::cout << '\n'
              << "3.top const" << '\n';
    //   std::cout << "ft top const: " << ft_vector.top() << '\n';
    //   std::cout << "std top const: " << std_vector.top() << '\n';

    std::cout << '\n'
              << "4.push" << '\n';
    for (int i = 5; i < 10; i++)
      ft_vector.push_back(i);
    for (int i = 5; i < 10; i++)
      std_vector.push_back(i);
    std::cout << "ft size: " << ft_vector.size() << '\n';
    std::cout << "std size: " << std_vector.size() << '\n';

    std::cout << '\n'
              << "5.pop" << '\n';
    ft_vector.pop_back();
    std_vector.pop_back();
    std::cout << "ft_size: " << ft_vector.size() << '\n';
    std::cout << "size: " << std_vector.size() << '\n';
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n   std::vector<int> second(4, 100); " << '\n';
    std::cout << "\n***************************************" << '\n';
    std::vector<int> second(4, 100); // four ints with value 100
    for (std::vector<int>::iterator it = second.begin(); it != second.end(); it++)
      std::cout << *it << '\n';
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n   myvector.get_allocator().allocate(5);" << '\n';
    std::cout << "\n***************************************" << '\n';
    std::vector<int> myvector;
    int *p;
    unsigned int i;

    // allocate an array with space for 5 elements using vector's allocator:
    p = myvector.get_allocator().allocate(5);

    // construct values in-place on the array:
    for (i = 0; i < 5; i++)
      myvector.get_allocator().construct(&p[i], i);

    std::cout << "The allocated array contains:";
    for (i = 0; i < 5; i++)
      std::cout << ' ' << p[i];
    std::cout << '\n';

    // destroy and deallocate:
    for (i = 0; i < 5; i++)
      myvector.get_allocator().destroy(&p[i]);
    myvector.get_allocator().deallocate(p, 5);
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n          Vector container test" << '\n';
    std::cout << "\n***************************************" << '\n';

    // constructors used in the same order as described above:
    std::vector<int> first;          // empty vector of ints
    std::vector<int> second(4, 100); // four ints with value 100

    /**
     *         explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()) :
                 size_type(n), value_type(val), allocator_type(alloc)
    */
    std::vector<int> third(second.begin(), second.end()); // iterating through second
    std::vector<int> fourth(third);                       // a copy of third

    std::cout << "\n***************************************" << '\n';
    std::cout << "\n     The contents of fifth are:;" << '\n';
    std::cout << "\n***************************************" << '\n';
    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16, 2, 77, 29};
    std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
    for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }
  return 0;
}
