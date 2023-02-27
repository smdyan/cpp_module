#ifndef BUREAUCRAFT_HPP
# define BUREAUCRAFT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string m_name;
		size_t m_grade;

		void		setGrade(int grade);

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(int grade);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &src);

		void		incrementGrade(void);
		void		decrementGrade(void);
		const std::string getName(void)const;
		size_t		getGrade(void)const;

	//Exceptions
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

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif