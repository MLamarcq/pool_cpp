/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:12:04 by mael              #+#    #+#             */
/*   Updated: 2023/09/13 19:37:36 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CLASS_HPP
# define HARL_CLASS_HPP

#include <string>
#include <iostream>
#include <stdio.h>

class Harl
{

	public :
			Harl();
			~Harl();
			void	complain(std::string level);

	private : 
			void	_debug(void) const;
			void	_info(void) const;
			void	_warning(void) const;
			void	_error(void) const ;
};

int main(int argc, char **argv);

#endif