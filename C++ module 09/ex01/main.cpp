#include "RPN.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cout << "ARG ERROR" << std::endl;
        return 1;
    }

    try{
        RPN _rpn;
        _rpn.operationProcessing(av[1]);
    }catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}