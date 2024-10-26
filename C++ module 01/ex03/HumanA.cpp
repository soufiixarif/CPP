#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon){

}

void HumanA::setWeapon(Weapon &weapon){
    this->weapon = weapon;
}
void HumanA::setNAme(std::string name){
    this->name = name;
}
std::string HumanA::getName(){
    return (this->name);
}
void HumanA::attack(){
    std::cout << getName() << " attacks with their " << weapon.getType() << std::endl;
}