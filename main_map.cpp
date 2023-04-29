/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 06:55:53 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/23 16:28:04 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "utils/avl_tree.hpp"

int main () {
	ft::pair <int,int> foo;
	ft::pair <int,int> bar;

	foo = ft::make_pair (10,20);
	bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

	ft::AVLTree nodes;

	nodes.insert(7, 50);
	nodes.insert(3, 10);
	nodes.insert(4, 25);
	nodes.insert(1, 40);
	nodes.insert(6, 22);
	nodes.insert(5, 30);
	nodes.insert(2, 20);

	
	return 0;
}