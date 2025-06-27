#include "Span.hpp"

int main(){
    Span sp(50);
    try{
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(4);
        sp.addNumber(7);
        sp.addNumber(10);
        sp.addNumber(14);
        sp.addNumber(19);
        sp.addNumber(29);
        sp.addNumber(49);
        }catch (const std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << "longest span (in sp): " << sp.longestSpan() << std::endl;
        std::cout << "shortest span (in sp): " << sp.shortestSpan() << std::endl;
    }catch(const std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << "\n===== Range Insertion Test =====\n";
        Span big(10000);
        std::vector<int> nums;
        for (int i = 0; i < 10000; ++i)
            nums.push_back(rand());

        big.addNumber(nums.begin(), nums.end());

        std::cout << "Shortest span (in big): " << big.shortestSpan() << std::endl;
        std::cout << "Longest span (in big): " << big.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}