/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 06:28:10 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/23 06:56:55 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair {
		//Member types
		typedef T1 first_type;
		typedef T2 second_type;

		//Member variables
		first_type	first;
		second_type	second;

		//Member functions
		//default constructor
		pair() :first(), second() { }
		
		//copy constructor
		template<class U, class V>
		pair (const pair<U,V>& pr) {
			this->first = pr.first;
			this->second = pr.second;
 		}
		
		//initialization constructor
		pair (const first_type& a, const second_type& b) {
			this->first = a;
			this->second = b;
		}

		// pair::operator=
		pair& operator= (const pair& pr) {
			if (this != &pr) {
				this->first = pr.first;
				this->second = pr.second;
			}
			return *this;
		}
		
	};
	
	//Non-member function overloads
	template <class T1, class T2>
	bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return lhs.first==rhs.first && lhs.second==rhs.second; }
	
	template <class T1, class T2>
	bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return !(lhs==rhs); }
	
	template <class T1, class T2>
	bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return rhs<lhs; }

	template <class T1, class T2> 
	bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return !(lhs<rhs); }

	template <class T1,class T2>
	ft::pair<T1,T2> make_pair (T1 x, T2 y) {
		return ( ft::pair<T1,T2>(x,y) );
	}

} // namespace ft


#endif