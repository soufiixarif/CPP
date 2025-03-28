#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal default constractor called" << std::endl;
    this->Type = "Animal";
}

Animal &Animal::operator=(const Animal &other){
    std::cout << "Animal Copy assignment operator called" << std::endl;
    this->Type = other.Type;
    return (*this);
}

Animal::Animal(const Animal &other){
    std::cout << "Animal copy constractor called" << std::endl;
    *this = other;
}

Animal::~Animal(){
    std::cout << "Animal deconstractor called" << std::endl;
}

std::string Animal::getType() const{
    return (this->Type);
}

void Animal::makeSound()const{
    std::cout << "Animal make his wierd sound" << std::endl;
}