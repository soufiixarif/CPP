#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA{
private:
    std::string name;
    Weapon &weapon;
public:
    HumanA(std::string name, Weapon &weapon);
    void setWeapon(Weapon &weapon);
    void setNAme(std::string name);
    std::string getName();
    void attack();
};