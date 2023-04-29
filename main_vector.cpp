/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:50:28 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/28 10:40:28 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>

#include <iterator>

#include <typeinfo> 

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
	
	ft::vector<int> v66(10);
	for (int i = 0; i < 10; i++) {
		v66.at(i) = i + 1;
	}
	ft::vector<int>::reverse_iterator it = v66.rbegin();
	std::cout << "res -> " << *it << "\n";
	// for (ft::vector<int>::reverse_iterator it = v66.rbegin(); it != v66.rend(); ++it) {
	// 	std::cout << " " << *it;
	// 	// std::cout << "hello" << std::endl;
	// }

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


	std::vector<int> foo98 (3,100);   // three ints with a value of 100
	std::vector<int> bar98 (5,200);   // five ints with a value of 200

	foo98.swap(bar98);

	std::cout << "foo98 contains:";
	for (unsigned i=0; i<foo98.size(); i++)
		std::cout << ' ' << foo98[i];
	std::cout << '\n';

	std::cout << "bar98 contains:";
	for (unsigned i=0; i<bar98.size(); i++)
		std::cout << ' ' << bar98[i];
	std::cout << '\n';

	ft::vector<int> foo1234 (3,100);   // three ints with a value of 100
	ft::vector<int> bar1234 (5,200);   // five ints with a value of 200

	foo1234.swap(bar1234);

	std::cout << "foo1234 contains:";
	// std::cout << foo1234.size() << "\n";
	for (ft::vector<int>::iterator it = foo1234.begin(); it!=foo1234.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar1234 contains:";
	for (ft::vector<int>::iterator it = bar1234.begin(); it!=bar1234.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int> myvector28 (3,100);
	ft::vector<int>::iterator ittt = myvector28.begin();

	// it = myvector28.begin();
	ittt = myvector28.insert( ittt , 200 );

	myvector28.insert (ittt,2,300);

	// "ittt" no longer valid, get a new one:
	ittt = myvector28.begin();

	std::vector<int> anothervector (2,400);
	myvector28.insert(ittt+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector28.insert (myvector28.begin(), myarray, myarray+3);

	std::cout << "myvector28 contains:";
	for (ittt=myvector28.begin(); ittt<myvector28.end(); ittt++)
		std::cout << ' ' << *ittt;
	std::cout << '\n';

	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	std::vector<int>::iterator tit;
	tit=first.begin()+1;

	second.assign (tit,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
	
	ft::vector<int> myV;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myV.push_back(i);


	// erase the first 3 elements:
	myV.erase (myV.begin() + 5,myV.begin()+ 9);

	std::cout << "myV contains:";
	for (size_t i=0; i<myV.size(); ++i)
	std::cout << ' ' << myV[i];
	std::cout << '\n';
	
	ft::vector<std::string> vec;
	vec.insert(vec.end() - vec.size(), "I admire your courage but I don't admire your singing ability.");

	ft::vector<int> foo1222(3, 15);
	ft::vector<int> bar1222(5, 42);
	
	ft::vector<int>::const_iterator it_foo = foo1222.begin();
	ft::vector<int>::const_iterator it_bar = bar1222.begin();

	
	std::cout << "BEFORE SWAP" << std::endl;

	std::cout << "foo1222 contains:" << std::endl;
	// printSize(foo1222);
	std::cout << "bar1222 contains:" << std::endl;
	// printSize(bar1222);

	foo1222.swap(bar1222);

	std::cout << "AFTER SWAP" << std::endl;

	std::cout << "foo1222 contains:" << std::endl;
	// printSize(foo1222);
	std::cout << "bar1222 contains:" << std::endl;
	// printSize(bar1222);

	std::cout << "Iterator validity:" << std::endl;
	std::cout << (it_foo == bar1222.begin()) << std::endl;
	std::cout << (it_bar == foo1222.begin()) << std::endl;

	typedef ft::iterator_traits<const std::string *> traits;
	if (typeid(traits::iterator_category)==typeid(ft::random_access_iterator_tag))
		std::cout << "int* is a random-access iterator\n";
	
	std::vector<int> aa(10);
	for (std::vector<int>::iterator it = aa.begin(); it != aa.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << "\n";

	aa.reserve(15);
	std::cout << "capacity aa=" << aa.capacity() << "\n";
	for (std::vector<int>::iterator it = aa.begin(); it != aa.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << "\n";
	std::cout << "capacity aa1=" << aa.capacity() << "\n";
	aa.insert(aa.begin() + 3, 12);
	std::cout << "capacity aa2=" << aa.capacity() << "\n";
	for (std::vector<int>::iterator it = aa.begin(); it != aa.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << "\n";
	return 0;
}
