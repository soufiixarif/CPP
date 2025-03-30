#include "Character.hpp"

Character::Character(){
    this->name = "charachter default name";
    this->garbage = new AMateria*[1];
    this->garbage[0] = NULL;
    for (int i = 0; i < 4; i++){
        inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &other){
    if (this != &other)
    {
        this->name = other.name;
        for (int i = 0; i < 4; i++){
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
        int i = 0;
        while(this->garbage[i])
            delete(this->garbage[i++]);
        delete this->garbage;
        this->garbage = new AMateria*[1];
        this->garbage[0] = NULL;
    }
    return (*this);
}

Character::Character(const Character &other){
    for (int i = 0; i < 4; i++){
        inventory[i] = NULL;
    }
    this->garbage = new AMateria*[1];
    this->garbage[0] = NULL;
    *this = other;
}

Character::~Character(){
    for (int i = 0; i < 4; i++)
        delete inventory[i];
    int i = 0;
    while(this->garbage[i])
        delete(this->garbage[i++]);
    delete this->garbage;
}

Character::Character(std::string name){
    this->garbage = new AMateria*[1];
    this->garbage[0] = NULL;
    this->name = name;
    for (int i = 0; i < 4; i++){
        inventory[i] = NULL;
    }
}

std::string const &Character::getName() const{
    return this->name;
}

void Character::equip(AMateria* m){
    if (!m)
        return;
    for(int i = 0; i < 4; i++){
        if(inventory[i] == m)
            return;
    }
    for (int i = 0; i < 4; i++){
        if (!inventory[i]){
            inventory[i] = m;
            break;
        }
    }
}

AMateria **get_new_amteria(AMateria **old, AMateria *new_ptr)
{
    int size = 0;
    while(old[size])
    {
        if(old[size++] == new_ptr)
            return old;
    }
    AMateria **new_am = new AMateria*[size+2];
    for(int i = 0 ; i< size ;i++)
    {
        new_am[i] = old[i];
        delete old[i];
    }
    delete old;
    new_am[size++] = new_ptr;
    new_am[size] = NULL;
    return(new_am);
}

void Character::unequip(int idx){
    if (idx >= 0 && idx < 4){
        this->garbage = get_new_amteria(this->garbage, this->inventory[idx]);
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &targer){
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(targer);
}
