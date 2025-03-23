#include "ClapTrap.hpp"

int main() {
    ClapTrap bot1("soufiix");

    bot1.attack("Enemy");
    bot1.takeDamage(9);
    bot1.beRepaired(3);
    bot1.takeDamage(4);

    return 0;
}