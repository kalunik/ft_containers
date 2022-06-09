//
// Created by Waif Jonathon on 6/9/22.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <memory>
#inlude <stack>
namespace ft{
	template<class T/*, class Allocator = std::allocator<T>*/>
	class vector {
	public:
		typedef T									value_type;
		typedef std::allocator<T>					allocator_type;
		typedef typename allocator_type::reference	reference;
		typedef allocator_type::const_reference		const_reference;

		explicit vector(const allocator_type& alloc = allocator_type());
		explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());
		template<class InputIterator>
				vector(InputIterator first, InputIterator last,
					   const allocator_type& alloc = allocator_type());
		vector (const vector& x);
		~vector();
		vector& operator= (const vector& x);

		/** ELEMENT ACCESS */
		reference operator[] (size_type n){
			return
		}
		const_reference operator[] (size_type n) const;
	};
}

#endif //FT_CONTAINERS_VECTOR_HPP
