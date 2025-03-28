#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Dog default constractor called" << std::endl;
    this->brain = new Brain();
    for(int i = 0; i < 100; i++){
        this->brain->setIdeas(i, "i will protect you my friend!");
    }
    this->Type = "Dog";
}

Dog &Dog::operator=(const Dog &other){
    std::cout << "Dog copy assiegnment operator called" << std::endl;
    this->Type = other.Type;
    delete this->brain;
    this->brain = new Brain(*(other.brain));
    return (*this);
}

Dog::Dog(const Dog &other){
    std::cout << "Dog Copy constractor called" << std::endl;
    this->brain = NULL;
    *this = other;
}


Dog::~Dog(){
    std::cout << "Dog deconstractor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound()const{
    std::cout << "Bark Bark!!" << std::endl;
}