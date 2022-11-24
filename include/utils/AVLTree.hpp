/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:53:14 by bbaatar           #+#    #+#             */
/*   Updated: 2022/11/21 16:53:16 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
#include "./binarySearchTreeIterator.hpp"
#include "./reverseIterator.hpp"
#include "./utils.hpp"

/**
 *  About custom allocators :
 *  need to create special allocators for node allocators:
    https://docs.ros.org/en/dashing/Tutorials/Allocator-Template-Tutorial.html
    about rebind other struct:
    template <class Type> struct rebind {
        typedef allocator<Type> other;
        };

    template <> class allocator<void> {
    public:
        typedef void* pointer;
        typedef const void* const_pointer;
        typedef void value_type;
        template <class U> struct rebind { typedef allocator<U> other; };
    };
 *
*/

namespace ft
{
    template <class T, class Compare, class Alloc = std::allocator<T> >
    class AVLTree
    {
    public:
        // types:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef Compare value_compare;

    private: // for Nodes:
        typedef typename allocator_type::template rebind<Node<value_type> >::other node_allocator;
        typedef typename node_allocator::pointer node_pointer;
        typedef typename node_allocator::reference node_reference;
        typedef typename node_allocator::const_reference node_const_reference;
        typedef typename node_allocator::const_pointer node_const_pointer;
        typedef typename node_allocator::size_type node_size_type;  // See 23.1

        // for Iterators
    public:
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename std::ptrdiff_t difference_type;       // See 23.1
        typedef typename allocator_type::size_type size_type;  // See 23.1
        typedef BinarySearchTreeIterator<value_type> iterator; // See 23.1
        // typedef BinarySearchTreeIterator<const value_type> const_iterator;  // See 23.1 //later need to test maybe? add the const type
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        // typedef ft::reverse_iterator<const_iterator> const_reverse_iterator; after creating const iterator
        typedef typename value_type::first_type key_type;
        typedef typename value_type::second_type mapped_type;
        typedef ft::BinarySearchTreeIterator<pointer, node_pointer> iterator;
        typedef ft::BinarySearchTreeIterator<const_pointer, node_pointer> const_iterator;

    private:
        node_allocator _node_alloc;
        value_compare _compare;
        node_pointer _root;
        node_pointer _end;
        int _size;

    public:
        // Default constructor:
        AVLTree(const value_compare &compare = value_compare(), const node_allocator &alloc = node_allocator())
            : _compare(compare),
              _size(0)
        {
            this->_node_alloc = alloc;
            this->_end = this->_createNewNode(value_type());
            this->root = this->_end;
        }

        ~AVLTree() {}
        // _destroy, _remove, rebalance, reSetHeight??
        //  newnode, getHeigth, getbalance, leftrotate, rightrotate, RLrotate, LRrotate, insert, search

    private:
        int _getHeight(node_pointer N)
        {
            if (N == ft_nullptr)
                return 0;
            return (N->height);
        }

        int _max(int a, int b)
        {
            return (a > b) ? a : b;
        }

        node_pointer _minValTree(node_pointer node)
        {
            node_pointer curr = node;
            while (curr->left != ft_nullptr)
                curr = curr->left;
            return curr;
        }

        node_pointer _createNewNode(value_type key)
        {
            node_pointer node = _node_alloc.allocate(1);
            _node_alloc.construct(node, key);
            node->left = NULL;
            node->right = NULL;
            node->parent = NULL;
            return (node);
        }

        // Left Rotate
        node_pointer _leftRotate(node_pointer x)
        {
            node_pointer y = x->right;
            node_pointer T2 = y->left;
            node_pointer tmp = x->parent;

            y->left = x;
            x->right = T2;
            if (tmp != _end)
            {
                if (tmp->left == x)
                    tmp->left = y;
                else
                    tmp->right = y;
            }
            // y->parent = tmp;
            y->parent = x->parent;
            x->parent = y;

            if (T2 != ft_nullptr)
                T2->parent = x;
            x->height = _max(_getHeight(x->left),
                             _getHeight(x->right)) +
                        1;
            y->height = _max(_getHeight(y->left), _getHeight(y->right)) + 1;
            return (y);
        }

        // Right Rotate
        node_pointer _rightRotate(node_pointer y)
        {
            node_pointer x = y->left;
            node_pointer T3 = x->right;
            node_pointer tmp = y->parent;

            x->right = y;
            y->left = T3;
            if (tmp != _end)
            {
                if (tmp->left == y)
                    tmp->left = x;
                else
                    tmp->right = x;
            }
            // x->parent = tmp;
            x->parent = y->parent;
            y->parent = x;
            if (T3 != ft_nullptr)
                T3->parent = y;
            y->height = _max(_getHeight(y->left), _getHeight(y->right)) + 1;
            x->height = _max(_getHeight(x->left), _getHeight(x->right)) + 1;
            return (x);
        }

        // Left Right Rotate
        node_pointer _leftRightRotate(node_pointer node)
        {
            node->left = _leftRotate(node->left);
            return (_rightRotate(node));
        }

        // Right Left Rotate
        node_pointer _rightLeftRotate(node_pointer node)
        {
            node->right = _rightRotate(node->right);
            return (_leftRotate(node));
        }

        int _getBalance(node_pointer node)
        {
            if (node == ft_nullptr)
                return 0;
            return (_getHeight(node->left) - _getheight(node->right));
        }

        node_pointer _balanceTree(node_pointer root)
        {
            int balance = _getBalance(root);
            if (balance > 1)
            {
                if (_getBalance(root->left) >= 0) // Left Left Case
                    return (_rightRotate(root));
                else // Left Right Case
                {
                    root->left = _leftRotate(root->left);
                    return (_rightRotate(root));
                }
            }
            if (balance < -1)
            {
                if (_getBalance(root->right) <= 0) // Right Right Case
                    return (_leftRotate(root));
                else // Right Left Case
                {
                    root->right = _rightRotate(root->right);
                    return (_leftRotate(root));
                }
            }
            return (root);
        }

        // single element (1)
        // tmp : tmp root node, newNode : adding new node
        // node_pointer insert(node_pointer tmp, value_type &key)
        node_pointer _insert(node_pointer tmp, node_pointer newNode)
        {
            // 1. search if key exists
            // 2. if doesn't exist insert node
            /* 1. Perform the normal BST insertion */
            // if the tree is empty, add first node in tree:
            // ene hurte hiisen _end g sain sudlah heregtei.
            if (tmp == ft_nullptr && this->_end == ft_nullptr)
                return (newNode);
            if (this->_compare(newNode->key.first, tmp->key.first))
            {
                tmp->left = _insert(tmp->left, newNode->key);
                if (tmp->left == newNode)
                    newNode->parent = tmp;
            }
            else if (newNode->key > tmp->key)
            {
                tmp->right = _insert(tmp->right, newNode->key);
                if (tmp->right == newNode)
                    newNode->parent = tmp;
            }
            else
                return tmp;
            tmp->height = 1 + _max(_getHeight(tmp->left), _getHeight(tmp->right)); // do I need new funciton? in case of null subtrees?
            tmp = _balanceTree(tmp);
            return (tmp);
        }

        // node deletetion in tree
        node_pointer _remove(node_pointer root, value_type key)
        {
            if (root == ft_nullptr || root == this->_end)
                return (root);
            // Left Side
            if (key < root->key)
                root->left = _remove(root->left, key);

            // Right Side
            else if (key > root->key)
                root->right = _remove(root->right, key);
            // Root Node
            else
            {
                // Tree with only one child or no child
                if (root->left == ft_nullptr && root->right == ft_nullptr)
                {
                    _node_alloc.destroy(root);
                    _node_alloc.deallocate(root, 1);
                    root = ft_nullptr;
                    return (root);
                }
                else if (root->right == ft_nullptr)
                {
                    node_pointer tmp = root;
                    root = root->left;
                    root->parent = tmp->parent;
                    _node_alloc.destroy(tmp);
                    _node_alloc.deallocate(tmp, 1);
                    tmp = ft_nullptr;
                    return (root);
                }
                else if (root->left == ft_nullptr)
                {
                    node_pointer tmp = root;
                    root = root->right;
                    root->parent = tmp->parent;
                    _node_alloc.destroy(tmp);
                    _node_alloc.deallocate(tmp, 1);
                    tmp = ft_nullptr;
                    return (root);
                }
                else
                {
                    // AVL_Node with two children: Get the inorder
                    // successor (smallest in the right subtree)
                    node_pointer tmp = _minValTree(root->right);
                    root->key = tmp->key;
                    // Copy the inorder successor's
                    // data to this AVL_Node
                    // Delete the inorder successor
                    root->right = _remove(root->right, tmp->key);
                    // this->_node_alloc.construct(root, k);
                }
            }
            root->height = 1 + _max(_getHeight(root->left), _getHeight(root->right));
            root = _balanceTree(root);
            return root;
        }

        node_pointer _search(node_pointer root, value_type key)
        {
            if (root == ft_nullptr)
                return (this->_end);
            if (root->key.first == key)
                return (root);
            else if (this->_compare(key.first, root->key.first))
                root->left = _search(root->left, key);
            else if (this->_compare(root->key.first, key.first))
                root->right = _search(root->right, key);
            else
                return (this->_end);
        }

        // Public
    public:
        iterator end()
        {
            // return (iterator(MinNode()));
        }
        // const_iterator end() const
        // {

        // }
        iterator begin()
        {
            // if (_size == 0)
            //     return (iterator(_header));
            // else
            //     return (iterator(minNode(_root)));
        }
        // const_iterator begin() const
        // {

        // }
        reverse_iterator rbegin()
        {
            // return reverse_iterator(end());
        }
        // const_reverse_iterator rbegin() const
        // {

        // }
        reverse_iterator rend()
        {
            // return reverse_iterator(begin());
        }
        // const_reverse_iterator rend() const
        // {

        // }
        bool empty() const
        {
            return (_size == 0 ? true : false);
        }
        size_type size() const
        {
            return (_size);
        }

        size_type max_size() const
        {
            return (_node_alloc.max_size());
        }
        void clear()
        {
        }
        // iterator find(const value_type &x)
        // {
        // }
        void printTree(node_pointer root)
        {
            if (root != NULL)
            {
                std::cout << root->key << " ";
                preOrder(root->left);
                preOrder(root->right);
            }
        }
        // node_allocator _node_alloc;
        // value_compare _compare;
        // node_pointer _root;
        // node_pointer _end;
        // int _size;
        node_pointer insert(value_type key)
        {
            node_pointer newNode = _createNewNode(key);
            // if tree is empty:
            if (this->_root == this->_end)
            {
                this->_root = newNode;
                this->_end = this->_root;
                this->_size = 1;
            }
            // if there is already tree exists:
            this->_root = _insert(this->_root, newNode);
            this->_size++;
            return (newNode);
        }
    };
}

#endif
