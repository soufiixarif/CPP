#pragma once
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource{
    public:
        MateriaSource();
        MateriaSource &operator=(const MateriaSource &other);
        MateriaSource(const MateriaSource &other);
        ~MateriaSource();

        void learnMateria(AMateria *materia);
        AMateria *createMateria(std::string const &type);
};