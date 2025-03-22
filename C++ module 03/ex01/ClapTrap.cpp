#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap default constructor called" << std::endl;
    this->Name = "Default";
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
}

ClapTrap::ClapTrap(std::string name): Name(name){
    std::cout << "ClapTrap Parametrized constructor called" << std::endl;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap &other){
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    this->Name = other.Name;
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other){
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    this->Name = other.Name;
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
    return(*this);
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target){
    if (this->EnergyPoints < 1){
        std::cout << "ClapTrap can´t hit, not enough energy points" << std::endl;
        return ;
    }
    if (this->HitPoints < 1){
        std::cout << "ClapTrap can´t hit, not enough Hit points" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
    this->EnergyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "ClapTrap " << this->Name << " take " << amount << " damage!" << std::endl;
    if (this->HitPoints < amount)
    {
        this->HitPoints = 0;
        std::cout << "ClapTrap " << this->Name << " dead!" << std::endl;
    }
    else
        this->HitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->EnergyPoints < 1){
        std::cout << "ClapTrap can´t repare itsef not enough energy points" << std::endl;
        return ;
    }
    if (this->HitPoints < 1){
        std::cout << "ClapTrap can´t repairs itself, not enough Hit points" << std::endl;
        return ;
    }
    std::cout << "ClapTrap repairs itself with " << amount << " of hit points" << std::endl; 
    this->HitPoints += amount;
    this->EnergyPoints -= 1;
}
