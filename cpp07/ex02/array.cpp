#include "Array.hpp"

// template<typename T>
// Array<T>::Array(void)
// {
// 	std::cout << "Array default constructor called" << std::endl;
// 	this->_array = NULL;
// 	return ;
// }
// template<typename T>
// Array<T>::Array(T const & type, unsigned int len) : _len(len)
// {
// 	std::cout << "Array type assignement constructor called" << std::endl;
// 	this->_array = new T[this->_len];
// 	for (int i = 0; i < this->_len; i++)
// 	{
// 		this->_array[i] = type;
// 	}
// 	return ;
// }

// template<typename T>
// Array<T>::~Array(void)
// {
// 	std::cout << "Array destructor called" << std::endl;
// 	if (this->_array)
// 		delete [] this->_array;
// 	return ;
// }

// Array.cpp

#include "Array.hpp"

template<typename T>
Array<T>::Array(void) : _array(NULL), _len(0)
{
    std::cout << "Array default constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(T const &type, unsigned int len) : _len(len)
{
    std::cout << "Array type assignment constructor called" << std::endl;
    this->_array = new T[this->_len];
    for (unsigned int i = 0; i < this->_len; ++i)
    {
        this->_array[i] = type;
    }
}

template<typename T>
Array<T>::~Array(void)
{
    std::cout << "Array destructor called" << std::endl;
	if (this->_array)
    	delete[] this->_array;
}
