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
    //ex02
    bool operator< (const Fixed& num) const;
    bool operator> (const Fixed& num) const;
    bool operator<= (const Fixed& num) const;
    bool operator>= (const Fixed& num) const;
    bool operator== (const Fixed& num) const;
    bool operator!= (const Fixed& num) const;
    Fixed operator+ (const Fixed& num);
    Fixed operator- (const Fixed& num);
    Fixed operator* (const Fixed& num);
    Fixed operator/ (const Fixed& num);
    Fixed& operator++ ( void );
    Fixed& operator-- ( void );
    Fixed operator++ ( int );
    Fixed operator-- ( int );

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    float   toFloat( void ) const;
    int     toInt( void ) const;
    //ex02
    static Fixed& min(Fixed& num1, Fixed& num2);
    static const Fixed& min(const Fixed& num1, const Fixed& num2);
    static Fixed& max(Fixed& num1, Fixed& num2);
    static const Fixed& max(const Fixed& num1, const Fixed& num2);
};

std::ostream& operator<< (std::ostream& o, const Fixed& num);

#endif
