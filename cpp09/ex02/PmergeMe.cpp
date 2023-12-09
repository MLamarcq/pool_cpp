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
		this->_vector.push_back(std::atoi(str.c_str()));
		this->_deque.push_back(std::atoi(str.c_str()));
	}
	std::cout << "Before : " ;
	std::vector<int>::iterator itde = this->_vector.end();
	for (std::vector<int>::iterator itd = this->_vector.begin(); itd != itde; itd++)
	{
		std::cout << *itd << " ";
	}
	std::cout << std::endl;
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

void	PmergeMe::avoid_duplicate_vec(void)
{
	std::vector<int>::iterator first = this->_vector.begin();
	std::vector<int>::iterator last = this->_vector.end();
	std::vector<int>::iterator unique_vec = std::unique(first, last);
	if (unique_vec != this->_vector.end())
	{
		this->_vector.erase(unique_vec, this->_vector.end());
		std::cout << "The vector detected duplicate value and erased it" << std::endl;
	}
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

size_t			PmergeMe::getSize_vect(void) const
{
	return (this->_vector.size());
}

size_t			PmergeMe::getSize_deque(void) const
{
	return (this->_deque.size());
}

void	PmergeMe::sorting_algorithm_vector(std::vector<int> &vect, int index1, int index2)
{
	if (index1 < index2)
	{
		int half = (index1 + index2) / 2;
		sorting_algorithm_vector(vect, index1, half);
		sorting_algorithm_vector(vect, half + 1, index2);
		merge(vect, index1, half, index2);
	}
	return ;
}


void	PmergeMe::do_vector(void)
{
	int i = 0 ;
	int j = this->_vector.size() - 1;
	std::cout << "We use in a first time the vector container" << std::endl;
	sorting_algorithm_vector(this->_vector, i, j);
	avoid_duplicate_vec();
	std::vector<int>::iterator arrivee = this->_vector.end();
	std::cout << "After : ";
	for (std::vector<int>::iterator depart = this->_vector.begin(); depart != arrivee; depart++)
	{
		std::cout << *depart << " ";
	}
	std::cout << std::endl;
	return ;
}

void	PmergeMe::merge(std::vector<int> &vect, int index1, int half, int index2)
{
	int i = index1;
	int j = half + 1;
	int k = index1;
	std::vector<int> temp(vect.size());
	while (i <= half && j <= index2)
	{
		if (vect[i] <= vect[j])
		{
			temp[k] = vect[i];
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
	return ;
}