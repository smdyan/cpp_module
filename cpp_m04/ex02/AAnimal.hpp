#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Color.h"

class AAnimal
{
protected:
		std::string type;
public:
					AAnimal(	void );
	virtual			~AAnimal( void );
					AAnimal( const AAnimal &src);
	AAnimal			&operator=( const AAnimal &rhs);
	virtual	void	makeSound( void ) const=0;
	std::string		getType( void ) const;

};

#endif