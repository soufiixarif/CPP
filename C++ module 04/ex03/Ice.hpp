#pragma once
#include "AMateria.hpp"

class Ice: public AMateria{
    public:
        Ice();
        Ice &operator=(const Ice &other);
        Ice(const Ice &other);
        ~Ice();

        AMateria *clone()const;
        void use(ICharacter& target );
};