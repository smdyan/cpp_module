#include "AAnimal.hpp"

AAnimal::AAnimal( void )
{
	this->type = "none";
	std::cout << "AAnimal was created" << std::endl;
}

AAnimal::~AAnimal( void )
{
	std::cout << "AAnimal was destroied" << std::endl;
}

AAnimal::AAnimal( const AAnimal &srs)
{
	*this = srs;
	std::cout << "AAnimal was copied" << std::endl;
}

AAnimal	&AAnimal::operator=( const AAnimal &rhs)
{
	std::cout << "AAnimal was assigned" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void	AAnimal::makeSound( void ) const
{
	std::cout << "The object has no type therefore no sound" << std::endl;
}

std::string	AAnimal::getType( void ) const
{
	return (this->type);
}
