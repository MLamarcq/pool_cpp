#include "AMateria.class.hpp"


int main()
{
	AMateria a("Jean-Luc");
	AMateria b(a);

	std::cout << "type = " << a.getType() << std::endl;
	std::cout << "type = " << b.getType() << std::endl;

	return (0);
}