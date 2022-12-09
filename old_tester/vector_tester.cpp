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
#include <list>
#include <vector> // std::vector
#include "../include/vector.hpp"

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

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
  std::cout << (first < second) << std::endl;
  std::cout << (first <= second) << std::endl;
  std::cout << (first > second) << std::endl;
  std::cout << (first >= second) << std::endl;
  if (redo)
    ft_eq_ope(second, first, 0);
}

void checkEraseSTD(std::vector<std::string> const &vct,
                   std::vector<std::string>::const_iterator const &it)
{
  static int i = 0;
  std::cout << "[" << i++ << "] "
            << "before it: " << *it << '\t'
            << "before vct.begin(): " << *vct.begin() << '\n'
            << "erase: " << it - vct.begin() << std::endl;
  // printSize(vct);
}
void checkErase(ft::vector<std::string> const &vct,
                ft::vector<std::string>::const_iterator const &it)
{
  static int i = 0;
  std::cout << "[" << i++ << "] "
            << "before it: " << *it << '\t'
            << "before vct.begin(): " << *vct.begin() << '\n'
            << "erase: " << it - vct.begin() << std::endl;
  // printSize(vct);
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
    for (std::vector<int>::const_iterator it = std_vector1.begin(); it < std_vector1.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::const_iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
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
    std::cout << "sum" << sum << '\n';
    std::cout << "ft_sum" << ft_sum << '\n';
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
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      1-X.  Constructor" << '\n';
    std::cout << "\n            Testing all constructors" << '\n';
    std::cout << "\n***************************************" << '\n';

    // constructors used in the same order as described above:
    std::vector<int> std_first;                                       // empty vector of ints
    ft::vector<int> ft_first;                                         // empty vector of ints
    std::vector<int> std_second(4, 100);                              // four ints with value 100
    ft::vector<int> ft_second(4, 100);                                // four ints with value 100
    std::vector<int> std_third(std_second.begin(), std_second.end()); // iterating through second
    ft::vector<int> ft_third(ft_second.begin(), ft_second.end());     // iterating through second
    std::vector<int> std_fourth(std_third);                           // a copy of third
    ft::vector<int> ft_fourth(ft_third);                              // a copy of third

    std::cout << "std contents of second are:";
    for (std::vector<int>::iterator std_it = std_second.begin(); std_it != std_second.end(); ++std_it)
      std::cout << ' ' << *std_it;
    std::cout << '\n';

    std::cout << " ft contents of second are:";
    for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';

    std::cout << "std contents of third are:";
    for (std::vector<int>::iterator std_it = std_third.begin(); std_it != std_third.end(); ++std_it)
      std::cout << ' ' << *std_it;
    std::cout << '\n';

    std::cout << " ft contents of third are:";
    for (ft::vector<int>::iterator ft_it = ft_third.begin(); ft_it != ft_third.end(); ++ft_it)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';

    std::cout << "std contents of fourth are:";
    for (std::vector<int>::iterator std_it = std_fourth.begin(); std_it != std_fourth.end(); ++std_it)
      std::cout << ' ' << *std_it;
    std::cout << '\n';

    std::cout << " ft contents of fourth are:";
    for (ft::vector<int>::iterator ft_it = ft_fourth.begin(); ft_it != ft_fourth.end(); ++ft_it)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16, 2, 77, 29};
    std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
    std::cout << "The contents of fifth are:";
    // for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    //   std::cout << ' ' << *it;
    std::cout << '\n';
  }
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
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      1-3.  Constructor" << '\n';
    std::cout << "\n            Range" << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_vector1;
    std::vector<int> std_vector2;
    ft::vector<int> ft_vector1;
    ft::vector<int> ft_vector2;

    std_vector1.assign(7, 100);
    ft_vector1.assign(7, 100);

    std::vector<int>::iterator it;
    ft::vector<int>::iterator ft_it;
    it = std_vector1.begin() + 1;
    ft_it = ft_vector1.begin() + 1;

    std_vector2.assign(it, std_vector1.end() - 1);
    // ft_vector2.assign(ft_it, ft_vector1.end() - 1);
    // assign iig ehleed hiih.

    for (std::vector<int>::iterator it = std_vector1.begin(); it != std_vector1.end(); it++)
      std::cout << "Elements of STD: " << *it << '\n';
    for (ft::vector<int>::iterator it = ft_vector1.begin(); it != ft_vector1.end(); it++)
      std::cout << "Elements of FT: " << *it << '\n';
    // comparisonFunc("Member function size() test", std_vector1.size(), ft_vector1.size());
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      7-1.  assign" << '\n';
    std::cout << "\n            fill" << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_first;
    ft::vector<int> ft_first;
    std::vector<int> std_second;
    ft::vector<int> ft_second;
    std::vector<int> std_third;
    ft::vector<int> ft_third;

    std_first.assign(7, 100); // 7 ints with a value of 100
    ft_first.assign(7, 100);  // 7 ints with a value of 100

    std::vector<int>::iterator it;
    it = std_first.begin() + 1;
    ft::vector<int>::iterator ft_it;
    ft_it = ft_first.begin() + 1;

    std_second.assign(it, std_first.end() - 1);  // the 5 central values of first
    ft_second.assign(ft_it, ft_first.end() - 1); // the 5 central values of first

    int myints[] = {1776, 7, 4};
    std_third.assign(myints, myints + 3); // assigning from array.
    ft_third.assign(myints, myints + 3);  // assigning from array.

    std::cout << "First vector : \n";
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_first.begin(); it < std_first.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_first.begin(); ft_it < ft_first.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';

    std::cout << "Second vector : \n";
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_second.begin(); it < std_second.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it < ft_second.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';

    std::cout << "Third vector : \n";
    std::cout << "std: " << '\t';
    for (std::vector<int>::iterator it = std_third.begin(); it < std_third.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    std::cout << " ft: " << '\t';
    for (ft::vector<int>::iterator ft_it = ft_third.begin(); ft_it < ft_third.end(); ft_it++)
      std::cout << ' ' << *ft_it;
    std::cout << '\n';
    // std::cout << "Size of first: " << int(first.size()) << '\n';
    // std::cout << "Size of second: " << int(second.size()) << '\n';
    // std::cout << "Size of third: " << int(third.size()) << '\n';
  }
  {
    // std::cout << "\n***************************************" << '\n';
    // std::cout << "\n      n. Bla bla bla " << '\n';
    // std::cout << "\n***************************************" << '\n';
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      8-1.  get_allocator" << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> std_vector1;
    ft::vector<int> ft_vector1;
    int *p;
    int *ft_p;
    unsigned int i;

    // allocate an array with space for 5 elements using vector's allocator:
    p = std_vector1.get_allocator().allocate(5);
    ft_p = ft_vector1.get_allocator().allocate(5);

    // construct values in-place on the array:
    for (i = 0; i < 5; i++)
    {
      std_vector1.get_allocator().construct(&p[i], i);
      ft_vector1.get_allocator().construct(&ft_p[i], i);
    }

    std::cout << "The allocated array contains:";
    std::cout << '\n';
    for (i = 0; i < 5; i++)
    {
      std::cout << "std: " << ' ' << p[i];
      std::cout << '\n';
      std::cout << " ft: " << ' ' << ft_p[i];
      std::cout << '\n';
    }
    std::cout << '\n';

    // // destroy and deallocate:
    // for (i = 0; i < 5; i++)
    //   myvector.get_allocator().destroy(&p[i]);
    // myvector.get_allocator().deallocate(p, 5);
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      9-1.  resize" << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<int> myvector;

    // set some initial content:
    for (int i = 1; i < 10; i++)
      myvector.push_back(i);
    std::cout << "myvector contains:";
    for (size_t i = 0; i < myvector.size(); i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';

    myvector.resize(5);

    std::cout << "myvector contains:";
    for (size_t i = 0; i < myvector.size(); i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';

    myvector.resize(8, 100);

    std::cout << "myvector contains:";
    for (size_t i = 0; i < myvector.size(); i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';

    myvector.resize(12);

    std::cout << "myvector contains:";
    for (size_t i = 0; i < myvector.size(); i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';
  }
  // {
  //   std::cout << "\n***************************************" << '\n';
  //   std::cout << "\n      10.  assign" << '\n';
  //   std::cout << "\n***************************************" << '\n';

  //   ft::vector<int> vct(7);
  //   ft::vector<int> vct_two(4);
  //   ft::vector<int> vct_three;
  //   ft::vector<int> vct_four;

  //   for (unsigned long int i = 0; i < vct.size(); ++i)
  //     vct[i] = (vct.size() - i) * 3;
  //   for (unsigned long int i = 0; i < vct_two.size(); ++i)
  //     vct_two[i] = (vct_two.size() - i) * 5;
  //   // printSize(vct);
  //   // printSize(vct_two);

  //   vct_three.assign(vct.begin(), vct.end());
  //   vct.assign(vct_two.begin(), vct_two.end());
  //   vct_two.assign(2, 42);
  //   vct_four.assign(4, 21);

  //   std::cout << "\t### After assign(): ###" << std::endl;

  //   // printSize(vct);
  //   // printSize(vct_two);
  //   // printSize(vct_three);
  //   // printSize(vct_four);

  //   vct_four.assign(6, 84);
  //   // printSize(vct_four);

  //   std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

  //   vct.assign(5, 53);
  //   vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

  //   // printSize(vct);
  //   // printSize(vct_two);
  // }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      11.  iterator" << '\n';
    std::cout << "\n***************************************" << '\n';

    const int size = 5;
    std::vector<int> vct(size);
    std::vector<int>::iterator it = vct.begin();
    std::vector<int>::const_iterator ite = vct.begin();

    for (int i = 0; i < size; ++i)
      it[i] = (size - i) * 5;
    // prepost_incdec(vct);
    for (it = vct.begin(); it != vct.end(); ++it)
      std::cout << "vector memebers are :" << *it << '\n';

    it = it + 5;
    it = 1 + it;
    it = it - 4;
    std::cout << *(it += 2) << std::endl;
    std::cout << *(it -= 1) << std::endl;

    *(it -= 2) = 42;
    std::cout << "MIDDLE vector iterators are :" << *it << '\n';

    *(it += 2) = 21;
    std::cout << "MIDDLE vector iterators are :" << *it << '\n';

    std::cout << "const_ite +=: " << *(ite += 2) << std::endl;
    std::cout << "const_ite -=: " << *(ite -= 2) << std::endl;

    std::cout << "(it == const_it): " << (ite == it) << std::endl;
    std::cout << "(const_ite - it): " << (ite - it) << std::endl;
    std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

    for (it = vct.begin(); it != vct.end(); ++it)
      std::cout << "AFTER vector memebers are :" << *it << '\n';

    // printSize(vct, true);
  }
  {
    const int size = 5;
    ft::vector<int> vct(size);
    ft::vector<int>::iterator it = vct.begin();
    ft::vector<int>::const_iterator ite = vct.begin();

    for (int i = 0; i < size; ++i)
      it[i] = (size - i) * 5;
    // prepost_incdec(vct);
    for (it = vct.begin(); it != vct.end(); ++it)
      std::cout << "vector memebers are :" << *it << '\n';

    it = it + 5;
    it = 1 + it;
    it = it - 4;
    std::cout << *(it += 2) << std::endl;
    std::cout << *(it -= 1) << std::endl;

    *(it -= 2) = 42;
    std::cout << "MIDDLE vector iterators are :" << *it << '\n';

    *(it += 2) = 21;
    std::cout << "MIDDLE vector iterators are :" << *it << '\n';

    std::cout << "const_ite +=: " << *(ite += 2) << std::endl;
    std::cout << "const_ite -=: " << *(ite -= 2) << std::endl;

    std::cout << "(it == const_it): " << (ite == it) << std::endl;
    std::cout << "(const_ite - it): " << (ite - it) << std::endl;
    std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

    for (it = vct.begin(); it != vct.end(); ++it)
      std::cout << "AFTER vector memebers are :" << *it << '\n';
  }
  // {
  //   std::cout << "\n***************************************" << '\n';
  //   std::cout << "\n      12. iterator arrow test" << '\n';
  //   std::cout << "\n***************************************" << '\n';

  //   const int size = 5;
  //   std::vector<int> vct(size);
  //   std::vector<int>::iterator it(vct.begin());
  //   std::vector<int>::const_iterator ite(vct.end());

  //   for (int i = 1; it != ite; ++i)
  //     *it++ = i;

  //   it = vct.begin();
  //   ite = vct.begin();

  //   std::cout << *(++ite) << std::endl;
  //   std::cout << *(ite++) << std::endl;
  //   std::cout << *ite++ << std::endl;
  //   std::cout << *++ite << std::endl;

  //   it->m();
  //   ite->m();

  //   std::cout << *(++it) << std::endl;
  //   std::cout << *(it++) << std::endl;
  //   std::cout << *it++ << std::endl;
  //   std::cout << *++it << std::endl;

  //   std::cout << *(--ite) << std::endl;
  //   std::cout << *(ite--) << std::endl;
  //   std::cout << *--ite << std::endl;
  //   std::cout << *ite-- << std::endl;

  //   (*it).m();
  //   (*ite).m();

  //   std::cout << *(--it) << std::endl;
  //   std::cout << *(it--) << std::endl;
  //   std::cout << *it-- << std::endl;
  //   std::cout << *--it << std::endl;
  // }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      13. reverse iterator" << '\n';
    std::cout << "\n***************************************" << '\n';
    const int size = 5;
    std::vector<int> vct(size);
    std::vector<int>::reverse_iterator it = vct.rbegin();
    std::vector<int>::const_reverse_iterator ite = vct.rbegin();

    for (int i = 0; i < size; ++i)
      it[i] = (size - i) * 5;

    it = it + 5;
    it = 1 + it;
    it = it - 4;
    std::cout << *(it += 2) << std::endl;
    std::cout << *(it -= 1) << std::endl;

    *(it -= 2) = 42;
    *(it += 2) = 21;

    std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

    std::cout << "(it == const_it): " << (ite == it) << std::endl;
    std::cout << "(const_ite - it): " << (ite - it) << std::endl;
    std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;
  }
  {
    const int size = 5;
    ft::vector<int> vct(size);
    ft::vector<int>::reverse_iterator it = vct.rbegin();
    ft::vector<int>::const_reverse_iterator ite = vct.rbegin();

    for (int i = 0; i < size; ++i)
      it[i] = (size - i) * 5;

    it = it + 5;
    it = 1 + it;
    it = it - 4;
    std::cout << *(it += 2) << std::endl;
    std::cout << *(it -= 1) << std::endl;

    *(it -= 2) = 42;
    *(it += 2) = 21;

    std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

    std::cout << "(it == const_it): " << (ite == it) << std::endl;
    std::cout << "(const_ite - it): " << (ite - it) << std::endl;
    std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;
  }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      14. reverse iterator - 2" << '\n';
    std::cout << "\n***************************************" << '\n';

    const int size = 5;
    std::vector<int> vct(size);
    std::vector<int>::reverse_iterator it_0(vct.rbegin());
    std::vector<int>::reverse_iterator it_1(vct.rend());
    std::vector<int>::reverse_iterator it_mid;

    std::vector<int>::const_reverse_iterator cit_0 = vct.rbegin();
    std::vector<int>::const_reverse_iterator cit_1;
    std::vector<int>::const_reverse_iterator cit_mid;

    for (int i = size; it_0 != it_1; --i)
      *it_0++ = i;
    it_0 = vct.rbegin();
    cit_1 = vct.rend();
    it_mid = it_0 + 3;
    cit_mid = it_0 + 3;
    cit_mid = cit_0 + 3;
    cit_mid = it_mid;

    std::cout << std::boolalpha;
    std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

    std::cout << "\t\tft_eq_ope:" << std::endl;
    // regular it
    ft_eq_ope(it_0 + 3, it_mid);
    ft_eq_ope(it_0, it_1);
    ft_eq_ope(it_1 - 3, it_mid);
    // const it
    ft_eq_ope(cit_0 + 3, cit_mid);
    ft_eq_ope(cit_0, cit_1);
    ft_eq_ope(cit_1 - 3, cit_mid);
    // both it
    ft_eq_ope(it_0 + 3, cit_mid);
    ft_eq_ope(it_mid, cit_0 + 3);
    ft_eq_ope(it_0, cit_1);
    ft_eq_ope(it_1, cit_0);
    ft_eq_ope(it_1 - 3, cit_mid);
    ft_eq_ope(it_mid, cit_1 - 3);
  }
  {
    const int size = 5;
    ft::vector<int> vct(size);
    ft::vector<int>::reverse_iterator it_0(vct.rbegin());
    ft::vector<int>::reverse_iterator it_1(vct.rend());
    ft::vector<int>::reverse_iterator it_mid;

    ft::vector<int>::const_reverse_iterator cit_0 = vct.rbegin();
    ft::vector<int>::const_reverse_iterator cit_1;
    ft::vector<int>::const_reverse_iterator cit_mid;

    for (int i = size; it_0 != it_1; --i)
      *it_0++ = i;
    it_0 = vct.rbegin();
    cit_1 = vct.rend();
    it_mid = it_0 + 3;
    cit_mid = it_0 + 3;
    cit_mid = cit_0 + 3;
    cit_mid = it_mid;

    std::cout << std::boolalpha;
    std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

    std::cout << "\t\tft_eq_ope:" << std::endl;
    // regular it
    ft_eq_ope(it_0 + 3, it_mid);
    ft_eq_ope(it_0, it_1);
    ft_eq_ope(it_1 - 3, it_mid);
    // const it
    ft_eq_ope(cit_0 + 3, cit_mid);
    ft_eq_ope(cit_0, cit_1);
    ft_eq_ope(cit_1 - 3, cit_mid);
    // both it
    ft_eq_ope(it_0 + 3, cit_mid);
    ft_eq_ope(it_mid, cit_0 + 3);
    ft_eq_ope(it_0, cit_1);
    ft_eq_ope(it_1, cit_0);
    ft_eq_ope(it_1 - 3, cit_mid);
    ft_eq_ope(it_mid, cit_1 - 3);
  }
  // {
  //   std::cout << "\n***************************************" << '\n';
  //   std::cout << "\n      15. bidirectional iterator" << '\n';
  //   std::cout << "\n***************************************" << '\n';

  //   std::list<int> lst;
  //   std::list<int>::iterator lst_it;
  //   for (int i = 1; i < 5; ++i)
  //     lst.push_back(i * 3);

  //   std::vector<int> vct(lst.begin(), lst.end());
  //   // printSize(vct);

  //   lst_it = lst.begin();
  //   for (int i = 1; lst_it != lst.end(); ++i)
  //     *lst_it++ = i * 5;
  //   vct.assign(lst.begin(), lst.end());
  //   // printSize(vct);

  //   vct.insert(vct.end(), lst.rbegin(), lst.rend());
  //   // printSize(vct);
  // }
  {
    std::cout << "\n***************************************" << '\n';
    std::cout << "\n      16. erase-string" << '\n';
    std::cout << "\n***************************************" << '\n';

    std::vector<std::string> vct(10);

    for (unsigned long int i = 0; i < vct.size(); ++i)
      vct[i] = std::string((vct.size() - i), i + 65);

    checkEraseSTD(vct, vct.erase(vct.begin() + 2));

    checkEraseSTD(vct, vct.erase(vct.begin()));
    checkEraseSTD(vct, vct.erase(vct.end() - 1));

    checkEraseSTD(vct, vct.erase(vct.begin(), vct.begin() + 3));
    checkEraseSTD(vct, vct.erase(vct.end() - 3, vct.end() - 1));

    vct.push_back("Hello");
    vct.push_back("Hi there");
    // printSize(vct);
    checkEraseSTD(vct, vct.erase(vct.end() - 3, vct.end()));

    vct.push_back("ONE");
    vct.push_back("TWO");
    vct.push_back("THREE");
    vct.push_back("FOUR");
    checkEraseSTD(vct, vct.erase(vct.begin(), vct.end()));
  }
  {
    std::cout << "FT!!!!!!!!!" << '\n';
    ft::vector<std::string> vct(10);

    for (unsigned long int i = 0; i < vct.size(); ++i)
      vct[i] = std::string((vct.size() - i), i + 65);

    checkErase(vct, vct.erase(vct.begin() + 2));

    checkErase(vct, vct.erase(vct.begin()));
    checkErase(vct, vct.erase(vct.end() - 1));

    // << "erase: " << it - vct.begin() << std::endl;
    // std::cout << "it:" << it - vct.begin() << '\n';
    
    checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
    checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

    vct.push_back("Hello");
    vct.push_back("Hi there");
    // printSize(vct);
    checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

    vct.push_back("ONE");
    vct.push_back("TWO");
    vct.push_back("THREE");
    vct.push_back("FOUR");
    checkErase(vct, vct.erase(vct.begin(), vct.end()));
  }
return 0;
}