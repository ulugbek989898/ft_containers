/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:07:53 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/14 13:56:55 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

namespace	ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	private:
		allocator_type	_alloc;
		pointer			_start;
		pointer			_end;
		pointer			_end_capacity;
	public:
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
		
		vector(/* args */);
		~vector() {
			this->clear();
			_alloc.deallocate(_start, this->capacity());
		}
	};
}

#endif