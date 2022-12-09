/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree_iterator.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:53:27 by bbaatar           #+#    #+#             */
/*   Updated: 2022/11/21 16:53:29 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_ITERATOR_HPP
#define BINARY_SEARCH_TREE_ITERATOR_HPP
#include <iostream>
#include <iterator>
#include "utils.hpp"
#include "reverseIterator.hpp"

// Created here Binary Search Iterator and CONST Binary Search iterator 2 class
namespace ft
{
	/**************************************************************************************/
	/**                             Non const binary search iterator                          */
	/**************************************************************************************/

	template <class T, class Node_pointer>
	class BinarySearchTreeIterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
	public:
		typedef T iterator_type;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef typename iterator_traits<T *>::value_type value_type;
		typedef typename iterator_traits<T>::pointer pointer;
		typedef typename iterator_traits<T>::reference reference;
		typedef typename iterator_traits<T>::difference_type difference_type;
	
	private:
		Node_pointer _node;

	public:
		BinarySearchTreeIterator() : _node(ft_nullptr) {}
		explicit BinarySearchTreeIterator(Node_pointer node) : _node(node) {}
		template <class Iterator>
		BinarySearchTreeIterator(const BinarySearchTreeIterator<Iterator, Node_pointer> &obj) : _node(obj.base()) {}
		// Copy operator
		BinarySearchTreeIterator &operator=(const BinarySearchTreeIterator &rhs)
		{
			if (this == &rhs)
				return (*this);
			this->_node = rhs.node();
			return (*this);
		}
		~BinarySearchTreeIterator(void) {}
		Node_pointer base() const { return (this->_node); };
		reference operator*() const { return (this->_node->key); }
		pointer operator->() const { return (&(operator*())); }
		Node_pointer node() const { return _node; }
		reference operator[](difference_type n) const { return (*(this->_node + n)); };
		// which use case?
		 bool operator==(const BinarySearchTreeIterator &obj)	{	return (this->_node == obj._node);}
		 bool operator!=(const BinarySearchTreeIterator &obj)	{	return (this->_node != obj._node);}

		// https://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/
		/**
		 * Output: succ // succ is Inorder successor of node.

			1. If right subtree of node is not NULL, then succ lies in right subtree. Do the following.
				Go to right subtree and return the node with minimum key value in the right subtree.
			2. If right subtree of node is NULL, then start from the root and use search-like technique. Do the following.
				Travel down the tree, if a node’s data is greater than root’s data then go right side, otherwise, go to left side.
		*/

		BinarySearchTreeIterator &operator++()
		{
			this->_node = successor(this->_node);
			return (*this);
		}

		BinarySearchTreeIterator operator++(int)
		{
			BinarySearchTreeIterator<value_type, Node_pointer> tmp = *this;
			operator++();
			return (tmp);
		}
		BinarySearchTreeIterator &operator--()
		{
			this->_node = predecessor(this->_node);
			return (*this);
		}; // pre-decrement

		BinarySearchTreeIterator operator--(int)
		{
			BinarySearchTreeIterator<value_type, Node_pointer> tmp = *this;
			operator--();
			return (tmp);
		}
	};

	template <class T, class Node_pointer>
	bool operator==(
		const BinarySearchTreeIterator<T, Node_pointer> &lhs,
		const BinarySearchTreeIterator<T, Node_pointer> &rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class T, class Node_pointer>
	bool operator!=(
		const BinarySearchTreeIterator<T, Node_pointer> &lhs,
		const BinarySearchTreeIterator<T, Node_pointer> &rhs)
	{
		return !(lhs.base() == rhs.base());
	}
	template <class Node_pointer>
	Node_pointer minValTree(Node_pointer tmp)
	{
		while (tmp->left != ft_nullptr)
			tmp = tmp->left;
		return (tmp);
	};

	template <class Node_pointer>
	Node_pointer maxValTree(Node_pointer tmp)
	{
		while (tmp->right != ft_nullptr)
			tmp = tmp->right;
		return (tmp);
	};

	template <class Node_pointer>
	Node_pointer successor(Node_pointer node)
	{
		if (node->right)
			return (minValTree(node->right));

		Node_pointer tmp = node->parent;
		while (tmp && tmp->right == node)
		{
			node = tmp;
			tmp = tmp->parent;
		}
		return (tmp);
	};

	template <class Node_pointer>
	Node_pointer predecessor(Node_pointer node)
	{
		if (node->left)
			return (maxValTree(node->left));

		Node_pointer tmp = node->parent;
		while (tmp && tmp->left == node)
		{
			node = tmp;
			tmp = tmp->parent;
		}
		if (tmp == ft_nullptr)
			return (node);
		return (tmp);
	};
}
#endif