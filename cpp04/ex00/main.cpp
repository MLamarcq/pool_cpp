/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:32:12 by mael              #+#    #+#             */
/*   Updated: 2023/10/05 11:34:49 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.class.hpp"
#include "dog.class.hpp"
#include "cat.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int main()
{
	Animal* a =  new Animal();
	Animal* b = new Dog();
	Animal* c = new Dog("Bernard");
	Animal *d = new Cat("Manfred");
	WrongAnimal *e = new WrongAnimal();
	WrongAnimal *f = new WrongCat();

	a->makeSound();
	b->makeSound();
	c->makeSound();
	d->makeSound();
	e->makeSound();
	f->makeSound();
	
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	
	return (0);
}