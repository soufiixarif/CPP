#include "Bureaucrat.hpp"

int main(){
    
    Bureaucrat soufiix("soufiix", 150);

    try{
        soufiix.decrement();
    }catch (const Bureaucrat::GradeTooHighException &e){
        std::cerr << e.what() << std::endl;
    }catch (const Bureaucrat::GradeTooLowException &e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << soufiix << std::endl;
}