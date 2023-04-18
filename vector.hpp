/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:07:53 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/17 15:18:43 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <vector>
# include <iostream>

# include "./utils/random_access_iterator.hpp"
# include "./utils/utils.hpp"

namespace	ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		//Member types

		typedef T	value_type;

		typedef Alloc	allocator_type;

		typedef typename allocator_type::reference	reference;

		typedef typename allocator_type::const_reference	const_reference;

		typedef typename allocator_type::pointer	pointer;

		typedef typename allocator_type::const_pointer	const_pointer;

		// typedef ft::random_access_iterator<value_type>	iterator;		//inside utils directory create random_access_iterator.hpp file;

		// typedef ft::random_access_iterator<const value_type> const iterator; //inside utils directory create random_access_iterator.hpp file;

		// typedef ft::reverse_iterator<iterator>	reverse_iterator; //inside utils directory create utils.hpp

		// typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;	//inside utils directory create utils.hpp

		// typedef ft::iterator_traits<iterator>::difference_type	difference_type;

		typedef typename allocator_type::size_type	size_type;
		
		
		//default constructor
		explicit vector (const allocator_type& alloc = allocator_type()) {
			_alloc = alloc;
			_start = 0;
			_end = 0;
			_end_capacity = 0;
		}

		//fill constructor
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
			_alloc = alloc;
			_start = _alloc.allocate(n);
			_end_capacity = _start + n;
			_end = _start;
			while (n--) {
				_alloc.construct(_end, val);
				_end++;
			}
		}

		//range constructor
		// template <class InputIterator> vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {
			
		// }
		
		// copy constructor
		vector (const vector& x) {
			_alloc = alloc;
			_start = nullptr;
			_end = nullptr;
			_end_capacity = nullptr;
			
			this->insert(this->begin, x.begin(), x.end());
		}
		
		//iterators:

		// iterator begin() {
		// 	return _start;
		// }
		
		// const_iterator begin() const {
		// 	return _start;
		// }

		// iterator end() {
		// 	if (this->empty())
		// 		return (this->begin());
		// 	return _end;
		// }

		// const_iterator end() const {
		// 	if (this->empty())
		// 		return (this->begin());
		// 	return _end;
		// }

		
		//Capacity:

		size_type	capacity() const {
			return (this->_end_capacity - this->_start);
		}

		size_type	size(void) const {
			return (this->_end - this->_start);
		}
		
		bool empty() const {
			if (size() == 0)
				return true;
			return false;
		}
		
		//Element access

		reference operator[](size_type pos) {
			return *(_start + pos);
		}
		
		// Modifiers:
		void	clear() {
			size_type	tmp_size = this->size();
			for (size_type i = 0; i < tmp_size; i++) {
				_end--;
				_alloc.destroy(_end);
			}
		}
		
		
		~vector() {
			this->clear();
			_alloc.deallocate(_start, this->capacity());
		}
	private:
		allocator_type	_alloc;
		pointer			_start;
		pointer			_end;
		pointer			_end_capacity;
	};
}

#endif