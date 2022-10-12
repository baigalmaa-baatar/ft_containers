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

int main(void)
{
  ft::stack<int> ft_stack;
  std::stack<int> std_stack;

  // Testing member functions:
  for (int i=0; i<5; i++) ft_stack.push(i);
  for (int i=0; i<5; i++) std_stack.push(i);
  
  std::cout << '\n' << "0.empty" << '\n';
  std::cout << "ft empty: " << ft_stack.empty() << '\n';
  std::cout << "std empty: " << std_stack.empty() << '\n';
  
  std::cout << '\n' << "1.size" << '\n';
  std::cout << "ft size: " << ft_stack.size() << '\n';
  std::cout << "std size: " << std_stack.size() << '\n';

  std::cout << '\n' << "2.top" << '\n';
  std::cout << "ft top: " << ft_stack.top() << '\n';
  std::cout << "std top: " << std_stack.top() << '\n';
  
  std::cout << '\n' << "3.top const" << '\n';
  std::cout << "ft top const: " << ft_stack.top() << '\n';
  std::cout << "std top const: " << std_stack.top() << '\n';

  std::cout << '\n' << "4.push" << '\n';
  for (int i=5; i<10; i++) ft_stack.push(i);
  for (int i=5; i<10; i++) std_stack.push(i);
  std::cout << "ft size: " << ft_stack.size() << '\n';
  std::cout << "std size: " << std_stack.size() << '\n';
  
  std::cout << '\n' << "5.pop" << '\n';
  ft_stack.pop();
  std_stack.pop();
  std::cout << "ft_size: " << ft_stack.size() << '\n';
  std::cout << "size: " << std_stack.size() << '\n';

  return 0;
}