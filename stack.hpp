/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:05:27 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/22 15:43:33 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
		
		public:
			// Member types
			typedef Container									container_type;
			typedef typename container_type::value_type			value_type;
			typedef typename container_type::size_type			size_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;
		
			//Member functions

			//constructor
			explicit stack (const container_type& ctnr = container_type()) {
				container = ctnr;
			}
			bool empty() const {
				return container.empty();
			}
			size_type size() const {
				return container.size();
			}
			reference top() {
				return container.back();
			}
			const_reference top() const {
				return container.back();
			}
			void push (const value_type& val) {
				container.push_back(val);
			}
			void pop() {
				container.pop_back();
			}
			friend bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
				return lhs.container == rhs.container;
			}

			friend bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
				return lhs.container < rhs.container;
			}
		protected:
			container_type	container;
	};
	
	// relational operators
	
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(lhs == rhs);
	}
	
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(rhs < lhs);
	}
	
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return rhs < lhs;
	}
	
	template <class T, class Container>
	bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
		return !(lhs < rhs);
	}

} // namespace ft


# endif