#include "Zombie.hpp"

int main(){
    Zombie *zombie;

    zombie = newZombie("zogromHeap");
    zombie->announce();
    randomChump("ZombiStack");

    delete(zombie);
}