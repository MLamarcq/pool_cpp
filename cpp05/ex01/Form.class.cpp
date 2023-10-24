#include "Form.class.hpp"

Form::Form(void)
{
	std::cout << "Form default constructor called" << std::endl;
	this->_name = "Boss's form";
	this->_signed = false;
	this->_sign_grade = 1;
	this->_exec_grade = 1;
	return ;
}
Form::Form(std::string name, int grade, int sign_grade, int exec_grade)
{
	std::cout << "Form assignement constructor called" << std::endl;

	while (sign_grade < grade)
	{
		std::string input;
		int check = 0;

		std::cout << "Can not have a sign grade higher than the grade. Please change it :" << std::endl;
		if (!(std::getline(std::cin, input)))
		{
			std::cout << "EOF called. End of program" << std::endl;
			return ;
		}
		if (is_digit(input) == 0)
			input.erase();
		else
		{
			check = std::atoi(input.c_str());
			sign_grade = check;
		}
	}
	this->_sign_grade = checkGrade(sign_grade);
	while (exec_grade < sign_grade)
	{
		
	}
	this->_exec_grade = checkGrade(exec_grade);
	// if (is_letter(name) == 0)
	// {
	// 	bool toggle = false;
	// 	std::string input;
	// 	std::cout << "Form's name is wrong. Please type another one : " << std::endl;
	// 	while (toggle == false)
	// 	{
	// 		if (!(std::getline(std::cin, input)))
	// 		{
	// 			std::cout << "EOF called. End of program" << std::endl;
	// 			return ;
	// 		}
	// 		if (is_letter(input) == 0)
	// 			input.erase();
	// 		else
	// 		{
	// 			this->_name = input;
	// 			toggle = true;
	// 		}
	// 	}
	// }
	// else
	// 	this->_name = name;
	this->_signed = false;
	return ;
}


















int			Form::is_letter(std::string str)
{
	int i = 0;

	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
			i++;
		else
			return (0);
	}
	return (1);
}

int			Bureaucrate::is_digit(std::string str)
{
	int i = 0;

	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}