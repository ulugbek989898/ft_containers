/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:50:28 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/19 15:28:23 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
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

	  ft::vector<int> myvector12(2);

		myvector12.at(0) = 78;
		myvector12.at(1) = 16;

		// now front equals 78, and back 16

		myvector12.front() -= myvector12.back();

		std::cout << "myvector.front() is now " << myvector12.front() << '\n';

	// comparing size, capacity and max_size
	ft::vector<int> myvector111(10);

	// set some content in the vector:
	for (int i=0; i< 5; i++)  {
		myvector111.at(i) = i;
	}
	std::cout << "size: " << myvector111.size() << "\n";
	std::cout << "capacity: " << myvector111.capacity() << "\n";
	std::cout << "max_size: " << myvector111.max_size() << "\n";

	ft::vector<int> foo;
	size_t sz = foo.capacity();
	std::cout << "initial capacity = " << foo.capacity() << "\n";
	for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  std::cout << "hello\n";
	// resizing vector
	 ft::vector<int> myvector1112(10);

	// set some initial content:
	for (int i = 0;i<10;i++) {
		myvector1112[i] = i + 1;
	};
	myvector1112.resize(5);
	myvector1112.resize(8, 100);
	myvector1112.resize(12);

	std::cout << "myvector1112 contains:";
	for (size_t i=0;i<myvector1112.size();i++)
		std::cout << ' ' << myvector1112[i];
	std::cout << '\n';
	std::cout << "///////////////////////////////\n";
	ft::vector<int> myvector_test (100);
	std::cout << "1. capacity of myvector_test: " << myvector_test.capacity() << '\n';

	myvector_test.resize(10);
	std::cout << "2. capacity of myvector_test: " << myvector_test.capacity() << '\n';
	
	ft::vector<int> foo1 (3,0);
	ft::vector<int> bar (5,0);

	bar = foo1;
	foo1 = ft::vector<int>();

	std::cout << "Size of foo1: " << int(foo1.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';

	// erasing from vector
	std::vector<int> myvector98;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector98.push_back(i);

	// erase the 6th element
	myvector98.erase (myvector98.begin()+5);

	// erase the first 3 elements:
	myvector98.erase (myvector98.begin(),myvector98.begin()+3);

	std::cout << "myvector98 contains:";
	for (size_t i=0; i<myvector98.size(); ++i)
	std::cout << ' ' << myvector98[i];
	std::cout << '\n';
	return 0;
}
