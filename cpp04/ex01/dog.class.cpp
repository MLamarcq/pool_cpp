/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:01:43 by mael              #+#    #+#             */
/*   Updated: 2023/10/08 12:00:33 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.class.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called\n" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain("Bones, Bones, Bones, Bones...");
	return ;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Type assignement dog constructor called\n" << std::endl;
	if (type.compare("Dog") != 0)
	{
		std::cout << "Hum, don't mess with me. A dog is a DOG, not " << type << "!" << std::endl;
		std::cout << "It's type is Dog. No deal\n" << std::endl;
		this->_type = "Dog";
	}
	else
		this->_type = type;
	this->_brain = new Brain("Bones, Bones, Bones, Bones...");
	return ;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	std::cout << "Copy dog constructor called\n" << std::endl;
	*this = src;
	return ;
}

Dog	&	Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog operator assignement called\n" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		this->_brain = rhs.getBrain();
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "I am a " << this->_type << " ! Listen : whouf whouf\n" << std::endl;
	return ;
}


Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::ChooseIdea(std::string idea, int target, int start, int end)
{
	this->_brain->chooseIdea(idea, target, start, end);
	return ;
}


void	Dog::PrintIdea(bool choice, int idea) const
{
	this->_brain->printIdea(choice, idea);
	return ;
}

void	Dog::ChooseSpecificIdea(void)
{
	this->_brain->chooseSpecificIdea();
	return ;
}