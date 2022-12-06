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
        typedef T value_type;

    public:
        T key;
        Node* parent;
        Node* left;
        Node* right;
        int height;

    public:
        Node() : key() {};
        Node(T key) : key(key) {};
    };

    template <class T, class Compare, class Allocator>
    class AVLTree
    {
    public:
        // types:
        typedef T value_type;
        typedef Compare key_compare;
        typedef Allocator allocator_type;

    private: // for Nodes:
        typedef typename allocator_type::template rebind<Node<T> >::other node_allocator;
        typedef typename node_allocator::reference node_reference;
        typedef typename node_allocator::const_reference node_const_reference;
        typedef typename node_allocator::difference_type node_difference_type;
        typedef typename node_allocator::pointer node_alloc_pointer;
        typedef typename node_allocator::const_pointer node_const_pointer;
        typedef typename node_allocator::size_type node_size_type;
        typedef Node<value_type> node_type;
        typedef node_type* node_pointer;

    public:
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        // typedef typename std::ptrdiff_t difference_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
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
        AVLTree(const key_compare& compare = key_compare(), const allocator_type& alloc = allocator_type())
            : _compare(compare),
            _size(0)
        {
            std::cout << "here???" << '\n';
            this->_node_alloc = alloc;
            this->_end = this->_createNewNode(value_type());
            this->_root = this->_end;
            // this->_end->left = this->_end;
            // this->_end->right = this->_end;
        };

        // Destructor
        ~AVLTree() {};

        // Public
    public:
        iterator begin()
        {
            std::cout << "begin iterator value:" << this->_root->key.second << '\n';
            // return (iterator(getMinimum()));
            node_type* tmp = this->_root;
            while (tmp != this->_end && tmp->left)
                tmp = tmp->left;
            return iterator(tmp);
        }
        const_iterator begin() const
        {
            return (const_iterator(getMinimum()));
        }
        iterator end() { return (iterator(this->_end)); };
        const_iterator end() const { return (const_iterator(this->_end)); };
        reverse_iterator rbegin()
        {
            // std::cout << "root:" << this->_root->key.first << "->" << this->_root->key.second << '\n';
            // std::cout << "root right :" << this->_root->right->key.first << "->" << this->_root->right->key.second << '\n';
            return reverse_iterator(end());
        };
        const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); };
        reverse_iterator rend() { return reverse_iterator(begin()); };
        const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };

    private:
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
            x->height = std::max(_getHeight(x->left), _getHeight(x->right)) + 1;
            y->height = std::max(_getHeight(y->left), _getHeight(y->right)) + 1;
            return (y);
        };

        node_pointer _rightRotate(node_pointer y)
        {
            node_pointer x = y->left;
            node_pointer T3 = x->right;
            node_pointer p = y->parent;
            x->right = y;
            y->left = T3;
            if (p != this->_end)
            {
                if (p->right == y)
                    p->right = x;
                else
                    p->left = x;
            }
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
                return (0);
            std::cout << "balanced height is :" << (_getHeight(node->left) - _getHeight(node->right)) << '\n';
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
                    return (_leftRightRotate(root));
                }
            }
            else if (balance < -1)
            {
                if (_getBalance(root->right) <= 0) // Right Right Case
                    return (_leftRotate(root));
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
            // ene hurte hiisen _end g sain sudlah heregtei.
            if (tmp == ft_nullptr || tmp == this->_end)
            {
                return (newNode);
            }
            if (!this->_compare(tmp->key.first, newNode->key.first))
                // if (newNode->key < tmp->key)
            {
                tmp->left = _insert(tmp->left, newNode);
                if (tmp->left == newNode)
                    newNode->parent = tmp;
            }
            else if (this->_compare(tmp->key.first, newNode->key.first))
            {
                tmp->right = _insert(tmp->right, newNode);

                if (tmp->right == newNode)
                {
                    newNode->parent = tmp;
                }
            }
            else
            {
                return tmp;
            }
            _setHeight(tmp);
            // tmp->height = 1 + _max(_getHeight(tmp->left), _getHeight(tmp->right)); // do I need new funciton? in case of null subtrees?
            tmp = _balanceTree(tmp);
            return (tmp);
        };

        node_pointer _remove(node_pointer root, T key)
        {
            if (root == ft_nullptr)
                return (ft_nullptr);
            else if (this->_compare(key.first, root->key.first))
            {
                std::cout << "smaller than root " << '\n';
                root->left = _remove(root->left, key);

            }
            else if (this->_compare(root->key.first, key.first))
            {
                std::cout << "bigger than root " << '\n';

                root->right = _remove(root->right, key);
            }
            else
            {
                std::cout << "this is the root node" << '\n';

                if (root->left == ft_nullptr && root->right == ft_nullptr)
                {
                    std::cout << "ROOT PARENT:" << root->parent->key.second << '\n';
                    if (_size > 1)
                    {
                    std::cout << "THIS END:" << this->_end->key.second << '\n';

                        if (root->parent->left == root)
                            root->parent->left = ft_nullptr;
                        else if (root->parent->right == root)
                            root->parent->right = ft_nullptr;
                    this->_node_alloc.destroy(root);
                    this->_node_alloc.deallocate(root, 1);
                    }
                    else
                    {
                        std::cout << "ELSE" << '\n';
                        // root = this->_end;
                        this->_node_alloc.destroy(root);
                        this->_node_alloc.deallocate(root, 1);
                    }
                    return (0);
                }
                else if (root->left == ft_nullptr)
                {
                    std::cout << " !!!!!right node height:" << root->height << '\n';

                    node_pointer temp = root;
                    root = root->right;
                    root->parent = temp->parent;
                    this->_node_alloc.destroy(temp);
                    this->_node_alloc.deallocate(temp, 1);
                    temp = ft_nullptr;
                    return (root);
                }
                else if (root->right == ft_nullptr)
                {
                    std::cout << " !!!!!left node height:" << root->height << '\n';

                    node_pointer temp = root;
                    root = root->left;
                    root->parent = temp->parent;
                    this->_node_alloc.destroy(temp);
                    this->_node_alloc.deallocate(temp, 1);
                    temp = ft_nullptr;
                    return (root);
                }
                else
                {
                    std::cout << "node with two children" << '\n';
                    node_pointer temp = _minValTree(root->right);
                    value_type k = temp->key;
                    _printPreOrder(root);
                    root->right = _remove(root->right, temp->key);
                    // _printPreOrder(root);
                    // std::cout << "\nroot left:" << root->left->key.second << '\n';
                    // std::cout << "root :" << root->key.second << '\n';
                    // std::cout << "root right:" << k.second << '\n';
                    node_pointer tr = root->right;
                    node_pointer tl = root->left;
                    node_pointer tp = root->parent;
                    int th = root->height;
                    this->_node_alloc.construct(root, k);
                    root->right = tr;
                    root->left = tl;
                    root->parent = tp;
                    root->height = th;
                    std::cout << " AFTER construct node root:" << root->key.second << '\n';
                    std::cout << " AFTER construct node left:" << root->left->key.second << '\n';
                    // std::cout << " AFTER construct node right:" << root->right->key.second << '\n';
                    std::cout << " AFTER construct node parent:" << root->parent->key.second << '\n';
                    // root->key.first = k.first;
                    // root->key.second = k.second;
                    // std::cout << "two children left node height:" << _getHeight(root->left) << '\n';
                    // std::cout << "two children right node height:" << _getHeight(root->right) << '\n';
                    // std::cout << "root left:" << root->left->key.second << '\n';
                    // std::cout << "root :" << root->key.second << '\n';
                    // std::cout << "root right:" << k.second << '\n';
                }
            }
            std::cout << "END no child child height:" << '\n';
            _setHeight(root);
            // std::cout << "here: " << root->key.second << '\n';
            root = _balanceTree(root);
            return (root);
        };
        // // node deletetion in tree
        // node_pointer _remove(node_pointer root, T key)
        // {
        //     if (root == ft_nullptr)
        //         return (ft_nullptr);
        //     // Left Side
        //     else if (_compare(key.first, root->key.first))
        //         root->left = _remove(root->left, key);
        //     // Right Side
        //     else if (_compare(root->key.first, key.first))
        //         root->right = _remove(root->right, key);
        //     // Root Node
        //     else
        //     {
        //         // Tree with only one child or no child
        //         if (root->left == ft_nullptr && root->right == ft_nullptr)
        //         {
        //             std::cout << "root: " << root->key.first << '\n';
        //             _node_alloc.destroy(root);
        //             std::cout << "here: " << root->key.first << '\n';
        //             _node_alloc.deallocate(root, 1);
        //             std::cout << "here deallocation: " << '\n';
        //             root = ft_nullptr;
        //             std::cout << "here ft_nullptr: " << '\n';
        //             return (root);
        //         }
        //         else if (root->left == ft_nullptr)
        //         {
        //             //if tree has only child in right subtree
        //             node_pointer tmp = root;
        //             root = root->right;
        //             root->parent = tmp->parent;
        //             _node_alloc.destroy(tmp);
        //             _node_alloc.deallocate(tmp, 1);
        //             tmp = ft_nullptr;
        //             return (root);
        //         }
        //         else if (root->right == ft_nullptr)
        //         {
        //             //if tree has only child in left subtree
        //             node_pointer tmp = root;
        //             root = root->left;
        //             root->parent = tmp->parent;
        //             _node_alloc.destroy(tmp);
        //             _node_alloc.deallocate(tmp, 1);
        //             tmp = ft_nullptr;
        //             return (root);
        //         }
        //         else
        //         {
        //             node_pointer tmp_left = root->left;
        //             // AVL_Node with two children: Get the inorder
        //             // successor (smallest in the right subtree)
        //             node_pointer tmp = _minValTree(root->right);
        //             // Copy the inorder successor's
        //             // data to this AVL_Node
        //             // value_type k = tmp->key;
        //             root = tmp;
        //             // Delete the inorder successor
        //             root->right = _remove(root->right, tmp->key);
        //             // this->_node_alloc.construct(root, k);
        //             root->left = tmp_left;
        //             // root->left = tmp_parent;
        //         }
        //     }
        //     _setHeight(root);
        //     // root->height = 1 + _max(_getHeight(root->left), _getHeight(root->right));
        //     root = _balanceTree(root);
        //     return (root);
        // };

        node_pointer _search(node_pointer root, key_type key) const
        {
            if (root == ft_nullptr)
                return (this->_end);
            if (root->key.first == key)
                return (root);
            else if (this->_compare(key, root->key.first))
                return (_search(root->left, key));
            else if (this->_compare(root->key.first, key))
                return (_search(root->right, key));
            return (this->_end);
        };
        void _setHeight(node_pointer tmp)
        {
            if (!tmp->left && !tmp->right)
            {
                // std::cout << "set height here: " << tmp->height << '\n';

                tmp->height = 1;
            }
            else if (tmp->left == ft_nullptr)
            {
                std::cout << "set height here: " << tmp->height << '\n';

                tmp->height = 1 + tmp->right->height;
            }
            else if (tmp->right == ft_nullptr || tmp->right == this->_end)
            {
                tmp->height = 1 + tmp->left->height;
            }
            else
            {
                std::cout << "right height : " << tmp->right->height << '\n';
                std::cout << "left height : " << tmp->left->height << '\n';
                tmp->height = 1 + std::max(tmp->right->height, tmp->left->height);
                std::cout << "final height : " << tmp->height << '\n';
            }
        };

        void _printPreOrder(node_pointer root)
        {
            if (root != NULL)
            {
                std::cout << root->key.first << "=>" << root->key.second << "  ";
                _printPreOrder(root->left);
                _printPreOrder(root->right);
            }
        };

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

        node_pointer search(key_type key) const
        {
            if (this->_root == this->_end)
            {
                return (this->_end);
            }
            else
            {
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

        node_pointer insert(const value_type& key)
        {
            node_pointer newNode = _createNewNode(key);
            // if tree doesn't exist
            if (this->_root == this->_end)
            {
                this->_root = newNode;
                this->_root->parent = this->_end;
                this->_end->left = this->_root;
                ++this->_size;
            }
            else
            {
                ++this->_size;
                this->_root = _insert(this->_root, newNode);
            }

            return (newNode);
        };
        // remove/delete
        void remove(T key)
        {
            std::cout << "this->root : " << key.first << "->" << key.second << '\n';
            this->_root = this->_remove(this->_root, key);
            --_size; //need to check
        }
        node_pointer getMinimum() const
        {
            // std::cout << "const??" << '\n';
            node_type* tmp = this->_root;
            while (tmp != this->_end && tmp->left)
                tmp = tmp->left;
            // std::cout << "here" << '\n';
            return (tmp);
        }

        void printPreOrder(void)
        {
            return (this->_printPreOrder(this->_root));
        }
    };

    // template <class node_pointer>
    // node_pointer _minValTree(node_pointer tmp)
    // {
    //     while (tmp->left != ft_nullptr)
    //         tmp = tmp->left;
    //     return (tmp);
    // };

    // template <class node_pointer>
    // node_pointer _maxValTree(node_pointer tmp)
    // {
    //     while (tmp->right != ft_nullptr)
    //         tmp = tmp->right;
    //     return (tmp);
    // };

    // template <class node_pointer>
    // node_pointer successor(node_pointer node)
    // {
    //     if (node->right)
    //         return (_minValTree(node->right));

    //     node_pointer tmp = node->parent;
    //     while (tmp && tmp->right == node)
    //     {
    //         node = tmp;
    //         tmp = tmp->parent;
    //     }
    //     return (tmp);
    // };

    // template <class node_pointer>
    // node_pointer predecessor(node_pointer node)
    // {
    //     if (node->left)
    //         return (_maxValTree(node->left));

    //     node_pointer tmp = node->parent;
    //     while (tmp && tmp->left == node)
    //     {
    //         node = tmp;
    //         tmp = tmp->parent;
    //     }
    //     if (tmp == ft_nullptr)
    //         return (node);
    //     return (tmp);
    // };
}

#endif



/**
 * _root = _end;
                    _end->left = _end;
                    _end->right = _end;
*/