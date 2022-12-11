/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaatar <bbaatar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:00:38 by bbaatar           #+#    #+#             */
/*   Updated: 2022/10/11 11:00:44 by bbaatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
    public:
        /**
         * Member types
         */

        typedef Container container_type;
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        // Member objects

    protected:
        Container _container;
        /**
         * Constructors
         */

    public:
        /**
         * Default constructor
         */
        explicit stack(const container_type& cont = container_type()) : _container(cont)
        {
        }
        //Copy constructor
        stack(const stack& other) : _container(other._container)
        {
        }
        //operator =
        stack& operator=(const stack &other)
        {
            this->_container = other._container;
            return (*this);
        }

        /**
         * Destructor
         */
        ~stack()
        {
        }

        /**
         * Member functions
         */

        bool empty() const { return _container.empty(); }
        size_type size() const { return _container.size(); }
        value_type &top() { return _container.back(); }
        const value_type &top() const { return _container.back(); }
        void push(const value_type &value) { return _container.push_back(value); }
        void pop() { return _container.pop_back(); }
        /**
         * Non-member functions
         */
        /**
         * About why we use friend function:
         * 
         * Since operator << will be called on an std::ostream, 
         * you cannot define this procedure as a member function for my_class, 
         * you have to define it as a global function, 
         * since it's an operation for std::ostream, not my_class.
         * By putting the friend keyword into the declaration, 
         * you are saying that you want to declare the 
         * operator << as a friend global function (not a member function!). 
         * The C++ standard lets you put the definition of the friend function there, 
         * but it won't be a member function. 
         * It is the same as the following, which is more clear:
        */
        template <class U, class Containerbis>
        friend bool operator==(const stack<T, Container> &lhs,
                               const stack<U, Containerbis> &rhs)
        {
            return (lhs._container == rhs._container);
        }
        template <class U, class Containerbis>
        friend bool operator<(const stack<T, Container> &lhs,
                              const stack<U, Containerbis> &rhs)
        {
            return (lhs._container < rhs._container);
        }
        template <class U, class Containerbis>
        friend bool operator!=(const stack<T, Container> &lhs,
                               const stack<U, Containerbis> &rhs)
        {
            return (lhs._container != rhs._container);
        }
        template <class U, class Containerbis>
        friend bool operator>(const stack<T, Container> &lhs,
                              const stack<U, Containerbis> &rhs)
        {
            return (lhs._container > rhs._container);
        }
        template <class U, class Containerbis>
        friend bool operator>=(const stack<T, Container> &lhs,
                               const stack<U, Containerbis> &rhs)
        {
            return (lhs._container >= rhs._container);
        }
        template <class U, class Containerbis>
        friend bool operator<=(const stack<T, Container> &lhs,
                               const stack<U, Containerbis> &rhs)
        {
            return (lhs._container <= rhs._container);
        }
    };
}
#endif