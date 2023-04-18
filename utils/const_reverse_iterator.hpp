/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_reverse_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:27:29 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/18 14:31:26 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTREVERSEITERATOR_HPP
# define CONSTREVERSEITERATOR_HPP

namespace ft {
	//const reverse iterator
	template <typename Iterator>
	class const_reverse_iterator {
	public:
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;

		const_reverse_iterator() : current() {}
		explicit const_reverse_iterator(Iterator x) : current(x) {}
		template <typename Iter>
		const_reverse_iterator(const const_reverse_iterator<Iter>& other) : current(other.base()) {}

		Iterator base() const { return current; }

		reference operator*() const {
			Iterator tmp = current;
			return *(--tmp);
		}

		pointer operator->() const { return &(operator*()); }

		const_reverse_iterator& operator++() {
			--current;
			return *this;
		}

		const_reverse_iterator operator++(int) {
			const_reverse_iterator tmp(*this);
			--current;
			return tmp;
		}

		const_reverse_iterator& operator--() {
			++current;
			return *this;
		}

		const_reverse_iterator operator--(int) {
			const_reverse_iterator tmp(*this);
			++current;
			return tmp;
		}

		const_reverse_iterator operator+(difference_type n) const {
			return const_reverse_iterator(current - n);
		}

		const_reverse_iterator& operator+=(difference_type n) {
			current -= n;
			return *this;
		}

		const_reverse_iterator operator-(difference_type n) const {
			return const_reverse_iterator(current + n);
		}

		const_reverse_iterator& operator-=(difference_type n) {
			current += n;
			return *this;
		}

		reference operator[](difference_type n) const {
			return *(*this + n);
		}

	private:
		Iterator current;
	};

	template <typename Iterator>
	bool operator==(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) {
		return lhs.base() == rhs.base();
	}

	template <typename Iterator>
	bool operator!=(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) {
		return !(lhs == rhs);
	}

	template <typename Iterator>
	bool operator<(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) {
		return rhs.base() < lhs.base();
	}

	template <typename Iterator>
	bool operator<=(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) {
		return !(rhs < lhs);
	}

	template <typename Iterator>
	bool operator>(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) {
		return rhs < lhs;
	}

	template <typename Iterator>
	bool operator>=(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) {
		return !(lhs < rhs);
	}

	template <typename Iterator>
	typename const_reverse_iterator<Iterator>::difference_type operator-(const const_reverse_iterator<Iterator>& lhs,
																		const const_reverse_iterator<Iterator>& rhs) {
		return rhs.base() - lhs.base();
	}

	template <typename Iterator>
	const_reverse_iterator<Iterator> operator+(typename const_reverse_iterator<Iterator>::difference_type n,
												const const_reverse_iterator<Iterator>& x) {
		return const_reverse_iterator<Iterator>(x.base() - n);
	}

}

#endif