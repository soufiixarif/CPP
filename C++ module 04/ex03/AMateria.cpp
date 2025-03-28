#include "AMateria.hpp"

AMateria::AMateria(){
    this->type = "default Type";
}

AMateria &AMateria::operator=(const AMateria &other){
    this->type = other.type;
    return *this;
}

AMateria::AMateria(const AMateria &other){
    *this = other;
}

AMateria::~AMateria(){

}

AMateria::AMateria(std::string const &type): type(type){

}

std::string const &AMateria::getType()const{
    return this->type;
}

void AMateria::use(ICharacter& target){
    std::cout << "use function called in AMateria by " << target.getName() << std::endl;
}