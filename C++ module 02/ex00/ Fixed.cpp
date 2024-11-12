#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->raw = 0;
}
Fixed::Fixed(Fixed& copy){

    std::cout << "Copy constructor called" << std::endl;
    this->raw = copy.getRawBits();
}
Fixed&    Fixed::operator=(const Fixed& op){
    std::cout << "Copy assignment operator called" << std::endl;
    this->raw = op.getRawBits();
    return (*this);
}
int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->raw);
}
void Fixed::setRawBits( int const raw ){
    this->raw = raw;
}