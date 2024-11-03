#include "Harl.hpp"

int main(int ac, char **av) {
    if (ac == 2){
        Harl harlObj;
        harlObj.complain(av[1]);
    }
    else
        std::cout <<"ARGS ERROR" << std::endl;

    return 0;
}