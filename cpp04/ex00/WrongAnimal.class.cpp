/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:22:22 by mael              #+#    #+#             */
/*   Updated: 2023/10/19 12:02:36 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.class.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal default construtor called\n" << std::endl;
	this->_type = "Wrong Animal";
	return ;
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal type assignement construtcor called" << std::endl;
	if (type.size() < 1)
		this->_type = "Wrong Animal";
	else
		this->_type = type;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
	return ;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "WrongAnimal copy operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "No sound came from " << this->_type << ". It is a wrong animal\n" << std::endl;
	return ;
}