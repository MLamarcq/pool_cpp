/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:24:53 by mael              #+#    #+#             */
/*   Updated: 2023/10/05 10:16:09 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.class.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor called" << std::endl;
	this->_type = "No type";
	return ;
}
Animal::Animal(std::string type)
{
	std::cout << "Type assignement animal constructor called" << std::endl;
	if (type.size() < 1)
		this->_type = "No type";
	else
		this->_type = type;
	return ;
}

Animal::Animal(Animal const &src)
{
	*this = src;
	return ;
}
Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

Animal & Animal::operator=(Animal const &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "This is animal sound. Nothing special\n" << std::endl;
	return ;
}