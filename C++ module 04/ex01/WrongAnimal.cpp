#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal default constractor called" << std::endl;
    this->Type = "WrongAnimal";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    this->Type = other.Type;
    return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
    std::cout << "WrongAnimal copy constractor called" << std::endl;
    *this = other;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal deconstractor called" << std::endl;
}

std::string WrongAnimal::getType() const{
    return (this->Type);
}

void WrongAnimal::makeSound()const{
    std::cout << "WrongAnimal make his wierd sound" << std::endl;
}