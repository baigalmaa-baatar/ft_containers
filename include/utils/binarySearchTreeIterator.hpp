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
#include "utils.hpp"

namespace ft
{
	template <typename T>
	struct Node
	{
	public:
		typedef T	value_type;
	public:
		T	key;
		Node *parent;
		Node *left;
		Node *right;
		int height;

	public:
		explicit Node() : key() {};
		Node(T key) : key(key) {};
	};

	template<class T, class Node_pointer>
	class BinarySearchTreeIterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
	public:
		typedef typename ft::iterator_traits<T *>::value_type		value_type;
		typedef typename ft::iterator_traits<T *>::pointer			pointer;
		typedef typename ft::iterator_traits<T *>::reference		reference;
		typedef typename ft::iterator_traits<T *>::difference_type	difference_type;
		typedef std::bidirectional_iterator_tag 					iterator_category;
		// typedef Node<typename ft::remove_const<value_type>::type> 	*Node_pointer;

	private:
		Node_pointer _node;

		Node_pointer minValue(Node_pointer node)
		{
			/* loop down to find the leftmost leaf */
			while (node->left != NULL)
			{
				node = node->left;
			}
			return node;
		}
		Node_pointer maxValue(Node_pointer node)
		{
			/* loop down to find the rightmost leaf */
			while (node->right != NULL)
			{
				node = node->right;
			}
			return node;
		}

	public:	
		BinarySearchTreeIterator() : _node(ft_nullptr) {}
		explicit BinarySearchTreeIterator(Node_pointer node) : _node(node) {}
		template <class Iterator>
		BinarySearchTreeIterator(const BinarySearchTreeIterator<Iterator, Node_pointer> &obj) : _node(obj.base()) {}
		//Copy operator
		BinarySearchTreeIterator &operator=(const BinarySearchTreeIterator &rhs)
		{
			if (this == &rhs)
				return (*this);
			this->_node = rhs.node();
			return (*this);
		}
		~BinarySearchTreeIterator(void) {}
		Node_pointer	base() const							{	return (this->_node); };
		bool operator==(const BinarySearchTreeIterator &obj)	{	return (this->_node == obj._node);}
		bool operator!=(const BinarySearchTreeIterator &obj)	{	return (this->_node != obj._node);}
		reference operator*() const 							{ 	return (this->_node->key);}
		pointer operator->() const								{	return (&(operator*()));}
		Node_pointer node() const								{	return _node;}
		reference operator[]( difference_type n ) const			{ 	return (*(this->_node + n)); };

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
			if (_node->right != NULL && !_node->right->is_nil)
				_node = minValue(_node->right);
			else
			{
				Node_pointer par = _node->parent;
				while (_node != NULL && _node == par->right)
				{
					_node = par;
					par = par->parent;
				}
				_node = par;
			}
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
			if (_node->left != NULL && !_node->left->is_nil)
				_node = maxValue(_node->left);
			else
			{
				Node_pointer par = _node->parent;
				while (_node != NULL && _node == par->left)
				{
					_node = par;
					par = par->parent;
				}
				_node = par;
			}
			return (*this);
		}

		BinarySearchTreeIterator &operator--(int)
		{
			BinarySearchTreeIterator<value_type, Node_pointer> tmp = *this;
			operator--();
			return (tmp);
		}
	};

	template <class T, class Node_pointer>
	bool operator==(
		const BinarySearchTreeIterator<T, Node_pointer>& lhs,
		const BinarySearchTreeIterator<T, Node_pointer>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class T, class Node_pointer>
	bool operator!=(
		const BinarySearchTreeIterator<T, Node_pointer>& lhs,
		const BinarySearchTreeIterator<T, Node_pointer>& rhs)
	{
		return !(lhs.base() == rhs.base());
	}
	//check if other operators need to develop
}
#endif
