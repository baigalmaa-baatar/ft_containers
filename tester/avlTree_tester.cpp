/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlTree_tester.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:26:32 by bbaatar           #+#    #+#             */
/*   Updated: 2022/11/24 16:26:34 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils/AVLTree.hpp"

int main(){

	ft::AVLTree<int> *tree = NULL;
	ft::Node<int> *node = NULL;


    node = tree->insert(10);

	std::cout << "Preorder traversal of the above AVL tree is:\n"<< std::endl;
	tree->printTree(node);
    std::cout << '\n';
	return 0;
}
