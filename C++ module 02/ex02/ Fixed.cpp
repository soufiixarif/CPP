#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->raw = 0;
}

Fixed::Fixed(const int &n): raw(n << fractionalBits){
    std::cout << "Int constructor called" << std::endl;
    // std::cout << "int is = " << raw <<std::endl;
} 

Fixed::Fixed(const float &f): raw(roundf(f * (1 << fractionalBits))){
    std::cout << "Float constructor called" << std::endl;
    // std::cout << "float is = " << raw <<std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    //is this != other
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
Fixed&    Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    this->raw = other.getRawBits();
    return (*this);
}
int Fixed::getRawBits( void ) const{
    return(this->raw);
}
void Fixed::setRawBits( int const raw ){
    this->raw = raw;
}

float Fixed::toFloat(void) const{
    return (((float)raw / (1 << fractionalBits)));
}

int Fixed::toInt(void) const{
    return ((int)this->toFloat());

}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

Fixed Fixed::operator+(const Fixed &other){
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other){
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other){
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other){
    return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator>(const Fixed &other){
    return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed &other){
    return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed &other){
    return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed &other){
    return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed &other){
    return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed &other){
    return (this->toFloat() != other.toFloat());
}

Fixed& Fixed::operator++(){
    this->raw += 1;
    return (*this);
}

Fixed Fixed::operator++(int){
    Fixed temp = *this;
    this->raw += 1;
    return (temp);
}

Fixed &Fixed::operator--(){
    this->raw -= 1;
    return (*this);
}

Fixed Fixed::operator--(int){
    Fixed temp = *this;
    this->raw -= 1;
    return (temp);
}
