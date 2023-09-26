/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:29:12 by mael              #+#    #+#             */
/*   Updated: 2023/09/26 14:44:53 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

int main()
{
	ClapTrap human1("Julien");
	ClapTrap human2("Thierry");
	ClapTrap human3("Bernard");

	std::cout << "\n";
	human1.attack("Thierry");
	std::cout << "\n";
	human2.takeDamage(5);
	std::cout << "\n";
	human2.attack("Julien");
	std::cout << "\n";
	human1.takeDamage(5);
	std::cout << "\n";
	human3.attack("Julien");
	//human3.attack("Thierry");
	
	//human2.takeDamage(5);
	human1.takeDamage(5);
	std::cout << "\n";
	human2.beRepaired(2);
	std::cout << "\n";
	human2.attack("Bernard");
	std::cout << "\n";
	human3.takeDamage(5);

	std::cout << "\n";
	ClapTrap human4(human2);
	std::cout << "\n";
	human4.attack("Julien");
	
	return (0);
}