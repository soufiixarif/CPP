#include <iostream>

class Zombie{
private :
    std::string name;
public :
    Zombie();
    void setName(std::string name);
    std::string getName(void);
    void  announce(void); 
    ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );
