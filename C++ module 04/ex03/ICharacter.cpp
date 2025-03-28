#include "ICharacter.hpp"

ICharacter::ICharacter(){
    this->name = "charachter default name";
    for (int i = 0; i < 4; i++){
        delete inventory[i];
        inventory[i] = nullptr;
    }
}

ICharacter &ICharacter::operator=(const ICharacter &other){
    this->name = other.name;
    for (int i = 0; i < 4; i++){
        delete inventory[i];
        inventory[i] = other.inventory[i]->clone();
    }
    return (*this);
}

ICharacter::ICharacter(const ICharacter &other){
    *this = other;
}

ICharacter::~ICharacter(){
    for (int i = 0; i < 4; i++)
        delete inventory[i];
}

ICharacter::ICharacter(std::string name): name(name){
    for (int i = 0; i < 4; i++){
        delete inventory[i];
        inventory[i] = nullptr;
    }
}

std::string const &ICharacter::getName() const{
    return this->name;
}

void ICharacter::equip(AMateria* m){
    for (int i = 0; i < 4; i++){
        if (!inventory[i]){
            inventory[i] = m;
            break;
        }
    }
}

void ICharacter::unequip(int idx){// add it to a vtable to save the adress
    if (idx >= 0 && idx < 4)
        inventory[idx] = nullptr;
}

void ICharacter::use(int idx, ICharacter &targer){
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(targer);
}
