/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:07:53 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/14 15:12:30 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "./utils/random_access_iterator.hpp"
# include "./utils/utils.hpp"

namespace	ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		//Member types

		// definition -> The first template parameter (T),		notes -> nothing;
		typedef T	value_type;

		//definition -> The second template parameter (Alloc),	notes -> defaults to: allocator<value_type>;
		typedef Alloc	allocator_type;

		//definition -> allocator_type::reference,	notes -> for the default allocator: value_type&;
		typedef typename allocator_type::reference	reference;

		//definition -> allocator_type::const_reference, notes -> for the default allocator: const value_type&;
		typedef typename allocator_type::const_reference	const_reference;

		//definition -> allocator_type::pointer, notes -> for the default allocator: value_type*;
		typedef typename allocator_type::pointer	pointer;

		//definition -> allocator_type::const_pointer, notes -> for the default allocator: const value_type*;
		typedef typename allocator_type::const_pointer	const_pointer;

		//definition -> a random access iterator to value_type, notes -> convertible to const_iterator;
		typedef ft::random_access_iterator<value_type>	iterator;		//inside utils directory create random_access_iterator.hpp file;

		//definition -> a random access iterator to const value_type, notes -> nothing;
		typedef ft::random_access_iterator<const value_type> const iterator; //inside utils directory create random_access_iterator.hpp file;

		//definition -> reverse_iterator<iterator>, notes -> noting;
		typedef ft::reverse_iterator<iterator>	reverse_iterator; //inside utils directory create utils.hpp

		//definition -> reverse_iterator<const_iterator>, notes -> nothing;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;	//inside utils directory create utils.hpp

		//definition -> a signed integral type, identical to: iterator_traits<iterator>::difference_type, notes -> 	usually the same as ptrdiff_t;
		typedef ft::iterator_traits<iterator>::difference_type	difference_type;

		//definition -> an unsigned integral type that can represent any non-negative value of difference_type, notes -> usually the same as size_t;
		typedef typename allocator_type::size_type	size_type;
		
		size_type	size(void) const {
			return (this->_end - this->_start);
		}
		
		void	clear() {
			size_type	tmp_size = this->size();
			for (size_type i = 0; i < tmp_size; i++) {
				_end--;
				_alloc.destroy(_end);
			}
		}
		
		size_type	capacity() const {
			return (this->_end_capacity - this->_start);
		}
		
		vector(/* args */) {}
		
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