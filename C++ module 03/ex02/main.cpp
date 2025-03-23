#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

    FragTrap frag("Fraggy");
    frag.attack("Enemy");
    frag.takeDamage(15);
    frag.beRepaired(8);
    frag.highFivesGuys();
    frag.takeDamage(500);
    frag.takeDamage(1);

    return 0;
}