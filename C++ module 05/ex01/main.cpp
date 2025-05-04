#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    Bureaucrat soufiix("soufiix", 2);
    Form wati9a("kaghit", false, 1,1);
    std::cout << "tale3 nivo chwia" << std::endl;
    soufiix.increment();
    std::cout << "sini hna" << std::endl; 
    soufiix.signForm(wati9a);
    soufiix.signForm(wati9a);
    try{
        soufiix.increment();
    }catch (const Bureaucrat::GradeTooHighException &e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << soufiix;
}