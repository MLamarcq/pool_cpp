#include "easyfind.class.hpp"

int main()
{
	std::list<int> lst;

	try
	{
		easyfind(lst, 4);
	}
	catch (NotFindException &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	fillContainer(lst, 10);
	
	try
	{
		easyfind(lst, 4);
	}
	catch (NotFindException &e)
	{
		std::cout << e.what() << std::endl;
	}	
	
	fillContainer(lst, 10);

	try
	{
		easyfind(lst, 25);
	}
	catch (NotFindException &e)
	{
		std::cout << e.what() << std::endl;
	}	

	fillContainer(lst, 10);

	try
	{
		easyfind(lst, 25);
	}
	catch (NotFindException &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);

}

