#include "Zombie.hpp"

Zombie::Zombie(){

}

void    Zombie::setName(std::string name){
    this->name = name;
}
std::string    Zombie::getName(){
    return (name);
}

void Zombie::announce( void ){
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
    std::cout << getName() << ": destroyed" << std::endl;
}