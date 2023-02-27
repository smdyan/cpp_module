#include "Dog.hpp"

Dog::Dog( void )
{
	this->type = "Dog";
	this->m_brain = new Brain();
	std::cout << RED << "Dog was created" << RESET << std::endl;
}

Dog::~Dog( void )
{
	delete this->m_brain;
	std::cout << RED << "Dog was destroied" << RESET << std::endl;
}

Dog::Dog( const Dog &srs)
{
	*this = srs;
	std::cout << RED << "Dog was copied" << RESET << std::endl;
}

Dog	&Dog::operator=( const Dog &rhs)
{
	std::cout << RED << "Dog was assigned" << RESET << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->m_brain = new Brain(*rhs.m_brain);
	}
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << RED << "Someone is barking..." << RESET << std::endl;
}

