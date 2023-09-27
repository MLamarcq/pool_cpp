/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:29:12 by mael              #+#    #+#             */
/*   Updated: 2023/09/27 15:12:02 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"


int main()
{
	std::srand(std::time(0));
	ScavTrap robot1("Francis");
	ScavTrap robot2(robot1);
	ScavTrap robot3(robot1);
	//ClapTrap robot4;
	std::cout << "\n";

	
	// std::cout << "Here are our Gate Keepers !" << std::endl;
	// robot1.guardGate();
	// robot2.guardGate();
	// robot3.guardGate();

	// std::cout << "Let's do some domages !" << std::endl;
	// robot1.attack(robot2.getName());
	// robot2.takeDamage(robot1.getAttackDamage());
	// robot2.attack(robot1.getName());
	// robot1.takeDamage(robot2.getAttackDamage());
	// robot3.attack(robot2.getName());
	// robot2.takeDamage(robot3.getAttackDamage());
	// std::cout << "\n";
	
	// std::cout << "We need some repair after huge fight !" << std::endl;
	// robot1.beRepaired(52);
	// robot2.beRepaired(3);

	// std::cout << "Let's have more blood (euh, oil in fact)" << std::endl;
	// while (robot2.getEnergyPoints() > 0 && robot1.getDeath() == false)
	// {
	// 	robot2.attack(robot1.getName());
	// 	robot1.takeDamage(robot2.getAttackDamage());
	// }
	// std::cout << "Can " << robot2.getName() << " attack once more?" << std::endl;
	
	std::cout << "\nNow to the death !" << std::endl;
	while (robot3.getHitpoints() > 0 && robot3.getDeath() == false)
	{
		robot1.attack(robot3.getName());
		robot3.takeDamage(robot1.getAttackDamage());
	}
	std::cout << "\nOh no, he is dead ! Let's repair him !" << std::endl;
	robot3.beRepaired(60);
	std::cout << robot3.getName() << " feels better !\n" << std::endl;
	
	return (0);
}