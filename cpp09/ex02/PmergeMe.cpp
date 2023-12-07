#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(int argc, char**argv)
{
	for(int i = 0; i < argc; i++)
	{
		std::string str(argv[i]);
		this->_vector.push_back(std::atoi(str.c_str()));
		this->_deque.push_back(std::atoi(str.c_str()));
	}
	std::cout << "On print le vecteur !" << std::endl;
	std::vector<int>::iterator ite = this->_vector.end();
	for (std::vector<int>::iterator it = this->_vector.begin(); it != ite; it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "On print la deque !" << std::endl;
	std::deque<int>::iterator itde = this->_deque.end();
	for (std::deque<int>::iterator itd = this->_deque.begin(); itd != itde; itd++)
	{
		std::cout << *itd << std::endl;
	}
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