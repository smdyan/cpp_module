#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*m_brain;
public:
			Dog( void );
			~Dog( void );
			Dog( const Dog &src);
	Dog		&operator=( const Dog &rhs);
	void	makeSound( void ) const;
};


#endif