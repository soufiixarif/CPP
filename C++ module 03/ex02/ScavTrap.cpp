#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap(){
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->Name = "default name";
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
};
ScavTrap::ScavTrap(ScavTrap &other):ClapTrap(){
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    this->Name = other.Name;
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
};
ScavTrap & ScavTrap::operator=(const ScavTrap &other){
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    this->Name = other.Name;
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
    return(*this);
};
ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap deconstarctor called" << std::endl;
}
ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    std::cout << "ScavTrap Parametrized constructor called" << std::endl;
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
};
void ScavTrap::guardGate(){
    if (this->HitPoints < 1){
        std::cout << "ScavTrap " << Name << " is out of hit points! It can't guard the gate!" << std::endl;
        return ;
    }
    if (this->EnergyPoints < 1){
        std::cout << "ScavTrap " << Name << " has no energy left! It can't guard the gate!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << Name << " is now in Gate Keeper mode!" << std::endl;
};

void ScavTrap::attack(const std::string &target){
    if (this->EnergyPoints < 1){
        std::cout << "ScavTrap can´t hit, not enough energy points" << std::endl;
        return ;
    }
    if (this->HitPoints < 1){
        std::cout << "ScavTrap can´t hit, not enough Hit points" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
    this->EnergyPoints -= 1;
}
