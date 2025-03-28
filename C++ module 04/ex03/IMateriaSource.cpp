#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(){
    for (int i = 0; i < 4; i++){
        this->inventory[i] = nullptr;
    }
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &other){
    for(int i = 0; i < 4; i++)
        delete this->inventory[i];
    for (int i = 0; i < 4; i++)
        this->inventory[i] = other.inventory[i]->clone();
    return (*this);
}

IMateriaSource::IMateriaSource(const IMateriaSource& other){
    *this = other;
}

IMateriaSource::~IMateriaSource(){
    for (int i = 0; i < 4; i++)
        delete inventory[i];
}

void IMateriaSource::learnMateria(AMateria *materia){
    for (int i = 0; i < 4; i++){
        if (!inventory[i]){
            inventory[i] = materia;
            break;
        }
    }
}

AMateria *IMateriaSource::createMateria(std::string const &tyoe){
    for (int i = 0; i < 4; i++){
        if (inventory[i] && inventory[i]->getType() == tyoe)
            return (inventory[i]->clone()); 
    }
    return nullptr;
}