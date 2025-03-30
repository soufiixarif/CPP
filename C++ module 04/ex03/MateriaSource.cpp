#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; i++){
        this->inventory[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other){
    if (this != &other){
        for(int i = 0; i < 4; i++)
            delete this->inventory[i];
        for (int i = 0; i < 4; i++)
            this->inventory[i] = other.inventory[i]->clone();
    }
    return (*this);
}

MateriaSource::MateriaSource(const MateriaSource& other){
    *this = other;
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++)
        delete inventory[i];
}

void MateriaSource::learnMateria(AMateria *materia){
    for (int i = 0; i < 4; i++){
        if (!inventory[i]){
            inventory[i] = materia;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type){
    for (int i = 0; i < 4; i++){
        if (inventory[i] && inventory[i]->getType() == type){
            return (inventory[i]->clone());
        }
    }
    return NULL;
}