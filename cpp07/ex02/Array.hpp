#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <typeinfo>

template <typename T>

class Array
{
	public :

			Array<T>(void);
			Array<T>(T const &type, unsigned int len);
			//Array(Array const &src);
			~Array<T>(void);

			//Array &operator=(Array const & rhs);

			//T getType(void) const;

	private :

			T *_array;
			unsigned int _len;
};

//#include "Array.tpp"

#endif