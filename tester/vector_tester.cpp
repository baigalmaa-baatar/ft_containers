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

template <typename T>
void comparisonFuncVec(std::string testName, std::vector<T> std_vector1, ft::vector<T> ft_vector1)
{
  std::cout << "Comparision test of " << testName << " with standard func : " << '\n';

  if (std_vector1 == ft_vector1)
  {
    std::cout << "matched" << std::endl;
  }
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

int main(void)
{
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      1-1.  Constructor" << '\n';
    std::cout << "\n            Default" << '\n';
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
    std::cout << "\n      1-2.  Constructor" << '\n';
    std::cout << "\n            Fill" << '\n';
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
    std::cout << "\n      1-3.  Constructor" << '\n';
    std::cout << "\n            Range" << '\n';
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
    std::cout << "\n      2-1. push-back " << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_vector1;
    ft::vector<int> ft_vector1;

    for (int i = 0; i < 10; i++)
    {
      std_vector1.push_back(i);
      ft_vector1.push_back(i);
    }
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
    comparisonFunc("Member function size() test", std_vector1.size(), ft_vector1.size());
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      2-1.  vector::insert() " << '\n';
    std::cout << "\n            single element  " << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_vector1;
    ft::vector<int> ft_vector1;

    std::vector<int>::iterator it = std_vector1.begin();
    ft::vector<int>::iterator ft_it = ft_vector1.begin();
    std_vector1.insert(it, 3, 100);
    ft_vector1.insert(ft_it, 3, 100);
    for (std::vector<int>::iterator it = std_vector1.begin(); it != std_vector1.end(); it++)
      std::cout << "Elements of STD: " << *it << '\t';
    std::cout << '\n';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it != ft_vector1.end(); ft_it++)
      std::cout << "Elements of  FT: " << *ft_it << '\t';
    std::cout << '\n';
    it = std_vector1.begin();
    ft_it = ft_vector1.begin();
    std_vector1.insert(it, 1, 200);
    ft_vector1.insert(ft_it, 1, 200);
    for (std::vector<int>::iterator it = std_vector1.begin(); it != std_vector1.end(); it++)
      std::cout << "Elements of STD: " << *it << '\t';
    std::cout << '\n';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it != ft_vector1.end(); ft_it++)
      std::cout << "Elements of  FT: " << *ft_it << '\t';
    std::cout << '\n';
    it = std_vector1.begin();
    ft_it = ft_vector1.begin();
    std_vector1.insert(it, 5, 300);
    ft_vector1.insert(ft_it, 5, 300);
    for (std::vector<int>::iterator it = std_vector1.begin(); it != std_vector1.end(); it++)
      std::cout << "Elements of STD: " << *it << '\t';
    std::cout << '\n';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it != ft_vector1.end(); ft_it++)
      std::cout << "Elements of  FT: " << *ft_it << '\t';
    std::cout << '\n';
    std::cout << "std size : " << std_vector1.size() << " : "
              << "std capacity : " << std_vector1.capacity() << '\n';
    std::cout << " ft size : " << ft_vector1.size() << " : "
              << " ft capacity : " << ft_vector1.capacity() << '\n';
    // comparisonFuncVec("test every members",std_vector1, ft_vector1); //eniig asuuh
    comparisonFunc("Member function size() test", std_vector1.size(), ft_vector1.size());
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      2-2.  vector::insert() " << '\n';
    std::cout << "\n            fill " << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_vector1;
    std::vector<int> ft_vector1;

    std::vector<int>::iterator it = std_vector1.begin();
    std::vector<int>::iterator ft_it = ft_vector1.begin();
    std::cout << "std size : " << std_vector1.size() << " : "
              << "std capacity : " << std_vector1.capacity() << '\n';
    std_vector1.insert(it, 2, 100);
    std::cout << " ft size : " << ft_vector1.size() << " : "
              << " ft capacity : " << ft_vector1.capacity() << '\n';
    ft_vector1.insert(ft_it, 2, 100);
    it = std_vector1.begin();
    ft_it = ft_vector1.begin();
    std::cout << "std size : " << std_vector1.size() << " : "
              << "std capacity : " << std_vector1.capacity() << '\n';
    std_vector1.insert(it + 1, 5, 200);
    std::cout << " ft size : " << ft_vector1.size() << " : "
              << " ft capacity : " << ft_vector1.capacity() << '\n';
    ft_vector1.insert(ft_it + 1, 5, 200);
    std::cout << "std size : " << std_vector1.size() << " : "
              << "std capacity : " << std_vector1.capacity() << '\n';
    std::cout << " ft size : " << ft_vector1.size() << " : "
              << " ft capacity : " << ft_vector1.capacity() << '\n';
    for (std::vector<int>::iterator it = std_vector1.begin(); it != std_vector1.end(); it++)
      std::cout << "Elements of STD: " << *it << '\t';
    std::cout << '\n';
    for (std::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it != ft_vector1.end(); ft_it++)
      std::cout << "Elements of  FT: " << *ft_it << '\t';
    std::cout << '\n';
    comparisonFunc("Member function size() test", std_vector1.size(), ft_vector1.size());
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      2-3.  vector::insert() " << '\n';
    std::cout << "\n            range " << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_vector1(3, 100);
    ft::vector<int> ft_vector1(3, 100);
    // ft::vector<int> ft_vector1; //ene tohioldold ajillahgui bgaa
    std::vector<int>::iterator it;
    ft::vector<int>::iterator ft_it;

    it = std_vector1.begin();
    ft_it = ft_vector1.begin();

    it = std_vector1.insert(it + 1, 200);
    ft_it = ft_vector1.insert(ft_it + 1, 200);
    std::cout << "std: " << '\t';
    for (it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
    it = std_vector1.begin();
    ft_it = ft_vector1.begin();
    std_vector1.insert(it + 4, 300);
    ft_vector1.insert(ft_it + 4, 300);
    std::cout << "std: " << '\t';
    for (it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
    std::vector<int> std_vector2(2, 400);
    ft::vector<int> ft_vector2(2, 400);
    it = std_vector1.begin();
    ft_it = ft_vector1.begin();
    std_vector1.insert(it + 2, std_vector2.begin(), std_vector2.end());
    ft_vector1.insert(ft_it + 2, ft_vector2.begin(), ft_vector2.end());
    // std::cout << "after:" << '\n';
    std::cout << "std: " << '\t';
    for (it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
  }
  // { //after fixing insert function
  //   std::cout << "\n***************************************" << '\n';
  //   std::cout << "\n      3-1. vector::reserve " << '\n';
  //   std::cout << "\n***************************************" << '\n';

  //   std::vector<int> std_vector1(3, 100);
  //   ft::vector<int> ft_vector1(3, 100);
  //   std::vector<int>::iterator it;
  //   ft::vector<int>::iterator ft_it;

  //   it = std_vector1.begin();
  //   it = std_vector1.insert(it, 200);
  //   ft_it = ft_vector1.begin();
  //   ft_it = ft_vector1.insert(ft_it, 200);

  //   std_vector1.insert(it, 2, 300);
  //   ft_vector1.insert(ft_it, 2, 300);

  //   // "it" no longer valid, get a new one:
  //   it = std_vector1.begin();
  //   ft_it = ft_vector1.begin();

  //   std::vector<int> anothervector(2, 400);
  //   ft::vector<int> ft_anothervector(2, 400);
  //   std_vector1.insert(it + 2, anothervector.begin(), anothervector.end());
  //   ft_vector1.insert(ft_it + 2, ft_anothervector.begin(), ft_anothervector.end());

  //   // int myarray[] = {501, 502, 503};
  //   // myvector.insert(myvector.begin(), myarray, myarray + 3);

  //   // std::cout << "myvector contains:";
  //   // for (it = myvector.begin(); it < myvector.end(); it++)
  //   //   std::cout << ' ' << *it;
  //   // std::cout << '\n';
  //   std::cout << "std: " << '\t';
  //   for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
  //     std::cout << ' ' << *it;
  //   std::cout << '\n';
  //   std::cout << " ft: " << '\t';
  //   for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
  //     std::cout << ' ' << *ft_it;
  //   std::cout << '\n';
  // }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      4-1.  erase " << '\n';
    std::cout << "\n            position " << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_vector1;
    ft::vector<int> ft_vector1;

    for (int i = 0; i < 10; i++)
    {
      std_vector1.push_back(i);
      ft_vector1.push_back(i);
    }
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
    // 0 1 2 3 4 5 6 7 8 9 10
    std::cout << "erase the 6th element:" << '\n';

    std_vector1.erase(std_vector1.begin() + 5);
    ft_vector1.erase(ft_vector1.begin() + 5);

    // erase the first 3 elements:
    // std_vector1.erase(std_vector1.begin(), std_vector1.begin() + 3);
    // ft_vector1.erase(ft_vector1.begin(), ft_vector1.begin() + 3);

    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';

    std::cout << "erase the 9th element:" << '\n';

    std_vector1.erase(std_vector1.begin() + 8);
    ft_vector1.erase(ft_vector1.begin() + 8);
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';

    std::cout << "erase the first element:" << '\n';

    std_vector1.erase(std_vector1.begin());
    ft_vector1.erase(ft_vector1.begin());
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';

    std::cout << "Testing if the returning position is right:" << '\n';

    std::vector<int>::iterator it = std_vector1.erase(std_vector1.begin());
    ft::vector<int>::iterator ft_it = ft_vector1.erase(ft_vector1.begin());
    std_vector1.erase(it);
    ft_vector1.erase(ft_it);
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';

    std::vector<int> std_vector2;
    ft::vector<int> ft_vector2;

    std::cout << "erase the on in vector has only one element" << '\n';

    std_vector2.push_back(42);
    ft_vector2.push_back(42);
    std_vector2.erase(std_vector2.begin());
    ft_vector2.erase(ft_vector2.begin());
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_vector2.begin(); it < std_vector2.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_vector2.begin(); ft_it < ft_vector2.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      4-2.  erase " << '\n';
    std::cout << "\n            range " << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_vector1;
    ft::vector<int> ft_vector1;

    for (int i = 0; i < 10; i++)
    {
      std_vector1.push_back(i);
      ft_vector1.push_back(i);
    }
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
    // 0 1 2 3 4 5 6 7 8 9 10

    std::cout << "Erase the first 3 elements : " << '\n';
    std_vector1.erase(std_vector1.begin(), std_vector1.begin() + 3);
    ft_vector1.erase(ft_vector1.begin(), ft_vector1.begin() + 3);
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      4-2.  pop_back " << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_vector1;
    ft::vector<int> ft_vector1;

    int sum(0);
    int ft_sum(0);
    std_vector1.push_back(100);
    std_vector1.push_back(200);
    std_vector1.push_back(300);
    ft_vector1.push_back(100);
    ft_vector1.push_back(200);
    ft_vector1.push_back(300);

    while (!std_vector1.empty())
    {
      sum += std_vector1.back();
      std_vector1.pop_back();
    }
    while (!ft_vector1.empty())
    {
      ft_sum += ft_vector1.back();
      ft_vector1.pop_back();
    }
    std_vector1.push_back(300);
    ft_vector1.push_back(300);
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      5-1. operator[]" << '\n';
    std::cout << "\n***************************************" << '\n';

    // std::vector<int> std_vector1{2, 4, 6, 8};
    int numbers[] = {2, 4, 6, 8};
    std::vector<int> std_vector1(numbers, numbers + 4);
    ft::vector<int> ft_vector1;
    for (int i = 2; i < 10; i += 2)
    {
      ft_vector1.push_back(i);
    }
    std::cout << "Before accessing operator[]: \n";
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
    // ft::vector<int> ft_vector1(numbers[0], numbers + 4); aldaag ni daraa zasah. yagaad bolohgui baigaag oloh

    std::cout << "Second element: " << std_vector1[1] << '\n';
    std::cout << " Second element: " << ft_vector1[1] << '\n';

    std_vector1[0] = 5;
    ft_vector1[0] = 5;

    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      6-1. swap" << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_vector1(3, 100); // three ints with a value of 100
    std::vector<int> std_vector2(5, 200); // five ints with a value of 200
    ft::vector<int> ft_vector1(3, 100);   // three ints with a value of 100
    ft::vector<int> ft_vector2(5, 200);   // five ints with a value of 200

    std::cout << "BEFORE swap std_vector1 : ";
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "BEFORE swap  ft_vector1 : ";
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
    std::cout << "BEFORE swap std_vector2 : ";
    for (std::vector<int>::iterator it = std_vector2.begin(); it < std_vector2.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "BEFORE swap  ft_vector2 : ";
    for (ft::vector<int>::iterator ft_it = ft_vector2.begin(); ft_it < ft_vector2.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';

    std_vector1.swap(std_vector2);
    ft_vector1.swap(ft_vector2);

    std::cout << " AFTER swap std_vector1 : ";
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " AFTER swap  ft_vector1 : ";
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
    std::cout << " AFTER swap std_vector2 : ";
    for (std::vector<int>::iterator it = std_vector2.begin(); it < std_vector2.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " AFTER swap  ft_vector2 : ";
    for (ft::vector<int>::iterator ft_it = ft_vector2.begin(); ft_it < ft_vector2.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';

    std::cout << "swaping same vector:" << '\n';
    std::cout << "BEFORE swap std_vector1 : ";
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << "BEFORE swap  ft_vector1 : ";
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
    std_vector1.swap(std_vector1);
    ft_vector1.swap(ft_vector1);
    std::cout << " AFTER swap std_vector1 : ";
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " AFTER swap  ft_vector1 : ";
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      1-4.  Constructor" << '\n';
    std::cout << "\n            Copy" << '\n';
    std::cout << "\n***************************************" << '\n';
    // Initializing vector with values

    std::vector<int> std_vector1;
    ft::vector<int> ft_vector1;
    for (int i = 2; i < 10; i += 2)
    {
      std_vector1.push_back(i);
      ft_vector1.push_back(i);
    }
    // Declaring new vector and copying
    // element of old vector
    // constructor method, Deep copy
    std::cout << "Previous vector elements are : \n";
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';

    std::vector<int> std_vector2(std_vector1);
    ft::vector<int> ft_vector2(ft_vector1);

    std::cout << "New vector elements are : \n";
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_vector2.begin(); it < std_vector2.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_vector2.begin(); ft_it < ft_vector2.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';

    // constructors used in the same order as described above:
    std::vector<int> first;                               // empty vector of ints
    std::vector<int> second(4, 100);                      // four ints with value 100
    std::vector<int> third(second.begin(), second.end()); // iterating through second
    std::vector<int> fourth(third);                       // a copy of third

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16, 2, 77, 29};
    std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

    std::cout << "The contents of fifth are:";
    for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }
  // {
  //   std::cout << "\n***************************************" << '\n';
  //   std::cout << "\n      n. Bla bla bla " << '\n';
  //   std::cout << "\n***************************************" << '\n';

  //   // second.assign(it, first.end() - 1); // the 5 central values of first

  //   // int myints[] = {1776, 7, 4};
  //   // third.assign(myints, myints + 3); // assigning from array.

  //   // std::cout << "\nElements of BEFORE assigning again: " << '\n';

  //   // for (std::vector<int>::iterator it = third.begin(); it != third.end(); it++)
  //   //   std::cout << "Elements of third: " << *it << '\n';

  //   // third.assign(5, 1);
  //   // std::cout << "Size of first: " << int(first.size()) << '\n';
  //   // std::cout << "Size of second: " << int(second.size()) << '\n';
  //   // std::cout << "Size of third: " << int(third.size()) << '\n';
  //   // for (std::vector<int>::iterator it = third.begin(); it != third.end(); it++)
  //   //   std::cout << "Elements of third: " << *it << '\n';
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
