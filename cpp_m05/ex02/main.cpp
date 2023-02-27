
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	{
		Bureaucrat *a = new Bureaucrat();
		Form *b = new PresidentialPardonForm("default");
		// Form *c = new RobotomyRequestForm();
		// Form *d = new ShrubberyCreationForm();

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
	}
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
	{
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Form *c = new PresidentialPardonForm("some dude");
		std::cout << a;
		std::cout << b;
		std::cout << c;
		try
		{
			c->execute(*b); // Try to execute before signing
		}
		catch (Form::FormNotSignedException &e)
		{
			std::cerr << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << std::endl;
		}
		try
		{
			c->beSigned(*a); // Assistant signs the Form
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << std::endl;
		}
		std::cout << c;
		try
		{
			c->beSigned(*b); // CEO signs the Form
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << std::endl;
		}
		std::cout << c;
		b->signForm(*c); // try signing the from again
		try
		{
			c->execute(*a); // execute the Form from assistant
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << std::endl;
		}
		try
		{
			c->execute(*b); // execute Form from CEO
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << b->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << std::endl;
		}
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "----------------------------------------------------------------------------------------" << std::endl;
	{
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		PresidentialPardonForm *b = new PresidentialPardonForm("this other dude");
		PresidentialPardonForm *c = new PresidentialPardonForm(*b);
		std::cout << a;
		std::cout << b;
		std::cout << c;
		b->beSigned(*a);
		a->signForm(*c);
		b->execute(*a);
		a->executeForm(*c);
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
	{
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		RobotomyRequestForm *b = new RobotomyRequestForm("Bender");
		ShrubberyCreationForm *c = new ShrubberyCreationForm("christmas");
		std::cout << a;
		std::cout << b;
		std::cout << c;
		b->beSigned(*a);
		a->signForm(*c);
		for (int i= 0; i < 10; i++)
			b->execute(*a);
		c->execute(*a);
		delete a;
		delete b;
		delete c;
	}
	return (0);
}
