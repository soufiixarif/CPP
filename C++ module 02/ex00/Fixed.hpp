#pragma once
#include <iostream>

class Fixed{
private:
    int raw;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(Fixed& copy);
    Fixed &    operator=(const Fixed& op);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    ~Fixed();
};
