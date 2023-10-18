#include "AMateria.class.hpp"
#include "ICharacter.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"
#include "MateriaSource.class.hpp"
#include "IMateriaSource.class.hpp"
#include "Character.class.hpp"

// int main()
// {
// 	Ice a("Jean-Luc");
// 	Cure b;

// 	std::cout << "type = " << a.getType() << std::endl;
// 	std::cout << "type = " << b.getType() << std::endl;

// 	return (0);
// }

int main()
{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		
		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		
		me->unEquip(1);
		me->unEquip(2);

		//me->on_the_floor();


		delete bob;
		delete me;
		delete src;
		return (0);
}