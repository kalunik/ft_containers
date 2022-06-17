//
// Created by Waif Jonathon on 6/3/22.
//
#include "vector.hpp"
#include <vector>
#include <iostream>

int main() {

	std::vector<int> a;

//	a.push_back(2);
//	a.push_back(3);
//	a.pop_back();
//	a.pop_back();
//	a.push_back(3);
//	a.push_back(3);
//	a.push_back(3);

//	b.push(3);
	std::cout << a.capacity() << " | " << a.size() << std::endl;
	try {
		std::cout << a.front() << std::endl;
	}
}
