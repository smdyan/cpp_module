
#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed 		a;	
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed		c( 12 );
	Fixed		d( 34 );

	if( c < d )
		std::cout << "a menche b" << std::endl;
	if( d > c )
		std::cout << "b bolsche a" << std::endl;
	std::cout << c + d << std::endl;
	std::cout << "min" << Fixed::min(c, d) << std::endl;
	std::cout << "max" << Fixed::max(c, d) << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
