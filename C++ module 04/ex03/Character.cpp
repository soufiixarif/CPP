#include "Character.hpp"

Character::Character(){
    this->name = "charachter default name";
    for (int i = 0; i < 4; i++){
        delete inventory[i];
        inventory[i] = nullptr;
    }
}

Character &Character::operator=(const Character &other){
    this->name = other.name;
    for (int i = 0; i < 4; i++){
        delete inventory[i];
        inventory[i] = other.inventory[i]->clone();
    }
    return (*this);
}

Character::Character(const Character &other){
    *this = other;
}

Character::~Character(){
    for (int i = 0; i < 4; i++)
        delete inventory[i];
}

Character::Character(std::string name): ICharacter(name){
    for (int i = 0; i < 4; i++){
        delete inventory[i];
        inventory[i] = nullptr;
    }
}

std::string const &Character::getName() const{
    return this->name;
}

void Character::equip(AMateria* m){
    for (int i = 0; i < 4; i++){
        if (!inventory[i]){
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx){// add it to a vtable to save the adress
    if (idx >= 0 && idx < 4)
        inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter &targer){
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(targer);
}
