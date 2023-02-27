
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		Bureaucrat *a = new Bureaucrat();
		Intern *z = new Intern();
		Form *b = z->makeForm("SomeRandomForm", "Clown");
		b = z->makeForm("PresidentialPardonForm", "Clown");
		std::cout << a;
		std::cout << b;
		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}
		std::cout << b;
		delete a;
		delete b;
		delete z;
	}
	
	std::cout << "------------------------------------------------------------------------------------------" << std::endl;
	{
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		Intern *z = new Intern();
		Form *b = z->makeForm("RobotomyRequestForm", "Bender");
		Form *c = z->makeForm("ShrubberyCreationForm", "Cristmas");
		std::cout << a;
		std::cout << b;
		std::cout << c;
		b->beSigned(*a);
		a->signForm(*c);
		std::cout << b;
		std::cout << c;
		for (int i= 0; i < 10; i++)
			b->execute(*a);
		a->executeForm(*c);
		delete a;
		delete b;
		delete c;
		delete z;
	}
	return (0);
}
