/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:41:55 by mael              #+#    #+#             */
/*   Updated: 2023/09/11 10:53:29 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string	&stringREF = str;
	
	
	std::cout << "L'adresse de str est = " << &str << std::endl;
	std::cout << "L'afresse pointee par stringPTR est = " << stringPTR << std::endl;
	std::cout << "L'adresse de la reference stringREF est = " << &stringREF << std::endl;
	
	std::cout << "\n";
	std::cout << "La valeur de str est = " << str << std::endl;
	std::cout << "La valeur pointee par stringPTR est = " << *stringPTR << std::endl;
	std::cout << "La valeur de la reference stringREF est = " << stringREF << std::endl;

	// std::cout << "\n";
	// *stringPTR = "J'aime la vie";
	// std::cout << "La valeur de str est = " << str << std::endl;
	// std::cout << "La valeur de la reference stringREF est = " << stringREF << std::endl;
	
	// std::cout << "\n";
	// stringREF = "J'aime la vie";
	// std::cout << "La valeur de str est = " << str << std::endl;
	// std::cout << "La valeur du pointeur stringPTR est = " << *stringPTR << std::endl;

	return (0);
}