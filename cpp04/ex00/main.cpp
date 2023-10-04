/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:32:12 by mael              #+#    #+#             */
/*   Updated: 2023/10/04 16:07:09 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.class.hpp"
#include "dog.class.hpp"
#include "cat.class.hpp"

int main()
{
	Animal* a =  new Animal();
	Animal* b = new Dog();
	Animal* c = new Dog("Bernard");
	Animal *d = new Cat("Manfred");
	
	a->makeSound();
	b->makeSound();
	c->makeSound();
	d->makeSound();
	
	delete a;
	delete b;
	delete c;
	delete d;
	
	return (0);
}