//
// Created by Waif Jonathon on 6/3/22.
//

#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include <vector>

namespace ft {
	template<class T/*, class Container = std::vector<T>*/ >

	class stack : private std::vector<T> {
	public:
		typedef std::vector<T> container_type;
		typedef typename container_type::value_type value_type;
		typedef typename container_type::size_type size_type;
		typedef typename container_type::reference reference;
		typedef typename container_type::const_reference const_reference;
	protected:
		container_type c;
	public:
		stack() {};
		stack(const stack &other) {
			*this = other;
		}
		~stack() {};
		stack &operator=(const stack &obj) {
			c = obj.c;
			return *this;
		}

		/** ELEMENT ACCESS */
		reference top() {
			return c.back();
		}

		const_reference top() const {
			return c.back();
		}

		/** CAPACITY */
		bool empty() const {
			return c.size() == 0;
		}

		size_type size() const {
			return c.size();
		}

		/** MODIFIERS */
		void push(const value_type &value) {
			c.push_back(value);
		}

		void pop() {
			c.pop_back();
		}

		/** NON-MEMBER FUNCTIONS*/
		friend bool operator==(const ft::stack<T> &lhs, const ft::stack <T>
		        &rhs) {
			return lhs.c == rhs.c;
		}
		friend bool operator!=(const ft::stack<T> &lhs, const ft::stack<T>
		        &rhs) {
			return lhs.c != rhs.c;
		}
		friend bool operator<(const ft::stack<T> &lhs, const ft::stack<T>
		        &rhs) {
			return lhs.c < rhs.c;
		}
		friend bool operator<=(const ft::stack<T> &lhs, const ft::stack<T>
		        &rhs) {
			return lhs.c <= rhs.c;
		}
		friend bool operator>(const ft::stack<T> &lhs, const ft::stack<T>
		        &rhs) {
			return lhs.c > rhs.c;
		}
		friend bool operator>=(const ft::stack<T> &lhs, const ft::stack<T>
		        &rhs) {
			return lhs.c >= rhs.c;
		}
	};
}

#endif //FT_CONTAINERS_STACK_HPP
