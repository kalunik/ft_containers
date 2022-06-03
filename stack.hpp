//
// Created by Waif Jonathon on 6/3/22.
//

#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include <vector>

namespace ft {
	template<typename T>

	class stack : private std::vector<T> {
	public:
		stack<T>() {};
		stack<T>(const stack<T> &other) {
			*this = other;
		}
		~stack<T>() {};
		stack<T>& operator=(const stack<T>& obj) {
			std::vector<T>::operator=(obj);
			return *this;
		}

		void push(const valueType& value) {
			this->push_back(value);
		}

	private:
		typename std::vector<T>::value_type valueType;
	};
}

#endif //FT_CONTAINERS_STACK_HPP
