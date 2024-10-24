#include "Zombie.hpp"

int main(){
    Zombie *zombie;

    randomChump("khorag");
    zombie = newZombie("zogrom");
    zombie->announce();

    delete(zombie);
}