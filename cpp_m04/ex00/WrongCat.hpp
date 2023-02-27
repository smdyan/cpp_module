#ifndef WRONG_WrongCat_HPP
#define WRONG_WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
			WrongCat( void );
			~WrongCat( void );
			WrongCat( WrongCat const &src);
	WrongCat		&operator=( WrongCat const &rhs);
	
	void	makeSound( void ) const;
};


#endif