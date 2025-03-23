#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    ScavTrap scav("Scavvy");

    scav.attack("Enemy");
    scav.takeDamage(10);
    scav.beRepaired(5);
    scav.guardGate();
    scav.takeDamage(300);
    scav.takeDamage(1);

    return 0;
}
