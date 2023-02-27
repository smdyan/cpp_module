
#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "-------------------------------------------------------" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		std::cout << a;

		try
		{
			a->incrementGrade();
		}
			catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Incrementing grade of " << a->getName() <<
			" failed: " << e.what() << std::endl;
		}
		std::cout << a;

		try
		{
		a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Decrementing grade of " << a->getName() <<
			" failed: " << e.what() << std::endl;
		}
		std::cout << a;

		try
		{
			a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Decrementing grade of " << a->getName() <<
			" failed: " << e.what() << std::endl;
		}
		std::cout << a;
		delete a;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		Bureaucrat *a = new Bureaucrat(1);
		std::cout << a;

		try
		{
		a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Decrementing grade of " << a->getName() <<
			" failed: " << e.what() << std::endl;
		}
		std::cout << a;

		try
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Incrementing grade of " << a->getName() <<
			" failed: " << e.what() << std::endl;
		}
		std::cout << a;

		try
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Incrementing grade of " << a->getName() <<
			" failed: " << e.what() << std::endl;
		}
		std::cout << a;
		delete a;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(0);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "Constructing default failed: " <<
			e.what() << std::endl;
		}

		if (a != NULL)
			delete a;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(160);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Constructing default failed: " <<
			e.what() << std::endl;
		}

		if (a != NULL)
			delete a;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		Bureaucrat *a = new Bureaucrat("Peter", 120);
		std::cout << a;
		a->decrementGrade();
		std::cout << a;
		Bureaucrat *b = new Bureaucrat(*a);
		delete a;
		std::cout << b;
		b->decrementGrade();
		std::cout << b;
		delete b;
	}
}