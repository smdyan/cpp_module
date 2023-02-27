#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*m_brain;
public:
			Cat( void );
			~Cat( void );
			Cat( const Cat &src );
	Cat		&operator=( const Cat &rhs );
	void	makeSound( void ) const;
};


#endif