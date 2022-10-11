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
# define STACK_HPP
# include <iostream>
# include <string>
# include <vector>

namespace ft
{
    template <class T, class Container = std::vector<T> > class stack
    {
    public:
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        typedef Container container_type;

    protected:
        Container c;

    public:
        explicit stack(const Container & = Container());
        bool empty() const { return c.empty(); }
        size_type size() const { return c.size(); }
        value_type &top() { return c.back(); }
        const value_type &top() const { return c.back(); }
        void push(const value_type &x) { c.push_back(x); }
        void pop() { c.pop_back(); }

        template <class U, class Containerbis>
            friend bool operator==(const stack<T, Container> &x,
                const stack<U, Containerbis> &y) {
                    return(x._container == y._container);
                    }
        template <class U, class Containerbis>
            friend bool operator<(const stack<T, Container> &x,
                const stack<U, Containerbis> &y) {
                    return (x._container < y._container);
                    }
        template <class U, class Containerbis>
            friend bool operator!=(const stack<T, Container> &x,
                const stack<U, Containerbis> &y) {
                    return (x._container != y._container);
                    }
        template <class U, class Containerbis>
            friend bool operator>(const stack<T, Container> &x,
                const stack<U, Containerbis> &y){
                    return (x._container > y._container);
                    }
        template <class U, class Containerbis>
            friend bool operator>=(const stack<T, Container> &x,
                const stack<U, Containerbis> &y) {
                    return (x._container >= y._container);
                    }
        template <class U, class Containerbis>
            friend bool operator<=(const stack<T, Container> &x,
                const stack<U, Containerbis> &y) {
                    return (x._container <= y._container);
                    }
    };
}

#endif