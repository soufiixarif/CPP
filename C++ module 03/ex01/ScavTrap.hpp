#include "ClapTrap.hpp"

class ScavTrap : ClapTrap{
    public :
        ScavTrap();
        ScavTrap(ScavTrap &other);
        ScavTrap & operator=(const ScavTrap &other);
        ~ScavTrap();
        ScavTrap(std::string name);
        void guardGate();
};