#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Cat default constractor called" << std::endl;
    this->Type = "Cat";
}

Cat &Cat::operator=(const Cat &other){
    std::cout << "Cat copy assiengment operator called" << std::endl;
    this->Type = other.Type;
    return (*this);
}

Cat::Cat(const Cat &other){
    std::cout << "Cat copy constractor called" << std::endl;
    *this = other;
}

Cat::~Cat(){
    std::cout << "Cat Deconstractor called" << std::endl;
}

void Cat::makeSound()const {
    std::cout << "Meow Meow!!!" << std::endl;
}