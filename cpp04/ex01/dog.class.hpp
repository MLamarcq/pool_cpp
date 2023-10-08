/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:52:14 by mael              #+#    #+#             */
/*   Updated: 2023/10/08 12:02:15 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
#define DOG_CLASS_HPP

#include "animal.class.hpp"
#include "Brain.class.hpp"

class Dog : public Animal
{
	public :

			Dog(void);
			Dog(std::string name);
			Dog(Dog const &src);
			virtual ~Dog(void);

			Dog &operator=(Dog const &rhs);

			void		makeSound(void) const;
			Brain		*getBrain(void) const;
			std::string	GetIdeas(int idea) const;
			void		ChooseIdea(std::string idea, int target, int start, int end);
			void		ChooseSpecificIdea(void);
			void		PrintIdea(bool choice,int idea) const;

	private :
	
			Brain	*_brain;
};


#endif