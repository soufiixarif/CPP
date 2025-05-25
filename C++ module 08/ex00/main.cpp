#include "easyfind.hpp"
#include <deque>

int main(){
    std::deque<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(10);
    
    try {
        int result = easyfind(vec, 3);
        std::cout << "Found value: " << result << std::endl;
        
        result = easyfind(vec, 12);
        std::cout << "Found value: " << result << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}