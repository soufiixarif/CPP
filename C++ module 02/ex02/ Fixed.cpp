#include "Fixed.hpp"

Fixed::Fixed(){
    this->raw = 0;
}

Fixed::Fixed(const int &n): raw(n << fractionalBits){
    
}
#include <iomanip>
Fixed::Fixed(const float &f): raw(roundf(f * (float)(1 << fractionalBits))){
}

Fixed::~Fixed(){
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}
Fixed&    Fixed::operator=(const Fixed& other){
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

Fixed Fixed::operator+(const Fixed &other) const{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const{
    return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator>(const Fixed &other) const{
    return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed &other) const{
    return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) const{
    return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) const{
    return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed &other) const{
    return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed &other) const{
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

Fixed &Fixed::min(Fixed &f1, Fixed&f2){
    return ((f1 < f2) ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed&f2){
    return ((f1 >f2) ? f1 : f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2){
    return ((f1 < f2) ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2){
    return ((f1 > f2) ? f1 : f2);
}