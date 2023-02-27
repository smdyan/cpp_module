
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    n = 0;
}

Fixed::~Fixed()
{}

Fixed::Fixed( const Fixed& num )
{
    n = num.getRawBits();
}

Fixed& Fixed::operator= ( const Fixed& num )
{
    if (this == &num)
        return ( *this );
    n = num.getRawBits();
    return ( *this );
}

Fixed::Fixed(const int val)
{
     n = (val << f);
}

Fixed::Fixed(const float val)
{
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

bool Fixed::operator< ( const Fixed& num ) const
{
    if( this->n < num.n )
        return true;
    else
        return false;
}

bool Fixed::operator> ( const Fixed& num ) const
{
    if( this->n > num.n )
        return true;
    else
        return false;
}

bool Fixed::operator<= ( const Fixed& num ) const
{
    if( this->n <= num.n )
        return true;
    else
        return false;
}

bool Fixed::operator>= ( const Fixed& num ) const
{
    if( this->n >= num.n )
        return true;
    else
        return false;
}

bool Fixed::operator== ( const Fixed& num ) const
{
    if( this->n == num.n )
        return true;
    else
        return false;
}

bool Fixed::operator!= ( const Fixed& num ) const
{
    if( this->n != num.n )
        return true;
    else
        return false;
}

Fixed Fixed::operator+ (const Fixed& num)
{
    return Fixed(this->toFloat() + num.toFloat());
}

Fixed Fixed::operator- (const Fixed& num)
{
    return Fixed(this->toFloat() - num.toFloat());
}

Fixed Fixed::operator* (const Fixed& num)
{
    return Fixed(this->toFloat() * num.toFloat());
}

Fixed Fixed::operator/ (const Fixed& num)
{
    return Fixed(this->toFloat() / num.toFloat());
}

Fixed& Fixed::operator++ (void)
{
    this->n += 1;
    return *this;
}

Fixed& Fixed::operator-- (void)
{
    this->n -= 1;
    return *this;
}

Fixed Fixed::operator++ ( int )
{
    Fixed temp = *this;
    this->n += 1;
    return temp;
}

Fixed Fixed::operator-- ( int )
{
    Fixed temp = *this;
    this->n -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
    if( num1 <= num2)
        return num1;
    else
        return num2;
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
    if( num1 <= num2)
        return num1;
    else
        return num2;
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
    if( num1 > num2)
        return num1;
    else
        return num2;
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
    if( num1 > num2)
        return num1;
    else
        return num2;
}