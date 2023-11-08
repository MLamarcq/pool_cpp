#include "Iter.hpp"

int main ()
{
	int tab[] = {3, 4, 5, 6};
	::Iter(tab, 4, ::print_tab<int>);
	std::cout << std::endl;
	::Iter(tab, 4, ::increase<int>);
	::Iter(tab, 4, ::print_tab<int>);
	std::cout << std::endl;


	char str[] = "Salut les gars";
	::Iter(str, 14, ::print_tab<char>);
	std::cout << std::endl;

	const char *str1;
	str1 = "Salut";
	::Iter(str1, 5, ::print_tab<const char>);
	std::cout << std::endl;

	return (0);
}