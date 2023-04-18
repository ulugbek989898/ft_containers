/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:50:28 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/18 16:30:17 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector1.hpp"
#include <iostream>

int	main() {
	// fill constructor
	ft::vector<std::string> v1(10, "hi");
	
	// fill constructor
	ft::vector<int> v2(5, 2);
	
	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << i << ")" << v1[i] << "\n";
	}
	
	// range constructor
	ft::vector<int> v3(v2.begin(), v2.end());
	for (size_t i = 0; i < v2.size(); i++) {
		std::cout << i + 1 << ")" << v2[i] << "\n";
	}

	//copy constructor
	ft::vector<std::string> v4(v1);
	for (size_t i = 0; i < v4.size(); i++) {
		std::cout << i + 1 << ")" << v4[i] << "\n";
	}

	for (ft::vector<std::string>::iterator it = v4.begin(); it != v4.end(); ++it) {
		std::cout << " " << *it << "\n";
	}
	
	ft::vector<int> v66(10, 10);
	for (ft::vector<int>::iterator it = v66.begin(); it != v66.end(); ++it) {
		std::cout << " " << *it << "\n";
	}

	//checking "at" element access
	ft::vector<int> myvector (10);   // 10 zero-initialized ints

//   assign some values:
  for (size_t i = 0; i< myvector.size(); i++) {
	myvector.at(i) = i;
  }
	
	std::cout << "myvector contains:";
	for (size_t i = 0; i < myvector.size(); i++) {
		std::cout << ' ' << myvector.at(i);
	}
	std::cout << '\n';
	
	ft::vector<int> myvector1 (5);

	int* p = myvector1.data();

	*p = 10;
	++p;
	*p = 20;
	p[2] = 100;

	std::cout << "myvector1 contains:";
	for (unsigned i=0; i<myvector1.size(); ++i)
		std::cout << ' ' << myvector1[i];
	std::cout << '\n';
}

