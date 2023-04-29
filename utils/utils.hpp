/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:49:16 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/24 16:16:59 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>
# include <iostream>
# include "type_traits.hpp"
# include "iterator_traits.hpp"

namespace ft {
	template<class InputIterator>
		typename ft::iterator_traits<InputIterator>::difference_type
			distance (InputIterator first, InputIterator last)
		{
			typename ft::iterator_traits<InputIterator>::difference_type rtn = 0;
			while (first != last)
			{
				first++;
				rtn++;
			}
			return (rtn);
		}
	template <typename T>
		struct is_ft_iterator_tagged : public valid_iterator_tag_res<false, T> { };

	template <>
		struct is_ft_iterator_tagged<ft::random_access_iterator_tag>
			: public ft::valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };

	template <>
		struct is_ft_iterator_tagged<ft::bidirectional_iterator_tag>
			: public ft::valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };

	template <>
		struct is_ft_iterator_tagged<ft::forward_iterator_tag>
			: public ft::valid_iterator_tag_res<true, ft::forward_iterator_tag> { };

	template <>
		struct is_ft_iterator_tagged<ft::input_iterator_tag>
			: public ft::valid_iterator_tag_res<true, ft::input_iterator_tag> { };

	template <>
		struct is_ft_iterator_tagged<ft::output_iterator_tag>
			: public ft::valid_iterator_tag_res<true, ft::output_iterator_tag> { };
}


#endif