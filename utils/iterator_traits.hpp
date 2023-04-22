/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:21:47 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/20 15:23:11 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <iostream>

namespace ft {

struct input_iterator_tag { };

struct output_iterator_tag { };

struct forward_iterator_tag : public input_iterator_tag { };

struct bidirectional_iterator_tag : public forward_iterator_tag { };

struct random_access_iterator_tag : public bidirectional_iterator_tag { };


template <class Iterator>
struct iterator_traits {
	typedef typename Iterator::value_type           value_type;
	typedef typename Iterator::pointer              pointer;
	typedef typename Iterator::reference            reference;
	typedef typename Iterator::difference_type      difference_type;
	typedef typename Iterator::iterator_category    iterator_category;
};


template <class IterPointer>
struct iterator_traits<IterPointer*> {
	typedef IterPointer                        value_type;
	typedef IterPointer*                       pointer;
	typedef IterPointer&                       reference;
	typedef std::ptrdiff_t                     difference_type;
	typedef ft::random_access_iterator_tag     iterator_category;
};


template <class IterPointer>
struct iterator_traits<const IterPointer*> {
	typedef IterPointer                        value_type;
	typedef const IterPointer*                 pointer;
	typedef const IterPointer&                 reference;
	typedef std::ptrdiff_t                     difference_type;
	typedef ft::random_access_iterator_tag     iterator_category;
};

template <class Category, class T, class Distance = std::ptrdiff_t,
          class Pointer = T*, class Reference = T&>
struct iterator {
	typedef T            value_type;
	typedef Pointer      pointer;
	typedef Reference    reference;
	typedef Distance     difference_type;
	typedef Category     iterator_category;
};

}

#endif
