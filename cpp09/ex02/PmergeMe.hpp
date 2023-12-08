#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <deque>
#include <climits>
// #define INT_MAX 2147483648

class PmergeMe
{
	public :

			PmergeMe(int argc, char **argv);
			PmergeMe(PmergeMe const & src);
			~PmergeMe(void);

			PmergeMe & operator=(PmergeMe const &rhs);

			std::vector<int>	getVector(void) const;
			std::deque<int>		getDeque(void) const;

			void	sorting_algorithm_vector(std::vector<int> &vect, int index1, int index2);
			void	do_vector(void);
			void	merge(std::vector<int> &vect, int index1, int half, int index2);

	private :

			PmergeMe(void);
			std::vector<int>	_vector;
			std::deque<int>		_deque;
};






















#endif