#pragma once
#include <iostream>

class ClapTrap{
    protected:
        std::string Name;
        unsigned int HitPoints;
        unsigned int EnergyPoints;
        unsigned int AttackDamage;
    public:
        ClapTrap();
        ClapTrap(ClapTrap &other);
        ClapTrap & operator=(const ClapTrap &other);
        ~ClapTrap();

        ClapTrap(std::string Name);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};