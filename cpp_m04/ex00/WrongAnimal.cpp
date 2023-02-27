#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	this->type = "none";
	std::cout << "WrongAnimal was created" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal was destroy" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &srs)
{
	*this = srs;
	std::cout << "WrongAnimal was copy" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=( const WrongAnimal &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "The object has no type therefore no sound" << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}
