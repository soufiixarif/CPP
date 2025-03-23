#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
    std::cout << "FragTrap default constructor called" << std::endl;
    this->Name = "Default";
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << "FragTrap parametrized constructor called" << std::endl;
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap &other): ClapTrap(){
    std::cout << "FragTrap Copy constructor called" << std::endl;
    this->Name = other.Name;
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap &other){
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    this->Name = other.Name;
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
    return(*this);
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(){
    if (this->HitPoints < 1){
        std::cout << "FragTrap " << Name << " is out of hit points! It can't request high five!" << std::endl;
        return ;
    }
    if (this->EnergyPoints < 1){
        std::cout << "FragTrap " << Name << " has no energy left! It can't request high five!" << std::endl;
        return ;
    }
    std::cout << "FragTrap" << Name << "is requesting a high five!" << std::endl;
}

void FragTrap::attack(const std::string &target){
    if (this->EnergyPoints < 1){
        std::cout << "FragTrap can´t hit, not enough energy points" << std::endl;
        return ;
    }
    if (this->HitPoints < 1){
        std::cout << "FragTrap can´t hit, not enough Hit points" << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
    this->EnergyPoints -= 1;
}