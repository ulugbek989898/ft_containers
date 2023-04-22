/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:43:43 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/22 14:46:25 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

template <class Iterator>
class reverse_iterator : public ft::iterator<typename ft::iterator_traits<Iterator>::iterator_category,
                                             typename ft::iterator_traits<Iterator>::value_type,
                                             typename ft::iterator_traits<Iterator>::difference_type,
                                             typename ft::iterator_traits<Iterator>::pointer,
                                             typename ft::iterator_traits<Iterator>::reference> {

	public:
		typedef Iterator                                 iterator_type;
		typedef ft::iterator_traits<iterator_type>       traits_type;
		typedef typename traits_type::pointer            pointer;
		typedef typename traits_type::reference          reference;
		typedef typename traits_type::difference_type    difference_type;

	private:
		iterator_type    m_current;

	public:
		reverse_iterator() : m_current() {}

		reverse_iterator(iterator_type x) : m_current(x) {}

		template <class T>
		reverse_iterator(const reverse_iterator<T> &value) : m_current(value.base()) {}

		reverse_iterator &operator=(const reverse_iterator &value) {
			if (this != &value) {
				m_current = value.base();
			}
			return *this;
		}

		~reverse_iterator() {}

		iterator_type base() const {
			return m_current;
		}

		reference operator*() const {
			iterator_type temp = m_current;
			return *--temp;
		}

		pointer operator->() const {
			return &this->operator*();
		}

		reference operator[](difference_type n) const {
			return *(*this + n);
		};

		reverse_iterator operator+(difference_type n) const {
			return reverse_iterator(m_current - n);
		}

		reverse_iterator &operator+=(difference_type n) {
			m_current -= n;
			return *this;
		}

		reverse_iterator &operator++() {
			--m_current;
			return *this;
		}

		reverse_iterator operator++(int) {
			reverse_iterator temp(*this);
			--m_current;
			return temp;
		}

		reverse_iterator operator-(difference_type n) const {
			return reverse_iterator(m_current + n);
		}

		reverse_iterator &operator-=(difference_type n) {
			m_current += n;
			return *this;
		}

		reverse_iterator &operator--() {
			++m_current;
			return *this;
		}

		reverse_iterator operator--(int) {
			reverse_iterator temp(*this);
			++m_current;
			return temp;
		}

};

template <class Iter1, class Iter2>
bool operator==(const reverse_iterator<Iter1> &x, const reverse_iterator<Iter2> &y) {
	return x.base() == y.base();
}

template <class Iter1, class Iter2>
bool operator!=(const reverse_iterator<Iter1> &x, const reverse_iterator<Iter2> &y) {
	return x.base() != y.base();
}

template <class Iter1, class Iter2>
bool operator<(const reverse_iterator<Iter1> &x, const reverse_iterator<Iter2> &y) {
	return x.base() > y.base();
}

template <class Iter1, class Iter2>
bool operator<=(const reverse_iterator<Iter1> &x, const reverse_iterator<Iter2> &y) {
	return x.base() >= y.base();
}

template <class Iter1, class Iter2>
bool operator>(const reverse_iterator<Iter1> &x, const reverse_iterator<Iter2> &y) {
	return x.base() < y.base();
}

template <class Iter1, class Iter2>
bool operator>=(const reverse_iterator<Iter1> &x, const reverse_iterator<Iter2> &y) {
	return x.base() <= y.base();
}

template <class Iter1, class Iter2>
typename reverse_iterator<Iter1>::difference_type
operator-(const reverse_iterator<Iter1> &x, const reverse_iterator<Iter2> &y) {
	return y.base() - x.base();
}

template <class Iterator>
reverse_iterator<Iterator>
operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &x) {
	return reverse_iterator<Iterator>(x.base() - n);
}

}    // namespace ft

#endif    // REVERSE_ITERATOR_HPP