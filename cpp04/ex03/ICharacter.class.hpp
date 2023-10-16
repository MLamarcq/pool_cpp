#ifndef ICHARACTER_CLASS_HPP
#define ICHARACTER_CLASS_HPP

#include <string>
#include <iostream>

class ICharacter
{
	public :

			ICharacter(void) = 0;
			ICharacter(std::string name) = 0;
			ICharacter(ICharacter const &src) = 0;
			virtual ~ICharacter(void) = 0;

			ICharacter &operator=(ICharacter const &rhs) = 0;

			virtual std::string const &getName() const = 0;
			// virtual void				equip(AMateria *materia) = 0;
			// virtual void				use(int index, ICharacter &target) = 0;
}

#endif