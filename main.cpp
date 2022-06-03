//
// Created by Waif Jonathon on 6/3/22.
//
#include "stack.hpp"
#include <stack>
#include <iostream>

int main() {
	std::stack<int> a;
	ft::stack<int> b;

	a.push(3);
	b.push(2);
	std::cout << b << std::endl;
}
