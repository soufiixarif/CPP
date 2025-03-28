#pragma once
#include "iostream"

class Animal{
    protected:
        std::string Type;
    public:
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();
    
        std::string getType() const;
        virtual void makeSound() const;
};