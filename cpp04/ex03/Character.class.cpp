#include "Character.class.hpp"

Character::Character(void)
{
	std::cout << "Character default constructor called" << std::endl;
	if (this->_name.empty() == 1)
	{
		std::string input;
		bool		toggle = false;
		std::cout << "You have to give a name to your character !" << std::endl;
		while (toggle == false)
		{
			std::cout << "Enter the name : ";
			if (!(std::getline(std::cin, input)))
			{
				std::cout << "Use of End of File. Exit." << std::endl;
				return ;
			}
			this->_name = input;
			if (is_letter(this->_name) == 0)
			{
				this->_name.erase();
				std::cout << "Wrong name format" << std::endl;
			}
			else
				toggle = true;
		}
	}
	this->_index = 0;
	this->_stock_index = 0;
	this->_item = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->_item[i] = NULL;
	this->_stock = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->_stock[i] = NULL;
	return ;
}

Character::Character(std::string name) : _name(name), _index(0), _stock_index(0)
{
	std::cout << "Character name assignement constructor called" << std::endl;
	this->_item = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->_item[i] = NULL;
	this->_stock = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->_stock[i] = NULL;
	return ;
}

Character::Character(Character const &src)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
	return ;
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	if (this->_item)
	{
		for (int i = 0; this->_item[i]; i++)
			delete this->_item[i];
		delete [] this->_item;
	}
	if (this->_stock)
	{
		for (int i = 0; this->_stock[i]; i++)
			delete this->_stock[i];
		delete [] this->_stock;
	}
	return ;
}

Character &Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		if (this->_item)
		{
			for (int i = 0; this->_item[i]; i++)
				delete this->_item[i];
			delete [] this->_item;
		}
		this->_item = new AMateria*[4];
		for (int i = 0; i < 4; i++)
			this->_item[i] = rhs.getItem(i);
		this->_name = rhs.getName();
		this->_index = rhs.getIndex();
	}
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (this->_name);
}

AMateria *Character::getItem(int index) const
{
	return (this->_item[index]);
}

int	Character::getIndex(void) const
{
	return (this->_index);
}

void	Character::equip(AMateria *materia)
{
	if (this->_index > 3)
	{
		std::cout << this->_name << "'s inventory is full. We can't add a new Materia" << std::endl;
		return ;
	}
	this->_item[this->_index] = materia;
	this->_index++;
	return ;
}

void	Character::use(int indx, ICharacter &target)
{
	if (this->_item[indx])
		this->_item[indx]->use(target);
	else
		std::cout << "Item not set yet" << std::endl;
	return ;
}

void	Character::unEquip(int index)
{
	int idx = index - 1;
	if (idx > 3)
	{
		std::cout << "You are trying to unequip an item that does not exist" << std::endl;
		return ;
	}
	if (this->_stock_index > 3)
	{
		std::cout << "There is too much item on the floor" << std::endl;
		return ;
	}
	this->_stock[_stock_index] = this->_item[idx];
	if (idx == 0)
	{
		this->_item[idx] = this->_item[idx + 1];
		this->_item[idx + 1] = this->_item[idx + 2];
		this->_item[idx + 2] = this->_item[idx + 3];
		this->_item[idx + 3] = NULL;
	}
	else if (idx == 1)
	{
		this->_item[idx] = this->_item[idx + 1];
		this->_item[idx + 1] = this->_item[idx + 2];
		this->_item[idx + 2] = NULL;
	}
	else if (idx == 2)
	{
		this->_item[idx] = this->_item[idx + 1];
		this->_item[idx + 1] = NULL;
	}
	else
		this->_item[idx] = NULL;
	this->_stock_index++;
	return ;
}

// void	Character::on_the_floor(void) const
// {
// 	if (this->_stock)
// 	{
// 		for (int i = 0; this->_stock[i]; i++)
// 			std::cout << this->_stock[i]->getType() << "is on the floor" << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << "You have to unEquip item from the character to check the floor" << std::endl;
// 	}
// 	return ;
// }