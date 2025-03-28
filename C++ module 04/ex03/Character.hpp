#pragma once
#include "ICharacter.hpp"

class  Character : public ICharacter{
    public:
        Character();
        Character &operator=(const Character &other);
        Character(const Character &other);
        ~Character();
    
        Character(std::string name);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};