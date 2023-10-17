#include "Character.class.hpp"

Character::Character(void)
{
	std::cout << "Character default constructor called" << std::endl;
	if (this->_name.size() < 1)
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
	this->_stock = new AMateria*[6];
	for (int i = 0; i < 6; i++)
		this->_stock[i] = NULL;
	return ;
}

Character::Character(std::string name) : _name(name), _index(0), _stock_index(0)
{
	std::cout << "Character name assignement constructor called" << std::endl;
	this->_item = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->_item[i] = NULL;
	this->_item = NULL;
	this->_stock = new AMateria*[6];
	for (int i = 0; i < 6; i++)
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
		if (this->_stock)
		{
			for (int i = 0; this->_stock[i]; i++)
				delete this->_stock[i];
			delete [] this->_stock;
		}
		this->_name = rhs.getName();
		this->_item = rhs.getItem();
		this->_index = 0;
	}
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (this->_name);
}

AMateria **Character::getItem(void) const
{
	return (this->_item);
}

void	Character::equip(AMateria *materia)
{
	if (this->_index > 3)
	{
		std::cout << this->_name << "'s inventory is full. We can't add a new Materia" << std::endl;
		return ;
	}
	this->_item[this->index] = new AMateria;
	this->_item[this->_index] = materia;
	this->_index++;
	return ;
}

void	Character::use(int indx, ICharacter &target)
{
	this->_item[indx]->use(target);
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
	if (this->_stock_index > 5)
	{
		std::cout << "There is too much item on the floor" << std::endl;
		return ;
	}
	this->_stock[_stock_index] = new AMateria;
	this->_stock_index = this->_item[idx];
	this->_item[idx] = NULL;
	this->_stock_index++;
	return ;
}