#include "Array.class.hpp"

int main()
{
	Array<int> array(3);
	Array<int> array2(1);
	Array<char> array3(15);
	

	std::cout << array.size() << std::endl;
	std::cout << array2.size() << std::endl;
	std::cout << array3.size() << std::endl;

	return (0);
}