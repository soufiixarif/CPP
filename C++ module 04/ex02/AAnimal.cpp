#include "AAnimal.hpp"

AAnimal::AAnimal(){
    std::cout << "AAnimal default constractor called" << std::endl;
    this->Type = "AAnimal";
}

AAnimal &AAnimal::operator=(const AAnimal &other){
    std::cout << "AAnimal Copy assignment operator called" << std::endl;
    this->Type = other.Type;
    return (*this);
}

AAnimal::AAnimal(const AAnimal &other){
    std::cout << "AAnimal copy constractor called" << std::endl;
    *this = other;
}

AAnimal::~AAnimal(){
    std::cout << "AAnimal deconstractor called" << std::endl;
}

std::string AAnimal::getType() const{
    return (this->Type);
}

void AAnimal::makeSound()const{
    std::cout << "AAnimal make his wierd sound" << std::endl;
}