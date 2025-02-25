#include "Zombie.hpp"

int main(){
    Zombie *zombie;

    zombie = zombieHorde(10, "Soufiix");
    for (int i = 0; i < 10; i++){
        zombie[i].announce();
    }

    delete [] (zombie);
}