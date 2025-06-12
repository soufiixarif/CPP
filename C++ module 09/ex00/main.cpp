#include "BitcoinExchange.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cerr << "ARGS ERROR" << std::endl;
        return 1;
    }
    try{
        BitcoinExchange btc("data.csv");
        
        // btc.printData();
        btc.dataProcessing(av[1]);
    }catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}