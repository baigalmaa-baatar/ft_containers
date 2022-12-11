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

#ifdef STD
#include <vector>
namespace ft = std;
#else
#include "../include/vector.hpp"
#endif

template <typename T>
void comparisonFuncVec(std::string testName, ft::vector<T> std_vector1, ft::vector<T> ft_vector1)
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

void checkErase(ft::vector<std::string> const &vct,
                ft::vector<std::string>::const_iterator const &it)
{
  static int i = 0;
  std::cout << "[" << i++ << "] "
            << "before it: " << *it << '\t'
            << "before vct.begin(): " << *vct.begin() << '\n'
            << "erase: " << it - vct.begin() << std::endl;
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

void testing_constructor_def()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      1-1.  Constructor" << '\n';
  std::cout << "\n            Default" << '\n';
  std::cout << "\n***************************************" << '\n';
  /**
   * Empty vector test
   */
  ft::vector<int> ft_vector1;
  std::cout << ft_vector1.size() << '\n';
}
void testing_constructor_fill()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      1-2.  Constructor" << '\n';
  std::cout << "\n            Fill" << '\n';
  std::cout << "\n***************************************" << '\n';

  ft::vector<int> ft_vector1(4, 100);

  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it != ft_vector1.end(); ft_it++)
    std::cout << "Elements of  FT: " << *ft_it << '\n';

  std::cout << ft_vector1.size() << '\n';
}

void testing_push_back()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      2-1. push-back " << '\n';
  std::cout << "\n***************************************" << '\n';

  ft::vector<int> ft_vector1;

  for (int i = 0; i < 10; i++)
  {
    ft_vector1.push_back(i);
  }

  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';

  // comparisonFuncVec("test every members",std_vector1, ft_vector1); //eniig asuuh
  std::cout << ft_vector1.size() << '\n';
}

void testing_insert()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      2-1.  vector::insert() " << '\n';
  std::cout << "\n            single element  " << '\n';
  std::cout << "\n***************************************" << '\n';

  ft::vector<int> ft_vector1;

  ft::vector<int>::iterator ft_it = ft_vector1.begin();
  ft_vector1.insert(ft_it, 3, 100);
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it != ft_vector1.end(); ft_it++)
    std::cout << "Elements of  FT: " << *ft_it << '\t';
  std::cout << '\n';
  ft_it = ft_vector1.begin();
  ft_vector1.insert(ft_it, 1, 200);
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it != ft_vector1.end(); ft_it++)
    std::cout << "Elements of  FT: " << *ft_it << '\t';
  std::cout << '\n';
  ft_it = ft_vector1.begin();
  ft_vector1.insert(ft_it, 5, 300);
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it != ft_vector1.end(); ft_it++)
    std::cout << "Elements of  FT: " << *ft_it << '\t';
  std::cout << '\n';
  std::cout << " ft size : " << ft_vector1.size() << " : "
            << " ft capacity : " << ft_vector1.capacity() << '\n';
  std::cout << ft_vector1.size() << '\n';
}

void testing_insert_fill()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      2-2.  vector::insert() " << '\n';
  std::cout << "\n            fill " << '\n';
  std::cout << "\n***************************************" << '\n';

  ft::vector<int> ft_vector1;

  ft::vector<int>::iterator ft_it = ft_vector1.begin();
  std::cout << " ft size : " << ft_vector1.size() << " : "
            << " ft capacity : " << ft_vector1.capacity() << '\n';
  ft_vector1.insert(ft_it, 2, 100);
  ft_it = ft_vector1.begin();
  std::cout << " ft size : " << ft_vector1.size() << " : "
            << " ft capacity : " << ft_vector1.capacity() << '\n';
  ft_vector1.insert(ft_it + 1, 5, 200);
  std::cout << " ft size : " << ft_vector1.size() << " : "
            << " ft capacity : " << ft_vector1.capacity() << '\n';
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it != ft_vector1.end(); ft_it++)
    std::cout << "Elements of  FT: " << *ft_it << '\t';
  std::cout << '\n';
  std::cout << ft_vector1.size() << '\n';
}

void testing_insert_range()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      2-3.  vector::insert() " << '\n';
  std::cout << "\n            range " << '\n';
  std::cout << "\n***************************************" << '\n';

  ft::vector<int> ft_vector1(3, 100);
  ft::vector<int>::iterator ft_it;

  ft_it = ft_vector1.begin();

  ft_it = ft_vector1.insert(ft_it + 1, 200);
  std::cout << " ft: " << '\t';
  for (ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
  ft_it = ft_vector1.begin();
  ft_vector1.insert(ft_it + 4, 300);
  std::cout << "std: " << '\t';
  std::cout << " ft: " << '\t';
  for (ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
  ft::vector<int> ft_vector2(2, 400);
  ft_it = ft_vector1.begin();
  ft_vector1.insert(ft_it + 2, ft_vector2.begin(), ft_vector2.end());
  std::cout << " ft: " << '\t';
  for (ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
}

void testing_erase_pos()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      4-1.  erase " << '\n';
  std::cout << "\n            position " << '\n';
  std::cout << "\n***************************************" << '\n';

  ft::vector<int> ft_vector1;

  for (int i = 0; i < 10; i++)
  {
    ft_vector1.push_back(i);
  }
  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
  std::cout << "erase the 6th element:" << '\n';

  ft_vector1.erase(ft_vector1.begin() + 5);

  std::cout << " ft: " << '\t';
  for (ft::vector<int>::const_iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';

  std::cout << "erase the 9th element:" << '\n';

  ft_vector1.erase(ft_vector1.begin() + 8);
  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';

  std::cout << "erase the first element:" << '\n';

  ft_vector1.erase(ft_vector1.begin());
  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';

  std::cout << "Testing if the returning position is right:" << '\n';

  ft::vector<int>::iterator ft_it = ft_vector1.erase(ft_vector1.begin());
  ft_vector1.erase(ft_it);
  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';

  ft::vector<int> ft_vector2;

  std::cout << "erase the on in vector has only one element" << '\n';

  ft_vector2.push_back(42);
  ft_vector2.erase(ft_vector2.begin());
  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_vector2.begin(); ft_it < ft_vector2.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
}

void testing_erase_range()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      4-2.  erase " << '\n';
  std::cout << "\n            range " << '\n';
  std::cout << "\n***************************************" << '\n';

  ft::vector<int> ft_vector1;

  for (int i = 0; i < 10; i++)
  {
    ft_vector1.push_back(i);
  }
  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';

  std::cout << "Erase the first 3 elements : " << '\n';
  ft_vector1.erase(ft_vector1.begin(), ft_vector1.begin() + 3);
  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
}

void testing_pop_back()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      4-2.  pop_back " << '\n';
  std::cout << "\n***************************************" << '\n';

  ft::vector<int> ft_vector1;

  int ft_sum(0);
  ft_vector1.push_back(100);
  ft_vector1.push_back(200);
  ft_vector1.push_back(300);

  while (!ft_vector1.empty())
  {
    ft_sum += ft_vector1.back();
    ft_vector1.pop_back();
  }
  ft_vector1.push_back(300);
  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
  std::cout << "ft_sum" << ft_sum << '\n';
}

void testing_operator1()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      5-1. operator[]" << '\n';
  std::cout << "\n***************************************" << '\n';

  // std::vector<int> std_vector1{2, 4, 6, 8};
  ft::vector<int> ft_vector1;
  for (int i = 2; i < 10; i += 2)
  {
    ft_vector1.push_back(i);
  }
  std::cout << "Before accessing operator[]: \n";
  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';

  std::cout << " Second element: " << ft_vector1[1] << '\n';

  ft_vector1[0] = 5;

  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
}

void testing_swap()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      6-1. swap" << '\n';
  std::cout << "\n***************************************" << '\n';

  ft::vector<int> ft_vector1(3, 100); // three ints with a value of 100
  ft::vector<int> ft_vector2(5, 200); // five ints with a value of 200

  std::cout << "BEFORE swap  ft_vector1 : ";
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
  std::cout << "BEFORE swap  ft_vector2 : ";
  for (ft::vector<int>::iterator ft_it = ft_vector2.begin(); ft_it < ft_vector2.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';

  ft_vector1.swap(ft_vector2);

  std::cout << " AFTER swap  ft_vector1 : ";
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
  std::cout << " AFTER swap  ft_vector2 : ";
  for (ft::vector<int>::iterator ft_it = ft_vector2.begin(); ft_it < ft_vector2.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';

  std::cout << "swaping same vector:" << '\n';
  std::cout << "BEFORE swap  ft_vector1 : ";
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
  ft_vector1.swap(ft_vector1);
  std::cout << " AFTER swap  ft_vector1 : ";
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
}

void testing_constructor_copy()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      1-4.  Constructor" << '\n';
  std::cout << "\n            Copy" << '\n';
  std::cout << "\n***************************************" << '\n';
  // Initializing vector with values

  ft::vector<int> ft_vector1;
  for (int i = 2; i < 10; i += 2)
  {
    ft_vector1.push_back(i);
  }
  std::cout << "Previous vector elements are : \n";
  std::cout << '\n';
  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_vector1.begin(); ft_it < ft_vector1.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';

  ft::vector<int> ft_vector2(ft_vector1);

  std::cout << "New vector elements are : \n";
  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_vector2.begin(); ft_it < ft_vector2.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
}

void testing_all_constructors()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      1-X.  Constructor" << '\n';
  std::cout << "\n            Testing all constructors" << '\n';
  std::cout << "\n***************************************" << '\n';

  // constructors used in the same order as described above:
  ft::vector<int> ft_first;                                     // empty vector of ints
  ft::vector<int> ft_second(4, 100);                            // four ints with value 100
  ft::vector<int> ft_third(ft_second.begin(), ft_second.end()); // iterating through second
  ft::vector<int> ft_fourth(ft_third);                          // a copy of third

  std::cout << " ft contents of second are:";
  for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';

  std::cout << " ft contents of third are:";
  for (ft::vector<int>::iterator ft_it = ft_third.begin(); ft_it != ft_third.end(); ++ft_it)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';

  std::cout << " ft contents of fourth are:";
  for (ft::vector<int>::iterator ft_it = ft_fourth.begin(); ft_it != ft_fourth.end(); ++ft_it)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
}

void testing_const_range()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      1-3.  Constructor" << '\n';
  std::cout << "\n            Range" << '\n';
  std::cout << "\n***************************************" << '\n';

  ft::vector<int> ft_vector1;
  ft::vector<int> ft_vector2;

  ft_vector1.assign(7, 100);

  ft::vector<int>::iterator ft_it;
  ft_it = ft_vector1.begin() + 1;

  ft_vector2.assign(ft_it, ft_vector1.end() - 1);

  for (ft::vector<int>::iterator it = ft_vector1.begin(); it != ft_vector1.end(); it++)
    std::cout << "Elements of FT: " << *it << '\n';
}

void testing_assign()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      7-1.  assign" << '\n';
  std::cout << "\n            fill" << '\n';
  std::cout << "\n***************************************" << '\n';

  ft::vector<int> ft_first;
  ft::vector<int> ft_second;
  ft::vector<int> ft_third;

  ft_first.assign(7, 100); // 7 ints with a value of 100

  ft::vector<int>::iterator ft_it;
  ft_it = ft_first.begin() + 1;

  ft_second.assign(ft_it, ft_first.end() - 1); // the 5 central values of first

  int myints[] = {1776, 7, 4};
  ft_third.assign(myints, myints + 3); // assigning from array.

  std::cout << "First vector : \n";
  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_first.begin(); ft_it < ft_first.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';

  std::cout << "Second vector : \n";
  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it < ft_second.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';

  std::cout << "Third vector : \n";
  std::cout << " ft: " << '\t';
  for (ft::vector<int>::iterator ft_it = ft_third.begin(); ft_it < ft_third.end(); ft_it++)
    std::cout << ' ' << *ft_it;
  std::cout << '\n';
}

void testing_get_alloc()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      8-1.  get_allocator" << '\n';
  std::cout << "\n***************************************" << '\n';

  ft::vector<int> ft_vector1;
  int *ft_p;
  unsigned int i;

  // allocate an array with space for 5 elements using vector's allocator:
  ft_p = ft_vector1.get_allocator().allocate(5);

  // construct values in-place on the array:
  for (i = 0; i < 5; i++)
  {
    ft_vector1.get_allocator().construct(&ft_p[i], i);
  }

  std::cout << "The allocated array contains:";
  std::cout << '\n';
  for (i = 0; i < 5; i++)
  {
    std::cout << " ft: " << ' ' << ft_p[i];
    std::cout << '\n';
  }
  std::cout << '\n';

  ft_vector1.get_allocator().deallocate(ft_p, 5);
}

void testing_resize()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      9-1.  resize" << '\n';
  std::cout << "\n***************************************" << '\n';

  ft::vector<int> myvector;

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

void testing_irerator()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      11.  iterator" << '\n';
  std::cout << "\n***************************************" << '\n';

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

void testing_reverse_iterator()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      13. reverse iterator" << '\n';
  std::cout << "\n***************************************" << '\n';

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

void testing_reverse_iterator2()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      14. reverse iterator - 2" << '\n';
  std::cout << "\n***************************************" << '\n';

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

void testing_erase_str()
{
  std::cout << "\n***************************************" << '\n';
  std::cout << "\n      15. erase-string" << '\n';
  std::cout << "\n***************************************" << '\n';

  ft::vector<std::string> vct(10);

  for (unsigned long int i = 0; i < vct.size(); ++i)
    vct[i] = std::string((vct.size() - i), i + 65);

  checkErase(vct, vct.erase(vct.begin() + 2));

  checkErase(vct, vct.erase(vct.begin()));
  vct.erase(vct.end() - 1);

  checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
  checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

  vct.push_back("Hello");
  vct.push_back("Hi there");

  vct.push_back("ONE");
  vct.push_back("TWO");
  vct.push_back("THREE");
  vct.push_back("FOUR");
  checkErase(vct, vct.erase(vct.begin(), vct.end()));
}

int main(void)
{
  testing_constructor_def();
  testing_constructor_fill();
  testing_push_back();
  testing_insert();
  testing_insert_fill();
  testing_insert_range();
  testing_erase_pos();
  testing_erase_range();
  testing_pop_back();
  testing_operator1();
  testing_swap();
  testing_constructor_copy();
  testing_all_constructors();
  testing_const_range();
  testing_assign();
  testing_get_alloc();
  testing_resize();
  testing_irerator();
  testing_reverse_iterator();
  testing_reverse_iterator2();
  testing_erase_str();

  return 0;
}