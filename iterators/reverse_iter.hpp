//
// Created by Waif Jonathon on 7/2/22.
//

#ifndef FT_CONTAINERS_REVERSE_ITER_HPP
#define FT_CONTAINERS_REVERSE_ITER_HPP
#include "iterator_traits.hpp"

namespace ft {
	template<class Iter>
	class reverse_iterator {
	public:
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef 		 Iter											iterator_type;

	protected:
		iterator_type	_base_it;

	public:
		/* * CONSTRUCTORS */
		reverse_iterator() : _base_it() {}
		explicit reverse_iterator(iterator_type it) : _base_it(it) {}

		template<class I>
		reverse_iterator(const reverse_iterator<I>& rev_it) {
			_base_it = rev_it._base_it;
		}

		iterator_type base() const { return reverse_iterator(_base_it); }

		reference operator*() const {
			return --reverse_iterator(_base_it); // ? is it ok `--`
		}

		reverse_iterator operator+ (difference_type n) const {
			return reverse_iterator(_base_it - n);
		}

		reverse_iterator& operator++() {
			--_base_it;
			return *this;
		}
		reverse_iterator  operator++(int) {
			reverse_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		reverse_iterator& operator+= (difference_type n) {
			_base_it -= n; // ? what if bidirectional gets here
			return *this;
		}

		reverse_iterator operator- (difference_type n) const {
			return reverse_iterator(_base_it + n); // ? what if bidirectional gets here
		}

		reverse_iterator& operator--() {
			++_base_it;
			return *this;
		}
		reverse_iterator  operator--(int) {
			reverse_iterator tmp = *this;
			--(*this);
			return tmp
		}

		reverse_iterator& operator-= (difference_type n) {
			_base_it += n; // ? what if bidirectional gets here
			return *this;
		}

		pointer operator->() const {
			return &(operator*());
		}

		reference operator[] (difference_type n) const {
			return base()[-n-1];
		}

	};

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs);
}

#endif //FT_CONTAINERS_REVERSE_ITER_HPP
