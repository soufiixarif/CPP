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
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;  
    bool operator!=(const Fixed &other) const;
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);
    static Fixed &min(Fixed &f1, Fixed &f2);
    static Fixed &max(Fixed &f1, Fixed &f2);
    static const Fixed &min(const Fixed &f1, const Fixed &f2);
    static const Fixed &max(const Fixed &f1, const Fixed &f2);
    ~Fixed();
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);