
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    n = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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

Fixed::Fixed(const int val)
{
    std::cout << "Int constructor called" << std::endl;
    n = (val << f);
}

Fixed::Fixed(const float val)
{
    std::cout << "Float constructor called" << std::endl;
    n = (int)roundf(val * (1 << f));
}

int     Fixed::getRawBits( void ) const
{
    return ( n );
}

void    Fixed::setRawBits( int const raw )
{
    n = raw;
}

int   Fixed::toInt( void ) const
{
    int tmp = this->n >> this->f;
    return (tmp);
}

float     Fixed::toFloat( void ) const
{
    float tmp = (float)this->n/(1 << this->f);
    return (tmp);
}

std::ostream& operator<< (std::ostream& o, const Fixed& num)
{
    o << num.toFloat();
    return (o);
}