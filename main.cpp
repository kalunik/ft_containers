//
// Created by Waif Jonathon on 6/3/22.
//
#include "stack.hpp"
#include <stack>
#include <iostream>

int main() {
	ft::stack<int> a;
	ft::stack<int> b;

	a.push(2);
	b.push(3);
	std::cout << (b == a) << std::endl;
}
