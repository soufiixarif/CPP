#pragma once
#include "ICharacter.hpp"
#include <iostream>

class ICharacter ;

class AMateria
{
    protected:
        std::string type;
        //    [...]
    public:
        AMateria();
        AMateria(const AMateria &other);
        AMateria &operator=(const AMateria &other);
        virtual ~AMateria();

        AMateria(std::string const & type);
        // [...]
        std::string const & getType() const; //Returns the materia type
        virtual void use(ICharacter& target );
        virtual AMateria *clone() const = 0;
};