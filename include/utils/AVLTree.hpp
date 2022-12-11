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
#include "binarySearchTreeIterator.hpp"
#include "utils.hpp"
#include "reverseIterator.hpp"
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
        typedef T       value_type;

    public:
        T               key;
        Node            *parent;
        Node            *left;
        Node            *right;
        int             height;

    public:
        Node() :        key(){};
        Node(T key) :   key(key){};
    };

    template <class T, class Compare, class Allocator>
    class AVLTree
    {
    public:
        // types:
        typedef T                                                               value_type;
        typedef Compare                                                         key_compare;
        typedef Allocator                                                       allocator_type;

    private: // for Nodes:
        typedef typename allocator_type::template rebind<Node<T> >::other       node_allocator;
        typedef typename node_allocator::reference                              node_reference;
        typedef typename node_allocator::const_reference                        node_const_reference;
        typedef typename node_allocator::difference_type                        node_difference_type;
        typedef typename node_allocator::pointer                                node_alloc_pointer;
        typedef typename node_allocator::const_pointer                          node_const_pointer;
        typedef typename node_allocator::size_type                              node_size_type;
        typedef Node<value_type>                                                node_type;
        typedef node_type                                                       *node_pointer;

    public:
        typedef typename allocator_type::reference                              reference;
        typedef typename allocator_type::const_reference                        const_reference;
        typedef typename allocator_type::difference_type                        difference_type;
        typedef typename allocator_type::pointer                                pointer;
        typedef typename allocator_type::const_pointer                          const_pointer;
        typedef typename allocator_type::size_type                              size_type;
        typedef typename value_type::first_type                                 key_type;
        typedef typename value_type::second_type                                mapped_type;
        typedef ft::BinarySearchTreeIterator<pointer, node_pointer>             iterator;
        typedef ft::BinarySearchTreeIterator<const_pointer, node_pointer>       const_iterator;
        typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                            const_reverse_iterator;

    private:
        node_allocator                                                          _node_alloc;
        key_compare                                                             _compare;
        node_pointer                                                            _root;
        node_pointer                                                            _end;
        node_pointer                                                            _r_end;
        int                                                                     _size;

    public:
        // Default constructor:
        AVLTree(const key_compare &compare = key_compare(), const allocator_type &alloc = allocator_type())
            : _compare(compare),
              _size(0)
        {
            this->_node_alloc = alloc;
            _end = _createNewNode(value_type());
            _r_end = _createNewNode(value_type());
            _end->left = _r_end;
            _r_end->parent = _end;
            _root = _end;
        };

        // Destructor
        ~AVLTree()
        {
            _remove(_end);
            _remove(_r_end);
        };

        // Public
    public:
        iterator begin()                                                                        { return (iterator(successor(_r_end))); };
        const_iterator begin() const                                                            { return (const_iterator(successor(_r_end))); };
        iterator end()                                                                          { return (iterator(this->_end)); };
        const_iterator end() const                                                              { return (const_iterator(this->_end)); };
        reverse_iterator rbegin()                                                               { return reverse_iterator(end()); };
        const_reverse_iterator rbegin() const                                                   { return (const_reverse_iterator(end())); };
        reverse_iterator rend()                                                                 { return reverse_iterator(begin()); };
        const_reverse_iterator rend() const                                                     { return const_reverse_iterator(begin()); };

    private:
        int _compare2(const value_type *x, const value_type *y) const
        {
            // check if x is equal to min, y is equal to max
            if (x == &_r_end->key || y == &_end->key)
            {
                return 1;
            }
            // check if x is equal to max, y is equal to min
            if (x == &_end->key || y == &_r_end->key)
            {
                return 0;
            }
            // if value is between min and max, return the comparesion
            return _compare(x->first, y->first);
        };

        int _getHeight(node_pointer N)
        {
            if (N == ft_nullptr)
                return (0);
            return (N->height);
        };

        int _max(int a, int b)
        {
            return (a > b) ? a : b;
        };

        node_pointer _createNewNode(value_type key)
        {
            node_pointer node = this->_node_alloc.allocate(1);
            this->_node_alloc.construct(node, key);
            node->left = ft_nullptr;
            node->right = ft_nullptr;
            node->parent = ft_nullptr;
            node->height = 1;
            return (node);
        };

        node_pointer _leftRotate(node_pointer x)
        {
            node_pointer y = x->right;
            node_pointer T2 = y->left;
            node_pointer p = x->parent;

            y->left = x;
            x->right = T2;
            if (p != ft_nullptr)
            {
                if (p->left == x)
                    p->left = y;
                else
                    p->right = y;
            }
            else
                _root = y;
            y->parent = x->parent;
            x->parent = y;

            if (T2 != ft_nullptr)
                T2->parent = x;
            x->height = _max(_getHeight(x->left), _getHeight(x->right)) + 1;
            y->height = _max(_getHeight(y->left), _getHeight(y->right)) + 1;
            return (y);
        };

        node_pointer _rightRotate(node_pointer x)
        {
            node_pointer y = x->left;
            node_pointer T2 = y->right;
            node_pointer p = x->parent;

            y->right = x;
            x->left = T2;
            if (p != ft_nullptr)
            {
                if (p->right == x)
                    p->right = y;
                else
                    p->left = y;
            }
            else
                _root = y;
            y->parent = x->parent;
            x->parent = y;

            if (T2 != ft_nullptr)
                T2->parent = x;
            x->height = _max(_getHeight(x->left), _getHeight(x->right)) + 1;
            y->height = _max(_getHeight(y->left), _getHeight(y->right)) + 1;
            return (y);
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
                return (0);
            return (_getHeight(node->left) - _getHeight(node->right));
        };

        node_pointer _balanceTree(node_pointer root)
        {
            int balance = _getBalance(root);
            if (balance > 1)
            {
                if (_getBalance(root->left) >= 0) // Left Left Case
                {
                    return (_rightRotate(root));
                }
                else // Left Right Case
                {
                    return (_leftRightRotate(root));
                }
            }
            else if (balance < -1)
            {
                if (_getBalance(root->right) <= 0) // Right Right Case
                {
                    return (_leftRotate(root));
                }
                else // Right Left Case
                {
                    return (_rightLeftRotate(root));
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
            if (tmp == ft_nullptr)
                return (newNode);

            if (!this->_compare2(&tmp->key, &newNode->key))
            {
                tmp->left = _insert(tmp->left, newNode);
                if (tmp->left == newNode)
                    newNode->parent = tmp;
            }
            else
            {
                tmp->right = _insert(tmp->right, newNode);
                if (tmp->right == newNode)
                    newNode->parent = tmp;
            }

            _setHeight(tmp);
            tmp = _balanceTree(tmp);
            return (tmp);
        };

        bool _remove(node_pointer node)
        {
            if (node == ft_nullptr)
                return (false);

            node_pointer parent = node->parent;
            if (node->left == ft_nullptr && node->right == ft_nullptr)
            {
                // this is the leaf node
                if (parent != ft_nullptr)
                {
                    if (parent->left == node)
                        parent->left = ft_nullptr;
                    else
                        parent->right = ft_nullptr;
                }
                else
                    _root = ft_nullptr;

                this->_node_alloc.destroy(node);
                this->_node_alloc.deallocate(node, 1);
            }
            else if (node->left == ft_nullptr || node->right == ft_nullptr)
            {
                // has one child
                node_pointer child;
                if (node->left != ft_nullptr)
                    child = node->left;
                else
                    child = node->right;

                if (parent != ft_nullptr)
                {
                    if (node == parent->left)
                        parent->left = child;
                    else
                        parent->right = child;

                    child->parent = parent;
                }
                else
                {
                    _root = child;
                    child->parent = ft_nullptr;
                }

                this->_node_alloc.destroy(node);
                this->_node_alloc.deallocate(node, 1);
            }
            else
            {
                // node has two children
                node_pointer tmp = successor(node);
                // swap the deleting node with successor node, successor node in right subtree's smallest node
                _swapTwoNodes(tmp, node);
                _remove(node);
            }
            _setHeight(parent);
            _balanceTree(parent);
            return (true);
        };

        // swaping two nodes places. x:successor node, y:deleting node
        void _swapTwoNodes(node_pointer x, node_pointer y)
        {
            node_pointer xparent = x->parent;
            node_pointer xleft = x->left;
            node_pointer xright = x->right;
            node_pointer yparent = y->parent;
            node_pointer yleft = y->left;
            node_pointer yright = y->right;

            if (xparent != ft_nullptr)
            {
                if (xparent->left == x)
                    xparent->left = y;
                else
                    xparent->right = y;
            }
            if (xleft != ft_nullptr)
                xleft->parent = y;
            if (xright != ft_nullptr)
                xright->parent = y;

            if (yparent != ft_nullptr)
            {
                if (yparent->left == y)
                    yparent->left = x;
                else
                    yparent->right = x;
            }
            if (yleft != ft_nullptr)
                yleft->parent = x;
            if (yright != ft_nullptr)
                yright->parent = x;

            node_pointer tl = x->left;
            node_pointer tr = x->right;
            node_pointer tp = x->parent;
            int th = x->height;
            x->left = y->left;
            x->right = y->right;
            x->parent = y->parent;
            x->height = y->height;
            y->left = tl;
            y->right = tr;
            y->parent = tp;
            y->height = th;

            if (x == _root)
                _root = y;

            if (y == _root)
                _root = x;
        }

        node_pointer _search(node_pointer root, key_type key) const
        {
            ft::pair<key_type, mapped_type> tmp = ft::make_pair(key, mapped_type());

            if (root == ft_nullptr)
                return (this->_end);
            if (root->key.first == key)
                return (root);
            else if (this->_compare2(&tmp, &root->key))
                return (_search(root->left, key));
            else if (this->_compare2(&root->key, &tmp))
                return (_search(root->right, key));
            return (this->_end);
        };

        void _setHeight(node_pointer node)
        {
            if (node == ft_nullptr)
                return;
            if (!node->left && !node->right)
                node->height = 1;
            else if (node->left == ft_nullptr)
                node->height = 1 + node->right->height;
            else if (node->right == ft_nullptr)
                node->height = 1 + node->left->height;
            else
                node->height = 1 + _max(node->right->height, node->left->height);

            _setHeight(node->parent);
        };
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

    public:
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
        node_pointer search(key_type key) const
        {
            return (_search(this->_root, key));
        };

        node_pointer insert_pos(node_pointer position, T key)
        {
            node_pointer newnode = _createNewNode(key);
            ++this->_size;
            if (position == _root)
                this->_root = _insert(this->_root, newnode);
            else
                _insert(position, newnode);
            return (newnode);
        }

        node_pointer insert(const value_type &key)
        {
            node_pointer newNode = _createNewNode(key);
            ++this->_size;
            this->_root = _insert(this->_root, newNode);
            return (newNode);
        };

        // remove/delete
        void remove(T key)
        {
            node_pointer n = _search(_root, key.first);
            if (n == _end)
                return;
            if (this->_remove(n))
                _size--;
        }

        void swap(AVLTree &other)
        {
            allocator_type temporary_alloc = other._node_alloc;
            node_pointer temporary_root = other._root;
            node_pointer temporary_end = other._end;
            node_pointer temporary_r_end = other._r_end;
            int temporary_size = other._size;

            other._size = this->_size;
            _size = temporary_size;

            other._node_alloc = this->_node_alloc;
            this->_node_alloc = temporary_alloc;

            other._end = this->_end;
            this->_end = temporary_end;

            other._r_end = this->_r_end;
            this->_r_end = temporary_r_end;

            other._root = this->_root;
            this->_root = temporary_root;
        }

        node_pointer lower_bound(const key_type &k) const
        {
            node_pointer curr_node = successor(_r_end);

            while (curr_node->key.first < k)
            {
                if (curr_node->key.first == k)
                    break;
                curr_node = successor(curr_node);
                if (curr_node == ft_nullptr || curr_node == this->_end)
                    return (this->_end);
            }
            return (curr_node);
        }

        node_pointer upper_bound(const key_type &k) const
        {
            node_pointer curr_node = successor(_r_end);
            while (curr_node->key.first <= k)
            {
                curr_node = successor(curr_node);
                if (curr_node == ft_nullptr || curr_node == this->_end)
                    return (this->_end);
            }
            return (curr_node);
        }
        allocator_type get_allocator() const{ return (_node_alloc); }
        node_pointer getMin(void) const
        {
            node_pointer tmp = this->_root;
            while (tmp->left != ft_nullptr)
                tmp = tmp->left;
            return (tmp);
        }

        void printPreOrder(const std::string &prefix, node_pointer node, bool left)
        {
            if (node != ft_nullptr)
            {
                if (node->left != ft_nullptr && node->left->parent != node)
                    std::cout << "broken node: " << node->left->key.first << "'s parent has to be " << node->key.first << " but, received " << node->left->parent->key.first << "\n";
                if (node->right != ft_nullptr && node->right->parent != node)
                    std::cout << "broken node: " << node->right->key.first << "'s parent has to be " << node->key.first << " but, received " << node->right->parent->key.first << "\n";

                std::cout << prefix;
                std::cout << (left ? "├──" : "└──");
                if (node == _end)
                    std::cout << "MAX"
                              << " (" << node->height << ")" << std::endl;
                else if (node == _r_end)
                    std::cout << "MIN"
                              << " (" << node->height << ")" << std::endl;
                else
                    std::cout << node->key.first << " (" << node->height << ")" << std::endl;
                printPreOrder(prefix + (left ? "│   " : "    "), node->left, true);
                printPreOrder(prefix + (left ? "│   " : "    "), node->right, false);
            }
        }

        void printPreOrder(void)
        {
            std::cout << "--------------------------------------\n";
            printPreOrder("", _root, false);
            std::cout << "--------------------------------------\n";
        }
    };
}

#endif