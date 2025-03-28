#pragma once
#include "AMateria.hpp"

class IMateriaSource{
    protected:
        AMateria *inventory[4];
    public:
        IMateriaSource();
        IMateriaSource(const IMateriaSource &other);
        IMateriaSource &operator=(const IMateriaSource& other);
        virtual ~IMateriaSource();
    
        virtual void learnMateria(AMateria* materia) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};