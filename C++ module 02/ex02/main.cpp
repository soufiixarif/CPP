#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    // Fixed a;
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    printf("Test");
    Fixed c(8388607.2f);
    std::cout << std::fixed << c << std::endl;
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;
}