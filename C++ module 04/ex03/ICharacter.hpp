#pragma once
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria ;
class  ICharacter{
    protected:
        std::string name;
        AMateria *inventory[4];
    public:
        ICharacter();
        ICharacter &operator=(const ICharacter &other);
        ICharacter(const ICharacter &other);
        virtual ~ICharacter(); //{}
    
        ICharacter(std::string name);
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};