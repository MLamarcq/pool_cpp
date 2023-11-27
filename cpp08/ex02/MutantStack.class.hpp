#ifndef MUTANTSTACK_CLASS_HPP
#define MUTANTSTACK_CLASS_HPP

#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template<typename T>

class MutantStack : public std::stack<T>
{
	public :

			MutantStack<T>(void);
			MutantStack<T>(MutantStack<T> const &src);
			~MutantStack<T>(void);

			MutantStack<T> &operator=(MutantStack<T> const &rhs);

			typedef typename std::stack<T>::container_type::iterator it;
			typedef typename std::stack<T>::container_type::const_iterator const_it;
			typedef typename std::stack<T>::container_type::reverse_iterator reverse_it;
			typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_it;

			it						begin(void);
			it						end(void);
			const_it				cbegin(void) const;
			const_it				cend(void) const;
			reverse_it				rbegin(void);
			reverse_it				rend(void);
			const_reverse_iterator	crbegin(void) const;
			const_reverse_iterator	crend(void) const;
};

#include "MutantStack.class.tpp"

#endif