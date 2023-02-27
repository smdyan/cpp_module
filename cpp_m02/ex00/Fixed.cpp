
#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    n = 0;
}

Fixed::Fixed( const Fixed& num )
{
    std::cout << "Copy constructor called" << std::endl;
    n = num.getRawBits();
}

Fixed& Fixed::operator= ( const Fixed& num )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &num)
        return ( *this );
    n = num.getRawBits();
    return ( *this );
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return ( n );
}

void    Fixed::setRawBits( int const raw )
{
    std::cout << "SetRawBits member function called" << std::endl;
    n = raw;
}