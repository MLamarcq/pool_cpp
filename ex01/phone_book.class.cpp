/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:32:58 by mael              #+#    #+#             */
/*   Updated: 2023/09/07 15:31:28 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

PhoneBook::PhoneBook(void) : _index(0) , _nbr_contact(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

int	PhoneBook::start_phone_book(Contact Contact, PhoneBook PhoneBook)
{
	std::string input;
	
	std::cout << "Welcome to your new phonebook !" << std::endl;
	std::cout << "Type 'Yes' to start or 'Exit' to quit : ";
	if (!(std::getline(std::cin, input)))
			return (0);
	if (ft_strncmp(input, "Exit", ft_strlen(input)) == 0)
		return (0);
	while (ft_strncmp(input, "Yes", ft_strlen(input)) != 0 && \
		ft_strncmp(input, "Exit", ft_strlen(input)) != 0)
	{
		std::cout << "Wrong input. Please try again : ";
		std::getline(std::cin, input);
	}
	if (ft_strncmp(input, "Exit", ft_strlen(input)) == 0)
		return (0);
	std::cout << "\n\n";
	std::cout << "Only 3 action allowed : ADD, SEARCH and EXIT" << std::endl;
	std::cout << "Chosse ADD to create a new contact, ";
	std::cout << "Search to see all your contact, ";
	std::cout << "and EXIT to quit your phonebook !" << std::endl;
	while (1)
	{
		input.erase();
		std::cout << "\n";
		std::cout << "Please, enter your action : ";
		if (!(std::getline(std::cin, input)))
			return (0);
		if (ft_strncmp(input, "ADD", ft_strlen(input)) == 0)
		{
			if (PhoneBook.add_contact(Contact) == 0)
				return (0);
		}
		else if (ft_strncmp(input, "SEARCH", ft_strlen(input)) == 0)
		{
			if (PhoneBook.nb_contact() == 0)
			{
				std::cout << "No contact set yet. Please type 'ADD' to start your phonebook" << std::endl;
			}
			else
			{
				PhoneBook.display_all(Contact);
				std::cout << "\n";
				std::cout << "You will be able to see all ";
				std::cout << "about the contact you choose" << std::endl;
				std::cout << "Please enter an index between 1 and 8 : ";
				if (!(std::getline(std::cin, input)))
					return (0);
				while (is_digit(input) == 0 || ft_strlen(input) != 1)
				{
					std::cout << "Please enter a number between 1 and 8 : ";
					if (!(std::getline(std::cin, input)))
						return (0);
				}
				while (std::atoi(input.c_str()) == 0 || std::atoi(input.c_str()) == 9)
				{
					std::cout << "Please enter a number between 1 and 8 : ";
					if (!(std::getline(std::cin, input)))
						return (0);
				}
				PhoneBook.display_contact(std::atoi(input.c_str()));
			}

		}
		else if (ft_strncmp(input, "EXIT", ft_strlen(input)) == 0)
			break ;
		else
			std::cout << "Wrong input, please try again" << std::endl;
	}
	return (1);
}

int	PhoneBook::add_contact(Contact Contact)
{
	if (_index + 1 > 8)
		_index = 0;
	if (Contact.fill_contact(&_contact[_index]) == 0)
		return (0);
	_index++;
	if (_nbr_contact < 8)
		_nbr_contact++;
	return (1);
}

// void	PhoneBook::essai(Contact Contact)
// {
// 	if (_index == 3)
// 	{
// 		int i= 0;
// 		while (i < _index)
// 		{
// 			Contact.print_contact(&_contact[i]);
// 			i++;
// 		}
// 	}
//}

int	PhoneBook::nb_contact() const
{
	return (_nbr_contact);
}

void	PhoneBook::display_all(Contact Contact) const
{
	int i;
	
	i = 0;
	std::cout << std::internal << std::setw(11) << "Index |" ;
	std::cout << std::internal << std::setw(11) << "FirstName |" ;
	std::cout << std::internal << std::setw(11) << "LastName |" ;
	std::cout << std::internal << std::setw(11) << "NickName |" << std::endl;
	while (i < _index)
	{
		_contact[i].print_inside_contact(i);
		std::cout << "\n";
		i++;
	}
	(void)Contact;
}
void	PhoneBook::display_contact(int index) const
{
	_contact[index - 1].print_contact();
}