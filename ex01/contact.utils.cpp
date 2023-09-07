/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.utils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:10:39 by mael              #+#    #+#             */
/*   Updated: 2023/09/07 16:11:09 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

void	Contact::print_contact(void) const
{
	std::cout << "First_name = " << _FirstName << std::endl;
	std::cout << "Last_name = " << _LastName << std::endl; 
	std::cout << "Nick_name = " << _NickName << std::endl; 
	std::cout << "PhoneNumber = " << _PhoneNumber << std::endl; 
	std::cout << "DarkestSecret = " << _DarkestSecret << std::endl; 
}

void	Contact::print_inside_contact(int i) const
{
	std::cout << std::right << std::setw(10) << (i + 1) << "|";
	if (ft_strlen(_FirstName) > 10)
		std::cout << std::right << std::setw(9) << _FirstName.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << _FirstName << "|";
	if (ft_strlen(_LastName) > 10)
		std::cout << std::right << std::setw(9) << _LastName.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << _LastName << "|";
	if (ft_strlen(_NickName) > 10)
		std::cout << std::right << std::setw(9) << _NickName.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << _NickName << "|";
}