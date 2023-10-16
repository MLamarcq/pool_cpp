#include "Character.class.hpp"

Character::Character(void)
{
    std::cout << "Character default constructor called" << std::endl;
    return ;
}

Character::Character(std::string name) : _name(name);
{
    std::cout << "Character name assignement constructor called" << std::endl;
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
    return ;
}

std::string const Character::getName(void) const
{
    return (this->_name);
}