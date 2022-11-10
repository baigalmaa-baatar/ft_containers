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
#include "../include/Vector.hpp"

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
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      1. Default constructor" << '\n';
    std::cout << "\n***************************************" << '\n';
    /**
     * Empty vector test
     */

    std::vector<int> std_vector1;
    ft::vector<int> ft_vector1;

    comparisonFunc("Member function size() test", std_vector1.size(), ft_vector1.size());
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      2. Fill constructor" << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_vector1(4, 100);
    ft::vector<int> ft_vector1(4, 100);

    for (std::vector<int>::iterator it = std_vector1.begin(); it != std_vector1.end(); it++)
      std::cout << "Elements of STD: " << *it << '\n';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it != ft_vector1.end(); ft_it++)
      std::cout << "Elements of  FT: " << *ft_it << '\n';
    comparisonFunc("Member function size() test", std_vector1.size(), ft_vector1.size());
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      3. Range constructor" << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_vector1;
    std::vector<int> std_vector2;
    std::vector<int> ft_vector1;
    std::vector<int> ft_vector2;

    std_vector1.assign(7, 100);
    ft_vector1.assign(7, 100);

    std::vector<int>::iterator it;
    ft::vector<int>::iterator ft_it;
    it = std_vector1.begin() + 1;
    // ft_it = ft_vector1.begin() + 1;

    // std_vector2.assign(it, std_vector1.end() - 1);
    // ft_vector2.assign(ft_it, ft_vector1.end() - 1);

    // for (std::vector<int>::iterator it = std_vector1.begin(); it != std_vector1.end(); it++)
    //   std::cout << "Elements of STD: " << *it << '\n';
    // for (ft::vector<int>::iterator it = ft_vector1.begin(); it != ft_vector1.end(); it++)
    //   std::cout << "Elements of FT: " << *it << '\n';
    // comparisonFunc("Member function size() test", std_vector1.size(), ft_vector1.size());
  }
  // {
  //   std::cout << "\n***************************************" << '\n';
  //   std::cout << "\n      n. Bla bla bla " << '\n';
  //   std::cout << "\n***************************************" << '\n';

  //   std::vector<int> myvector(3, 100);
  //   std::vector<int>::iterator it;

  //   it = myvector.begin();
  //   it = myvector.insert(it, 200);

  //   myvector.insert(it, 2, 300);

  //   // "it" no longer valid, get a new one:
  //   it = myvector.begin();

  //   std::vector<int> anothervector(2, 400);
  //   myvector.insert(it + 2, anothervector.begin(), anothervector.end());

  //   int myarray[] = {501, 502, 503};
  //   myvector.insert(myvector.begin(), myarray, myarray + 3);

  //   std::cout << "myvector contains:";
  //   for (it = myvector.begin(); it < myvector.end(); it++)
  //     std::cout << ' ' << *it;
  //   std::cout << '\n';
  // }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      2-1.  vector::insert() " << '\n';
    std::cout << "\n            single element  " << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_vector1(4, 200);
    ft::vector<int> ft_vector1(4, 200);

    std::vector<int>::iterator it = std_vector1.begin();
    ft::vector<int>::iterator ft_it = ft_vector1.begin();
    std::cout << "std size : " << std_vector1.size() << " : "
              << "std capacity : " << std_vector1.capacity() << '\n';
    std::cout << " ft size : " << ft_vector1.size() << " : "
              << " ft capacity : " << ft_vector1.capacity() << '\n';
    std_vector1.insert(it, 2, 100);
    ft_vector1.insert(ft_it, 2, 100);
    std::cout << "std size : " << std_vector1.size() << " : "
              << "std capacity : " << std_vector1.capacity() << '\n';
    std::cout << " ft size : " << ft_vector1.size() << " : "
              << " ft capacity : " << ft_vector1.capacity() << '\n';
    // it = std_vector1.begin();
    // ft_it = ft_vector1.begin();
    // std::cout << "std size : " << std_vector1.size() << " : "
    //           << "std capacity : " << std_vector1.capacity() << '\n';
    // std_vector1.insert(it, 200);
    // std::cout << " ft size : " << ft_vector1.size() << " : "
    //           << " ft capacity : " << ft_vector1.capacity() << '\n';
    // ft_vector1.insert(ft_it, 200);
    // std::cout << "std size : " << std_vector1.size() << " : "
    //           << "std capacity : " << std_vector1.capacity() << '\n';
    // std::cout << " ft size : " << ft_vector1.size() << " : "
    //           << " ft capacity : " << ft_vector1.capacity() << '\n';
    // it = std_vector1.begin();
    // ft_it = ft_vector1.begin();
    // std_vector1.insert(it, 300);
    // ft_vector1.insert(ft_it, 300);
    for (std::vector<int>::iterator it = std_vector1.begin(); it != std_vector1.end(); it++)
      std::cout << "Elements of STD: " << *it << '\t';
    std::cout << '\n';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it != ft_vector1.end(); ft_it++)
      std::cout << "Elements of  FT: " << *ft_it << '\t';
    std::cout << '\n';
    comparisonFunc("Member function size() test", std_vector1.size(), ft_vector1.size());
  }
  // {
  //   std::cout << "\n***************************************" << '\n';
  //   std::cout << "\n      2-2.  vector::insert() " << '\n';
  //   std::cout << "\n            fill " << '\n';
  //   std::cout << "\n***************************************" << '\n';

  //   std::vector<int> std_vector1;
  //   std::vector<int> ft_vector1;

  //   std::vector<int>::iterator it = std_vector1.begin();
  //   std::vector<int>::iterator ft_it = ft_vector1.begin();
  //   std::cout << "std size : " << std_vector1.size() << " : "
  //             << "std capacity : " << std_vector1.capacity() << '\n';
  //   std_vector1.insert(it, 2, 100);
  //   std::cout << " ft size : " << ft_vector1.size() << " : "
  //             << " ft capacity : " << ft_vector1.capacity() << '\n';
  //   ft_vector1.insert(ft_it, 2, 100);
  //   it = std_vector1.begin();
  //   ft_it = ft_vector1.begin();
  //   std::cout << "std size : " << std_vector1.size() << " : "
  //             << "std capacity : " << std_vector1.capacity() << '\n';
  //   std_vector1.insert(it, 5, 200);
  //   std::cout << " ft size : " << ft_vector1.size() << " : "
  //             << " ft capacity : " << ft_vector1.capacity() << '\n';
  //   ft_vector1.insert(ft_it, 5, 200);
  //   std::cout << "std size : " << std_vector1.size() << " : "
  //             << "std capacity : " << std_vector1.capacity() << '\n';
  //   std::cout << " ft size : " << ft_vector1.size() << " : "
  //             << " ft capacity : " << ft_vector1.capacity() << '\n';
  //   for (std::vector<int>::iterator it = std_vector1.begin(); it != std_vector1.end(); it++)
  //     std::cout << "Elements of STD: " << *it << '\t';
  //   std::cout << '\n';
  //   for (std::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it != ft_vector1.end(); ft_it++)
  //     std::cout << "Elements of  FT: " << *ft_it << '\t';
  //   std::cout << '\n';
  //   comparisonFunc("Member function size() test", std_vector1.size(), ft_vector1.size());
  // }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      2-3.  vector::insert() " << '\n';
    std::cout << "\n            range " << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_vector1(3, 100);
    std::vector<int> myvector(3, 100);
    std::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert(it, 200);

    myvector.insert(it, 2, 300);

    // "it" no longer valid, get a new one:

    std::vector<int> anothervector(2, 400);
    std::cout << "before:" << '\n';
    for (it = myvector.begin(); it < myvector.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    it = myvector.begin();
    myvector.insert(it + 2, anothervector.begin(), anothervector.end());
    std::cout << "after:" << '\n';
    for (it = myvector.begin(); it < myvector.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';

    // int myarray[] = {501, 502, 503};
    // myvector.insert(myvector.begin(), myarray, myarray + 3);

    // std::cout << "myvector contains:";
    // for (it = myvector.begin(); it < myvector.end(); it++)
    //   std::cout << ' ' << *it;
    // std::cout << '\n';

    return 0;
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      2. vector::reserve " << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> myvector(3, 100);
    std::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert(it, 200);

    myvector.insert(it, 2, 300);

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    std::vector<int> anothervector(2, 400);
    myvector.insert(it + 2, anothervector.begin(), anothervector.end());

    int myarray[] = {501, 502, 503};
    myvector.insert(myvector.begin(), myarray, myarray + 3);

    std::cout << "myvector contains:";
    for (it = myvector.begin(); it < myvector.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }
  // {
  //   std::cout << "\n***************************************" << '\n';
  //   std::cout << "\n      n. Bla bla bla " << '\n';
  //   std::cout << "\n***************************************" << '\n';

  //   std::vector<int> first;
  //   std::vector<int> second;
  //   std::vector<int> third;

  //   first.assign(7, 100); // 7 ints with a value of 100

  //   std::vector<int>::iterator it;
  //   it = first.begin() + 1;

  //   // test for ft functions:

  //   // first.clear();
  //   // first.push_back(5);

  //   second.assign(it, first.end() - 1); // the 5 central values of first

  //   int myints[] = {1776, 7, 4};
  //   third.assign(myints, myints + 3); // assigning from array.

  //   std::cout << "\nElements of BEFORE assigning again: " << '\n';

  //   for (std::vector<int>::iterator it = third.begin(); it != third.end(); it++)
  //     std::cout << "Elements of third: " << *it << '\n';

  //   third.assign(5, 1);
  //   std::cout << "Size of first: " << int(first.size()) << '\n';
  //   std::cout << "Size of second: " << int(second.size()) << '\n';
  //   std::cout << "Size of third: " << int(third.size()) << '\n';
  //   for (std::vector<int>::iterator it = third.begin(); it != third.end(); it++)
  //     std::cout << "Elements of third: " << *it << '\n';
  // }

  // {
  //   std::cout << "\n***************************************" << '\n';
  //   std::cout << "\n      2. Parameter constructor" << '\n';
  //   std::cout << "\n***************************************" << '\n';
  //   /**
  //    * Empty vector test
  //    */

  //   std::vector<int> std_vector1(4, 100); // four ints with value 100
  //   ft::vector<int> ft_vector1(4, 100); // four ints with value 100

  //   for (int i = 0; i < 42; i++)
  //   {
  //     std_vector1.push_back(i);
  //     ft_vector1.push_back(i);
  //   }

  //   comparisonFunc("Member function size() test", std_vector1.size(), ft_vector1.size());
  // }
  /*
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
  */
  // {
  //   std::cout << "\n***************************************" << '\n';
  //   std::cout << "\n          Vector container test" << '\n';
  //   std::cout << "\n***************************************" << '\n';

  //   // constructors used in the same order as described above:
  //   std::vector<int> first;          // empty vector of ints
  //   std::vector<int> second(4, 100); // four ints with value 100

  //   /**
  //    *         explicit vector (size_type n, const value_type& val = value_type(),
  //                const allocator_type& alloc = allocator_type()) :
  //                size_type(n), value_type(val), allocator_type(alloc)
  //   */
  //   std::vector<int> third(second.begin(), second.end()); // iterating through second
  //   std::vector<int> fourth(third);                       // a copy of third

  //   std::cout << "\n***************************************" << '\n';
  //   std::cout << "\n     The contents of first_ft are:;" << '\n';
  //   std::cout << "\n***************************************" << '\n';
  //   // the iterator constructor can also be used to construct from arrays:
  //   int myints[] = {16, 2, 77, 29};
  //   std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
  //   for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
  //     std::cout << ' ' << *it;
  //   std::cout << '\n';
  // }
  // {
  //   std::cout << "\n***************************************" << '\n';
  //   std::cout << "\n      1. Default constructor" << '\n';
  //   std::cout << "\n***************************************" << '\n';
  //   ft::vector<int> first_ft;
  //   std::vector<int> first_std; // four ints with value 100

  //   first_ft.push_back(21);
  //   first_ft.push_back(42);
  //   first_std.push_back(21);
  //   first_std.push_back(42);
  //   for (ft::vector<int>::iterator it = first_ft.begin(); it != first_ft.end(); ++it)
  //     std::cout << ' ' << *it;
  //   std::cout << '\n';

  //   for (std::vector<int>::iterator it = first_std.begin(); it != first_std.end(); ++it)
  //     std::cout << ' ' << *it;
  //   std::cout << '\n';
  // }
  return 0;
}
