
#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string m_name;
		bool			m_is_signed;
		const int		m_sign_grade;
		const int		m_exec_grade;

	public:
		Form(void);
		Form(const Form &src);
		Form(int sign_grade, int exec_grade);
		Form(const std::string name);
		Form(const std::string name, int sign_grade, int exec_grade);
		~Form();
		Form &operator=(const Form &src);

		void			beSigned(Bureaucrat &signer);
		const std::string getName(void)const;
		const std::string getIsSigned(void)const;
		bool			getIsSignedBool(void)const;
		int				getSignGrade(void)const;
		int				getExecGrade(void)const;

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Form *a);

# endif