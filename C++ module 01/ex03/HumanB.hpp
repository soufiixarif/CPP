#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanB{
private:
    std::string name;
    Weapon *weapon;
public:
    HumanB(std::string name);
    void setWeapon(Weapon &weapon);
    void setNAme(std::string);
    std::string getName();
    void attack();
};