#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain default constractor called" << std::endl;
}

Brain& Brain::operator=(const Brain &other){
    std::cout << "Brain copy assignment operator called" << std::endl;
    *this->ideas = *other.ideas;
    return (*this);
}

Brain::Brain(const Brain &other){
    std::cout << "Brain copy constractor called" << std::endl;
    *this = other;
}

Brain::~Brain(){
    std::cout << "Brain deconstractor called" << std::endl;
}

void Brain::setIdeas(unsigned int i, std::string idea){
    if (i < 100)
        this->ideas[i] = idea;
}