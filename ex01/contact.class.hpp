/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:57:21 by mael              #+#    #+#             */
/*   Updated: 2023/09/07 15:18:22 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <string>

class Contact
{
	
	public :
	
		Contact(void);
		~Contact(void);
		// int	change_contact(void);
		// int	print_contact(void);
		int		fill_contact(Contact *Contact);
		void	print_contact(void) const;
		void	print_inside_contact(int i) const ;


	private :
	
		std::string _FirstName;
		std::string _LastName;
		std::string _NickName;
		std::string _PhoneNumber;
		std::string _DarkestSecret;
};

#endif