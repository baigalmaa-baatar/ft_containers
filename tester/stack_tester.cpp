/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tester.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <bbaatar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:01:00 by bbaatar           #+#    #+#             */
/*   Updated: 2022/10/11 11:01:02 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifdef STD
#include <stack>
namespace ft = std;
#else
#include "../include/stack.hpp"
#endif

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

void testing_constructors(void)
{
  /**
   * Member function empty() TRUE and FALSE test
   */

  ft::stack<int> stk;

  stk.push(21);
  stk.push(22);
  stk.push(24);
  stk.push(25);

  while (!stk.empty())
  {
    std::cout << stk.top() << " ";
    stk.pop();
  }
}

void testing_size()
{
  /**
   * Member function size() 0 test
   */

  ft::stack<int> ft_stack1;

  for (int i = 0; i < 42; i++)
  {
    ft_stack1.push(i);
  }
  std::cout << ft_stack1.size() << '\n';
}

void testing_top()
{
  /**
   * Member function top() test
   */
  ft::stack<int> ft_stack1;

  for (int i = 0; i < 42; i++)
  {
    ft_stack1.push(i);
  }
  std::cout << ft_stack1.top() << '\n';
}

void testing_top2()
{
  /**
   * Member function top() test
   */

  ft::stack<int> ft_stack1;

  for (int i = 0; i < 42; i++)
  {
    ft_stack1.push(i);
  }

  std::cout << ft_stack1.top() << '\n';
}
void testing_top_const()
{
  /**
   * Member function top() const test
   */

  ft::stack<int> ft_stack1;

  int const i = 10;

  ft_stack1.push(i);

  ft_stack1.top() = 5;

  std::cout << ft_stack1.size() << '\n';
  std::cout << ft_stack1.top() << '\n';
}
void testing_push()
{
  /**
   * Member function push() test
   */

  ft::stack<int> ft_stack1;

  for (int i = 0; i < 42; i++)
  {
    ft_stack1.push(i);
  }
  std::cout << ft_stack1.size() << '\n';
  std::cout << ft_stack1.top() << '\n';
}
void testing_pop()
{
  /**
   * Member function pop() test
   */

  ft::stack<int> ft_stack1;

  for (int i = 0; i < 42; i++)
  {
    ft_stack1.push(i);
  }
  ft_stack1.pop();
  std::cout << ft_stack1.size() << '\n';
  std::cout << ft_stack1.top() << '\n';
}

void testing_operator_equal()
{
  // non member operator "==" TRUE

  ft::stack<int> ft_stack1;
  ft::stack<int> ft_stack2;
  // Testing member functions:

  for (int i = 0; i < 10; i++)
  {
    ft_stack1.push(i);
    ft_stack2.push(i);
  }
  std::cout << "ft result:" << (ft_stack1 == ft_stack2) << '\n';
}
void testing_operator_equal2()
{
  // non member operator "==" FALSE

  ft::stack<int> ft_stack1;
  ft::stack<int> ft_stack2;

  for (int i = 0; i < 10; i++)
  {
    ft_stack1.push(i);
    ft_stack2.push(i + 1);
  }
  std::cout << "ft result:" << (ft_stack1 == ft_stack2) << '\n';
}

void testing_operator3()
{
  // non member operator "<" TRUE
  ft::stack<int> ft_stack1;
  ft::stack<int> ft_stack2;

  for (int i = 0; i < 10; i++)
  {
    ft_stack1.push(i);
    ft_stack2.push(i * 2);
  }
  std::cout << "ft result:" << (ft_stack1 == ft_stack2) << '\n';
}

void testing_operator4()
{
  // non member operator "<" FALSE
  ft::stack<int> ft_stack1;
  ft::stack<int> ft_stack2;

  for (int i = 0; i < 10; i++)
  {
    ft_stack1.push(i * 2);
    ft_stack2.push(i);
  }
  std::cout << "ft result:" << (ft_stack1 == ft_stack2) << '\n';
}

void testing_operator5()
{
  // non member operator "!=" TRUE
  ft::stack<int> ft_stack1;
  ft::stack<int> ft_stack2;

  for (int i = 0; i < 10; i++)
  {
    ft_stack1.push(i * 2);
    ft_stack2.push(i);
  }
  std::cout << "ft result:" << (ft_stack1 != ft_stack2) << '\n';
}
void testing_operator6()
{
  // non member operator != FALSE
  ft::stack<int> ft_stack1;
  ft::stack<int> ft_stack2;

  for (int i = 0; i < 10; i++)
  {
    ft_stack1.push(i);
    ft_stack2.push(i);
  }
  std::cout << "ft result:" << (ft_stack1 != ft_stack2) << '\n';
}
void testing_operator7()
{
  // non member operator > TRUE
  ft::stack<int> ft_stack1;
  ft::stack<int> ft_stack2;

  for (int i = 0; i < 10; i++)
  {
    ft_stack1.push(i * 2);
    ft_stack2.push(i);
  }
  std::cout << "ft result:" << (ft_stack1 > ft_stack2) << '\n';

}
void testing_operator8()
{
  // non member operator > FALSE
  ft::stack<int> ft_stack1;
  ft::stack<int> ft_stack2;

  for (int i = 0; i < 10; i++)
  {
    ft_stack1.push(i);
    ft_stack2.push(i * 2);
  }
  std::cout << "ft result:" << (ft_stack1 > ft_stack2) << '\n';
}

void testing_operator9()
{
  // non member operator >= TRUE equal
  ft::stack<int> ft_stack1;
  ft::stack<int> ft_stack2;

  for (int i = 0; i < 10; i++)
  {
    ft_stack1.push(i);
    ft_stack2.push(i);
  }
  std::cout << "ft result:" << (ft_stack1 >= ft_stack2) << '\n';
}

void testing_operator10()
{
  // non member operator >= TRUE bigger
  ft::stack<int> ft_stack1;
  ft::stack<int> ft_stack2;

  for (int i = 0; i < 10; i++)
  {
    ft_stack1.push(i * 2);
    ft_stack2.push(i);
  }
  std::cout << "ft result:" << (ft_stack1 >= ft_stack2) << '\n';
}

void testing_operator11()
{
  // non member operator >= FALSE
  ft::stack<int> ft_stack1;
  ft::stack<int> ft_stack2;

  for (int i = 0; i < 10; i++)
  {
    ft_stack1.push(i);
    ft_stack2.push(i * 2);
  }
  std::cout << "ft result:" << (ft_stack1 >= ft_stack2) << '\n';
}

void testing_operator12()
{
  // non member operator <= TRUE equal
  ft::stack<int> ft_stack1;
  ft::stack<int> ft_stack2;

  for (int i = 0; i < 10; i++)
  {
    ft_stack1.push(i);
    ft_stack2.push(i);
  }
  std::cout << "ft result:" << (ft_stack1 <= ft_stack2) << '\n';
}

void testing_operator13()
{
  // non member operator <= TRUE smaaller
  ft::stack<int> ft_stack1;
  ft::stack<int> ft_stack2;

  for (int i = 0; i < 10; i++)
  {
    ft_stack1.push(i);
    ft_stack2.push(i * 2);
  }
  std::cout << "ft result:" << (ft_stack1 <= ft_stack2) << '\n';
}

void testing_operator14()
{
  // non member operator <= FALSE
  ft::stack<int> ft_stack1;
  ft::stack<int> ft_stack2;

  for (int i = 0; i < 10; i++)
  {
    ft_stack1.push(i * 2);
    ft_stack2.push(i);
  }
  std::cout << "ft result:" << (ft_stack1 <= ft_stack2) << '\n';
}
void testing_operator15()
{
  #define t_stack_ ft::stack<int>
  typedef t_stack_::container_type container_type;

  container_type ctnr;

  // container_type ctnr;
  ctnr.push_back(21);
  ctnr.push_back(42);
  ctnr.push_back(1337);
  ctnr.push_back(19);
  ctnr.push_back(0);
  ctnr.push_back(183792);

  t_stack_ stck(ctnr);

  std::cout << "empty: " << stck.empty() << std::endl;
  std::cout << "size: " << stck.size() << std::endl;

  stck.push(1);
  stck.push(2);
  stck.push(3);
  stck.push(4);
  stck.push(5);
  stck.push(6);

  std::cout << "Added some elements" << std::endl;
  std::cout << "empty: " << stck.empty() << std::endl;
}

int main(void)
{
  testing_constructors();
  testing_size();
  testing_top();
  testing_top2();
  testing_top_const();
  testing_push();
  testing_pop();
  testing_operator_equal();;
  testing_operator_equal2();
  testing_operator3();
  testing_operator4();
  testing_operator5();
  testing_operator6();
  testing_operator7();
  testing_operator8();
  testing_operator9();
  testing_operator10();
  testing_operator11();
  testing_operator12();
  testing_operator13();
  testing_operator14();
  testing_operator15();

  return 0;
}