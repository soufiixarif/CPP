#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    Bureaucrat soufiix("soufiix", 2);
    Form bill("wati9a mliha", false, 2, 1);

    soufiix.signForm(bill);
    // try{
    //     bill.beSigned(soufiix);
    // }catch (const Form::GradeTooLowException &e){
    //     std::cerr << e.what() << std::endl;
    // }
    std::cout << soufiix << std::endl;
    std::cout << bill << std::endl;
}