
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): m_name("default"), m_grade(150)
{
	std::cout << "Bureaucrat Default Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): m_name(src.getName() + "_copy")
{
	std::cout << "Bureaucrat Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(int grade): m_name("default")
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << grade << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name): m_name(name), m_grade(150)
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): m_name(name)
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << grade << std::endl;
	this->setGrade(grade);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor for " << this->getName() << " called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->m_grade = src.getGrade();
	return *this;
}

void	Bureaucrat::incrementGrade(void)
{
	std::cout << "Trying to increment grade of " << this->getName() << std::endl;
	this->setGrade(this->m_grade - 1);
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << "Trying to decrement grade of " << this->getName() << std::endl;
	this->setGrade(this->m_grade + 1);
}

const std::string	Bureaucrat::getName(void)const
{
	return (this->m_name);
}
size_t	Bureaucrat::getGrade(void)const
{
	return (this->m_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->m_grade = grade;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\tgrade: " << a->getGrade() << std::endl;
	return (o);
}
