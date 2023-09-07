/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:01:45 by mael              #+#    #+#             */
/*   Updated: 2023/09/07 15:38:06 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"
#include <iostream>

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

int	Contact::fill_contact(Contact *Contact)
{
	int i;
	std::string str;

	i = 0;
	while (i < 5)
	{
		str.erase();
		if (i == 0)
		{
			std::cout << "Choose first name for this contact : ";
			while(ft_strlen(str) < 1)
			{
				if (!(std::getline(std::cin, str)))
				{
					std::cout << "std::getline failed" << std::endl;
					return (0);
				}
			}
			while (check_char(str, '2') == 0)
			{
				std::cout << "Only letters are accepted. Try again : ";
				if (!(std::getline(std::cin, str)))
				{
					std::cout << "std::getline failed" << std::endl;
					return (0);
				}
			}
			Contact->_FirstName = str;
		}
		else if (i == 1)
		{
			std::cout << "Choose last name for this contact : ";
			while(ft_strlen(str) < 1)
			{
				if (!(std::getline(std::cin, str)))
				{
					std::cout << "std::getline failed" << std::endl;
					return (0);
				}
			}
			while (check_char(str, '2') == 0)
			{
				std::cout << "Only letters are accepted. Try again : ";
				if (!(std::getline(std::cin, str)))
				{
					std::cout << "std::getline failed" << std::endl;
					return (0);
				}
			}
			Contact->_LastName = str;
		}
		else if (i == 2)
		{
			std::cout << "Choose nick name for this contact : ";
			while(ft_strlen(str) < 1)
			{
				if (!(std::getline(std::cin, str)))
				{
					std::cout << "std::getline failed" << std::endl;
					return (0);
				}
			}
			while (check_char(str, '2') == 0)
			{
				std::cout << "Only letters are accepted. Try again : ";
				if (!(std::getline(std::cin, str)))
				{
					std::cout << "std::getline failed" << std::endl;
					return (0);
				}
			}
			Contact->_NickName = str;
		}
		else if (i == 3)
		{
			std::cout << "Choose phone number for this contact : ";
			while(ft_strlen(str) < 1)
			{
				if (!(std::getline(std::cin, str)))
				{
					std::cout << "std::getline failed" << std::endl;
					return (0);
				}
			}
			while (check_char(str, '1') == 0)
			{
				std::cout << "Only digit are accepted. Try again : ";
				if (!(std::getline(std::cin, str)))
				{
					std::cout << "std::getline failed" << std::endl;
					return (0);
				}
			}
			Contact->_PhoneNumber = str;
		}
		else if (i == 4)
		{
			std::cout << "Choose darkest secret for this contact : ";
			while(ft_strlen(str) < 1)
			{
				if (!(std::getline(std::cin, str)))
				{
					std::cout << "std::getline failed" << std::endl;
					return (0);
				}
			}
			while (check_char(str, '2') == 0)
			{
				std::cout << "Only letters are accepted. Try again : ";
				if (!(std::getline(std::cin, str)))
				{
					std::cout << "std::getline failed" << std::endl;
					return (0);
				}
			}
			Contact->_DarkestSecret = str;
		}
		i++;
	}
	return (1);
}

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