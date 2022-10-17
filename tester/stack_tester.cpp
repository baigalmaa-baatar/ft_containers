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
#include <stack> // std::stack
#include "../include/Stack.hpp"

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
    /**
     * Member function empty() TRUE and FALSE test
     */

    std::stack<int> std_stack1;
    ft::stack<int> ft_stack1;

    comparisonFunc("Member function empty() TRUE test", std_stack1.empty(), ft_stack1.empty());

    for (int i = 0; i < 42; i++)
    {
      std_stack1.push(i);
      ft_stack1.push(i);
    }
    comparisonFunc("Member function empty() FALSE test", std_stack1.empty(), ft_stack1.empty());
  }
  {
    /**
     * Member function size() 0 test
     */

    std::stack<int> std_stack1;
    ft::stack<int> ft_stack1;

    comparisonFunc("Member function size() 0 test", std_stack1.size(), ft_stack1.size());

    for (int i = 0; i < 42; i++)
    {
      std_stack1.push(i);
      ft_stack1.push(i);
    }

    comparisonFunc("Member function size() not zero test", std_stack1.size(), ft_stack1.size());
  }

  {
    /**
     * Member function top() test
     */

    std::stack<int> std_stack1;
    ft::stack<int> ft_stack1;

    for (int i = 0; i < 42; i++)
    {
      std_stack1.push(i);
      ft_stack1.push(i);
    }

    comparisonFunc("Member function top() test", std_stack1.top(), ft_stack1.top());
  }
  {
    /**
     * Member function top() test
     */

    std::stack<int> std_stack1;
    ft::stack<int> ft_stack1;

    for (int i = 0; i < 42; i++)
    {
      std_stack1.push(i);
      ft_stack1.push(i);
    }

    comparisonFunc("Member function top() test", std_stack1.top(), ft_stack1.top());
  }
  {
    /**
     * Member function top() const test
     */

    std::stack<int> std_stack1;
    ft::stack<int> ft_stack1;

    int const i = 10;

    std_stack1.push(i);
    ft_stack1.push(i);

    std_stack1.top() = 5;
    ft_stack1.top() = 5;

    std::cout << std_stack1.size() << '\n';
    std::cout << ft_stack1.size() << '\n';
    comparisonFunc("Member function top() test", std_stack1.top(), ft_stack1.top());
  }
  {
    /**
     * Member function push() test
     */

    std::stack<int> std_stack1;
    ft::stack<int> ft_stack1;

    for (int i = 0; i < 42; i++)
    {
      std_stack1.push(i);
      ft_stack1.push(i);
    }

    comparisonFunc("Member function push() TOP test", std_stack1.top(), ft_stack1.top());
    comparisonFunc("Member function push() SIZE test", std_stack1.size(), ft_stack1.size());
  }
  {
    /**
     * Member function pop() test
     */

    std::stack<int> std_stack1;
    ft::stack<int> ft_stack1;

    for (int i = 0; i < 42; i++)
    {
      std_stack1.push(i);
      ft_stack1.push(i);
    }
    std_stack1.pop();
    ft_stack1.pop();
    comparisonFunc("Member function pop() TOP test", std_stack1.top(), ft_stack1.top());
    comparisonFunc("Member function pop() SIZE test", std_stack1.size(), ft_stack1.size());
  }
  {
    // non member operator "==" TRUE

    std::stack<int> std_stack1;
    std::stack<int> std_stack2;
    ft::stack<int> ft_stack1;
    ft::stack<int> ft_stack2;
    // Testing member functions:

    for (int i = 0; i < 10; i++)
    {
      std_stack1.push(i);
      std_stack2.push(i);
      ft_stack1.push(i);
      ft_stack2.push(i);
    }
    nonMemberComparison("Non-member operator == TRUE test", (std_stack1 == std_stack2), (ft_stack1 == ft_stack2));
    // std::cout << "Standard result:" << (std_stack1 == std_stack2) << '\n';
    // std::cout << "ft result:" << (ft_stack1 == ft_stack2) << '\n';
  }
  {
    // non member operator "==" FALSE

    std::stack<int> std_stack1;
    std::stack<int> std_stack2;
    ft::stack<int> ft_stack1;
    ft::stack<int> ft_stack2;

    for (int i = 0; i < 10; i++)
    {
      std_stack1.push(i);
      std_stack2.push(i + 1);
      ft_stack1.push(i);
      ft_stack2.push(i + 1);
    }
    nonMemberComparison("Non-member operator == FALSE test", (std_stack1 == std_stack2), (ft_stack1 == ft_stack2));
  }
  {
    // non member operator "<" TRUE
    std::stack<int> std_stack1;
    std::stack<int> std_stack2;
    ft::stack<int> ft_stack1;
    ft::stack<int> ft_stack2;

    for (int i = 0; i < 10; i++)
    {
      std_stack1.push(i);
      ft_stack1.push(i);
      std_stack2.push(i * 2);
      ft_stack2.push(i * 2);
    }
    nonMemberComparison("Non-member operator < true test", (std_stack1 < std_stack2), (ft_stack1 < ft_stack2));
  }
  {
    // non member operator "<" FALSE
    std::stack<int> std_stack1;
    std::stack<int> std_stack2;
    ft::stack<int> ft_stack1;
    ft::stack<int> ft_stack2;

    for (int i = 0; i < 10; i++)
    {
      std_stack1.push(i * 2);
      std_stack2.push(i);
      ft_stack1.push(i * 2);
      ft_stack2.push(i);
    }
    nonMemberComparison("Non-member operator < FALSE test", (std_stack1 < std_stack2), (ft_stack1 < ft_stack2));
  }
  {
    // non member operator "!=" TRUE
    std::stack<int> std_stack1;
    std::stack<int> std_stack2;
    ft::stack<int> ft_stack1;
    ft::stack<int> ft_stack2;

    for (int i = 0; i < 10; i++)
    {
      std_stack1.push(i * 2);
      std_stack2.push(i);
      ft_stack1.push(i * 2);
      ft_stack2.push(i);
    }
    nonMemberComparison("Non-member operator != TRUE test", (std_stack1 != std_stack2), (ft_stack1 != ft_stack2));
  }
  {
    // non member operator != FALSE
    std::stack<int> std_stack1;
    std::stack<int> std_stack2;
    ft::stack<int> ft_stack1;
    ft::stack<int> ft_stack2;

    for (int i = 0; i < 10; i++)
    {
      std_stack1.push(i);
      std_stack2.push(i);
      ft_stack1.push(i);
      ft_stack2.push(i);
    }
    nonMemberComparison("Non-member operator != FALSE test", (std_stack1 != std_stack2), (ft_stack1 != ft_stack2));
  }
  {
    // non member operator > TRUE
    std::stack<int> std_stack1;
    std::stack<int> std_stack2;
    ft::stack<int> ft_stack1;
    ft::stack<int> ft_stack2;

    for (int i = 0; i < 10; i++)
    {
      std_stack1.push(i * 2);
      std_stack2.push(i);
      ft_stack1.push(i * 2);
      ft_stack2.push(i);
    }
    nonMemberComparison("Non-member operator > TRUE test", (std_stack1 > std_stack2), (ft_stack1 > ft_stack2));
  }
  {
    // non member operator > FALSE
    std::stack<int> std_stack1;
    std::stack<int> std_stack2;
    ft::stack<int> ft_stack1;
    ft::stack<int> ft_stack2;

    for (int i = 0; i < 10; i++)
    {
      std_stack1.push(i);
      std_stack2.push(i * 2);
      ft_stack1.push(i);
      ft_stack2.push(i * 2);
    }
    nonMemberComparison("Non-member operator > FALSE test", (std_stack1 > std_stack2), (ft_stack1 > ft_stack2));
  }
  {
    // non member operator >= TRUE equal
    std::stack<int> std_stack1;
    std::stack<int> std_stack2;
    ft::stack<int> ft_stack1;
    ft::stack<int> ft_stack2;

    for (int i = 0; i < 10; i++)
    {
      std_stack1.push(i);
      std_stack2.push(i);
      ft_stack1.push(i);
      ft_stack2.push(i);
    }
    nonMemberComparison("Non-member operator >= TRUE equal test", (std_stack1 >= std_stack2), (ft_stack1 >= ft_stack2));
  }
  {
    // non member operator >= TRUE bigger
    std::stack<int> std_stack1;
    std::stack<int> std_stack2;
    ft::stack<int> ft_stack1;
    ft::stack<int> ft_stack2;

    for (int i = 0; i < 10; i++)
    {
      std_stack1.push(i * 2);
      std_stack2.push(i);
      ft_stack1.push(i * 2);
      ft_stack2.push(i);
    }
    nonMemberComparison("Non-member operator >= TRUE bigger test", (std_stack1 >= std_stack2), (ft_stack1 >= ft_stack2));
  }
  {
    // non member operator >= FALSE
    std::stack<int> std_stack1;
    std::stack<int> std_stack2;
    ft::stack<int> ft_stack1;
    ft::stack<int> ft_stack2;

    for (int i = 0; i < 10; i++)
    {
      std_stack1.push(i);
      std_stack2.push(i * 2);
      ft_stack1.push(i);
      ft_stack2.push(i * 2);
    }
    nonMemberComparison("Non-member operator >= FALSE test", (std_stack1 >= std_stack2), (ft_stack1 >= ft_stack2));
  }
  {
    // non member operator <= TRUE equal
    std::stack<int> std_stack1;
    std::stack<int> std_stack2;
    ft::stack<int> ft_stack1;
    ft::stack<int> ft_stack2;

    for (int i = 0; i < 10; i++)
    {
      std_stack1.push(i);
      std_stack2.push(i);
      ft_stack1.push(i);
      ft_stack2.push(i);
    }
    nonMemberComparison("Non-member operator >= TRUE equal test", (std_stack1 <= std_stack2), (ft_stack1 <= ft_stack2));
  }
  {
    // non member operator <= TRUE smaaller
    std::stack<int> std_stack1;
    std::stack<int> std_stack2;
    ft::stack<int> ft_stack1;
    ft::stack<int> ft_stack2;

    for (int i = 0; i < 10; i++)
    {
      std_stack1.push(i);
      std_stack2.push(i * 2);
      ft_stack1.push(i);
      ft_stack2.push(i * 2);
    }
    nonMemberComparison("Non-member operator >= TRUE smaller test", (std_stack1 <= std_stack2), (ft_stack1 <= ft_stack2));
  }
  {
    // non member operator <= FALSE
    std::stack<int> std_stack1;
    std::stack<int> std_stack2;
    ft::stack<int> ft_stack1;
    ft::stack<int> ft_stack2;

    for (int i = 0; i < 10; i++)
    {
      std_stack1.push(i * 2);
      std_stack2.push(i);
      ft_stack1.push(i * 2);
      ft_stack2.push(i);
    }
    nonMemberComparison("Non-member operator <= FALSE test", (std_stack1 <= std_stack2), (ft_stack1 <= ft_stack2));
  }
  
  return 0;
}