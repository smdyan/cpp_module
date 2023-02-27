#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
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