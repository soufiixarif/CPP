#include "iter.hpp"

void print_inside(const int &x){
    std::cout << "the value is: "<< x << std::endl;
}

void incriment_inside(int &x){
    x++;
}

int main(){
    int ptr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ::iter(ptr, 10, print_inside);

    std::cout << "-------incriment-----------" << std::endl;
    ::iter(ptr,10,incriment_inside);
    std::cout << "----------print------------" << std::endl;
    ::iter(ptr, 10, print_inside);
    
}