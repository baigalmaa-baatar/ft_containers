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

	template <typename T>
	class BinarySearchTreeIterator
	{
	public:
		typedef typename ft::iterator_traits<T *>::value_type value_type;
		typedef typename ft::iterator_traits<T *>::pointer pointer;
		typedef typename ft::iterator_traits<T *>::reference reference;
		typedef typename ft::iterator_traits<T *>::difference_type difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef Node<typename ft::remove_const<value_type>::type> *node_pointer;

	private:
		node_pointer _node;
		node_pointer minValue(node_pointer node)
		{
			/* loop down to find the leftmost leaf */
			while (node->left != NULL)
			{
				node = node->left;
			}
			return node;
		}
		node_pointer maxValue(node_pointer node)
		{
			/* loop down to find the rightmost leaf */
			while (node->right != NULL)
			{
				node = node->right;
			}
			return node;
		}

	public:
		BinarySearchTreeIterator(void) {}
		// BinarySearchTreeIterator(void *node) : _node(static_cast<node_pointer>(node)){}
		// need to cast to static
		BinarySearchTreeIterator(void *node) : _node(node)
		{
		}
		// BinarySearchTreeIterator(const Node<typename ft::remove_const<value_type>::type> &obj) : _node(obj._node)
		BinarySearchTreeIterator(const BinarySearchTreeIterator<typename ft::remove_const<value_type>::type> &obj)
		{
			*this = obj;
		}
		BinarySearchTreeIterator &operator=(const BinarySearchTreeIterator &rhs)
		{
			if (this == &rhs)
				return (*this);
			this->_node = rhs.node();
			return (*this);
		}
		~BinarySearchTreeIterator(void) {}

		bool operator==(const BinarySearchTreeIterator &obj)
		{
			return (this->_node == obj._node);
		}

		bool operator!=(const BinarySearchTreeIterator &obj)
		{
			return (this->_node != obj._node);
		}
		/**
		 * "*a=t"?
		 */
		reference operator*()
		{
			// std::cout << "calling here *a=t" << '\n';
			return (*(_node->value));
		}
		pointer operator->() const
		{
			return &(operator*());
		}
		node_pointer node() const
		{
			return _node;
		}
		/**
		 * "a++"
		 */
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
				node_pointer par = _node->parent;
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
			BinarySearchTreeIterator<value_type> tmp = *this;
			operator++();
			return (tmp);
		}
		/**
		 * "a--"
		 */
		BinarySearchTreeIterator &operator--()
		{
			if (_node->left != NULL && !_node->left->is_nil)
				_node = maxValue(_node->left);
			else
			{
				node_pointer par = _node->parent;
				while (_node != NULL && _node == par->left)
				{
					_node = par;
					par = par->parent;
				}
				_node = par;
			}
			return (*this);
		}
		/**
		 * "--a"
		 */
		BinarySearchTreeIterator &operator--(int)
		{
			BinarySearchTreeIterator<value_type> tmp = *this;
			operator--();
			return (tmp);
		}
	};
	template <typename A, typename B>
	bool operator==(
		const BinarySearchTreeIterator<A> &lhs,
		const BinarySearchTreeIterator<B> &rhs)
	{
		return (lhs._node == rhs._node);
	}
	template <typename A, typename B>
	bool operator!=(
		const BinarySearchTreeIterator<A> &lhs,
		const BinarySearchTreeIterator<B> &rhs)
	{
		return !(lhs._node == rhs._node);
	}
}
#endif
