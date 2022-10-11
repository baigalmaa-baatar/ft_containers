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

  // std::cout << "0. ft_size: " << ft_stack.size() << '\n';
  std::cout << "0. size: " << std_stack.size() << '\n';

  // for (int i=0; i<5; i++) ft_stack.push(i);
  // std::cout << "1. ft_size: " << ft_stack.size() << '\n';

  for (int i = 0; i < 5; i++)
    std_stack.push(i);
  std::cout << "1. size: " << std_stack.size() << '\n';

  // ft_stack.pop();
  // std::cout << "2. ft_size: " << ft_stack.size() << '\n';

  std_stack.pop();
  std::cout << "2. size: " << std_stack.size() << '\n';

  return 0;
}