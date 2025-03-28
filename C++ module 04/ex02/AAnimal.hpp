#pragma once
#include "iostream"

class AAnimal{
    protected:
        std::string Type;
    public:
        AAnimal();
        AAnimal(const AAnimal &other);
        AAnimal &operator=(const AAnimal &other);
        virtual ~AAnimal();
    
        std::string getType() const;
        virtual void makeSound() const = 0;
};