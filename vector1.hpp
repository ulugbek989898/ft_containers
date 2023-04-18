/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:32:17 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/18 17:32:22 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <vector>
# include <iostream>
# include <stdexcept> // for std::out_of_range
# include "utils/type_traits.hpp"
# include "utils/reverse_iterator.hpp"
# include "utils/const_reverse_iterator.hpp"

namespace ft {

	template <typename T, typename Alloc = std::allocator<T> >

	class vector
	{
	public:
	//Member types
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::size_type size_type;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		// Iterator class
		class iterator {
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef T value_type;
			// typedef difference_type difference_type;
			typedef T* pointer;
			typedef T& reference;
			
			iterator() : ptr(NULL) {}
			explicit iterator(pointer p) : ptr(p) {}
			iterator(const iterator& other) : ptr(other.ptr) {}
			iterator& operator=(const iterator& other) { ptr = other.ptr; return *this; }
			~iterator() {}
			
			bool operator==(const iterator& other) const { return ptr == other.ptr; }
			bool operator!=(const iterator& other) const { return ptr != other.ptr; }
			bool operator<(const iterator& other) const { return ptr < other.ptr; }
			bool operator<=(const iterator& other) const { return ptr <= other.ptr; }
			bool operator>(const iterator& other) const { return ptr > other.ptr; }
			bool operator>=(const iterator& other) const { return ptr >= other.ptr; }
			
			iterator& operator++() { ++ptr; return *this; }
			iterator operator++(int) { iterator tmp(*this); ++ptr; return tmp; }
			iterator& operator--() { --ptr; return *this; }
			iterator operator--(int) { iterator tmp(*this); --ptr; return tmp; }
			iterator& operator+=(difference_type n) { ptr += n; return *this; }
			iterator operator+(difference_type n) const { return iterator(ptr + n); }
			// iterator operator+(difference_type n, const iterator& it) { return iterator(it.ptr + n); }
			iterator& operator-=(difference_type n) { ptr -= n; return *this; }
			iterator operator-(difference_type n) const { return iterator(ptr - n); }
			difference_type operator-(const iterator& other) const { return ptr - other.ptr; }
			reference operator*() const { return *ptr; }
			pointer operator->() const { return ptr; }
			reference operator[](difference_type n) const { return ptr[n]; }
			
		private:
			pointer ptr;
		};

		 // Const iterator class
		class const_iterator {
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef const T value_type;
			// typedef difference_type difference_type;
			typedef const T* pointer;
			typedef const T& reference;
			
			const_iterator() : ptr(NULL) {}
			explicit const_iterator(pointer p) : ptr(p) {}
			const_iterator(const const_iterator& other) : ptr(other.ptr) {}
			const_iterator(const iterator& other) : ptr(other.operator->()) {}
			const_iterator& operator=(const const_iterator& other) { ptr = other.ptr; return *this; }
			~const_iterator() {}
			
			bool operator==(const const_iterator& other) const { return ptr == other.ptr; }
			bool operator!=(const const_iterator& other) const { return ptr != other.ptr; }
			bool operator<(const const_iterator& other) const { return ptr < other.ptr; }
			bool operator<=(const const_iterator& other) const { return ptr <= other.ptr; }
			bool operator>(const const_iterator& other) const { return ptr > other.ptr; }
			bool operator>=(const const_iterator& other) const { return ptr >= other.ptr; }
			
			const_iterator& operator++() { ++ptr; return *this; }
			const_iterator operator++(int) { const_iterator tmp(*this); ++ptr; return tmp; }
			const_iterator& operator--() { --ptr; return *this; }
			const_iterator operator--(int) { const_iterator tmp(*this); --ptr; return tmp; }
			const_iterator& operator+=(difference_type n) { ptr += n; return *this; }
			const_iterator operator+(difference_type n) const { return const_iterator(ptr + n); }
			// friend const_iterator operator+(difference_type n, const const_iterator& it) { return const_iterator(it.ptr + n); }
			const_iterator& operator-=(difference_type n) { ptr -= n; return *this; }
			const_iterator operator-(difference_type n) const { return const_iterator(ptr - n); }
			difference_type operator-(const const_iterator& other) const { return ptr - other.ptr; }
			reference operator*() const { return *ptr; }
			pointer operator->() const { return ptr; }
			reference operator[](difference_type n) const { return ptr[n]; }
			
		private:
			pointer ptr;
		};
		
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		

		
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

		// range constructor
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		{
			size_type n = 0;
			for (InputIterator it = first; it != last; ++it){
				n++;
			}
			
			_alloc = alloc;
			_start = _alloc.allocate(n);
			_end = _start + n;
			_end_capacity = _start + n;
			for (size_type i = 0; first != last; ++first, ++i)
				_alloc.construct(_start + i, *first);
		}
		//copy constructor
		vector (const vector& x) {
			this->_alloc = x._alloc;
			size_type	n = x.size();
			this->_start = _alloc.allocate(n);
			this->_end = _start + n;
			this->_end_capacity = _start + n;
			for (size_type i = 0; i < n; ++i)
				_alloc.construct(_start + i, *(x._start + i));
		}
		//destructor
		~vector() {
			this->clear();
			_alloc.deallocate(_start, this->capacity());
		}

		//iterators:

		iterator begin() {
			return iterator(_start);
		}
		
		const_iterator begin() const {
			return iterator(_start);
		}

		iterator end() {
			if (this->empty())
				return (this->begin());
			return iterator(_end);
		}

		const_iterator end() const {
			if (this->empty())
				return (this->begin());
			return iterator(_end);
		}
		
		reverse_iterator rbegin() {
			return reverse_iterator(this->end());
		}

		const_reverse_iterator crbegin() {
			return const_reverse_iterator(this->end());
		}

		reverse_iterator rend() {
			return reverse_iterator(this->begin());
		}

		const_reverse_iterator crend() {
			return const_reverse_iterator(this->begin());
		}
		
		//Capacity
		size_type	capacity() const {
			return (this->_end_capacity - this->_start);
		}

		size_type	size(void) const {
			return (this->_end - this->_start);
		}
		
		bool empty() const {
			return (size() == 0);
		}
		
		//Element access

		reference operator[](size_type pos) {
			return *(_start + pos);
		}

		const_reference operator[](size_type pos) const {
			return *(_start + pos);
		}
		
		reference at(size_type pos) {
			if (pos >= size()) {
				throw std::out_of_range("vector");
			}
			return *(_start + pos);
		}
		
		const_reference at(size_type pos) const {
			if (pos >= size()) {
				throw std::out_of_range("vector");
			}
			return _start[pos];
		}
		
		value_type* data() {
			return _start;
		}

		const value_type* data() const {
			return _start;
		}

		reference front() {
			return *(this->begin());
		}

		const_reference front() const {
			return *(this->begin());
		}
		
		reference back() {
			return *(this->end() - 1);
		}

		const_reference back() const {
			return *(this->end() - 1);
		}

		// Modifiers:
		void	clear() {
			size_type	tmp_size = this->size();
			for (size_type i = 0; i < tmp_size; i++) {
				_end--;
				_alloc.destroy(_end);
			}
		}
	private:
		allocator_type	_alloc;
		pointer			_start;
		pointer			_end;
		pointer			_end_capacity;
	};
}

#endif
