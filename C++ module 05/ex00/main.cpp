#include "Bureaucrat.hpp"

int main(){
    Bureaucrat soufiix("soufiix", 2);

    soufiix.increment();
    try{
        soufiix.increment();
    }catch (const Bureaucrat::GradeTooHighException &e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << soufiix << std::endl;
}