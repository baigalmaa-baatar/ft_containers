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
    template <typename T>
    struct Node
    {
    public:
        typedef T value_type;

    public:
        T key;
        Node *parent;
        Node *left;
        Node *right;
        int height;

    public:
        explicit Node() : key(){};
        Node(T key) : key(key){};
    };

    template <class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
    class AVLTree
    {
    public:
        // types:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef Compare key_compare;

    private: // for Nodes:
        typedef typename allocator_type::template rebind<Node<T> >::other node_allocator;
        typedef typename node_allocator::reference node_reference;
        typedef typename node_allocator::const_reference node_const_reference;
        typedef typename node_allocator::difference_type node_difference_type;
        typedef typename node_allocator::pointer node_alloc_pointer;
        typedef typename node_allocator::const_pointer node_const_pointer;
        typedef typename node_allocator::size_type node_size_type;
        typedef Node<value_type> node_type;
        typedef node_type *node_pointer;

    public:
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename std::ptrdiff_t difference_type;
        typedef typename allocator_type::size_type size_type;
        typedef typename value_type::first_type key_type;
        typedef typename value_type::second_type mapped_type;
        typedef ft::BinarySearchTreeIterator<pointer, node_pointer> iterator;
        typedef ft::BinarySearchTreeIterator<const_pointer, node_pointer> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

    private:
        node_allocator _node_alloc;
        key_compare _compare;
        node_pointer _root;
        node_pointer _end;
        int _size;

    public:
        // Default constructor:
        AVLTree(const key_compare &compare = key_compare(), const node_allocator &alloc = node_allocator())
            : _compare(compare),
              _size(0)
        {
            this->_node_alloc = alloc;
            this->_end = this->_createNewNode(value_type());
            this->_root = this->_end;
        };

        ~AVLTree(){};
        // _destroy, _remove, rebalance, reSetHeight??
        //  newnode, getHeigth, getbalance, leftrotate, rightrotate, RLrotate, LRrotate, insert, search

    private:
        int _getHeight(node_pointer N)
        {
            if (N == ft_nullptr)
                return 0;
            return (N->height);
        };

        int _max(int a, int b)
        {
            return (a > b) ? a : b;
        };

        node_pointer _minValTree(node_pointer node)
        {
            node_pointer curr = node;
            while (curr->left != ft_nullptr)
                curr = curr->left;
            return curr;
        };

        node_pointer _createNewNode(const value_type &key)
        {
            node_pointer node = this->_node_alloc.allocate(1);
            this->_node_alloc.construct(node, key);
            std::cout << "k:" << key.first << '\n';
            std::cout << "v:" << key.second << '\n';
            node->left = ft_nullptr;
            node->right = ft_nullptr;
            node->parent = ft_nullptr;
            node->height = 1;
            return (node);
        };

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
        };

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
        };

        // Left Right Rotate
        node_pointer _leftRightRotate(node_pointer node)
        {
            node->left = _leftRotate(node->left);
            return (_rightRotate(node));
        };

        // Right Left Rotate
        node_pointer _rightLeftRotate(node_pointer node)
        {
            node->right = _rightRotate(node->right);
            return (_leftRotate(node));
        };

        int _getBalance(node_pointer node)
        {
            if (node == ft_nullptr)
                return 0;
            return (_getHeight(node->left) - _getHeight(node->right));
        };

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
        };

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
            std::cout << "counter 1:" << '\n';
            if (tmp == ft_nullptr || this->_end == ft_nullptr)
            {
                std::cout << "if is empty insert private function:" << '\n';
                return (newNode);
            }
            if (this->_compare(newNode->key.first, tmp->key.first))
            // if (newNode->key < tmp->key)
            {
                std::cout << "if insert private function:" << '\n';
                tmp->left = _insert(tmp->left, newNode);
                if (tmp->left == newNode)
                    newNode->parent = tmp;
            }
            else if (this->_compare(tmp->key.first, newNode->key.first))
            {
                std::cout << "else if insert private function:" << '\n';
                tmp->right = _insert(tmp->right, newNode);

                if (tmp->right == newNode)
                {
                    newNode->parent = tmp;
                }
                // std::cout << "after if parent condition insert private function:" << '\n';
            }
            else
            {
                std::cout << "else insert private function:" << '\n';
                return tmp;
            }
            // std::cout << "height is :" << tmp->height << '\n';
            tmp->height = 1 + _max(_getHeight(tmp->left), _getHeight(tmp->right)); // do I need new funciton? in case of null subtrees?
            tmp = _balanceTree(tmp);
            return (tmp);
        };

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
        };

        node_pointer _search(node_pointer root, key_type key) const
        {
            if (root == ft_nullptr)
                return (this->_end);
            if (root->key.first == key)
                return (root);
            else if (this->_compare(key, root->key.first))
                root->left = _search(root->left, key);
            else if (this->_compare(root->key.first, key))
                root->right = _search(root->right, key);

            return (this->_end);
        };

        // Public
    public:
        iterator begin()
        {
            node_pointer tmp = this->_root;
            std::cout << "_root key is : " << _root->key.first << '\n';
            while (tmp != this->_end && tmp->left)
                tmp = tmp->left;
            return iterator(tmp);
        }
        iterator end() { return (iterator(this->_end)); };
        const_iterator end() const { return (const_iterator(this->_end)); };
        reverse_iterator rbegin() { return reverse_iterator(end()); };
        const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); };
        reverse_iterator rend() { return reverse_iterator(begin()); };
        const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };
        bool empty() const
        {
            return (_size == 0 ? true : false);
        };
        size_type size() const
        {
            return (_size);
        };

        size_type max_size() const
        {
            return (_node_alloc.max_size());
        };
        // clear, destruct and deallocate:
        void _destroy(node_pointer node)
        {
            if (node != ft_nullptr)
            {
                _destroy(node->left);
                _destroy(node->right);
                this->_node_alloc.destroy(node);
                this->_node_alloc.deallocate(node, 1);
            }
        }
        void clear()
        {
            if (this->_root != this->_end)
            {
                _destroy(this->_root);
                this->_size = 0;
                this->_root = this->_end;
                this->_end->left = this->_root;
            }
        };
        // iterator find(const value_type &x)
        // {
        // }
        // void printTree(node_pointer root) // Pre order traversal
        // {
        //     if (root != NULL)
        //     {
        //         std::cout << root->key << std::endl;
        //         printTree(root->left);
        //         printTree(root->right);
        //     }
        // };
        node_pointer search(key_type key) const
        {
            if (this->_root == this->_end)
            {
                // std::cout << "seach if " << '\n';
                return (this->_end);
            }
            else
            {
                // std::cout << "seach else " << '\n';
                return (_search(this->_root, key));
            }
        };
        node_pointer insert_pos(node_pointer pos, T key)
        {
            node_pointer newnode = _createNewNode(key);
            if (pos == this->_end)
            {
                pos = newnode;
                pos->parent = this->_end;
                this->_end->left = pos;
                ++this->_size;
            }
            else
            {
                ++this->_size;
                pos = _insert(pos, newnode);
            }
            return (newnode);
        };
        node_pointer insert(const value_type &key)
        {
            node_pointer newNode = _createNewNode(key);
            // printTree(newNode);
            // if tree is empty:
            std::cout << "key is : " << key.first << '\n';
            std::cout << "value is : " << key.second << '\n';
            if (this->_root != this->_end)
            {
                this->_root = newNode;
                std::cout << "if here" << '\n';
                this->_root->parent = this->_end;
                this->_end->left = this->_root;
                ++this->_size;
            }
            else
            {
                // std::cout << "else here" << '\n';
                // if there is already tree exists:
                this->_root = _insert(this->_root, newNode);
                std::cout << "after insert else here" << '\n';
                ++this->_size;
            }
            return (newNode);
        };
    };

    template <class node_pointer>
    node_pointer successor(node_pointer node)
    {
        if (node->right)
            return (_minValTree(node->right));

        node_pointer tmp = node->parent;
        while (tmp && tmp->right == node)
        {
            node = tmp;
            tmp = tmp->parent;
        }
        return (tmp);
    };

    template <class node_pointer>
    node_pointer predecessor(node_pointer node)
    {
        if (node->left)
            return (_maxValTree(node->left));

        node_pointer tmp = node->parent;
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
