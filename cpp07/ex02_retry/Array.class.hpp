#ifndef ARRAY_CLASS_HPP
#define ARRAY_CLASS_HPP

#include <string>
#include <iostream>
#include <sstream>

template <typename T>

class Array
{
		public :

				Array<T>(void);
				Array<T>(unsigned int len);
				Array<T>(Array<T> const &src);
				~Array<T>(void);

				Array<T> &operator=(Array<T> const &rhs);
				T operator[](unsigned int index);

				T* getArray(void) const;
				//unsigned int getLen(void) const;
				unsigned int size(void) const;



				class OutOfRangeException : public std::exception
				{
					public :
							const char *what() const throw();
				};

		private :

				T*			_array;
				unsigned int _len;

};

#include "Array.tpp"

#endif