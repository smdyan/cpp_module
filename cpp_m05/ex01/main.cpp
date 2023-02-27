
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat *a = new Bureaucrat();
	Form *b = new Form();
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

	std::cout << "-------------------------------------------------------" << std::endl;
	Bureaucrat *a2 = new Bureaucrat("Assistant", 145);
	Bureaucrat *b2 = new Bureaucrat("CEO", 1);
	Form *c2 = new Form("Rent Contract", 140, 100);
	std::cout << a2;
	std::cout << b2;
	std::cout << c2;
	try
	{
		a2->signForm( *c2 );
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << a2->getName() << " was not able to sign the Form " << c2->getName() << ": " << e.what() << std::endl;
	}
	std::cout << c2;
	try
	{
		b2->signForm( *c2 ); //c2 is already signed
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << b2->getName() << " was not able to sign the Form " << c2->getName() << ": " << e.what() << std::endl;
	}
	std::cout << c2;
	b2->signForm(*c2);
	delete a2;
	delete b2;
	delete c2;

	std::cout << "-------------------------------------------------------" << std::endl;
	{
		Form *a = NULL;
		try
		{
			a = new Form(160, 145); //overgrade
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << "Constructing default failed: " << e.what() << std::endl;
		}
		try
		{
			a = new Form(145, 160);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << "Constructing default failed: " << e.what() << std::endl;
		}
		try
		{
			a = new Form(-15, 145);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << "Constructing default failed: " << e.what() << std::endl;
		}
		try
		{
			a = new Form(145, -15);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << "Constructing default failed: " << e.what() << std::endl;
		}
		if (a != NULL)
			delete a;
	}
	return (0);
}
