#include "Ice.hpp"

Ice::Ice(){
    this->type = "ice";
}

Ice &Ice::operator=(const Ice &other){
    this->type = other.type;
    return *this;
}

Ice::Ice(const Ice &other){
    *this = other;
}

Ice::~Ice(){

}

AMateria *Ice::clone()const{
    AMateria *tmp = new Ice();
    return tmp;
}

void Ice::use(ICharacter &target){
    std::cout << "shoots an ice bolt at " << target.getName() << std::endl;
}