//
// Created by Waif Jonathon on 6/9/22.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <memory>

namespace ft{
	template<class T, class Allocator = std::allocator<T> >
	class vector {
	public:
		typedef T                                        value_type;
		typedef Allocator                                allocator_type;
		typedef typename allocator_type::reference       reference;
		typedef typename allocator_type::const_reference const_reference;
//		typedef implementation-defined                   iterator;
//		typedef implementation-defined                   const_iterator;
		typedef typename allocator_type::size_type       size_type;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::pointer         pointer;
		typedef typename allocator_type::const_pointer   const_pointer;
//		typedef std::reverse_iterator<iterator>          reverse_iterator;
//		typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

	protected:
		T*		_data;
		size_t	_size;
		size_t	_capacity;

	public:
		explicit vector(const allocator_type& alloc = allocator_type()) {
			reAlloc(2);
		}
		explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());
		template<class InputIterator>
				vector(InputIterator first, InputIterator last,
					   const allocator_type& alloc = allocator_type());
		vector (const vector& x);
		~vector();
		vector& operator= (const vector& x);

		/* * ELEMENT ACCESS */
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;

		/* * MODIFIERS */
		void push_back(const value_type& val) {
			if (_size >= _capacity)
				reAlloc(_capacity + _capacity/2);

			_data[_size] = val;
			_size++;
		}

		/* * CAPACITY */
		size_t size() const { return _size; }

	private:
		/* * UTILS */
		void reAlloc(size_t newCapacity) {
			T* newData = new T[newCapacity];

			if (newCapacity < _capacity)
				_capacity = newCapacity;

			for (size_t i = 0; i < _capacity; i++) {
				newData[i] = _data[i];
			}

			delete[] _data;
			_data = newData;
			_capacity = newCapacity;
		}
	};
}

#endif //FT_CONTAINERS_VECTOR_HPP
