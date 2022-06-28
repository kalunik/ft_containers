//
// Created by Waif Jonathon on 6/24/22.
//

#ifndef FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
#define FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

template<typename T>
class RandomIter {
public:
	typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
	typedef typename ft::iterator_traits<T*>::value_type		value_type;
	typedef typename ft::iterator_traits<T*>::pointer			pointer;
	typedef typename ft::iterator_traits<T*>::reference			reference;
	typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;

protected:
	pointer _ptr;

public:
	RandomIter() : _ptr(NULL) {}
	RandomIter(pointer obj) : _ptr(obj) {}
	virtual ~RandomIter() {}

	RandomIter(const RandomIter<T> &obj) {
		_ptr = obj;
	}

	RandomIter<value_type>& operator=(const RandomIter<value_type> &obj) {
		_ptr = obj;
		return *this;
	}

	bool operator==(const RandomIter<value_type> &rhs) const {
		return (_ptr ==	rhs._ptr); }
	bool operator!=(const RandomIter<value_type> &rhs) const {
		return (_ptr !=	rhs._ptr); }

	reference operator*() const {
		return *_ptr;
	}
	reference operator->() const {
		return _ptr;
	}

	RandomIter& operator++() {
		++_ptr;
		return *this;
	}
	RandomIter operator++(int) {
		RandomIter tmp(*this);
		++_ptr; //difference w/h ++(*ptr);
		return tmp;
	}

	RandomIter& operator--() {
		--_ptr;
		return *this;
	}
	RandomIter operator--(int) {
		RandomIter tmp(*this);
		--_ptr; //difference w/h ++(*ptr);
		return tmp;
	}

	RandomIter operator+(difference_type n) const {
		RandomIter tmp = *this;
		return tmp + n;
	}
	RandomIter operator-(difference_type n) {
		RandomIter tmp = *this;
		return tmp - n;
	}
	difference_type operator-(const RandomIter &rhs) const {
		return _ptr - rhs._ptr;
	}




//	RandomIter<T>& operator

/*
operator                                    bool()const
    {
        if(m_ptr)
            return true;
        else
            return false;
    }

    bool                                        operator==(const blRawIterator<blDataType>& rawIterator)const{return (m_ptr == rawIterator.getConstPtr());}
    bool                                        operator!=(const blRawIterator<blDataType>& rawIterator)const{return (m_ptr != rawIterator.getConstPtr());}

    blRawIterator<blDataType>&                  operator+=(const difference_type& movement){m_ptr += movement;return (*this);}
    blRawIterator<blDataType>&                  operator-=(const difference_type& movement){m_ptr -= movement;return (*this);}
    blRawIterator<blDataType>&                  operator++(){++m_ptr;return (*this);}
    blRawIterator<blDataType>&                  operator--(){--m_ptr;return (*this);}
    blRawIterator<blDataType>                   operator++(int){auto temp(*this);++m_ptr;return temp;}
    blRawIterator<blDataType>                   operator--(int){auto temp(*this);--m_ptr;return temp;}
    blRawIterator<blDataType>                   operator+(const difference_type& movement){auto oldPtr = m_ptr;m_ptr+=movement;auto temp(*this);m_ptr = oldPtr;return temp;}
    blRawIterator<blDataType>                   operator-(const difference_type& movement){auto oldPtr = m_ptr;m_ptr-=movement;auto temp(*this);m_ptr = oldPtr;return temp;}

    difference_type                             operator-(const blRawIterator<blDataType>& rawIterator){return std::distance(rawIterator.getPtr(),this->getPtr());}

    blDataType&                                 operator*(){return *m_ptr;}
    const blDataType&                           operator*()const{return *m_ptr;}
    blDataType*                                 operator->(){return m_ptr;}

    blDataType*                                 getPtr()const{return m_ptr;}
    const blDataType*                           getConstPtr()const{return m_ptr;}

*/

};

#endif //FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP
