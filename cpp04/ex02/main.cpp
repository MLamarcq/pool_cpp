/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:32:12 by mael              #+#    #+#             */
/*   Updated: 2023/10/14 12:17:22 by mael             ###   ########.fr       */
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
	// Aanimal* a =  new Aanimal();
	// Aanimal* b = new Dog();
	// Aanimal* c = new Dog("Bernard");
	// Aanimal *d = new Cat("Manfred");
	// WrongAanimal *e = new WrongAanimal();
	// WrongAanimal *f = new WrongCat();

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

	// const Aanimal* meta = new Aanimal();
	// const Aanimal* j = new Dog();
	// const Aanimal* i = new Cat();
	
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
	
	//Aanimal *a = new Cat;
	// Aanimal *b = new Cat;
	Aanimal *Sylvain = new Cat("Gerard");
	Cat Tom("Fichtre");
	Dog Medor;
	
	//Tom.FillBrain("Hello");
	//a.chooseIdea("Hello", 5, 0, 0);
	std::cout << "Tom's type = " << Tom.getType()<< std::endl << std::endl;
	Tom.ChooseIdea("MORE MOUSE", 98, 30, 50);
	Tom.ChooseSpecificIdea();
	Tom.PrintIdea(true, 0);
	Sylvain->makeSound();
	
	// Medor.PrintIdea(true, 0);
	// Medor = a;
	
	//delete a;
	// delete Medor;
	delete Sylvain;
	
	return (0);
}