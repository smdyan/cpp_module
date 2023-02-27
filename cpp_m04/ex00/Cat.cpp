#include "Cat.hpp"

Cat::Cat( void )
{
	this->type = "Cat";
	std::cout << GREEN << "Cat was created" << RESET << std::endl;
}

Cat::~Cat( void )
{
	std::cout << GREEN << "Cat was destroied" << RESET << std::endl;
}

Cat::Cat( const Cat &srs)
{
	*this = srs;
	std::cout << GREEN << "Cat was copied" << RESET << std::endl;
}

Cat	&Cat::operator=( const Cat &rhs)
{
	std::cout << GREEN << "Cat was assigned" << RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout  << GREEN << "Someone is saying meow..." << RESET << std::endl;
}
