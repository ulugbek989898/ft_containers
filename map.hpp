/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:37:53 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/28 10:14:16 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <iostream>
# include "utils/pair.hpp"
# include <map>

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key	key_type;
		typedef T	mapped_type;
		typedef ft::pair<const key_type,mapped_type>	value_type;
		typedef Compare	key_compare;
		typedef Allocator	allocator_type;
		typedef typename allocator_type::reference	reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer	pointer;
		typedef typename allocator_type::const_pointer	const_pointer;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::size_type	size_type;
		//left iterators
		
		class value_compare : public std::binary_function<value_type, value_type, bool> {

			friend class map;
			protected:
				key_compare m_comp;
				value_compare(key_compare comp) : m_comp(comp) {}

			public:
				bool operator()(const value_type &lhs, const value_type &rhs) const {
					return m_comp(lhs.first, rhs.first);
				}
		};
		
		
	private:
		// tree_type			_tree;
		key_compare			_comp;
		allocator_type		_alloc;
		size_type			_size;

	public:
		// Member functions
		//  empty container constructor
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
			_alloc = alloc;
			_comp = comp;
			_size = 0;
		}
		
		//  range constructor
		// template <class InputIterator>  map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
		// 	_alloc = alloc;
		// 	_comp = comp;
		// 	_size = 0;
		// 	//later when insert() is finished
		// 	// this->insert(first, last);
		// } 1 2 3 9 4 5 6 7 8
		// pos_len = 3;
		//               6 7 8
		// copy constructor
		map (const map& x) {
			_alloc = x._alloc;
			_comp = x._comp;
			_size = 0;
			//later when insert() is finished
			// this->insert(x.begin(), x.end());
		}
		
		//destructor
		~map() {
			
		}
		
	};

	
} // namespace ft


#endif