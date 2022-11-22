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
    template <class T, class Compare = ft::less<T>, class Alloc = std::allocator<T>>
    class AVLTree
    {
    public:
        // types:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef Compare value_compare;
        typedef typename allocator_type::template rebind<Node<value_type>>::other node_allocator;
        typedef typename node_allocator::pointer node_pointer;
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

    private:
        allocator_type _val_alloc;
        node_allocator _node_alloc;
        value_compare _compare;
        node_pointer _nil;
        node_pointer _header;
        node_pointer _root;
        size_type _size;

        // Private functions:
        node_pointer minNode(node_pointer node) const
        {
            /* loop down to find the leftmost leaf */
            while (node != NULL && !is_nil(node->left))
                node = node->left;
            return node;
        }
        node_pointer maxNode(node_pointer node) const
        {
            while (node != NULL && !is_nil(node->right))
                node = node->right;
            return node;
        }

    public:
        node_pointer rightRotate(node_pointer y)
        {
            node_pointer x = y->left;
            node_pointer T2 = x->right;

            // Perform rotation
            x->right = y;
            y->left = T2;

            // Update heights
            y->height = max(height(y->left),
                            height(y->right)) +
                        1;
            x->height = max(height(x->left),
                            height(x->right)) +
                        1;

            // Return new root
            return x;
        }
        // A utility function to left
        // rotate subtree rooted with x
        // See the diagram given above.
        node_pointer leftRotate(node_pointer x)
        {
            node_pointer y = x->right;
            node_pointer T2 = y->left;

            // Perform rotation
            y->left = x;
            x->right = T2;

            // Update heights
            x->height = max(height(x->left),
                            height(x->right)) +
                        1;
            y->height = max(height(y->left),
                            height(y->right)) +
                        1;

            // Return new root
            return y;
        }

        // Get Balance factor of node N
        int getBalance(node_pointer N)
        {
            if (N == NULL)
                return 0;
            return height(N->left) - height(N->right);
        }

        // Recursive function to insert a key
        // in the subtree rooted with node and
        // returns the new root of the subtree.

        // single element (1)
        ft::pair<iterator, bool> insert(const value_type &val)
        {
            // 1. search if key exists
            // 2. if doesn't exist insert node
            // Node *insert(Node * node, int key)
            // {
            /* 1. Perform the normal BST insertion */
            bool 
            if (node == NULL)
                return (newNode(key));

            if (key < node->key)
                node->left = insert(node->left, key);
            else if (key > node->key)
                node->right = insert(node->right, key);
            else // Equal keys are not allowed in BST
                return node;

            /* 2. Update height of this ancestor node */
            node->height = 1 + max(height(node->left),
                                   height(node->right));

            /* 3. Get the balance factor of this ancestor
                node to check whether this node became
                unbalanced */
            int balance = getBalance(node);

            // If this node becomes unbalanced, then
            // there are 4 cases

            // Left Left Case
            if (balance > 1 && key < node->left->key)
                return rightRotate(node);

            // Right Right Case
            if (balance < -1 && key > node->right->key)
                return leftRotate(node);

            // Left Right Case
            if (balance > 1 && key > node->left->key)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
                // }
            }
            //    with hint (2)
            iterator insert(iterator position, const value_type &val);
            //    range (3)
            template <class InputIterator>
            void insert(InputIterator first, InputIterator last);

            node_pointer insert(node_pointer node, value_type val)
            {
                /* 1. Perform the normal BST insertion */
                if (node == NULL)
                    return (node(val));

                if (val < node->val)
                    node->left = insert(node->left, val);
                else if (val > node->val)
                    node->right = insert(node->right, val);
                else // Equal values are not allowed in BST
                    return node;

                /* 2. Update height of this ancestor node_pointer /
                node->height = 1 + max(height(node->left),
                                       height(node->right));

                  3. Get the balance factor of this ancestor
                    node to check whether this node became
                    unbalanced
                */
                int balance = getBalance(node);

                // If this node becomes unbalanced, then
                // there are 4 cases

                // Left Left Case
                if (balance > 1 && val < node->left->val)
                    return rightRotate(node);

                // Right Right Case
                if (balance < -1 && val > node->right->val)
                    return leftRotate(node);

                // Left Right Case
                if (balance > 1 && val > node->left->val)
                {
                    node->left = leftRotate(node->left);
                    return rightRotate(node);
                }

                // Right Left Case
                if (balance < -1 && val < node->right->val)
                {
                    node->right = rightRotate(node->right);
                    return leftRotate(node);
                }

                /* return the (unchanged) node pointer */
                return node;
            }
            void init_nil_head()
            {
                _nil = _node_alloc.allocate(1);
                _node_alloc.construct(_nil, Node<value_type>());
                _nil->is_nil = true;
                _header = _node_alloc.allocate(1);
                _node_alloc.construct(_header, Node<value_type>());
                _header->val = _val_alloc.allocate(1);
                _val_alloc.construct(_header->val, value_type());
            }

            // Public
        public:
            // Default constructor
            AVLTree(const Compare &comp, const allocator_type &a = allocator_type()) : _val_alloc(a), _node_alloc(node_allocator()), _compare(comp), _root(0), _size(0)
            {
                init_nil_head();
                _root = _header;
            }
            // Fill constructor
            AVLTree() : _root(0), _val_alloc(allocator_type()), _node_alloc(node_allocator()), _compare(value_compare()), _size(0)
            {
                init_nil_head();
                _root = _header;
            }
            // Copy constructor
            AVLTree(const AVLTree &src) : _compare(src._compare), _root(NULL)
            {
                *this = src;
            }
            // Range constructor
            template <class InputIterator>
            AVLTree(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last,
                    const value_compare &comp, const allocator_type &alloc = allocator_type()) : _val_alloc(alloc),
                                                                                                 _node_alloc(node_allocator()),
                                                                                                 _compare(comp)
            {
                init_nil_head();
                _root = _header;
                (void)first;
                (void)last;
                // for (; first != last; ++first)
                //     insert(*first); //add after adding ranges
            }
            // Print the nodes:
            // void printInorder(node_pointer root)
            // {
            //     while (root != NULL)
            //     {
            //         printInorder(root->left);
            //         std::cout << root->val << " ";
            //         printInorder(root->right);
            //     }
            // }
            void preOrder(node_pointer root)
            {
                if (root != NULL)
                {
                    std::cout << root->key << " ";
                    preOrder(root->left);
                    preOrder(root->right);
                }
            }
            iterator end()
            {
                return (iterator(_header));
            }
            // const_iterator end() const
            // {

            // }
            iterator begin()
            {
                if (_size == 0)
                    return (iterator(_header));
                else
                    return (iterator(minNode(_root)));
            }
            // const_iterator begin() const
            // {

            // }
            reverse_iterator rbegin()
            {
                return reverse_iterator(end());
            }
            // const_reverse_iterator rbegin() const
            // {

            // }
            reverse_iterator rend()
            {
                return reverse_iterator(begin());
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
                return (_val_alloc.max_size());
            }
            void clear()
            {
            }
            iterator find(const key_type &x)
            {
                
            }
        };
    }

#endif
