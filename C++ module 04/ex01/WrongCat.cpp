#include "WrongCat.hpp"

WrongCat::WrongCat(){
    std::cout << "WrongCat default constractor called" << std::endl;
    this->Type = "WrongCat";
}

WrongCat &WrongCat::operator=(const WrongCat &other){
    std::cout << "WrongCat copy assiengment operator called" << std::endl;
    this->Type = other.Type;
    return (*this);
}

WrongCat::WrongCat(const WrongCat &other){
    std::cout << "WrongCat copy constractor called" << std::endl;
    *this = other;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat Deconstractor called" << std::endl;
}


void WrongCat::makeSound()const {
    std::cout << "MOuuuuuuu!!!" << std::endl;
}