/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <bbaatar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:01:30 by bbaatar           #+#    #+#             */
/*   Updated: 2022/10/11 11:01:31 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include "./utils/binarySearchTreeIterator.hpp"
#include "./utils/reverseIterator.hpp"
#include "./utils/AVLTree.hpp"

namespace ft
{
    template <typename Key, typename T, typename Compare = ft::less<Key>,
              class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
    public:
        // types:
        typedef Key                                         key_type;
        typedef T                                           mapped_type;
        typedef pair<const key_type, mapped_type>           value_type;
        typedef Compare                                     key_compare;
        typedef Alloc                                       allocator_type;
        typedef value_type                                  &reference;
        typedef const value_type                            &const_reference;
        typedef value_type                                  *pointer;
        typedef const value_type                            *const_pointer;
        typedef ptrdiff_t                                   difference_type;
        typedef typename allocator_type::size_type          size_type;

        class value_compare
        {
        private:
            key_compare                                     _comp;
            value_compare(key_compare c) :                  _comp(c) {}
            value_compare &operator=(const value_compare &o);

        public:
            typedef bool                                    result_type;
            typedef value_type                              first_arg_type;
            typedef value_type                              second_arg_type;
            ~value_compare() {}
            value_compare(const value_compare &o) :         _comp(o._comp) {}
            bool operator()(const value_type &x, const value_type &y) const
            {
                return _comp(x.first, y.first);
            }
            template <typename _Key, typename _T, typename _Compare>
            friend class map;
        };

    private:
        typedef Node<value_type>                            Node_type;
        typedef Node_type                                   *Node_ptr;
        typedef AVLTree<value_type, key_compare, allocator_type> Tree_type;
        typedef Tree_type                                   *Tree_ptr;

    public:
        typedef typename Tree_type::iterator                iterator;            
        typedef typename Tree_type::const_iterator          const_iterator;
        typedef ft::reverse_iterator<iterator>              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

    private:
        Tree_type _tree;
        allocator_type _alloc;
        key_compare _comp;

    public:
        // Constructor
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
            : _tree(comp, alloc), _alloc(alloc), _comp(comp) { }
        // Range constructor
        template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
            : _tree(comp, alloc), _alloc(alloc), _comp(comp)
        {
            insert(first, last);
        }
        //Copy constructor
        map(const map &x)
        {
            *this = x;
        }
        // Destructor
        ~map() { this->_tree.clear(); }
        // Copy container content 
        map &operator=(const map &x)
        {
            if (this != &x)
            {
                this->_tree.clear();
                this->_comp = x._comp;
                this->_alloc = x._alloc;
                insert(x.begin(), x.end());
            }
            return (*this);
        };
        // iterators:
        iterator begin()        { return (this->_tree.begin()); };
        const_iterator begin() const { return (this->_tree.begin()); };
        iterator end() { return (this->_tree.end()); };
        const_iterator end() const { return (this->_tree.end()); };
        reverse_iterator rbegin() { return (this->_tree.rbegin()); };
        const_reverse_iterator rbegin() const { return (this->_tree.rbegin()); };
        reverse_iterator rend() { return (this->_tree.rend()); };
        const_reverse_iterator rend() const { return (this->_tree.rend()); };
        // capacity:
        bool empty() const { return (this->_tree.empty()); }
        size_type size() const { return (this->_tree.size()); }
        size_type max_size() const { return (this->_tree.max_size()); }
        // element access:
        mapped_type &operator[](const key_type &k)
        {
            return ((*((this->insert(make_pair(k,mapped_type()))).first)).second);
            // ft::pair<iterator, bool> p = insert(ft::make_pair(k, mapped_type()));
            // return (p.first->second);
        };

        // modifiers:
        ft::pair<iterator, bool> insert(const value_type& val)
        {
            iterator node = iterator(this->_tree.search(val.first));
            if (node != end())
                return (ft::make_pair<iterator, bool>(node, false));
            Node_ptr inserted_node = this->_tree.insert(val);
            return (ft::pair<iterator, bool>(iterator(inserted_node), true));
        };

        iterator insert(iterator pos, const value_type &val)
        {
            Node_ptr node = pos.base();
            if (val.first > predecessor(node)->key.first && val.first < successor(node)->key.first)
                pos = iterator(this->_tree.insert_pos(node, val));
            else
                pos = insert(val).first;
            return (pos);
        };

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                this->_tree.insert(*first);
                first++;
            };
        }
        void erase(iterator position)
        {
           this->_tree.remove(*position);
        }
        size_type erase(const key_type &k)
        {
            size_type res = size();
            this->_tree.remove(*find(k));
            return (res - size());
        }
        void erase(iterator first, iterator last)
        {
            iterator current;
            while (first != last)
            {
                current = first;
                first++;
                erase(current);
            }
        }

        void swap(map& other)
        {
            (void)other;
        }

        void clear()
        {
            return (this->_tree.clear());
        }

        // observers:
        key_compare key_comp() const { return (this->_comp); };
        value_compare value_comp() const { return (this->value_comp(_comp)); };

        // 23.3.1.3 map operations:
        iterator find(const key_type &k)
        {
            return (iterator(this->_tree.search(k)));
        };
        const_iterator find(const key_type &k) const
        {
            return (iterator(this->_tree.search(k)));
        };
        size_type count(const key_type &x) const;
        iterator lower_bound(const key_type &x);
        const_iterator lower_bound(const key_type &x) const;
        iterator upper_bound(const key_type &x);
        const_iterator upper_bound(const key_type &x) const;
        pair<iterator, iterator>
        equal_range(const key_type &x);
        pair<const_iterator, const_iterator>
        equal_range(const key_type &x) const;
    };
    template <class Key, class T, class Compare, class Allocator>
    bool operator==(const map<Key, T, Compare, Allocator> &x,
                    const map<Key, T, Compare, Allocator> &y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator<(const map<Key, T, Compare, Allocator> &x,
                   const map<Key, T, Compare, Allocator> &y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator!=(const map<Key, T, Compare, Allocator> &x,
                    const map<Key, T, Compare, Allocator> &y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator>(const map<Key, T, Compare, Allocator> &x,
                   const map<Key, T, Compare, Allocator> &y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator>=(const map<Key, T, Compare, Allocator> &x,
                    const map<Key, T, Compare, Allocator> &y);

    template <class Key, class T, class Compare, class Allocator>
    bool operator<=(const map<Key, T, Compare, Allocator> &x,
                    const map<Key, T, Compare, Allocator> &y);
    // specialized algorithms:
    template <class Key, class T, class Compare, class Allocator>
    void swap(map<Key, T, Compare, Allocator> &x,
              map<Key, T, Compare, Allocator> &y);
}
#endif