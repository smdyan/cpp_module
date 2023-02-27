#include "Dog.hpp"

Dog::Dog( void )
{
	this->type = "Dog";
	std::cout << RED << "Dog was created" << RESET << std::endl;
}

Dog::~Dog( void )
{
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
		this->type = rhs.type;
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << RED << "Someone is barking..." << RESET << std::endl;
}

