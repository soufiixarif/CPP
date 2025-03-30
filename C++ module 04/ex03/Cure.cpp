#include "Cure.hpp"

Cure::Cure(){
    this->type = "cure";
}

Cure &Cure::operator=(const Cure &other){
    this->type = other.type;
    return *this;
}

Cure::Cure(const Cure &other){
    *this = other;
}

Cure::~Cure(){

}

AMateria *Cure::clone()const{
    AMateria *tmp = new Cure();
    return tmp;
}

void Cure::use(ICharacter &target){
    std::cout << "heals " << target.getName() << "’s wounds" << std::endl;
}