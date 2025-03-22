#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->Name = "default name";
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
};
ScavTrap::ScavTrap(ScavTrap &other){
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
ScavTrap::ScavTrap(std::string name):ClapTrap(Name){
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
