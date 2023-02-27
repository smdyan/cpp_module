#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Color.h"

class Animal
{
protected:
		std::string type;
public:
					Animal(	void );
	virtual			~Animal( void );
					Animal( const Animal &src);
	Animal			&operator=( const Animal &rhs);
	virtual	void	makeSound( void ) const;
	std::string		getType( void ) const;

};

#endif