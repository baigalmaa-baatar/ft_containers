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

	ft::AVLTree<int, int> *tree = NULL;
	ft::Node<int> *node = NULL;

    node = tree->insert(10);
    tree->insert(20);
    tree->insert(30);
    tree->insert(40);
    tree->insert(50);
    tree->insert(25);

	std::cout << "Preorder traversal of the above AVL tree is:\n"<< std::endl;
	tree->printTree(node);
    std::cout << '\n';
	//Deleting the node 25
    // tree = AVL_delete(tree, 20);
	// std::cout <<endl<<"preOrder traversal after"<< " deletion of 25:\n"<< std::endl;
	// preOrder(tree);
    std::cout << '\n';
	return 0;
}
