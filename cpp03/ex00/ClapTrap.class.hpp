/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:06:45 by mael              #+#    #+#             */
/*   Updated: 2023/09/25 16:57:38 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	public : 

			//Constructors / Destructor
			ClapTrap();
			ClapTrap(std::string const name);
			ClapTrap(ClapTrap const &src);
			~ClapTrap();

			//Operators
			ClapTrap & operator=(ClapTrap const &rhs);


			//Function member
			void	attack(std::string const &target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amout);


	private :

			std::string				_name;
			unsigned int			_HitPoints;
			unsigned int			_EnergyPoints;
			unsigned int			_AttackDamage;
	
};

int	is_letter(std::string const	&str);




#endif