#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
    public :
    FragTrap();
    FragTrap(FragTrap &other);
    FragTrap &operator=(const FragTrap& other);
    ~FragTrap();

    FragTrap(std::string name);
    void highFivesGuys(void);
    void attack(const std::string &target);
};