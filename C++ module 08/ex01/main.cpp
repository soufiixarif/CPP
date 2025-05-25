#include "Span.hpp"

int main(){
    Span sp(1);
    try{
        sp.addNumber(5);
        sp.addNumber(9);
        sp.addNumber(-1000);
        sp.addNumber(6);
        sp.addNumber(0);
        sp.addNumber(100);
        sp.addNumber(2);
        sp.addNumber(92);
        sp.addNumber(80);
        }catch (const std::exception &e){
        std::cout << e.what() << std::endl;
    }
    sp.showVector();
    std::cout << "min is: " << sp.min() << std::endl;
    std::cout << "max is: " << sp.max() << std::endl;
try{
    std::cout << "longest span: " << sp.longestSpan() << std::endl;
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
}catch(const std::exception &e){
    std::cout << e.what() << std::endl;
}
    
}