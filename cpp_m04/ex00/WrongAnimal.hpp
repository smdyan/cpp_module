#ifndef WRONG_WrongAnimal_HPP
#define WRONG_WrongAnimal_HPP

#include <iostream>
#include "Color.h"

class WrongAnimal
{
protected:
		std::string type;
public:
					WrongAnimal( void );
					~WrongAnimal( void );
					WrongAnimal( const WrongAnimal &src);
	WrongAnimal		&operator=( const WrongAnimal &rhs);
	void			makeSound( void ) const;
	std::string		getType( void ) const;
};

#endif