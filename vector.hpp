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
		T*				_data;
		size_t			_size;
		size_t			_capacity;
		allocator_type	_alloc;

	public:
		explicit vector(const allocator_type& alloc = allocator_type()) :
		_size(0), _capacity(0), _alloc(alloc) {
			resize(2);
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
				// ? how to move _data and _alloc
			}
			return *this;
		}

		/* * ELEMENT ACCESS */
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;

		/* * MODIFIERS */
		void push_back(const value_type& val) {
			if (_size >= _capacity)
				resize(_capacity + _capacity/2);

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
		void resize(size_t newCapacity, value_type val = value_type()) {
			T* newData = _alloc.allocate(newCapacity);

			for (size_t i = 0; i < newCapacity; i++) {
				_alloc.construct(newData, val);
			}

			// * first param – forward_iterator; if I use this `val` is unused
//			std::uninitialized_fill_n(newData, newCapacity, T());

			size_t	oldCapacity = _capacity;
			if (newCapacity < _capacity) {
				_capacity = newCapacity;
			}

			for (size_t i = 0; i < _capacity; i++) {
				newData[i] = _data[i];
				_alloc.destroy(_data + i); // ? maybe there is no need
			}

			_alloc.deallocate(_data, oldCapacity);
			_data = newData;
			_capacity = newCapacity;
		}
		size_type capacity() const { return _capacity; }


	};
}

#endif //FT_CONTAINERS_VECTOR_HPP
