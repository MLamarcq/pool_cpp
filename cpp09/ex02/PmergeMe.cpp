#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(int argc, char**argv)
{
	for(int i = 1; i < argc; i++)
	{
		std::string str(argv[i]);
		// std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
		this->_vector.push_back(std::atoi(str.c_str()));
		this->_deque.push_back(std::atoi(str.c_str()));
	}
	// std::cout << "On print le vecteur !" << std::endl;
	// std::vector<int>::iterator ite = this->_vector.end();
	// for (std::vector<int>::iterator it = this->_vector.begin(); it != ite; it++)
	// {
	// 	std::cout << *it << std::endl;
	// }
	// std::cout << "On print la deque !" << std::endl;
	// std::deque<int>::iterator itde = this->_deque.end();
	// for (std::deque<int>::iterator itd = this->_deque.begin(); itd != itde; itd++)
	// {
	// 	std::cout << *itd << std::endl;
	// }
	return ;
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	*this = src;
	return ;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
	if (this != &rhs)
	{
		this->_vector = rhs.getVector();
		this->_deque = rhs.getDeque();
	}
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	return ;
}


std::vector<int>	PmergeMe::getVector(void) const
{
	return (this->_vector);
}
			
std::deque<int>	PmergeMe::getDeque(void) const
{
	return (this->_deque);
}

// void	PmergeMe::sorting_algorithm_vector(std::vector<int> &vect)
// {

// 	if (vect.size() <= 1)
// 		return ;
// 	int half = vect.size() / 2;
// 	std::vector<int>::iterator it = vect.begin();
// 	std::vector<int> one;
// 	std::vector<int> two;
// 	std::copy(it, it + (half + 1), std::back_inserter(one));
// 	std::advance(it, half + 1);
// 	std::copy(it, vect.end(), std::back_inserter(two));

// 	// for(std::vector<int>::iterator pl = one.begin(); pl != one.end(); pl++)
// 	// 	std::cout << "one = " << *pl << std::endl;
// 	// for(std::vector<int>::iterator pla = two.begin(); pla != two.end(); pla++)
// 	// 	std::cout << "two = " << *pla << std::endl;
// 	sorting_algorithm_vector(one);
// 	sorting_algorithm_vector(two);
// 	merge
// 	return ;
// }

void	PmergeMe::sorting_algorithm_vector(std::vector<int> &vect, int index1, int index2)
{
	if (index1 < index2)
	{
		int half = (index1 + index2) / 2;
		sorting_algorithm_vector(vect, index1, half);
		sorting_algorithm_vector(vect, half + 1, index2);
		merge(vect, index1, half, index2);
	}
	// std::vector<int>::iterator ite = vect.end();
	// for (std::vector<int>::iterator it = vect.begin(); it != ite; it++)
	// 	std::cout << *it << std::endl;
	return ;
}


void	PmergeMe::do_vector(void)
{
	int i = 0 ;
	int j = this->_vector.size() - 1;
	sorting_algorithm_vector(this->_vector, i, j);
	std::vector<int>::iterator ite = this->_vector.end();
	for (std::vector<int>::iterator it = this->_vector.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return ;
}

void	PmergeMe::merge(std::vector<int> &vect, int index1, int half, int index2)
{
	int i = index1;
	int j = half + 1;
	int k = index1;
	std::vector<int> temp(vect.size());
	// std::cout << "i = " << i << ", j = " << j << ", half = " << half << ", index2 = " << index2 << std::endl;
	while (i <= half && j <= index2)
	{
		if (vect[i] <= vect[j])
		{
			temp[k] = vect[i];
			// std::cout << "at first loop in merge we have : ";
			// std::cout << "vect[" << i << "] = " << vect[i] << std::endl;
			i++;
		}
		else
		{
			temp[k] = vect[j];
			j++;
		}
		k++;
	}
	while (i <= half)
	{
		temp[k] = vect[i];
		i++;
		k++;
	}
	while (j <= index2)
	{
		temp[k] = vect[j];
		j++;
		k++;
	}
	for (int index = index1; index <= index2; index++)
	{
		vect[index] = temp[index];
	}
	// int p = 0;
	// while (vect[p])
	// {
	// 	std::cout << "vect [" << p << "] = " << vect[p] << std::endl;
	// 	p++;
	// }
	// for (size_t p = 0; p < vect.size(); ++p) {
	// 	std::cout << "vect[" << p << "] = " << vect[p] << std::endl;
	return ;
}