/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_vec.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:34:46 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/18 10:54:44 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORVEC
# define ITEROTORVEC
# include <iostream>

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class iterator {
		public:
			typedef Alloc allocator_type;
			typedef std::random_access_iterator_tag iterator_category;
			typedef T value_type;
			typedef typename allocator_type::difference_type difference_type;
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

		template <typename T, typename Alloc = std::allocator<T> >
		class const_iterator {
		public:
			typedef Alloc allocator_type;
			typedef std::random_access_iterator_tag iterator_category;
			typedef const T value_type;
			// typedef difference_type difference_type;
			typedef typename allocator_type::difference_type difference_type;
			typedef const T* pointer;
			typedef const T& reference;
			
			const_iterator() : ptr(NULL) {}
			explicit const_iterator(pointer p) : ptr(p) {}
			const_iterator(const const_iterator& other) : ptr(other.ptr) {}
			const_iterator(const ft::iterator& other) : ptr(other.operator->()) {}
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

		
} // namespace ft


#endif