#include "Animal.hpp"

Animal::Animal( void )
{
	this->type = "none";
	std::cout << "Animal was created" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal was destroied" << std::endl;
}

Animal::Animal( const Animal &srs)
{
	*this = srs;
	std::cout << "Animal was copied" << std::endl;
}

Animal	&Animal::operator=( const Animal &rhs)
{
	std::cout << "Animal was assigned" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void	Animal::makeSound( void ) const
{
	std::cout << "The object has no type therefore no sound" << std::endl;
}

std::string	Animal::getType( void ) const
{
	return (this->type);
}
