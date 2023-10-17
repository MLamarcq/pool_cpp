#include "AMateria.class.hpp"
#include "ICharacter.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"


int main()
{
	Ice a("Jean-Luc");
	Cure b;

	std::cout << "type = " << a.getType() << std::endl;
	std::cout << "type = " << b.getType() << std::endl;

	return (0);
}