#include "ClapTrap.hpp"

int main() {
    ClapTrap bot1("Bot1");

    bot1.attack("Enemy");
    bot1.takeDamage(5);
    bot1.beRepaired(3);

    // Draining energy points
    for (int i = 0; i < 10; i++) {
        bot1.attack("Target");
    }

    // Should not be able to attack due to 0 energy
    bot1.attack("Final Target");

    return 0;
}