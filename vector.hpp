/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:32:17 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/22 14:54:15 by uisroilo         ###   ########.fr       */
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
# include "utils/utils.hpp"
# include "utils/lexicographical_compare.hpp"
# include "utils/iterator_vec.hpp"

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
		typedef	typename ft::vector_iterator<value_type> iterator;
		typedef	typename ft::vector_iterator< const value_type> const_iterator;

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
			return const_iterator(_start);
		}

		iterator end() {
			if (this->empty())
				return (this->begin());
			return iterator(_end);
		}

		const_iterator end() const {
			if (this->empty())
				return (this->begin());
			return const_iterator(_end);
		}
		
		reverse_iterator rbegin() {
			return reverse_iterator(this->end());
		}

		const_reverse_iterator rbegin () const {
			return const_reverse_iterator(this->end());
		}

		reverse_iterator rend() {
			return reverse_iterator(this->begin());
		}

		const_reverse_iterator rend () const {
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
		
		iterator erase(iterator pos) {
			for (iterator i = pos; i != this->end() - 1; i++) {
				*i = *(i + 1);
			}
			_end--;
			_alloc.destroy(_end);
			return pos;
		}
		
		iterator erase(iterator first, iterator last) {
			size_type start = first - this->begin(),
						end = last - this->begin(),
						range = last - first,
						pos = 0;

			for (size_type i = start; end + pos < this->size(); i++) {
				_start[i] = _start[end + pos++];
			}
			for (size_type i = 0; i < range; i++) {
				_end--;
				_alloc.destroy(_end);
			}
			return first;
		}
		
		void swap (vector& x)
		{
			if (x == *this)
				return;
			
			pointer save_start = x._start;
			pointer save_end = x._end;
			pointer save_end_capacity = x._end_capacity;
			allocator_type save_alloc = x._alloc;

			x._start = this->_start;
			x._end = this->_end;
			x._end_capacity = this->_end_capacity;
			x._alloc = this->_alloc;

			this->_start = save_start;
			this->_end = save_end;
			this->_end_capacity = save_end_capacity;
			this->_alloc = save_alloc;
		}

		// // single element (1)
		iterator insert (iterator position, const value_type& val)
		{
			size_type pos_len = &(*position) - _start;
			if (size_type(_end_capacity - _end) >= this->size() + 1)
			{
				for (size_type i = 0; i < pos_len; i++)
					_alloc.construct(_end - i, *(_end - i - 1));
				_end++;
				_alloc.construct(&(*position), val);
			}
			else
			{
				pointer new_start = pointer();
				pointer new_end = pointer();
				pointer new_end_capacity = pointer();

				int next_capacity = (this->size() * 2 > 0) ? this->size() * 2 : 1; 
				new_start = _alloc.allocate( next_capacity );
				new_end = new_start + this->size() + 1;
				new_end_capacity = new_start + next_capacity;

				for (size_type i = 0; i < pos_len; i++)
					_alloc.construct(new_start + i, *(_start + i));
				_alloc.construct(new_start + pos_len, val);
				for (size_type j = 0; j < this->size() - pos_len; j++)
					_alloc.construct(new_end - j - 1, *(_end - j - 1));

				for (size_type l = 0; l < this->size(); l++)
					_alloc.destroy(_start + l);
				if (_start)
					_alloc.deallocate(_start, this->capacity());
				
				_start = new_start;
				_end = new_end;
				_end_capacity = new_end_capacity;
			}
			return (iterator(_start + pos_len));
		}
	//range
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				// bool is_valid;
				// if (!(is_valid = ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::value))
				// 	throw (ft::InvalidIteratorException<typename ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::type>());
				
				size_type dist = ft::distance(first, last);
				if (size_type(_end_capacity - _end) >= dist)
				{
					for(size_type i = 0; i < this->size() - (&(*position) - _start); i++)
						_alloc.construct(_end - i + (dist - 1), *(_end - i - 1));
					_end += dist;
					for (; &(*first) != &(*last); first++, position++)
						_alloc.construct(&(*position), *first);
				}
				else
				{
					pointer new_start = pointer();
					pointer new_end = pointer();
					pointer new_end_capacity = pointer();

					new_start = _alloc.allocate( this->size() * 2 );
					new_end = new_start + this->size() + dist;
					new_end_capacity = new_start + ( this->size() * 2 );

					if (size_type(new_end_capacity - new_start) < this->size() + dist)
					{
						if (new_start)
							_alloc.deallocate(new_start, new_end_capacity - new_start);
						new_start = _alloc.allocate (this->size() + dist);
						new_end = new_start + this->size() + dist;
						new_end_capacity = new_end;
					}

					for (int i = 0; i < &(*position) - _start; i++)
						_alloc.construct(new_start + i, *(_start + i));
					for (int j = 0; &(*first) != &(*last); first++, j++)
						_alloc.construct(new_start + (&(*position) - _start) + j, *first);
					for (size_type k = 0; k < this->size() - (&(*position) - _start); k++)
						_alloc.construct(new_start + (&(*position) - _start) + dist + k, *(_start + (&(*position) - _start) + k));

					for (size_type l = 0; l < this->size(); l++)
						_alloc.destroy(_start + l);
					_alloc.deallocate(_start, this->capacity());

					_start = new_start;
					_end = new_end;
					_end_capacity = new_end_capacity;
				}
			}
	//fill
		void insert (iterator position, size_type n, const value_type& val)
		{
			if (n == 0)
				return ;
			if (n > this->max_size())
				throw (std::length_error("vector::insert (fill)"));
			size_type pos_len = &(*position) - _start;
			if (size_type(_end_capacity - _end) >= n)
			{
				for (size_type i = 0; i < this->size() - pos_len; i++)
					_alloc.construct(_end - i + (n - 1), *(_end - i - 1));
				_end += n;
				while (n)
				{
					_alloc.construct(&(*position) + (n - 1), val);
					n--;
				}
			}
			else
			{
				pointer new_start = pointer();
				pointer new_end = pointer();
				pointer new_end_capacity = pointer();
				
				int next_capacity = (this->capacity() > 0) ? (int)(this->size() * 2) : 1;
				new_start = _alloc.allocate(next_capacity);
				new_end_capacity = new_start + next_capacity;

				if (size_type(new_end_capacity - new_start) < this->size() + n)
				{
					if (new_start)
						_alloc.deallocate(new_start, new_start - new_end_capacity);
					next_capacity = this->size() + n;
					new_start = _alloc.allocate(next_capacity);
					new_end = new_start + this->size() + n;
					new_end_capacity = new_start + next_capacity;
				}

				new_end = new_start + this->size() + n;

				for (int i = 0; i < (&(*position) - _start); i++)
					_alloc.construct(new_start + i, *(_start + i));
				for (size_type k = 0; k < n; k++)
					_alloc.construct(new_start + pos_len + k, val);
				for (size_type j = 0; j < (this->size() - pos_len); j++)
					_alloc.construct(new_end - j - 1, *(_end - j - 1));

				for (size_type u = 0; u < this->size(); u++)
					_alloc.destroy(_start + u);
				_alloc.deallocate(_start, this->capacity());

				_start = new_start;
				_end = new_end;
				_end_capacity = new_end_capacity;
			}
		}

	
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		{
			this->clear();
			size_type dist = ft::distance(first, last);
			if (size_type(_end_capacity - _start) >= dist)
			{
				for(; &(*first) != &(*last); first++, _end++)
					_alloc.construct(_end, *first);
			}
			else
			{
				pointer new_start = pointer();
				pointer new_end = pointer();
				pointer new_end_capacity = pointer();

				new_start = _alloc.allocate(dist);
				new_end = new_start;
				new_end_capacity = new_start + dist;

				for(; &(*first) != &(*last); first++, new_end++)
					_alloc.construct(new_end, *first);
				
				_alloc.deallocate(_start, this->capacity());

				_start = new_start;
				_end = new_end;
				_end_capacity = new_end_capacity;
			}
		}
	
		void assign (size_type n, const value_type& val)
	{
		this->clear();
		if (n == 0)
			return ;
		if (size_type(_end_capacity - _start) >= n)
		{
			while (n)
			{
				_alloc.construct(_end++ , val);
				n--;
			}
		}
		else
		{
			_alloc.deallocate(_start, this->capacity());
			_start = _alloc.allocate( n );
			_end = _start;
			_end_capacity = _start + n;
			while (n)
			{
				_alloc.construct(_end++, val);
				n--;
			}
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
