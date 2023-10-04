/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:29:12 by mael              #+#    #+#             */
/*   Updated: 2023/10/03 15:04:28 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"


int main()
{
	std::srand(std::time(0));
	
	DiamondTrap robot1("Didier");
	FragTrap	robot2("Julien");
	
	
	robot1.whoAmI();
	robot1.attack("Julien");
	robot2.takeDamage(robot1.getAttackDamage());
	robot1.higtFiveGuys(robot2);
	
	return (0);
}