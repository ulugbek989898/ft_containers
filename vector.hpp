/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:32:17 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/20 14:01:56 by uisroilo         ###   ########.fr       */
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
# include "utils/lexicographical_compare.hpp"

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
		

		//Member functions
		
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
		
		//Assign content
		vector& operator= (const vector& x) {
			if (this != & x) {
				this->~vector();
				size_type n = x.size();
				_start = _alloc.allocate(x.capacity());
				_end_capacity = _start + n;
				_end = _start;
				size_type i = 0;
				while (i < n) {
					_alloc.construct(_end, *(x.begin() + i));
					_end++;
					i++;
				}
			}
			return *this;
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

		size_type max_size() const {
			return this->_alloc.max_size();
		}

		void resize (size_type n, value_type val = value_type()) {
			if (n < this->size()) {
				for (size_type tmp_size = this->size(); n < tmp_size; tmp_size--) {
					_end--;
					_alloc.destroy(_start + tmp_size - 1);
				}
			}
			else if (n > this->capacity()) {
				this->reserve(n);
			}
			if (n > this->size()) {
				for (size_type i = this->size(); i < n; i++) {
					_alloc.construct(_end, val);
					_end++;
				}
			}
		}
		void reserve (size_type n) {
			if (n > this->capacity()) {
				allocator_type tmp_alloc;
				pointer tmp_start = tmp_alloc.allocate(n);
				size_type	tmp_size = this->size();
				
				for (size_type i = 0; i < this->size(); i++)
				{
					tmp_alloc.construct(tmp_start + i, *(_start + i));
				}
				this->~vector();
				_alloc = tmp_alloc;
				_start = tmp_start;
				_end = _start + tmp_size;
				_end_capacity = _start + n;
			}
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

		void push_back (const value_type& val) {
			if (!this->capacity()) {
				this->reserve(1);
			} else if (this->size() == this->capacity()) {
				this->reserve(this->capacity() * 2);
			}
			_alloc.construct(_end, val);
			_end++;
		}

		void pop_back() {
			if (!this->empty()) {
				_end--;
				_alloc.destroy(_end);
			}
		}
		
		iterator erase (iterator position) {
			if (position == end()) {
				return position;
			}
			for (iterator it = position; it != this->end() - 1; ++it) {
				*it = * (it + 1);
			}
			this->pop_back();
			return position;
		}
		iterator erase (iterator first, iterator last) {
			if (first == last)
				return last;
		
			iterator i = first;
			iterator j = last;
			
			while (j != this->end()) {
				*i = *j;
				++i;
				++j;
			}
			
			while (i != this->end()) {
				--_end;
				_alloc.destroy(&*i);
			}
			return first;
		}
		
		void swap (vector& x) {
			if (this == &x) {
				return;
			}
			
			pointer tmp_start = this->_start;
			this->_start = x._start;
			x._start = tmp_start;

			pointer tmp_end = this->_end;
			this->_end = x._end;
			x._end = tmp_end;
			
			pointer tmp_capacity = this->_end_capacity;
			this->_end_capacity = x._end_capacity;
			x._end_capacity = tmp_capacity;
		}

		// // single element (1)
		iterator insert (iterator position, const value_type& val) {
		size_type pos = position - this->_start;
		if (this->_end != this->_end_capacity && position == end()) {
			this->_alloc.construct(this->_end, val);
			++this->_end;
		}
		else {
			if (_end == _end_capacity) {
				size_type new_capacity = capacity() ? 2 * capacity() : 1;
				pointer new_start = this->_alloc.allocate(new_capacity);
				pointer new_end = new_start;
				pointer new_end_capacity = new_start + new_capacity;

				pointer it = this->_start;
				while (it != position) {
					this->_alloc.construct(new_end, *it);
					++new_end;
					++it;
				}

				_alloc.construct(new_end, val);
				++new_end;

				while (it != _end) {
					_alloc.construct(new_end, *it);
					++new_end;
					++it;
				}

				clear();
				_alloc.deallocate(_start, capacity());

				_start = new_start;
				_end = new_end;
				_end_capacity = new_end_capacity;
			}
			else {
				pointer it = _end;
				while (it != position) {
					*it = *(it - 1);
					--it;
				}

				*it = val;
				++_end;
			}
		}

		return _start + pos;
	}

	//range
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last) {
		size_type num_elems = last - first;
		difference_type offset = position - _start;

		if (num_elems == 0)
			return position;

		if (size_type(_end_capacity - _end) < num_elems)
			reserve(size() + num_elems);

		iterator pos = _start + offset;
		iterator old_end = _end;
		size_type i = 0;

		// Move existing elements to make room for new ones
		for (iterator it = old_end; it != pos; --it)
			allocator_type::construct(_alloc, it, *(it-1));
		_end += num_elems;

		// Copy new elements into the available space
		for (const_iterator it = first; it != last; ++it, ++i)
			allocator_type::construct(_alloc, pos + i, *it);

		return pos;
	}

	//fill
	void insert (iterator position, size_type n, const value_type& val) {
		if (n == 0) {
			return;
		}

		difference_type index = position - _start;
		if (size() + n > capacity()) {
			reserve(size() + n);
			position = _start + index;
		}

		pointer new_end = _start + size() + n;
		pointer old_end = _end;
		_end = new_end;

		// shift existing elements
		for (pointer p = old_end - 1; p >= position + n; --p) {
			_alloc.construct(p + n, *p);
			_alloc.destroy(p);
		}

		// insert new elements
		for (size_type i = 0; i < n; ++i) {
			_alloc.construct(position + i, val);
		}
	}
		

		//Allocator:
		allocator_type get_allocator() const {
			return _alloc;
		}
	private:
		allocator_type	_alloc;
		pointer			_start;
		pointer			_end;
		pointer			_end_capacity;
	};

	template <typename T, typename Alloc >
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		else {
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (lhs[i] != rhs[i])
					return false;
			}
			
		}
		return true;
	}
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}
	
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	
	template <class T, class Allocator>
	bool operator<=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Allocator>
	bool operator>(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
		return rhs < lhs;
	}

	template <class T, class Allocator>
	bool operator>=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs) {
		return !(lhs < rhs);
	}
}


#endif
