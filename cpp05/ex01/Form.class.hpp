#ifndef FORM_CLASS_HPP
#define FORM_CLASS_HPP


#include <string>
#include <iostream>

class Form
{
		public :

				Form(std::string name, int grade, int sign_grade, int exec_grade);
				Form(Form const &src);
				~Form(void);

				Form &operator=(Form const &rhs);

				std::string getName(void) const;
				bool		getSigned(void) const;
				int			getSignGrade(void) const;
				int			getExecGrade(void) const;

				bool		beSigned(Form const &rhs) const;
				void		signForm(void) const;

				int			checkGrade(int grade) const;

				int			is_letter(std::string str);
				int			is_digit(int grade);

				class GradeTooLowExecption : public std::exception
				{
					public :
							const char *what() const throw();
				};

				class GradeTooHighExecption : public std::exception
				{
					public :
							const char *what() const throw();
				};


		private :

				Form(void);
				std::string _name;
				bool		_signed;
				int			_sign_grade;
				int			_exec_grade;



};

std::ostream &operator<<(std::ostream &ost, Form const &rhs);

#endif