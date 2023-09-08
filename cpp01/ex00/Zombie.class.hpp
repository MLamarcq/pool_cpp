/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:54:59 by mael              #+#    #+#             */
/*   Updated: 2023/09/08 17:04:35 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

#include <string>
#include <iostream>
#include <stdio.h>

class Zombie
{
	public : 
	
		Zombie();
		~Zombie();
		void	annonce(void) const;
		Zombie	*newZombie(std::string name);
		void	randomChump(std::string name);
		
	private :

			std::string _name;
};