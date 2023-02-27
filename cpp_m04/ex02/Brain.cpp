#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << CYAN << "Brain was created" << RESET << std::endl;
}

Brain::~Brain( void )
{
	std::cout << CYAN << "Brain was destroied" << RESET << std::endl;
}

Brain::Brain( const Brain &srs)
{
	*this = srs;
	std::cout << CYAN << "Brain was copied" << RESET << std::endl;
}

Brain	&Brain::operator=( const Brain &rhs)
{
	std::cout << CYAN << "Brain was assigned" << RESET << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}