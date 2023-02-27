#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
			Dog( void );
			~Dog( void );
			Dog( const Dog &src);
	Dog		&operator=( const Dog &rhs);
	void	makeSound( void ) const;
};


#endif