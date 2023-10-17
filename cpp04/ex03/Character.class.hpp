#ifndef CHARACTER_CLASS_HPP
#define CHARACTER_CLASS_HPP

#include "AMateria.class.hpp"
#include "ICharacter.class.hpp"

class Character : public ICharacter
{
	public :
		Character(void);
		Character(std::string name);
		Character(Character const &src);
		~Character(void);

		Character &operator=(Character const &rhs);

	private :
		std::string	_name;
		int		_index;
		int		_stock_index;
		AMateria	**_item;
		AMateria	**_stock;
}


#endif