#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int         n;
    static const int   f = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& num);
    Fixed& operator= (const Fixed& num);
    Fixed(const int val);
    Fixed(const float val);

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    float   toFloat( void ) const;
    int     toInt( void ) const;
};

std::ostream& operator<< (std::ostream& o, const Fixed& num);

#endif
