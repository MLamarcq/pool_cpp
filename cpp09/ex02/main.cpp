#include "PmergeMe.hpp"

int parse_input(char **argv)
{
	int i = 1;
	char *ptr;
	while (argv[i])
	{
		int j = 0;
		while (argv[i][j])
		{
			if (isdigit(argv[i][j]) == 0)
			{
				std::cout << "Wrong input : '" << argv[i] << "'. Need numbers or positive numbers only" << std::endl;
				return (0);
			}
			j++;
		}
		if (std::strtol(argv[i], &ptr, 10) > INT_MAX)
		{
			std::cout << argv[i] << " is not a valid number. It can not be negative or higter than max_INT" << std::endl;
			return (0);
		}
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (parse_input(argv) == 0)
		return (0);
	if (argc <= 2)
	{
		std::cout << "Wrong number of arguement. We need minimum 2 numbers to execute the sorting algorithm" << std::endl;
		return (0);
	}
	// std::cout << "SUCCESS !" << std::endl;
	PmergeMe one(argc, argv);
	clock_t v1;
	v1 = clock();
	one.do_vector();
	v1 = clock() - v1;
	std::cout << "The vector used " << std::fixed << std::setprecision(6) << static_cast<float>(v1)/CLOCKS_PER_SEC << " seconds to sort a pool of " << one.getSize_vect() << " numbers" << std::endl;
	return (0);
}