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
#include <vector>

namespace ft
{
    template <class T, class Container = std::vector<T> >
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
        explicit stack(const Container & = Container())
        {
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