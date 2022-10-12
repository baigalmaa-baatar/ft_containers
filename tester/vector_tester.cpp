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

int main(void)
{
  ft::vector<int> ft_vector;
  std::vector<int> std_vector;

  // Testing member functions:
  for (int i=0; i<5; i++) ft_vector.push_back(i);
  for (int i=0; i<5; i++) std_vector.push_back(i);
  
  std::cout << '\n' << "0.empty" << '\n';
  std::cout << "ft empty: " << ft_vector.empty() << '\n';
  std::cout << "std empty: " << std_vector.empty() << '\n';
  
  std::cout << '\n' << "1.size" << '\n';
  std::cout << "ft size: " << ft_vector.size() << '\n';
  std::cout << "std size: " << std_vector.size() << '\n';

  std::cout << '\n' << "2.top" << '\n';
//   std::cout << "ft top: " << ft_vector.top() << '\n';
//   std::cout << "std top: " << std_vector.top() << '\n';
  
  std::cout << '\n' << "3.top const" << '\n';
//   std::cout << "ft top const: " << ft_vector.top() << '\n';
//   std::cout << "std top const: " << std_vector.top() << '\n';

  std::cout << '\n' << "4.push" << '\n';
  for (int i=5; i<10; i++) ft_vector.push_back(i);
  for (int i=5; i<10; i++) std_vector.push_back(i);
  std::cout << "ft size: " << ft_vector.size() << '\n';
  std::cout << "std size: " << std_vector.size() << '\n';
  
  std::cout << '\n' << "5.pop" << '\n';
  ft_vector.pop_back();
  std_vector.pop_back();
  std::cout << "ft_size: " << ft_vector.size() << '\n';
  std::cout << "size: " << std_vector.size() << '\n';

  return 0;
}

