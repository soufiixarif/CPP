#pragma once
#include <iostream>

class Fixed{
private:
    int raw;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed(const int &n);
    Fixed(const float &f);
    Fixed &    operator=(const Fixed& other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    ~Fixed();
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);