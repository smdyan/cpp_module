#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int                 n;
    static const int    f = 8;

public:
    Fixed();
    Fixed(const Fixed& num);
    Fixed& operator= (const Fixed& num);
    ~Fixed();
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
};

#endif
