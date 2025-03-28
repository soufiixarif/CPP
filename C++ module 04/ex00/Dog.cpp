#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Dog default constractor called" << std::endl;
    this->Type = "Dog";
}

Dog &Dog::operator=(const Dog &other){
    std::cout << "Dog copy assiegnment operator called" << std::endl;
    this->Type = other.Type;
    return (*this);
}

Dog::Dog(const Dog &other){
    std::cout << "Dog Copy constractor called" << std::endl;
    *this = other;
}


Dog::~Dog(){
    std::cout << "Dog deconstractor called" << std::endl;
}

void Dog::makeSound()const{
    std::cout << "Bark Bark!!" << std::endl;
}