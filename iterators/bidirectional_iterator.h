//
// Created by Waif Jonathon on 6/23/22.
//

#ifndef FT_CONTAINERS_BIDIRECTIONAL_ITERATOR_H
#define FT_CONTAINERS_BIDIRECTIONAL_ITERATOR_H

#include "iterator_traits.hpp"

template<class T>
class BidirectIter {
public:
	typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
	typedef typename ft::iterator_traits<T*>::value_type		value_type;
	typedef typename ft::iterator_traits<T*>::pointer			pointer;
	typedef typename ft::iterator_traits<T*>::reference			reference;
	typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;

	BidirectIter(pointer ptr) { };
};

#endif //FT_CONTAINERS_BIDIRECTIONAL_ITERATOR_H
