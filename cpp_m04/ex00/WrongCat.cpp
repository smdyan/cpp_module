#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	this->type = "WrongCat";
	std::cout << YELLOW << "WrongCat was created" << RESET << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << YELLOW << "WrongCat was destroied" << RESET << std::endl;
}

WrongCat::WrongCat( WrongCat const &srs)
{
	*this = srs;
	std::cout << YELLOW << "WrongCat was copied" << RESET << std::endl;
}

WrongCat	&WrongCat::operator=( WrongCat const &rhs)
{
	std::cout << YELLOW << "WrongCat was assigned" << RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void	WrongCat::makeSound( void ) const
{
	std::cout  << YELLOW << "Someone is saying meow..." << RESET << std::endl;
}
