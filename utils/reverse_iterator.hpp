/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:43:43 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/18 14:20:15 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

namespace ft {

	template <typename Iterator>
		class reverse_iterator {
		public:
			typedef typename Iterator::iterator_category iterator_category;
			typedef typename Iterator::value_type value_type;
			typedef typename Iterator::difference_type difference_type;
			typedef typename Iterator::pointer pointer;
			typedef typename Iterator::reference reference;

			reverse_iterator() : current() {}
			explicit reverse_iterator(Iterator x) : current(x) {}
			template <typename Iter>
			reverse_iterator(const reverse_iterator<Iter>& other) : current(other.base()) {}

			Iterator base() const { return current; }

			reference operator*() const {
				Iterator tmp = current;
				return *(--tmp);
			}

			pointer operator->() const { return &(operator*()); }

			reverse_iterator& operator++() {
				--current;
				return *this;
			}

			reverse_iterator operator++(int) {
				reverse_iterator tmp(*this);
				--current;
				return tmp;
			}

			reverse_iterator& operator--() {
				++current;
				return *this;
			}

			reverse_iterator operator--(int) {
				reverse_iterator tmp(*this);
				++current;
				return tmp;
			}

			reverse_iterator operator+(difference_type n) const {
				return reverse_iterator(current - n);
			}

			reverse_iterator& operator+=(difference_type n) {
				current -= n;
				return *this;
			}

			reverse_iterator operator-(difference_type n) const {
				return reverse_iterator(current + n);
			}

			reverse_iterator& operator-=(difference_type n) {
				current += n;
				return *this;
			}

			reference operator[](difference_type n) const {
				return *(*this + n);
			}

		private:
			Iterator current;
		};

		template <class Iterator>
		reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
			return reverse_iterator<Iterator>(rev_it.base() - n);
		}

		template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return rhs.base() - lhs.base();
		}

		template <class Iterator1, class Iterator2>
		bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
			return lhs.base() == rhs.base();
		}

		template <class Iterator1, class Iterator2>
		bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
			return !(lhs == rhs);
		}

		template <class Iterator1, class Iterator2>
		bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
			return lhs.base() > rhs.base();
		}

		template <class Iterator1, class Iterator2>
		bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
			return lhs.base() >= rhs.base();
		}

		template <class Iterator1, class Iterator2>
		bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
			return lhs.base() < rhs.base();
		}

		template <class Iterator1, class Iterator2>
		bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
			return lhs.base() <= rhs.base();
		}

}

#endif