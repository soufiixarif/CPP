#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Cat default constractor called" << std::endl;
    this->brain = new Brain();
    for(int i = 0; i < 100; i++){
        this->brain->setIdeas(i, "give me some food my slave!");
    }
    this->Type = "Cat";
}

Cat &Cat::operator=(const Cat &other){
    std::cout << "Cat copy assiengment operator called" << std::endl;
    this->Type = other.Type;
    delete this->brain;
    this->brain = new Brain(*(other.brain));
    return (*this);
}

Cat::Cat(const Cat &other){
    std::cout << "Cat copy constractor called" << std::endl;
    this->brain = NULL;// no need
    *this = other;
}

Cat::~Cat(){
    std::cout << "Cat Deconstractor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound()const {
    std::cout << "Meow Meow!!!" << std::endl;
}