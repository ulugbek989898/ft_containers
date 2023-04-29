/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:18:37 by uisroilo          #+#    #+#             */
/*   Updated: 2023/04/22 15:35:32 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <iostream>
int main ()
{
	ft::vector<int> myvector (22,200);        // vector with 2 elements


	ft::stack<int,ft::vector<int> > third;  // empty stack using vector
	ft::stack<int,ft::vector<int> > fourth (myvector);

	std::cout << "isEmpty?: " << third.empty() << '\n';
	std::cout << "isEmpty?: " << fourth.empty() << '\n';

	std::cout << "size: " << third.size() << '\n';
	std::cout << "size: " << fourth.size() << '\n';


	ft::vector<int> myvector12 (5);
	for (size_t i = 0; i < 5; i++)
	{
		myvector12.at(i) = i + 10;
	}
	
	ft::stack<int> mystack(myvector12);

	// mystack.top() -= 5;

	std::cout << "mystack.top() is now " << mystack.top() << '\n';

	ft::stack<int> mystack1222;

	for (int i=0; i<5; ++i) {
		mystack1222.push(i);
	}
	std::cout << "mystack1222.top() is now " << mystack1222.top() << '\n';
	std::cout << '\n';

	ft::stack<int> mystackPop;

	for (int i=0; i<5; ++i) mystackPop.push(i);

	std::cout << "Popping out elements...";
	while (!mystackPop.empty())
	{
		std::cout << ' ' << mystackPop.top();
		mystackPop.pop();
	}
	std::cout << '\n';
	return 0;
}