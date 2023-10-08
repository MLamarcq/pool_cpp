/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:32:12 by mael              #+#    #+#             */
/*   Updated: 2023/10/08 12:05:22 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.class.hpp"
#include "dog.class.hpp"
#include "cat.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"
#include "Brain.class.hpp"

int main()
{
	// Animal* a =  new Animal();
	// Animal* b = new Dog();
	// Animal* c = new Dog("Bernard");
	// Animal *d = new Cat("Manfred");
	// WrongAnimal *e = new WrongAnimal();
	// WrongAnimal *f = new WrongCat();

	// a->makeSound();
	// b->makeSound();
	// c->makeSound();
	// d->makeSound();
	// e->makeSound();
	// f->makeSound();
	
	// delete a;
	// delete b;
	// delete c;
	// delete d;
	// delete e;
	// delete f;

	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	
	// i->makeSound(); //will output the cat sound!
	// j->makeSound();
	// meta->makeSound();

	// delete meta;
	// delete j;
	// delete i;
	
	// Brain brain;

	// brain.fillBrain("Hello");
	// //brain.getIdeas(20);

	// // brain.chooseIdea("hehe", 40, 0, 10);
	// // brain.chooseIdea("salut les amis !", 66, 0, 0);
	// // brain.chooseIdea("Love you", 0, 20, 35);
	// // brain.chooseIdea("Am i right ?", 44, 78, 95);
	
	// brain.chooseSpecificIdea();
	
	// brain.printIdea(true, 33);
	//Brain brain2(brain);
	
	//Animal *a = new Cat;
	// Animal *b = new Cat;
	Cat Tom("Fichtre");
	Dog b;
	
	//Tom.FillBrain("Hello");
	//a.chooseIdea("Hello", 5, 0, 0);
	std::cout << "type = " << Tom.getType()<< std::endl;
	Tom.ChooseIdea("M'enfin !", 98, 30, 50);
	Tom.ChooseSpecificIdea();
	Tom.PrintIdea(true, 0);
	
	b.PrintIdea(true, 0);
	// b = a;
	
	//delete a;
	// delete b;
	
	return (0);
}