
#include "Form.hpp"

Form::Form(void): m_name("default"), m_is_signed(false), m_sign_grade(150), m_exec_grade(150)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const Form &src): m_name(src.getName() + "_copy"), m_is_signed(false), m_sign_grade(src.getSignGrade()), m_exec_grade(src.getExecGrade())
{
	std::cout << "Form Copy Constructor called to copy " << src.getName() << 	" into " << this->getName() << std::endl;
	*this = src;
}

Form::Form(int sign_grade, int exec_grade): m_name("default"), m_is_signed(false), m_sign_grade(sign_grade), m_exec_grade(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName() << " with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade << std::endl;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(const std::string name): m_name(name), m_is_signed(false), m_sign_grade(150), m_exec_grade(150)
{
	std::cout << "Form Constructor called for " << this->getName() << " with sign-grade of " << this->getSignGrade() <<
	" and execution-grade of " << this->getExecGrade() << std::endl;
}

Form::Form(const std::string name, int sign_grade, int exec_grade): m_name(name), m_is_signed(false), m_sign_grade(sign_grade), m_exec_grade(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade << std::endl;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form::~Form()
{
	std::cout << "Form Deconstructor for " << this->getName() << " called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

void Form::beSigned(Bureaucrat &signer)
{
	if ((int)signer.getGrade() > this->getSignGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == "NO")
	{
		this->m_is_signed = true;
		std::cout << this->getName() << " Form was signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

const std::string	Form::getName(void)const
{
	return (this->m_name);
}

const std::string	Form::getIsSigned(void)const
{
	if (this->m_is_signed)
		return ("YES");
	else
		return ("NO");
}

bool	Form::getIsSignedBool(void)const
{
	return (this->m_is_signed);
}

int	Form::getSignGrade(void)const
{
	return (this->m_sign_grade);
}

int	Form::getExecGrade(void)const
{
	return (this->m_exec_grade);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getSignGrade() <<
	"\n\texec-grade:\t" << a->getExecGrade() <<
	"\n\tis signed:\t" << a->getIsSigned() << std::endl;
	return (o);
}
