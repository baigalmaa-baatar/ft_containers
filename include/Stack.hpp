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
# include <vector>

namespace ft {
    template <class T, class Container = std::vector<T> > 
    class stack
    {
        public:
            //Member types

            typedef Container   container_type;	
            typedef typename    Container::value_type   value_type;
            typedef typename    Container::size_type    size_type;
            //Member objects

        protected:
            Container c;
            //Constructors

        public:
            explicit stack (const Container & = Container()) {}
            //Member functions

            bool empty() const { return c.empty(); }
            size_type size() const { return c.size(); }
            void push( const value_type& value ) { return c.push_back(value); }
            void pop() { return c.pop_back(); }
            //Non-member functions

            template <class U, class Containerbis>
                friend bool operator==( const stack<T,Container> &lhs, 
                    const stack<U,Containerbis> &rhs ) {
                        return (lhs._container == rhs._container);
                    }
    };
}
#endif