#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "Color.h"

class Brain
{
private:
	std::string	ideas[100];
public:
			Brain( void );
			~Brain( void );
			Brain( const Brain &srs );
	Brain	&operator=( const Brain &rhs );
};


#endif