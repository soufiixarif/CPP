#include "PmergeMe.hpp"

int main(int ac, char **av){
    PmergeMe to_sort;

    try{
        to_sort.sort(ac, av);
    }catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}