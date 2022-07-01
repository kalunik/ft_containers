//
// Created by Waif Jonathon on 6/9/22.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <memory>
#include <stdexcept>
#include "iterators/random_access_iterator.hpp"

namespace ft{
	template<class T, class Allocator = std::allocator<T> >
	class vector {
	public:
		typedef Allocator									allocator_type;

		typedef T											value_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef RandomIter<T>								iterator;
		typedef RandomIter<const T>							const_iterator;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
//		typedef std::reverse_iterator<iterator>          reverse_iterator;
//		typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

	protected:
		pointer			_data;
		size_t			_size;
		size_t			_capacity;
		allocator_type	_alloc;

	public:
		explicit vector(const allocator_type& alloc = allocator_type()) :
		_size(0), _capacity(0), _alloc(alloc) {
			reserve(2); // * original vector doesn't use this
		}
		/*explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());
		template<class InputIterator>
				vector(InputIterator first, InputIterator last,
					   const allocator_type& alloc = allocator_type());*/
		vector(const vector& x) {
			this = x;
		}
		~vector() {
			for (size_t i = 0; i < _capacity; i++) {
				_alloc.destroy(_data);
			}

			_alloc.deallocate(_data, _capacity);
		}

		/** @warning May not work properly !!! */
		vector& operator= (const vector& x) {
			if (this != &x) {
				_size = x._size;
				_capacity = x._capacity;
				// ? how to move `_data` and `_alloc`
			}
			return *this;
		}

		/* * ELEMENT ACCESS */
		reference at (size_type n) {
			if (n >= size())
				throw std::out_of_range("vector");
			return _data[n];
		}
		const_reference at (size_type n) const {
			if (n >= size())
				throw std::out_of_range("vector");
			return _data[n];
		}
		reference operator[] (size_type n) {
//			assert(n < size());
			return _data[n];
		}
		const_reference operator[] (size_type n) const {
//			assert(n < size());
			return _data[n];
		}
		reference front() {
			return _data[0]; // ! orig : segfault if obj is empty(); mine: 0(ub)
		}
		const_reference front() const {
			return _data[0];
		}
		reference back() {
			return _data[size()-1];
			// ! orig : segfault if obj is empty(); mine: 0(ub)
		}
		const_reference back() const {
			return _data[size()-1];
		}

		/* * ITERATORS */
		iterator begin() {
			return iterator(_data);
		}
		const_iterator begin() const {
			return const_iterator(_data);
		}
		iterator end() {
			return iterator(_data + _size);
		}
		const_iterator end() const {
			return const_iterator(_data + _size);
		}

		/* * MODIFIERS */
		void push_back(const value_type& val) {
			if (_size >= _capacity)
				reserve(_capacity + _capacity / 2);

			_data[_size] = val;
			_size++;
		}
		void pop_back() {
			if (_size > 0) {
				_size--;
				_data[_size].~T();
			}
		}


		/* * CAPACITY */
		size_t size() const { return _size; }
		size_type max_size() const { return sizeof(T); }
		void reserve(size_t n) {
			T* newData = _alloc.allocate(n);

			std::uninitialized_fill_n(newData, n, T());

			size_t	oldCapacity = _capacity;
			if (n < _capacity) {
				_capacity = n;
			}

			for (size_t i = 0; i < _capacity; i++) {
				newData[i] = _data[i];
//				_alloc.destroy(_data + i); // ? maybe there is no need
			}

			if (oldCapacity > 0) {
				_alloc.deallocate(_data, oldCapacity);
				// ? it dealloc even oldCap is 0
			}
			_data = newData;
			_capacity = n;
		}
		size_type capacity() const { return _capacity; }


	};
}

#endif //FT_CONTAINERS_VECTOR_HPP
